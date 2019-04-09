#include "ControlPanel.h"


struct CONTROL_PANEL_STATE _controlpanel_state;

Uint16 dummy;

void ControlPanel_Init(void)
{
    EALLOW;

    // Set up SPI A
    SpibRegs.SPICCR.bit.SPISWRESET = 0;         // Enter RESET state
    SpibRegs.SPICCR.bit.SPICHAR = 0x7;          // 8 bits
    SpibRegs.SPICCR.bit.CLKPOLARITY = 1;        // data latched on rising edge
    SpibRegs.SPICTL.bit.CLK_PHASE=0;            // normal clocking scheme
    SpibRegs.SPICTL.bit.MASTER_SLAVE=1;         // master
    SpibRegs.SPIBRR.bit.SPI_BIT_RATE = 90;
    //SpibRegs.SPIBRR = 90;                       // baud rate
    SpibRegs.SPIPRI.bit.TRIWIRE=1;              // 3-wire mode
    SpibRegs.SPICCR.bit.SPISWRESET = 1;         // clear reset state; ready to transmit

    // Set up muxing for SPIB pins
    GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 0x2;      // select SPIB_SIMO
    GpioCtrlRegs.GPAGMUX2.bit.GPIO24 = 0x1;
    GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 0x3;      // select SPIB_CLK
    GpioCtrlRegs.GPBGMUX1.bit.GPIO32 = 0x0;

    // just use GPIO33 as the chip select so we can control it ourselves
    GpioCtrlRegs.GPBMUX1.bit.GPIO33 = 0x0;      // SELECT GPIO33
    GpioCtrlRegs.GPBDIR.bit.GPIO33 = 1;         // output
    GpioCtrlRegs.GPBDIR.bit.GPIO33 = 1;         // set it to high

//    GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 3;        // select SPISIMOB
//    GpioCtrlRegs.GPAMUX2.bit.GPIO26 = 3;        // select SPICLKB
//    GpioCtrlRegs.GPAMUX2.bit.GPIO27 = 0;        // just use GPIO27 so we can control it ourselves
//    GpioCtrlRegs.GPADIR.bit.GPIO27 = 1;         // output
//    GpioDataRegs.GPASET.bit.GPIO27 = 1;         // set it to high

    EDIS;
}

Uint16 reverse_byte(Uint16 x)
{
    static const Uint16 table[] = {
        0x0000, 0x8000, 0x4000, 0xc000, 0x2000, 0xa000, 0x6000, 0xe000,
        0x1000, 0x9000, 0x5000, 0xd000, 0x3000, 0xb000, 0x7000, 0xf000,
        0x0800, 0x8800, 0x4800, 0xc800, 0x2800, 0xa800, 0x6800, 0xe800,
        0x1800, 0x9800, 0x5800, 0xd800, 0x3800, 0xb800, 0x7800, 0xf800,
        0x0400, 0x8400, 0x4400, 0xc400, 0x2400, 0xa400, 0x6400, 0xe400,
        0x1400, 0x9400, 0x5400, 0xd400, 0x3400, 0xb400, 0x7400, 0xf400,
        0x0c00, 0x8c00, 0x4c00, 0xcc00, 0x2c00, 0xac00, 0x6c00, 0xec00,
        0x1c00, 0x9c00, 0x5c00, 0xdc00, 0x3c00, 0xbc00, 0x7c00, 0xfc00,
        0x0200, 0x8200, 0x4200, 0xc200, 0x2200, 0xa200, 0x6200, 0xe200,
        0x1200, 0x9200, 0x5200, 0xd200, 0x3200, 0xb200, 0x7200, 0xf200,
        0x0a00, 0x8a00, 0x4a00, 0xca00, 0x2a00, 0xaa00, 0x6a00, 0xea00,
        0x1a00, 0x9a00, 0x5a00, 0xda00, 0x3a00, 0xba00, 0x7a00, 0xfa00,
        0x0600, 0x8600, 0x4600, 0xc600, 0x2600, 0xa600, 0x6600, 0xe600,
        0x1600, 0x9600, 0x5600, 0xd600, 0x3600, 0xb600, 0x7600, 0xf600,
        0x0e00, 0x8e00, 0x4e00, 0xce00, 0x2e00, 0xae00, 0x6e00, 0xee00,
        0x1e00, 0x9e00, 0x5e00, 0xde00, 0x3e00, 0xbe00, 0x7e00, 0xfe00,
        0x0100, 0x8100, 0x4100, 0xc100, 0x2100, 0xa100, 0x6100, 0xe100,
        0x1100, 0x9100, 0x5100, 0xd100, 0x3100, 0xb100, 0x7100, 0xf100,
        0x0900, 0x8900, 0x4900, 0xc900, 0x2900, 0xa900, 0x6900, 0xe900,
        0x1900, 0x9900, 0x5900, 0xd900, 0x3900, 0xb900, 0x7900, 0xf900,
        0x0500, 0x8500, 0x4500, 0xc500, 0x2500, 0xa500, 0x6500, 0xe500,
        0x1500, 0x9500, 0x5500, 0xd500, 0x3500, 0xb500, 0x7500, 0xf500,
        0x0d00, 0x8d00, 0x4d00, 0xcd00, 0x2d00, 0xad00, 0x6d00, 0xed00,
        0x1d00, 0x9d00, 0x5d00, 0xdd00, 0x3d00, 0xbd00, 0x7d00, 0xfd00,
        0x0300, 0x8300, 0x4300, 0xc300, 0x2300, 0xa300, 0x6300, 0xe300,
        0x1300, 0x9300, 0x5300, 0xd300, 0x3300, 0xb300, 0x7300, 0xf300,
        0x0b00, 0x8b00, 0x4b00, 0xcb00, 0x2b00, 0xab00, 0x6b00, 0xeb00,
        0x1b00, 0x9b00, 0x5b00, 0xdb00, 0x3b00, 0xbb00, 0x7b00, 0xfb00,
        0x0700, 0x8700, 0x4700, 0xc700, 0x2700, 0xa700, 0x6700, 0xe700,
        0x1700, 0x9700, 0x5700, 0xd700, 0x3700, 0xb700, 0x7700, 0xf700,
        0x0f00, 0x8f00, 0x4f00, 0xcf00, 0x2f00, 0xaf00, 0x6f00, 0xef00,
        0x1f00, 0x9f00, 0x5f00, 0xdf00, 0x3f00, 0xbf00, 0x7f00, 0xff00,
    };
    return table[x];
}

