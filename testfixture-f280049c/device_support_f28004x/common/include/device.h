//#############################################################################
//
// FILE:   device.h
//
// TITLE:  Device setup for examples.
//
//#############################################################################
// $TI Release: F28004x Support Library v1.05.00.00 $
// $Release Date: Thu Oct 18 15:43:57 CDT 2018 $
// $Copyright:
// Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//#############################################################################

#ifndef __DEVICE_H__
#define __DEVICE_H__

//
// Included Files
//
#include "driverlib.h"

//*****************************************************************************
//
// Defines for pin numbers and other GPIO configuration
//
//*****************************************************************************
#ifdef _LAUNCHXL_F280049C
//
// LaunchPad
//

//
// LEDs
//
#define DEVICE_GPIO_PIN_LED1        34U  // GPIO number for LD4
#define DEVICE_GPIO_PIN_LED2        23U  // GPIO number for LD5
#define DEVICE_GPIO_CFG_LED1        GPIO_34_GPIO34  // "pinConfig" for LD4
#define DEVICE_GPIO_CFG_LED2        GPIO_23_GPIO23  // "pinConfig" for LD5

//
// CANA
//
#define DEVICE_GPIO_PIN_CANTXA      32U  // GPIO number for CANTXA
#define DEVICE_GPIO_PIN_CANRXA      33U  // GPIO number for CANRXA
#define DEVICE_GPIO_CFG_CANRXA      GPIO_33_CANRXA  // "pinConfig" for CANA RX
#define DEVICE_GPIO_CFG_CANTXA      GPIO_32_CANTXA  // "pinConfig" for CANA TX

//
// LINA
//
#define DEVICE_GPIO_CFG_LINTXA      GPIO_37_LINTXA  // "pinConfig" for LINA TX
#define DEVICE_GPIO_CFG_LINRXA      GPIO_35_LINRXA  // "pinConfig" for LINA RX

//
// FSI
//
#define DEVICE_GPIO_PIN_FSI_RXCLK   33U  // GPIO number for FSI RXCLK
#define DEVICE_GPIO_CFG_FSI_RXCLK   GPIO_33_FSI_RXCLK  // "pinConfig" for FSI RXCLK

//
// SPI
//
#define DEVICE_GPIO_PIN_SPICLKA     56U  // GPIO number for SPI CLKA
#define DEVICE_GPIO_PIN_SPISIMOA    16U  // GPIO number for SPI SIMOA
#define DEVICE_GPIO_PIN_SPISOMIA    17U  // GPIO number for SPI SOMIA
#define DEVICE_GPIO_PIN_SPISTEA     57U  // GPIO number for SPI STEA
#define DEVICE_GPIO_CFG_SPICLKA     GPIO_56_SPICLKA   // "pinConfig" for SPI CLKA
#define DEVICE_GPIO_CFG_SPISIMOA    GPIO_16_SPISIMOA  // "pinConfig" for SPI SIMOA
#define DEVICE_GPIO_CFG_SPISOMIA    GPIO_17_SPISOMIA  // "pinConfig" for SPI SOMIA
#define DEVICE_GPIO_CFG_SPISTEA     GPIO_57_SPISTEA   // "pinConfig" for SPI STEA
#define DEVICE_GPIO_PIN_SPICLKB     26U  // GPIO number for SPI CLKB
#define DEVICE_GPIO_PIN_SPISIMOB    24U  // GPIO number for SPI SIMOB
#define DEVICE_GPIO_PIN_SPISOMIB    31U  // GPIO number for SPI SOMIB
#define DEVICE_GPIO_PIN_SPISTEB     27U  // GPIO number for SPI STEB
#define DEVICE_GPIO_CFG_SPICLKB     GPIO_26_SPICLKB   // "pinConfig" for SPI CLKB
#define DEVICE_GPIO_CFG_SPISIMOB    GPIO_24_SPISIMOB  // "pinConfig" for SPI SIMOB
#define DEVICE_GPIO_CFG_SPISOMIB    GPIO_31_SPISOMIB  // "pinConfig" for SPI SOMIB
#define DEVICE_GPIO_CFG_SPISTEB     GPIO_27_SPISTEB   // "pinConfig" for SPI STEB

