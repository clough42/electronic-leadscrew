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


#ifndef SERIALPORT_H_
#define SERIALPORT_H_

// SCIA_BASE: GPIO37/35 map to pins 9 (SCIATX) and 10 (SCIARX)
// SCIB_BASE: GPIO40/13 map to pins 3 (SCIBRX) and 4 (SCIBTX)
class SerialPort
{
public:
    SerialPort(const uint32_t sciBase);
    virtual ~SerialPort();

    void initHardware();

    void send(const char *text);
    void send(const unsigned char *bytes, const uint32_t length);

    void rxisr(void);
    void txisr(void);

    uint32_t numberBytesReady();
    unsigned char readByte();

private:
    uint32_t _sciBase;
    unsigned char _buffer[512];
    uint32_t _bufferHead; // where we write to
    uint32_t _bufferTail; // where we read from
    bool _bufferFull;
    void sci_init_pin_rx(const uint32_t gpioPin, const uint32_t gpioCfg);
    void sci_init_pin_tx(const uint32_t gpioPin, const uint32_t gpioCfg);
};

#endif /* SERIALPORT_H_ */
