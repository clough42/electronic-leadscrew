MEMORY
{
 PAGE 0:    /* Program Memory */

 PAGE 1:    /* Data Memory */

   ADCA_RESULT   : origin = 0x000B00, length = 0x000020
   ADCB_RESULT   : origin = 0x000B20, length = 0x000020
   ADCC_RESULT   : origin = 0x000B40, length = 0x000020
   ADCA          : origin = 0x007400, length = 0x000080
   ADCB          : origin = 0x007480, length = 0x000080
   ADCC          : origin = 0x007500, length = 0x000080

   ANALOG_SUBSYS : origin = 0x05D700, length = 0x000100

   CANA          : origin = 0x048000, length = 0x000800
   CANB          : origin = 0x04A000, length = 0x000800

   CLA1          : origin = 0x001400, length = 0x000080     /* CLA registers */

   CLAPROMCRC    : origin = 0x0061C0, length = 0x000020

   CLB_XBAR      : origin = 0x007A40, length = 0x000040

   CMPSS1        : origin = 0x005C80, length = 0x000020
   CMPSS2        : origin = 0x005CA0, length = 0x000020
   CMPSS3        : origin = 0x005CC0, length = 0x000020
   CMPSS4        : origin = 0x005CE0, length = 0x000020
   CMPSS5        : origin = 0x005D00, length = 0x000020
   CMPSS6        : origin = 0x005D20, length = 0x000020
   CMPSS7        : origin = 0x005D40, length = 0x000020

   CPU_TIMER0    : origin = 0x000C00, length = 0x000008     /* CPU Timer0 registers */
   CPU_TIMER1    : origin = 0x000C08, length = 0x000008     /* CPU Timer1 registers */
   CPU_TIMER2    : origin = 0x000C10, length = 0x000008     /* CPU Timer2 registers */

   DACA          : origin = 0x005C00, length = 0x000010
   DACB          : origin = 0x005C10, length = 0x000010

   DCC0          : origin = 0x05E700, length = 0x000040

   DCSM_BANK0_Z1    : origin = 0x05F000, length = 0x000030
   DCSM_BANK0_Z2    : origin = 0x05F040, length = 0x000030
   DCSM_BANK1_Z1    : origin = 0x05F100, length = 0x000030
   DCSM_BANK1_Z2    : origin = 0x05F140, length = 0x000030
   DCSM_COMMON      : origin = 0x05F070, length = 0x000010     /* Common Dual code security module registers */

   DMA          : origin = 0x001000, length = 0x000200

   ECAP1        : origin = 0x005200, length = 0x000040     /* Enhanced Capture 1 registers */
   ECAP2        : origin = 0x005240, length = 0x000040     /* Enhanced Capture 2 registers */
   ECAP3        : origin = 0x005280, length = 0x000040     /* Enhanced Capture 3 registers */
   ECAP4        : origin = 0x0052C0, length = 0x000040     /* Enhanced Capture 4 registers */
   ECAP5        : origin = 0x005300, length = 0x000040     /* Enhanced Capture 5 registers */
   ECAP6        : origin = 0x005340, length = 0x000040     /* Enhanced Capture 6 registers */
   ECAP7        : origin = 0x005380, length = 0x000040     /* Enhanced Capture 7 registers */

   PGA1         : origin = 0x005B00, length = 0x000010
   PGA2         : origin = 0x005B10, length = 0x000010
   PGA3         : origin = 0x005B20, length = 0x000010
   PGA4         : origin = 0x005B30, length = 0x000010
   PGA5         : origin = 0x005B40, length = 0x000010
   PGA6         : origin = 0x005B50, length = 0x000010
   PGA7         : origin = 0x005B60, length = 0x000010

   EPWM1        : origin = 0x004000, length = 0x000100     /* Enhanced PWM 1 registers */
   EPWM2        : origin = 0x004100, length = 0x000100     /* Enhanced PWM 2 registers */
   EPWM3        : origin = 0x004200, length = 0x000100     /* Enhanced PWM 3 registers */
   EPWM4        : origin = 0x004300, length = 0x000100     /* Enhanced PWM 4 registers */
   EPWM5        : origin = 0x004400, length = 0x000100     /* Enhanced PWM 5 registers */
   EPWM6        : origin = 0x004500, length = 0x000100     /* Enhanced PWM 6 registers */
   EPWM7        : origin = 0x004600, length = 0x000100     /* Enhanced PWM 7 registers */
   EPWM8        : origin = 0x004700, length = 0x000100     /* Enhanced PWM 8 registers */

   EPWM_XBAR    : origin = 0x007A00, length = 0x000040

   EQEP1        : origin = 0x005100, length = 0x000040     /* Enhanced QEP 1 registers */
   EQEP2        : origin = 0x005140, length = 0x000040     /* Enhanced QEP 2 registers */

   FLASH0_CTRL  : origin = 0x05F800, length = 0x000300
   FLASH0_ECC   : origin = 0x05FB00, length = 0x000040

   FSITXA       : origin = 0x006600, length = 0x000080
   FSIRXA       : origin = 0x006680, length = 0x000080

   GPIOCTRL     : origin = 0x007C00, length = 0x000200     /* GPIO control registers */
   GPIODAT      : origin = 0x007F00, length = 0x000040     /* GPIO data registers */

   I2CA         : origin = 0x007300, length = 0x000040     /* I2C-A registers */

   INPUT_XBAR   : origin = 0x007900, length = 0x000020

   LINA         : origin = 0x006A00, length = 0x000100
   LINB         : origin = 0x006B00, length = 0x000100

   MEMCFG       : origin = 0x05F400, length = 0x000080     /* Mem Config registers */
   ACCESSPROTECTION  : origin = 0x05F4C0, length = 0x000040     /* Access Protection registers */
   MEMORYERROR  : origin = 0x05F500, length = 0x000040     /* Access Protection registers */

   NMIINTRUPT   : origin = 0x007060, length = 0x000010     /* NMI Watchdog Interrupt Registers */

   OUTPUT_XBAR  : origin = 0x007A80, length = 0x000040

   PIE_CTRL     : origin = 0x000CE0, length = 0x000020     /* PIE control registers */

   PIE_VECT     : origin = 0x000D00, length = 0x000200     /* PIE Vector Table */

   PMBUSA       : origin = 0x006400, length = 0x000020

   SCIA         : origin = 0x007200, length = 0x000010     /* SCI-A registers */
   SCIB         : origin = 0x007210, length = 0x000010     /* SCI-B registers */

   SDFM1        : origin = 0x005E00, length = 0x000080     /* Sigma delta 1 registers */

   SPIA         : origin = 0x006100, length = 0x000010
   SPIB         : origin = 0x006110, length = 0x000010

   WD           : origin = 0x007000, length = 0x000040
   DMACLASRCSEL : origin = 0x007980, length = 0x000040
   DEV_CFG      : origin = 0x05D000, length = 0x000180
   CLK_CFG      : origin = 0x05D200, length = 0x000100
   CPU_SYS      : origin = 0x05D300, length = 0x000100
   PERIPH_AC    : origin = 0x05D500, length = 0x000200

   ERAD_GLOBAL  : origin = 0x05E800, length = 0x000013
   ERAD_HWBP1   : origin = 0x05E900, length = 0x000008
   ERAD_HWBP2   : origin = 0x05E908, length = 0x000008
   ERAD_HWBP3   : origin = 0x05E910, length = 0x000008
   ERAD_HWBP4   : origin = 0x05E918, length = 0x000008
   ERAD_HWBP5   : origin = 0x05E920, length = 0x000008
   ERAD_HWBP6   : origin = 0x05E928, length = 0x000008
   ERAD_HWBP7   : origin = 0x05E930, length = 0x000008
   ERAD_HWBP8   : origin = 0x05E938, length = 0x000008
   ERAD_CTR1    : origin = 0x05E980, length = 0x000010
   ERAD_CTR2    : origin = 0x05E990, length = 0x000010
   ERAD_CTR3    : origin = 0x05E9A0, length = 0x000010
   ERAD_CTR4    : origin = 0x05E9B0, length = 0x000010

   XBAR         : origin = 0x007920, length = 0x000020
   SYNC_SOC     : origin = 0x007940, length = 0x000010

   XINT         : origin = 0x007070, length = 0x000010
}