//
// I2C
//
#define DEVICE_GPIO_PIN_SDAA        35U  // GPIO number for I2C SDAA
#define DEVICE_GPIO_PIN_SCLA        37U  // GPIO number for I2C SCLA
#define DEVICE_GPIO_CFG_SDAA        GPIO_35_SDAA  // "pinConfig" for I2C SDAA
#define DEVICE_GPIO_CFG_SCLA        GPIO_37_SCLA  // "pinConfig" for I2C SCLA

//
// eQEP
//
#define DEVICE_GPIO_PIN_EQEP1A      35U  // GPIO number for EQEP 1A
#define DEVICE_GPIO_PIN_EQEP1B      37U  // GPIO number for EQEP 1B
#define DEVICE_GPIO_PIN_EQEP1I      59U  // GPIO number for EQEP 1I
#define DEVICE_GPIO_CFG_EQEP1A      GPIO_35_EQEP1A  // "pinConfig" for EQEP 1A
#define DEVICE_GPIO_CFG_EQEP1B      GPIO_37_EQEP1B  // "pinConfig" for EQEP 1B
#define DEVICE_GPIO_CFG_EQEP1I      GPIO_59_EQEP1I  // "pinConfig" for EQEP 1I

//
// EPWM
//
#define DEVICE_PERIPHERAL_BASE_EPWM EPWM6_BASE  // Base peripheral EPWM 6
#define DEVICE_PERIPHERAL_INT_EPWM  INT_EPWM6   // Base peripheral EPWM 6 interrupt
#define DEVICE_GPIO_PIN_EPWMxA      10U  // GPIO number for EPWM6A
#define DEVICE_GPIO_PIN_EPWMxB      11U  // GPIO number for EPWM6B
#define DEVICE_GPIO_PIN_IOINDEX     8U   // GPIO number for IO Index
#define DEVICE_GPIO_CFG_EPWMxA      GPIO_10_EPWM6A  // "pinConfig" for EPWM6A
#define DEVICE_GPIO_CFG_EPWMxB      GPIO_11_EPWM6B  // "pinConfig" for EPWM6B
#define DEVICE_GPIO_CFG_IOINDEX     GPIO_8_GPIO8    // "pinConfig" for IO Index

#else
//
// ControlCARD
//    

//
// LEDs
//
#define DEVICE_GPIO_PIN_LED1        31U  // GPIO number for LD2
#define DEVICE_GPIO_PIN_LED2        34U  // GPIO number for LD3
#define DEVICE_GPIO_CFG_LED1        GPIO_31_GPIO31  // "pinConfig" for LD2
#define DEVICE_GPIO_CFG_LED2        GPIO_34_GPIO34  // "pinConfig" for LD3

//
// CANA
//
#define DEVICE_GPIO_PIN_CANTXA      31U  // GPIO number for CANTXA
#define DEVICE_GPIO_PIN_CANRXA      30U  // GPIO number for CANRXA

//
// CAN External Loopback
//
#define DEVICE_GPIO_CFG_CANRXA      GPIO_30_CANRXA  // "pinConfig" for CANA RX
#define DEVICE_GPIO_CFG_CANTXA      GPIO_31_CANTXA  // "pinConfig" for CANA TX
#define DEVICE_GPIO_CFG_CANRXB      GPIO_10_CANRXB  // "pinConfig" for CANB RX
#define DEVICE_GPIO_CFG_CANTXB      GPIO_8_CANTXB   // "pinConfig" for CANB TX

