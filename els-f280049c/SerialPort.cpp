// Electronic Leadscrew
// https://github.com/alexphredorg/electronic-leadscrew
//
// Copyright (c) 2020 Alex Wetmore
//
// Derived from:
// Clough42 Electronic Leadscrew
// https://github.com/clough42/electronic-leadscrew
//
// MIT License
//
// Copyright (c) 2019 James Clough
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


#include "els.h"

// hack global variables used by the ISR to get back to the right class
SerialPort *__serialPortA = NULL;
SerialPort *__serialPortB = NULL;

__interrupt void sciaRxISR(void)
{
    __serialPortA->rxisr();
}

__interrupt void sciaTxISR(void)
{
    __serialPortA->txisr();
}

__interrupt void scibRxISR(void)
{
    __serialPortB->rxisr();
}

__interrupt void scibTxISR(void)
{
    __serialPortB->txisr();
}

SerialPort::SerialPort(const uint32_t sciBase)
{
    _sciBase = sciBase;
    _bufferTail = 0;
    _bufferHead = 0;
    _bufferFull = false;
}

SerialPort::~SerialPort()
{
}

void SerialPort::initHardware(void)
{
    uint32_t rxInterrupt = (_sciBase == SCIA_BASE) ? INT_SCIA_RX : INT_SCIB_RX;

    if (_sciBase == SCIA_BASE) {
        // GPIO37/35 map to pins 9 (SCIATX) and 10 (SCIARX)
        sci_init_pin_tx(37, GPIO_37_SCITXDA);
        sci_init_pin_rx(35, GPIO_35_SCIRXDA);
        __serialPortA = this;
    }
    else
    {
        // GPIO40/13 map to pins 3 (SCIBRX) and 4 (SCIBTX)
        sci_init_pin_tx(40, GPIO_40_SCITXDB);
        sci_init_pin_rx(13, GPIO_13_SCIRXDB);
        __serialPortB = this;
    }

    //
    // Disable global interrupts.
    //
    DINT;

    //
    // Initialize interrupt controller and vector table.
    //
    Interrupt_initModule();
    Interrupt_initVectorTable();
    IER = 0x0000;
    IFR = 0x0000;

    //
    // Map the ISR to the wake interrupt.
    //
    if (_sciBase == SCIA_BASE)
    {
        Interrupt_register(INT_SCIA_RX, sciaRxISR);
    }
    else
    {
        Interrupt_register(INT_SCIB_RX, scibRxISR);
    }

    // 9600 n81
    SCI_setConfig(
            _sciBase,
            DEVICE_LSPCLK_FREQ,
            9600,
            (SCI_CONFIG_WLEN_8 | SCI_CONFIG_STOP_ONE | SCI_CONFIG_PAR_NONE));
    SCI_resetChannels(_sciBase);
    SCI_clearInterruptStatus(_sciBase, SCI_INT_TXFF | SCI_INT_RXFF);
    SCI_resetRxFIFO(_sciBase);
    SCI_resetTxFIFO(_sciBase);
    SCI_enableFIFO(_sciBase);
    SCI_enableModule(_sciBase);
    SCI_performSoftwareReset(_sciBase);

    SCI_setFIFOInterruptLevel(_sciBase, SCI_FIFO_TX0, SCI_FIFO_RX1);
    SCI_enableInterrupt(_sciBase, /* SCI_INT_TXFF | */ SCI_INT_RXFF);

    Interrupt_enable(rxInterrupt);

    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);

    //
    // Enable global interrupts.
    //
    EINT;

}

void SerialPort::sci_init_pin_rx(const uint32_t gpioPin, const uint32_t gpioCfg)
{
    GPIO_setMasterCore(gpioPin, GPIO_CORE_CPU1);
    GPIO_setPinConfig(gpioCfg);
    GPIO_setDirectionMode(gpioPin, GPIO_DIR_MODE_IN);
    GPIO_setPadConfig(gpioPin, GPIO_PIN_TYPE_STD);
    GPIO_setQualificationMode(gpioPin, GPIO_QUAL_ASYNC);
}

void SerialPort::sci_init_pin_tx(const uint32_t gpioPin, const uint32_t gpioCfg)
{
    GPIO_setMasterCore(gpioPin, GPIO_CORE_CPU1);
    GPIO_setPinConfig(gpioCfg);
    GPIO_setDirectionMode(gpioPin, GPIO_DIR_MODE_OUT);
    GPIO_setPadConfig(gpioPin, GPIO_PIN_TYPE_STD);
    GPIO_setQualificationMode(gpioPin, GPIO_QUAL_ASYNC);
}

void SerialPort::send(const char *text)
{
    SCI_writeCharArray(_sciBase, (uint16_t*)text, strlen(text));
}

void SerialPort::send(const unsigned char *msg, const uint32_t length)
{
    SCI_writeCharArray(_sciBase, (uint16_t*)msg, length);
}

void SerialPort::rxisr(void)
{
    int count = SCI_getRxFIFOStatus(_sciBase);

    for (int i = 0; i < count; i++)
    {
        unsigned char ch = (unsigned char) SCI_readCharNonBlocking(_sciBase);
        _buffer[_bufferHead] = ch;
        // overwrite when full

        if (_bufferFull)
            _bufferTail = (_bufferTail + 1) % sizeof(_buffer);
        _bufferHead = (_bufferHead + 1) % sizeof(_buffer);

        if (_bufferHead == _bufferTail)
        {
            _bufferFull = true;
        }
    }

    SCI_clearInterruptStatus(_sciBase, SCI_INT_RXFF);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);
}

void SerialPort::txisr(void)
{
    // no-op right now
    SCI_clearInterruptStatus(_sciBase, SCI_INT_TXFF);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);
}

uint32_t SerialPort::numberBytesReady(void)
{
    if (_bufferFull)
    {
        return sizeof(_buffer);
    }
    else if (_bufferHead >= _bufferTail)
    {
        return _bufferHead - _bufferTail;
    }
    else
    {
        return sizeof(_buffer) + _bufferHead - _bufferTail;
    }
}

unsigned char SerialPort::readByte(void)
{
    unsigned char ch = _buffer[_bufferTail];
    _bufferTail = (_bufferTail + 1) % sizeof(_buffer);
    return ch;
}
