//
// Included Files
//
#include "F28x_Project.h"     // Device Headerfile and Examples Include File
#include "ControlPanel.h"
#include "StepperDrive.h"
#include "Encoder.h"
#include "Configuration.h"
#include <stdio.h>

//
// Function Prototypes statements for functions found within this file.
//
__interrupt void cpu_timer0_isr(void);

long double feed = 200.0 * 8.0 / 4096.0;
//Uint32 numerator = (Uint32)250 * 10 * 12 * 200 * 8;
//Uint32 denominator = (Uint32)4096 * 254 * 100;

//
// Main
//
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

    //
    // Step 1. Initialize System Control:
    // PLL, WatchDog, enable Peripheral Clocks
    // This example function is found in the F2806x_SysCtrl.c file.
    //
    InitSysCtrl();

    //
    // Step 2. Initalize GPIO:
    // This example function is found in the F2806x_Gpio.c file and
    // illustrates how to set the GPIO to it's default state.
    //
    // InitGpio();  // Skipped for this example

    //
    // Step 3. Clear all interrupts and initialize PIE vector table:
    // Disable CPU interrupts
    //
    DINT;

    //
    // Initialize the PIE control registers to their default state.
    // The default state is all PIE interrupts disabled and flags
    // are cleared.
    // This function is found in the F2806x_PieCtrl.c file.
    //
    InitPieCtrl();

    //
    // Disable CPU interrupts and clear all CPU interrupt flags
    //
    IER = 0x0000;
    IFR = 0x0000;

    //
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    // This will populate the entire table, even if the interrupt
    // is not used in this example.  This is useful for debug purposes.
    // The shell ISR routines are found in F2806x_DefaultIsr.c.
    // This function is found in F2806x_PieVect.c.
    //
    InitPieVectTable();

    //
    // Interrupts that are used in this example are re-mapped to
    // ISR functions found within this file.
    //
    EALLOW;    // This is needed to write to EALLOW protected registers
    PieVectTable.TIMER0_INT = &cpu_timer0_isr;
    EDIS;      // This is needed to disable write to EALLOW protected registers

    //
    // Step 4. Initialize the Device Peripheral. This function can be
    //         found in F2806x_CpuTimers.c
    //
    InitCpuTimers();   // For this example, only initialize the Cpu Timers

    //
    // Configure CPU-Timer 0 to interrupt every 500 milliseconds:
    // 80MHz CPU Freq, 50 millisecond Period (in uSeconds)
    //
    ConfigCpuTimer(&CpuTimer0, 90, STEPPER_CYCLE_US);

    //
    // To ensure precise timing, use write-only instructions to write to the
    // entire register. Therefore, if any of the configuration bits are changed
    // in ConfigCpuTimer and InitCpuTimers (in F2806x_CpuTimers.h), the
    // below settings must also be updated.
    //

    //
    // Use write-only instruction to set TSS bit = 0
    //
    CpuTimer0Regs.TCR.all = 0x4001;

    //
    // Set up SPI for control panel
    //
    ControlPanel_Init();

    //
    // Set up GPIO and state machine for stepper drive
    //
    StepperDrive_Init();

    //
    // Set up Encoder input
    //
    Encoder_Init();

    // GPIO 9 as an indicator
    EALLOW;
    GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO7 = 1;
    GpioDataRegs.GPACLEAR.bit.GPIO7 = 1;
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO2 = 1;
    GpioDataRegs.GPACLEAR.bit.GPIO2 = 1;
    EDIS;

    //
    // Step 5. User specific code, enable interrupts:
    //

    //
    // Enable CPU INT1 which is connected to CPU-Timer 0
    //
    IER |= M_INT1;

    //
    // Enable TINT0 in the PIE: Group 1 interrupt 7
    //
    PieCtrlRegs.PIEIER1.bit.INTx7 = 1;

    //
    // Enable global Interrupts and higher priority real-time debug events
    //
    EINT;   // Enable Global interrupt INTM
    ERTM;   // Enable Global realtime interrupt DBGM

    //
    // Start up
    //

    //
    // Step 6. IDLE loop. Just sit and loop forever (optional)
    //
    union KEY_REG keys;
    keys.all = 0xff;

    for(;;) {
        ControlPanel_SetLEDs(keys.all);
        ControlPanel_SetValue(feed);

        keys = ControlPanel_Refresh();

        //
        // Respond to keypresses
        //
        if( keys.all & 0x01 ) {
            StepperDrive_SetDesiredPosition(4);
            feed += 0.001;
        }
        if( keys.all & 0x02 ) {
            StepperDrive_SetDesiredPosition(3);
        }
        if( keys.all & 0x04 ) {
            StepperDrive_SetDesiredPosition(2);
        }
        if( keys.all & 0x08 ) {
            StepperDrive_SetDesiredPosition(1);
            feed -= 0.001;
        }
        if( keys.all & 0x10 ) {
            StepperDrive_SetDesiredPosition(0);
        }
        if( keys.all & 0x20 ) {
            StepperDrive_SetDesiredPosition(-1);
        }
        if( keys.all & 0x40 ) {
            StepperDrive_SetDesiredPosition(-2);
        }
        if( keys.all & 0x80 ) {
            StepperDrive_SetDesiredPosition(-3);
        }

        if( feed > 0.999 ) feed = 0.999;
        if( feed < 0.0 ) feed = 0.0;

        DELAY_US(10000); // update at 100Hz-ish

    };
}


Uint32 previousSpindlePosition = 0;
long double previousFeed = 0;


inline int32 Apply_Ratio(Uint32 count)
{
    //return ((long long)count) * numerator / denominator;
    return count * feed;
}

//
// cpu_timer0_isr -
//
__interrupt void
cpu_timer0_isr(void)
{
    CpuTimer0.InterruptCount++;

    // flag entrance to ISR for timing
    GpioDataRegs.GPASET.bit.GPIO7 = 1;

    //
    // Calculate the correct stepper position
    //
    Uint32 spindlePosition = Encoder_GetPosition();
    int32 desiredSteps = Apply_Ratio(spindlePosition);

    // overflow
    if( spindlePosition < previousSpindlePosition && previousSpindlePosition - spindlePosition > Encoder_GetMaxCount()/2 ) {
        StepperDrive_IncrementCurrentPosition(-1 * Apply_Ratio(Encoder_GetMaxCount()));
    }
    // underflow
    if( spindlePosition > previousSpindlePosition && spindlePosition - previousSpindlePosition > Encoder_GetMaxCount()/2 ) {
        StepperDrive_IncrementCurrentPosition(Apply_Ratio(Encoder_GetMaxCount()));
    }

    StepperDrive_SetDesiredPosition(desiredSteps);

    // if the feed changed, we want to reset and avoid a big step
    if( feed != previousFeed ) {
        StepperDrive_SetCurrentPosition(desiredSteps);
    }

    previousSpindlePosition = spindlePosition;
    previousFeed = feed;

    //
    // Service the stepper driver
    //
    StepperDrive_Service_ISR();

    ControlPanel_SetRPM(Encoder_GetRPM());

    // flag exit from ISR for timing
    GpioDataRegs.GPACLEAR.bit.GPIO7 = 1;

    //
    // Acknowledge this interrupt to receive more interrupts from group 1
    //
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

//
// End of File
//