//
// LINA
//
#define DEVICE_GPIO_CFG_LINTXA      GPIO_46_LINTXA  // "pinConfig" for LINA TX
#define DEVICE_GPIO_CFG_LINRXA      GPIO_47_LINRXA  // "pinConfig" for LINA RX

//
// FSI
//
#define DEVICE_GPIO_PIN_FSI_RXCLK   13U  // GPIO number for FSI RXCLK
#define DEVICE_GPIO_CFG_FSI_RXCLK   GPIO_13_FSI_RXCLK  // "pinConfig" for FSI RXCLK

//
// SPI
//
#define DEVICE_GPIO_PIN_SPICLKA     9U  // GPIO number for SPI CLKA
#define DEVICE_GPIO_PIN_SPISIMOA    8U  // GPIO number for SPI SIMOA
#define DEVICE_GPIO_PIN_SPISOMIA    10U  // GPIO number for SPI SOMIA
#define DEVICE_GPIO_PIN_SPISTEA     11U  // GPIO number for SPI STEA
#define DEVICE_GPIO_CFG_SPICLKA     GPIO_9_SPICLKA   // "pinConfig" for SPI CLKA
#define DEVICE_GPIO_CFG_SPISIMOA    GPIO_8_SPISIMOA  // "pinConfig" for SPI SIMOA
#define DEVICE_GPIO_CFG_SPISOMIA    GPIO_10_SPISOMIA // "pinConfig" for SPI SOMIA
#define DEVICE_GPIO_CFG_SPISTEA     GPIO_11_SPISTEA   // "pinConfig" for SPI STEA
#define DEVICE_GPIO_PIN_SPICLKB     26U  // GPIO number for SPI CLKB
#define DEVICE_GPIO_PIN_SPISIMOB    24U  // GPIO number for SPI SIMOB
#define DEVICE_GPIO_PIN_SPISOMIB    25U  // GPIO number for SPI SOMIB
#define DEVICE_GPIO_PIN_SPISTEB     27U  // GPIO number for SPI STEB
#define DEVICE_GPIO_CFG_SPICLKB     GPIO_26_SPICLKB   // "pinConfig" for SPI CLKB
#define DEVICE_GPIO_CFG_SPISIMOB    GPIO_24_SPISIMOB  // "pinConfig" for SPI SIMOB
#define DEVICE_GPIO_CFG_SPISOMIB    GPIO_25_SPISOMIB  // "pinConfig" for SPI SOMIB
#define DEVICE_GPIO_CFG_SPISTEB     GPIO_27_SPISTEB   // "pinConfig" for SPI STEB

//
// I2C
//
#define DEVICE_GPIO_PIN_SDAA        32U  // GPIO number for I2C SDAA
#define DEVICE_GPIO_PIN_SCLA        33U  // GPIO number for I2C SCLA
#define DEVICE_GPIO_CFG_SDAA        GPIO_32_SDAA  // "pinConfig" for I2C SDAA
#define DEVICE_GPIO_CFG_SCLA        GPIO_33_SCLA  // "pinConfig" for I2C SCLA

//
// eQEP
//
#define DEVICE_GPIO_PIN_EQEP1A      6U  // GPIO number for EQEP 1A
#define DEVICE_GPIO_PIN_EQEP1B      7U  // GPIO number for EQEP 1B
#define DEVICE_GPIO_PIN_EQEP1I      9U  // GPIO number for EQEP 1I
#define DEVICE_GPIO_CFG_EQEP1A      GPIO_6_EQEP1A  // "pinConfig" for EQEP 1A
#define DEVICE_GPIO_CFG_EQEP1B      GPIO_7_EQEP1B  // "pinConfig" for EQEP 1B
#define DEVICE_GPIO_CFG_EQEP1I      GPIO_9_EQEP1I  // "pinConfig" for EQEP 1I

