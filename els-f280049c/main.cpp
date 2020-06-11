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
#include "SanityCheck.h"
#include "flash.h"


__interrupt void cpu_timer0_isr(void);
void initCPUTimers();
void configCPUTimer();

uint16_t cpuTimer0IntCount;

//
// DEPENDENCY INJECTION
//
// Declare all of the main components and wire them together
//

// Debug harness
Debug debug;

// Feed table factory
FeedTableFactory feedTableFactory;

// Common SPI Bus driver
//SPIBus spiBus;

// SerialPortB
SerialPort serialPortB(SCIB_BASE);

// Control Panel driver
NextionControlPanel controlPanel(&serialPortB);

// EEPROM driver
//EEPROM eeprom(&spiBus);

// Encoder driver
Encoder encoder;

// Stepper driver
StepperDrive stepperDrive;

// Core engine
Core core(&encoder, &stepperDrive);

// User interface
UserInterface userInterface(&controlPanel, &core, &feedTableFactory);

void main(void)
{
#ifdef _FLASH

    // Copy time critical code and Flash setup code to RAM
    // The RamfuncsLoadStart, RamfuncsLoadEnd, and RamfuncsRunStart
    // symbols are created by the linker. Refer to the linker files.
    memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (size_t)&RamfuncsLoadSize);

    // Initialize the flash instruction fetch pipeline
    // This configures the MCU to pre-fetch instructions from flash.
    Flash_initModule(FLASH0CTRL_BASE, FLASH0ECC_BASE, DEVICE_FLASH_WAITSTATES);
#endif

    controlPanel.init((IUserInterface *) &userInterface);

/*
    // Initialize System Control:
    // PLL, WatchDog, enable Peripheral Clocks
    InitSysCtrl();

    // Disable CPU interrupts
    DINT;

    // Initialize the PIE control registers to their default state.
    InitPieCtrl();

    // Disable CPU interrupts and clear all CPU interrupt flags
    IER = 0x0000;
    IFR = 0x0000;

    // Initialize the PIE vector table with pointers to shell Interrupt
    // Service Routines (ISR) to help with debugging.
    InitPieVectTable();

    // Set up the CPU0 timer ISR
    EALLOW;
    PieVectTable.TIMER0_INT = &cpu_timer0_isr;
    PieVectTable.SCIA_RX_INT = &cpu_scia_isr;
    EDIS;

    // initialize the CPU timer
    InitCpuTimers();   // For this example, only initialize the Cpu Timers
    ConfigCpuTimer(&CpuTimer0, CPU_CLOCK_MHZ, STEPPER_CYCLE_US);

    // Use write-only instruction to set TSS bit = 0
    CpuTimer0Regs.TCR.all = 0x4001;

    // Initialize peripherals and pins
    debug.initHardware();
    spiBus.initHardware();
    controlPanel.initHardware();
    eeprom.initHardware();
    stepperDrive.initHardware();
    encoder.initHardware();

    // Enable CPU INT1 which is connected to CPU-Timer 0
    IER |= M_INT1;

    // Enable TINT0 in the PIE: Group 1 interrupt 7
    PieCtrlRegs.PIEIER1.bit.INTx7 = 1;

    // ISR registers for SerialA // TODO -- refactor into SerialA class
    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;
    PieCtrlRegs.PIEIER9.bit.INTx1 = 1;
    IER = PIEACK_GROUP9;

    // Enable global Interrupts and higher priority real-time debug events
    EINT;
    ERTM;
*/

    // initialize board hardware
    Device_init();
    Device_initGPIO();
    Interrupt_initModule();
    Interrupt_initVectorTable();

    // Initialize peripherals and pins
    debug.initHardware();
    serialPortB.initHardware();
    stepperDrive.initHardware();
    encoder.initHardware();
    //spiBus.initHardware();
    //eeprom.initHardware();

    // Disable CPU interrupts
    DINT;

    // setup the timer and start it
    Interrupt_register(INT_TIMER0, &cpu_timer0_isr);
    initCPUTimers();
    configCPUTimer();
    CPUTimer_enableInterrupt(CPUTIMER0_BASE);
    Interrupt_enable(INT_TIMER0);
    CPUTimer_startTimer(CPUTIMER0_BASE);

    // Enable global Interrupts and higher priority real-time debug events
    EINT;
    ERTM;

    controlPanel.selectPage(0);

    // User interface loop
    for(;;) {
        // LED1 flashes between UI loops to let us know that
        // it is working
        debug.toggle_led_1();

        // service the user interface
        userInterface.loop();

        //controlPanel.setTextField("text_feed", cpuTimer0IntCount);
        //controlPanel.setTextField("text_feed", encoder.getPosition());

        // delay
        DEVICE_DELAY_US(1000000 / UI_REFRESH_RATE_HZ);
    }
}

//
//
// copied from devicelib/examples/timer/timer_ex1_cputimers.c
//
// initCPUTimers - This function initializes CPUTIMER0
// to a known state.
//
void
initCPUTimers(void)
{
    //
    // Initialize timer period to maximum
    //
    CPUTimer_setPeriod(CPUTIMER0_BASE, 0xFFFFFFFF);

    //
    // Initialize pre-scale counter to divide by 1 (SYSCLKOUT)
    //
    CPUTimer_setPreScaler(CPUTIMER0_BASE, 0);

    //
    // Make sure timer is stopped
    //
    CPUTimer_stopTimer(CPUTIMER0_BASE);

    //
    // Reload all counter register with period value
    //
    CPUTimer_reloadTimerCounter(CPUTIMER0_BASE);

    //
    // Reset interrupt counter
    //
    cpuTimer0IntCount = 0;
}

//
// copied from devicelib/examples/timer/timer_ex1_cputimers.c
//
// configCPUTimer - This function initializes the selected timer to the
// period specified by the "freq" and "period" parameters. The "freq" is
// entered as Hz and the period in uSeconds. The timer is held in the stopped
// state after configuration.
//
void
configCPUTimer()
{
    uint32_t temp;

    //
    // Initialize timer period:
    //
    temp = (uint32_t)(CPU_CLOCK_HZ / 1000000 * STEPPER_CYCLE_US);
    CPUTimer_setPeriod(CPUTIMER0_BASE, temp);

    //
    // Set pre-scale counter to divide by 1 (SYSCLKOUT):
    //
    CPUTimer_setPreScaler(CPUTIMER0_BASE, 0);

    //
    // Initializes timer control register. The timer is stopped, reloaded,
    // free run disabled, and interrupt enabled.
    // Additionally, the free and soft bits are set
    //
    CPUTimer_stopTimer(CPUTIMER0_BASE);
    CPUTimer_reloadTimerCounter(CPUTIMER0_BASE);
    CPUTimer_setEmulationMode(CPUTIMER0_BASE,
                              CPUTIMER_EMULATIONMODE_STOPAFTERNEXTDECREMENT);
    CPUTimer_enableInterrupt(CPUTIMER0_BASE);

    //
    // Resets interrupt counters for the three cpuTimers
    //
    cpuTimer0IntCount = 0;
}

// CPU Timer 0 ISR
__interrupt void
cpu_timer0_isr(void)
{
    cpuTimer0IntCount++;

    // LED2 flashes between ISR loops to let us know that
    // it is working
    debug.toggle_led_2();

    // service the Core engine ISR, which in turn services the StepperDrive ISR
    core.ISR();

    //
    // Acknowledge this interrupt to receive more interrupts from group 1
    //
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}
