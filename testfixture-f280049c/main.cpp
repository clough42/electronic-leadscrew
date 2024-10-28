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


#include "F28x_Project.h"
#include "Configuration.h"
#include "SanityCheck.h"
#include "ControlPanel.h"
#include "EEPROM.h"
#include "StepperDrive.h"
#include "Debug.h"
#include "TestKeys.h"
#include "TestEEPROM.h"
#include "TestVREG.h"
#include "TestStep.h"
#include "TestAlarm.h"


__interrupt void cpu_timer0_isr(void);


//
// DEPENDENCY INJECTION
//
// Declare all of the main components and wire them together
//

// Debug harness
Debug debug;

// Common SPI Bus driver
SPIBus spiBus;

// Control Panel driver
ControlPanel controlPanel(&spiBus);

// EEPROM driver
EEPROM eeprom(&spiBus);

// Stepper driver
StepperDrive stepperDrive;

// Tests
TestKeys testKeys;
TestEEPROM testEeprom(&eeprom);
TestVREG testVreg;
TestStep testStep(&stepperDrive);
TestAlarm testAlarm(&stepperDrive);

void main(void)
{
#ifdef _FLASH
    // Copy time critical code and Flash setup code to RAM
    // The RamfuncsLoadStart, RamfuncsLoadEnd, and RamfuncsRunStart
    // symbols are created by the linker. Refer to the linker files.
    memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (size_t)&RamfuncsLoadSize);

    // Initialize the flash instruction fetch pipeline
    // This configures the MCU to pre-fetch instructions from flash.
    InitFlash();
#endif

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
    testKeys.initHardware();
    testEeprom.initHardware();
    testVreg.initHardware();
    testStep.initHardware();
    testAlarm.initHardware();

    // Enable CPU INT1 which is connected to CPU-Timer 0
    IER |= M_INT1;

    // Enable TINT0 in the PIE: Group 1 interrupt 7
    PieCtrlRegs.PIEIER1.bit.INTx7 = 1;

    // Enable global Interrupts and higher priority real-time debug events
    EINT;
    ERTM;

    // default for LEDs should show blank
    LED_REG leds;
    leds.all = 0;

    // User interface loop
    for(;;) {
        KEY_REG keys;

        // mark beginning of loop for debugging
        debug.begin2();

        keys = controlPanel.getKeys();

        testKeys.test(keys, &leds);
        testEeprom.test(&leds);
        testVreg.test(&leds);
        testStep.test(&leds);
        testAlarm.test(&leds);

        controlPanel.setLeds(leds);
        controlPanel.refresh();

        // mark end of loop for debugging
        debug.end2();

        // delay
        DELAY_US(1000000 / UI_REFRESH_RATE_HZ);
    }
}


// CPU Timer 0 ISR
__interrupt void
cpu_timer0_isr(void)
{
    CpuTimer0.InterruptCount++;

    // flag entrance to ISR for timing
    debug.begin1();

    // flag exit from ISR for timing
    debug.end1();

    //
    // Acknowledge this interrupt to receive more interrupts from group 1
    //
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}