Uint16 lcd_char(Uint16 x)
{
    static const Uint16 table[] = {
        0b1111110000000000, // 0
        0b0110000000000000, // 1
        0b1101101000000000, // 2
        0b1111001000000000, // 3
        0b0110011000000000, // 4
        0b1011011000000000, // 5
        0b1011111000000000, // 6
        0b1110000000000000, // 7
        0b1111111000000000, // 8
        0b1111011000000000, // 9
        0b0000000100000000  // .
    };
    if( x < sizeof(table) ) {
        return table[x];
    }
    return table[sizeof(table)-1];
}

void SendByte(Uint16 data) {
    SpibRegs.SPITXBUF = data;
    while(SpibRegs.SPISTS.bit.INT_FLAG !=1) {}
    dummy = SpibRegs.SPIRXBUF;
}

Uint16 ReceiveByte(void) {
    SpibRegs.SPITXBUF = dummy;
    while(SpibRegs.SPISTS.bit.INT_FLAG !=1) {}
    return SpibRegs.SPIRXBUF;
}

void SendControlPanelData()
{
    int i;
    Uint16 ledMask = _controlpanel_state.leds.all;

    SpibRegs.SPICTL.bit.TALK = 1;

    GpioDataRegs.GPBCLEAR.bit.GPIO33 = 1;
    SendByte(reverse_byte(0x8a));           // brightness
    GpioDataRegs.GPBSET.bit.GPIO33 = 1;

    GpioDataRegs.GPBCLEAR.bit.GPIO33 = 1;
    SendByte(reverse_byte(0x40));           // auto-increment
    GpioDataRegs.GPBSET.bit.GPIO33 = 1;

    GpioDataRegs.GPBCLEAR.bit.GPIO33 = 1;
    SendByte(reverse_byte(0xc0));           // display data
    for( i=0; i < 8; i++ ) {
        SendByte(_controlpanel_state.sevenSegmentData[i]);
        SendByte( (ledMask & 0x80) ? 0xff00 : 0x0000 );
        ledMask <<= 1;
    }
    GpioDataRegs.GPBSET.bit.GPIO33 = 1;

    SpibRegs.SPICTL.bit.TALK = 0;
}

void DecomposeRPM()
{
    Uint16 rpm = _controlpanel_state.rpm;
    int i;

    for(i=3; i>=0; i--) {
        _controlpanel_state.sevenSegmentData[i] = (rpm == 0 && i != 3) ? 0 : lcd_char(rpm % 10);
        rpm = rpm / 10;
    }
}

void DecomposeValue()
{
    int i;
    Uint16 digit;
    long double value = (long double)_controlpanel_state.value;

    for(i=4; i<8; i++) {
        digit = ((Uint16)value)%10;
        _controlpanel_state.sevenSegmentData[i] = lcd_char(digit);
        value = value * 10;
    }
    _controlpanel_state.sevenSegmentData[4] = lcd_char(10);
}

union KEY_REG ReadKeys(void)
{
    SpibRegs.SPICTL.bit.TALK = 1;

    GpioDataRegs.GPBCLEAR.bit.GPIO33 = 1;
    SendByte(reverse_byte(0x42));

    SpibRegs.SPICTL.bit.TALK = 0;

    DELAY_US(1);

    Uint16 byte1 = ReceiveByte();
    Uint16 byte2 = ReceiveByte();
    Uint16 byte3 = ReceiveByte();
    Uint16 byte4 = ReceiveByte();

    union KEY_REG keyMask;
    keyMask.all =
            (byte1 & 0x88) |
            (byte2 & 0x88) >> 1 |
            (byte3 & 0x88) >> 2 |
            (byte4 & 0x88) >> 3;

    GpioDataRegs.GPBSET.bit.GPIO33 = 1;

    return keyMask;
}

union KEY_REG ControlPanel_Refresh()
{
    GpioDataRegs.GPASET.bit.GPIO10 = 1;

    DecomposeRPM();
    DecomposeValue();

    GpioDataRegs.GPACLEAR.bit.GPIO10 = 1;

    SendControlPanelData();

    return ReadKeys();
}