//
// EPWM
//
#define DEVICE_PERIPHERAL_BASE_EPWM EPWM1_BASE  // Base peripheral EPWM 1
#define DEVICE_PERIPHERAL_INT_EPWM  INT_EPWM1   // Base peripheral EPWM 1 interrupt
#define DEVICE_GPIO_PIN_EPWMxA      0U  // GPIO number for EPWM1A
#define DEVICE_GPIO_PIN_EPWMxB      1U  // GPIO number for EPWM1B
#define DEVICE_GPIO_PIN_IOINDEX     2U  // GPIO number for IO Index
#define DEVICE_GPIO_CFG_EPWMxA      GPIO_0_EPWM1A  // "pinConfig" for EPWM1A
#define DEVICE_GPIO_CFG_EPWMxB      GPIO_1_EPWM1B  // "pinConfig" for EPWM1B
#define DEVICE_GPIO_CFG_IOINDEX     GPIO_2_GPIO2   // "pinConfig" for IO Index

#endif

//
// SCI for USB-to-UART adapter on FTDI chip
//
#define DEVICE_GPIO_PIN_SCIRXDA     28U             // GPIO number for SCI RX
#define DEVICE_GPIO_PIN_SCITXDA     29U             // GPIO number for SCI TX
#define DEVICE_GPIO_CFG_SCIRXDA     GPIO_28_SCIRXDA // "pinConfig" for SCI RX
#define DEVICE_GPIO_CFG_SCITXDA     GPIO_29_SCITXDA // "pinConfig" for SCI TX

//*****************************************************************************
//
// Defines related to clock configuration
//
//*****************************************************************************
//
// 20MHz XTAL on controlCARD. For use with SysCtl_getClock().
//
#define DEVICE_OSCSRC_FREQ          20000000U

//
// Define to pass to SysCtl_setClock(). Will configure the clock as follows:
// PLLSYSCLK = 20MHz (XTAL_OSC) * 10 (IMULT) * 1 (FMULT) / 2 (PLLCLK_BY_2)
//
#define DEVICE_SETCLOCK_CFG         (SYSCTL_OSCSRC_XTAL | SYSCTL_IMULT(10) |  \
                                     SYSCTL_FMULT_NONE | SYSCTL_SYSDIV(2) |   \
                                     SYSCTL_PLL_ENABLE)

//
// 100MHz SYSCLK frequency based on the above DEVICE_SETCLOCK_CFG. Update the
// code below if a different clock configuration is used!
//
#define DEVICE_SYSCLK_FREQ          ((DEVICE_OSCSRC_FREQ * 10 * 1) / 2)

//
// 25MHz LSPCLK frequency based on the above DEVICE_SYSCLK_FREQ and a default
// low speed peripheral clock divider of 4. Update the code below if a
// different LSPCLK divider is used!
//
#define DEVICE_LSPCLK_FREQ          (DEVICE_SYSCLK_FREQ / 4)

//*****************************************************************************
//
// Macro to call SysCtl_delay() to achieve a delay in microseconds. The macro
// will convert the desired delay in microseconds to the count value expected
// by the function. \b x is the number of microseconds to delay.
//
//*****************************************************************************
#define DEVICE_DELAY_US(x) SysCtl_delay(((((long double)(x)) / (1000000.0L /  \
                              (long double)DEVICE_SYSCLK_FREQ)) - 9.0L) / 5.0L)

//*****************************************************************************
//
// Defines, Globals, and Header Includes related to Flash Support
//
//*****************************************************************************
#ifdef _FLASH
#include <stddef.h>

extern uint16_t RamfuncsLoadStart;
extern uint16_t RamfuncsLoadEnd;
extern uint16_t RamfuncsLoadSize;
extern uint16_t RamfuncsRunStart;
extern uint16_t RamfuncsRunEnd;
extern uint16_t RamfuncsRunSize;
#endif

#define DEVICE_FLASH_WAITSTATES 4

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
extern void Device_init(void);
extern void Device_enableAllPeripherals(void);
extern void Device_initGPIO(void);
extern void __error__(char *filename, uint32_t line);

#endif // __DEVICE_H__