SECTIONS
{
/*** PIE Vect Table and Boot ROM Variables Structures ***/
  UNION run = PIE_VECT, PAGE = 1
   {
      PieVectTableFile
      GROUP
      {
         EmuKeyVar
         EmuBModeVar
         FlashCallbackVar
         FlashScalingVar
      }
   }

   AdcaResultFile        : > ADCA_RESULT,   PAGE = 1
   AdcbResultFile        : > ADCB_RESULT,   PAGE = 1
   AdccResultFile        : > ADCC_RESULT,   PAGE = 1

   AdcaRegsFile          : > ADCA,          PAGE = 1
   AdcbRegsFile          : > ADCB,          PAGE = 1
   AdccRegsFile          : > ADCC,          PAGE = 1

   AnalogSubsysRegsFile  : > ANALOG_SUBSYS, PAGE = 1

   CanaRegsFile          : > CANA,          PAGE = 1
   CanbRegsFile          : > CANB,          PAGE = 1

   Cla1RegsFile          : > CLA1,          PAGE = 1
   Cla1SoftIntRegsFile   : > PIE_CTRL,      PAGE = 1, type=DSECT

   ClaPromCrc0RegsFile   : > CLAPROMCRC,    PAGE = 1

   ClbXbarRegsFile       : > CLB_XBAR,      PAGE = 1

   Cmpss1RegsFile        : > CMPSS1,        PAGE = 1
   Cmpss2RegsFile        : > CMPSS2,        PAGE = 1
   Cmpss3RegsFile        : > CMPSS3,        PAGE = 1
   Cmpss4RegsFile        : > CMPSS4,        PAGE = 1
   Cmpss5RegsFile        : > CMPSS5,        PAGE = 1
   Cmpss6RegsFile        : > CMPSS6,        PAGE = 1
   Cmpss7RegsFile        : > CMPSS7,        PAGE = 1

   CpuTimer0RegsFile     : > CPU_TIMER0,    PAGE = 1
   CpuTimer1RegsFile     : > CPU_TIMER1,    PAGE = 1
   CpuTimer2RegsFile     : > CPU_TIMER2,    PAGE = 1

   DacaRegsFile          : > DACA           PAGE = 1
   DacbRegsFile          : > DACB           PAGE = 1

   Dcc0RegsFile          : > DCC0           PAGE = 1

   DcsmBank0Z1RegsFile        : > DCSM_BANK0_Z1,         PAGE = 1
   DcsmBank0Z2RegsFile        : > DCSM_BANK0_Z2,         PAGE = 1
   DcsmBank1Z1RegsFile        : > DCSM_BANK1_Z1,         PAGE = 1
   DcsmBank1Z2RegsFile        : > DCSM_BANK1_Z2,         PAGE = 1
   DcsmCommonRegsFile         : > DCSM_COMMON,           PAGE = 1

   DmaRegsFile                : > DMA,                   PAGE = 1

   ECap1RegsFile         : > ECAP1,        PAGE = 1
   ECap2RegsFile         : > ECAP2,        PAGE = 1
   ECap3RegsFile         : > ECAP3,        PAGE = 1
   ECap4RegsFile         : > ECAP4,        PAGE = 1
   ECap5RegsFile         : > ECAP5,        PAGE = 1
   ECap6RegsFile         : > ECAP6,        PAGE = 1
   ECap7RegsFile         : > ECAP7,        PAGE = 1

   Pga1RegsFile          : > PGA1,         PAGE = 1
   Pga2RegsFile          : > PGA2,         PAGE = 1
   Pga3RegsFile          : > PGA3,         PAGE = 1
   Pga4RegsFile          : > PGA4,         PAGE = 1
   Pga5RegsFile          : > PGA5,         PAGE = 1
   Pga6RegsFile          : > PGA6,         PAGE = 1
   Pga7RegsFile          : > PGA7,         PAGE = 1

   EPwm1RegsFile         : > EPWM1,        PAGE = 1
   EPwm2RegsFile         : > EPWM2,        PAGE = 1
   EPwm3RegsFile         : > EPWM3,        PAGE = 1
   EPwm4RegsFile         : > EPWM4,        PAGE = 1
   EPwm5RegsFile         : > EPWM5,        PAGE = 1
   EPwm6RegsFile         : > EPWM6,        PAGE = 1
   EPwm7RegsFile         : > EPWM7,        PAGE = 1
   EPwm8RegsFile         : > EPWM8,        PAGE = 1

   EPwmXbarRegsFile      : > EPWM_XBAR      PAGE = 1

   EQep1RegsFile         : > EQEP1,         PAGE = 1
   EQep2RegsFile         : > EQEP2,         PAGE = 1

   EnhancedDebugGlobalRegsFile    : > ERAD_GLOBAL, PAGE = 1
   EnhancedDebugHWBP1RegsFile     : > ERAD_HWBP1,  PAGE = 1
   EnhancedDebugHWBP2RegsFile     : > ERAD_HWBP2,  PAGE = 1
   EnhancedDebugHWBP3RegsFile     : > ERAD_HWBP3,  PAGE = 1
   EnhancedDebugHWBP4RegsFile     : > ERAD_HWBP4,  PAGE = 1
   EnhancedDebugHWBP5RegsFile     : > ERAD_HWBP5,  PAGE = 1
   EnhancedDebugHWBP6RegsFile     : > ERAD_HWBP6,  PAGE = 1
   EnhancedDebugHWBP7RegsFile     : > ERAD_HWBP7,  PAGE = 1
   EnhancedDebugHWBP8RegsFile     : > ERAD_HWBP8,  PAGE = 1
   EnhancedDebugCounter1RegsFile  : > ERAD_CTR1,   PAGE = 1
   EnhancedDebugCounter2RegsFile  : > ERAD_CTR2,   PAGE = 1
   EnhancedDebugCounter3RegsFile  : > ERAD_CTR3,   PAGE = 1
   EnhancedDebugCounter4RegsFile  : > ERAD_CTR4,   PAGE = 1

   Flash0CtrlRegsFile    : > FLASH0_CTRL    PAGE = 1
   Flash0EccRegsFile     : > FLASH0_ECC     PAGE = 1

   FsiTxaRegsFile        : > FSITXA         PAGE = 1
   FsiRxaRegsFile        : > FSIRXA         PAGE = 1

   GpioCtrlRegsFile      : > GPIOCTRL,      PAGE = 1
   GpioDataRegsFile      : > GPIODAT,       PAGE = 1

   I2caRegsFile          : > I2CA,          PAGE = 1

   InputXbarRegsFile     : > INPUT_XBAR     PAGE = 1
   XbarRegsFile          : > XBAR           PAGE = 1

   LinaRegsFile          : > LINA,            PAGE = 1
   LinbRegsFile          : > LINB,            PAGE = 1

   MemCfgRegsFile            : > MEMCFG,            PAGE = 1
   AccessProtectionRegsFile  : > ACCESSPROTECTION,  PAGE = 1
   MemoryErrorRegsFile       : > MEMORYERROR,       PAGE = 1

   NmiIntruptRegsFile       : > NMIINTRUPT,     PAGE = 1

   OutputXbarRegsFile       : > OUTPUT_XBAR,    PAGE = 1

   PieCtrlRegsFile          : > PIE_CTRL,       PAGE = 1

   PmbusaRegsFile           : > PMBUSA,         PAGE = 1

   SciaRegsFile             : > SCIA,           PAGE = 1
   ScibRegsFile             : > SCIB,           PAGE = 1

   Sdfm1RegsFile            : > SDFM1,          PAGE = 1

   SpiaRegsFile             : > SPIA,           PAGE = 1
   SpibRegsFile             : > SPIB,           PAGE = 1

   WdRegsFile               : > WD,             PAGE = 1
   DmaClaSrcSelRegsFile     : > DMACLASRCSEL    PAGE = 1
   DevCfgRegsFile           : > DEV_CFG,        PAGE = 1
   ClkCfgRegsFile           : > CLK_CFG,        PAGE = 1
   CpuSysRegsFile           : > CPU_SYS,        PAGE = 1
   SysPeriphAcRegsFile      : > PERIPH_AC,      PAGE = 1

   SyncSocRegsFile          : > SYNC_SOC,       PAGE = 1

   XintRegsFile             : > XINT,           PAGE = 1

}

/*
//===========================================================================
// End of file.
//===========================================================================
*/
