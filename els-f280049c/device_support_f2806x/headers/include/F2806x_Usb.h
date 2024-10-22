//###########################################################################
//
// FILE:   F2806x_Usb.h
//
// TITLE:  F2806x Device USB Register Definitions.
//
//###########################################################################
// $TI Release: 2806x C/C++ Header Files V1.10 $
// $Release Date: April 7, 2011 $
// $Copyright:
// Copyright (C) 2009-2022 Texas Instruments Incorporated - http://www.ti.com/
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
//###########################################################################

#ifndef F2806x_USB_H
#define F2806x_USB_H

#ifdef __cplusplus
extern "C" {
#endif

//
// USB Individual Register Bit Definitions:

struct USBFADDR_BITS
{
	Uint16	FUNCADDR:7;			// 6:0	Functional Address
	Uint16	rsvd1:1;			// 7	Reserved
};

union USBFADDR_REG
{
	Uint16 all;
	struct USBFADDR_BITS	bit;
};

struct USBPOWER_BITS
{
	Uint16	PWRDNPHY:1;			// 0	Power Down PHY
	Uint16	SUSPEND:1;			// 1	Enable Suspend
	Uint16	RESUME:1;			// 2	Enable Resume Signaling
	Uint16	RESET:1;			// 3	Enable Reset Signaling
	Uint16	rsvd1:2;			// 5:4	Reserved
	Uint16	SOFT_CONN:1;		// 6	Soft Connect/Disconnect
	Uint16	ISOUP:1;			// 7	Isochronous Update
};

union USBPOWER_REG
{
	Uint16 all;
	struct USBPOWER_BITS	bit;
};

struct USBTXIS_BITS
{
	Uint16	EP0:1;			// 0	Transmit Endpoint 0 Interrupt
	Uint16	EP1:1;			// 1	Transmit Endpoint 1 Interrupt
	Uint16	EP2:1;			// 2	Transmit Endpoint 2 Interrupt
	Uint16	EP3:1;			// 3	Transmit Endpoint 3 Interrupt
	Uint16	rsvd1:12;		// 15:4	Reserved
};

union USBTXIS_REG
{
	Uint32 all;
	struct USBTXIS_BITS	bit;
};

struct USBRXIS_BITS
{
    Uint16	rsvd1:1;		// 0	Reserved
	Uint16	EP1:1;			// 1	Recieve Endpoint 1 Interrupt
	Uint16	EP2:1;			// 2	Recieve Endpoint 2 Interrupt
	Uint16	EP3:1;			// 3	Recieve Endpoint 3 Interrupt
	Uint16	rsvd2:12;		// 15:4	Reserved
};

union USBRXIS_REG
{
	Uint32 all;
	struct USBRXIS_BITS	bit;
};

struct USBTXIE_BITS
{
	Uint16	EP0:1;			// 0	Transmit Endpoint 0 Interrupt Enable
	Uint16	EP1:1;			// 1	Transmit Endpoint 1 Interrupt Enable
	Uint16	EP2:1;			// 2	Transmit Endpoint 2 Interrupt Enable
	Uint16	EP3:1;			// 3	Transmit Endpoint 3 Interrupt Enable
	Uint16	rsvd2:12;		// 15:4	Reserved
};

union USBTXIE_REG
{
	Uint32 all;
	struct USBTXIE_BITS	bit;
};

struct USBRXIE_BITS
{
	Uint16	rsvd1:1;		// 0	Reserved
	Uint16	EP1:1;			// 1	Recieve Endpoint 1 Interrupt Enable
	Uint16	EP2:1;			// 2	Recieve Endpoint 2 Interrupt Enable
	Uint16	EP3:1;			// 3	Recieve Endpoint 3 Interrupt Enable
	Uint16	rsvd2:12;		// 15:4	Reserved
};

union USBRXIE_REG
{
	Uint32 all;
	struct USBRXIE_BITS	bit;
};

struct USBIS_BITS
{
	Uint16	SUSPEND:1;			// 0	Suspend Signaling Detected Interrupt
	Uint16	RESUME:1;			// 1	Resume Signaling Detected Interrupt
	Uint16	RESET:1;			// 2	Reset Signaling Detected Interrupt
	Uint16	SOF:1;				// 3	New Frame Detected Interrupt
	Uint16	rsvd1:1;			// 4	Reserved
	Uint16	DISCON:1;			// 5	Device Disconnection Detected Interrupt
	Uint16	rsvd2:2;			// 7:6	Reserved
};

union USBIS_REG
{
	Uint16 all;
	struct USBIS_BITS	bit;
};

struct USBIE_BITS
{
	Uint16	SUSPEND:1;	// 0	Suspend Signaling Detected Interrupt Enable
	Uint16	RESUME:1;	// 1	Resume Signaling Detected Interrupt Enable
	Uint16	RESET:1;	// 2	Reset Signaling Detected Interrupt Enable
	Uint16	SOF:1;		// 3	New Frame Detected Interrupt Enable
	Uint16	rsvd1:1;	// 4	Reserved
	Uint16	DISCON:1;	// 5	Device Disconnection Detected Interrupt Enable
	Uint16	rsvd2:2;	// 7:6	Reserved
};

union USBIE_REG
{
	Uint16 all;
	struct USBIE_BITS	bit;
};

struct USBFRAME_BITS
{
	Uint16	FRAME:11;			// 10:0	Frame Number
	Uint16	rsvd1:5;			// 15:11	Reserved
};

union USBFRAME_REG
{
    Uint32 all;
	struct USBFRAME_BITS	bit;
};

struct USBEPIDX_BITS
{
	Uint16	EPIDX:4;			// 3:0	Endpoint Index
	Uint16	rsvd1:4;			// 7:4	Reserved
};

union USBEPIDX_REG
{
	Uint16 all;
	struct USBEPIDX_BITS	bit;
};

struct USBTEST_BITS
{
	Uint16	rsvd1:5;			// 4:0	Reserved
	Uint16	FORCEFS:1;			// 5	Force Full Speed Upon Reset
	Uint16	FIFOACC:1;			// 6	FIFO Access
	Uint16	FORCEH:1;			// 7	Force Host Mode
};

union USBTEST_REG
{
	Uint16 all;
	struct USBTEST_BITS	bit;
};

struct USBDEVCTL_BITS
{
	Uint16	SESSION:1;			// 0	Session Start/End
	Uint16	HOSTREQ:1;			// 1	Host Request
	Uint16	HOST:1;				// 2	Host Mode
	Uint16	VBUS:2;				// 4:3	Vbus Level
	Uint16	LSDEV:1;			// 5	Low Speed Device Detected
	Uint16	FSDEV:1;			// 6	Full Speed Device Detected
	Uint16	DEV:1;				// 7	Device Mode
};

union USBDEVCTL_REG
{
	Uint16	all;
	struct USBDEVCTL_BITS	bit;
};

struct USBTXFIFOSZ_BITS
{
	Uint16	SIZE:4;				// 3:0	Max Packet Size
	Uint16	DPB:1;				// 4	Double Packet Buffer Support
	Uint16	rsvd1:3;			// 7:5	Reserved
};

union USBTXFIFOSZ_REG
{
	Uint16 	all;
	struct USBTXFIFOSZ_BITS	bit;
};

struct USBRXFIFOSZ_BITS
{
	Uint16	SIZE:4;				// 3:0	Max Packet Size
	Uint16	DPB:1;				// 4	Double Packet Buffer Support
	Uint16	rsvd1:3;			// 7:5	Reserved
};

union USBRXFIFOSZ_REG
{
	Uint16 	all;
	struct USBRXFIFOSZ_BITS	bit;
};

struct USBTXFIFOADD_BITS
{
	Uint16	ADDR:9;				// 8:0	Endpoint Data
	Uint16	rsvd1:7;			// 15:9	Reserved
};

union USBTXFIFOADD_REG
{
	Uint32 all;
	struct USBTXFIFOADD_BITS	bit;
};

struct USBRXFIFOADD_BITS
{
	Uint16	ADDR:9;				// 8:0	Endpoint Data
	Uint16	rsvd1:7;			// 15:9	Reserved
};

union USBRXFIFOADD_REG
{
	Uint32 all;
	struct USBRXFIFOADD_BITS	bit;
};

struct USBCONTIM_BITS
{
	Uint16	WTID:4;				// 3:0	Wait ID
	Uint16	WTCON:4;			// 7:4	Connect Wait
};

union USBCONTIM_REG
{
	Uint16 	all;
	struct USBCONTIM_BITS	bit;
};

struct USBTXFUNCADDR0_BITS
{
	Uint16	ADDR:7;				// 6:0	Device Address
	Uint16	rsvd1:1;			// 7	Reserved
};

union USBTXFUNCADDR0_REG
{
	Uint16	all;
	struct USBTXFUNCADDR0_BITS	bit;
};

struct USBTXHUBADDR0_BITS
{
	Uint16	ADDR:7;				// 6:0	Hub Address
	Uint16	MULTTRAN:1;			// 7	Hub has Multiple Translators
};

union USBTXHUBADDR0_REG
{
	Uint16 	all;
	struct USBTXHUBADDR0_BITS	bit;
};

struct USBTXHUBPORT0_BITS
{
	Uint16	PORT:7;				// 6:0	Hub Port
	Uint16	rsvd1:1;			// 7	Reserved
};

union USBTXHUBPORT0_REG
{
	Uint16 	all;
	struct USBTXHUBPORT0_BITS	bit;
};

struct USBTXFUNCADDR1_BITS
{
	Uint16	ADDR:7;				// 6:0	Device Address
	Uint16	rsvd1:1;			// 7	Reserved
};

union USBTXFUNCADDR1_REG
{
	Uint16 	all;
	struct USBTXFUNCADDR1_BITS	bit;
};

struct USBTXHUBADDR1_BITS
{
	Uint16	ADDR:7;				// 6:0	Hub Address
	Uint16	MULTTRAN:1;			// 7	Hub has Multiple Translators
};

union USBTXHUBADDR1_REG
{
	Uint16 	all;
	struct USBTXHUBADDR1_BITS	bit;
};

struct USBTXHUBPORT1_BITS
{
	Uint16	PORT:7;				// 6:0	Hub Port
	Uint16	rsvd1:1;			// 7	Reserved
};

union USBTXHUBPORT1_REG
{
	Uint16 	all;
	struct USBTXHUBPORT1_BITS	bit;
};

struct USBRXFUNCADDR1_BITS
{
	Uint16	ADDR:7;				// 6:0	Device Address
	Uint16	rsvd1:1;			// 7	Reserved
};

union USBRXFUNCADDR1_REG
{
	Uint16 	all;
	struct USBRXFUNCADDR1_BITS	bit;
};

struct USBRXHUBADDR1_BITS
{
	Uint16	ADDR:7;				// 6:0	Hub Address
	Uint16	MULTTRAN:1;			// 7	Hub has Multiple Translators
};

union USBRXHUBADDR1_REG
{
	Uint16 	all;
	struct USBRXHUBADDR1_BITS	bit;
};

struct USBRXHUBPORT1_BITS
{
	Uint16	PORT:7;				// 6:0	Hub Port
	Uint16	rsvd1:1;			// 7	Reserved
};

union USBRXHUBPORT1_REG
{
	Uint16 	all;
	struct USBRXHUBPORT1_BITS	bit;
};

struct USBTXFUNCADDR2_BITS
{
	Uint16	ADDR:7;				// 6:0	Device Address
	Uint16	rsvd1:1;			// 7	Reserved
};

union USBTXFUNCADDR2_REG
{
	Uint16 	all;
	struct USBTXFUNCADDR2_BITS	bit;
};

struct USBTXHUBADDR2_BITS
{
	Uint16	ADDR:7;				// 6:0	Hub Address
	Uint16	MULTTRAN:1;			// 7	Hub has Multiple Translators
};

union USBTXHUBADDR2_REG
{
	Uint16 	all;
	struct USBTXHUBADDR2_BITS	bit;
};

struct USBTXHUBPORT2_BITS
{
	Uint16	PORT:7;				// 6:0	Hub Port
	Uint16	rsvd1:1;			// 7	Reserved
};

union USBTXHUBPORT2_REG
{
	Uint16 	all;
	struct USBTXHUBPORT2_BITS	bit;
};

struct USBRXFUNCADDR2_BITS
{
	Uint16	ADDR:7;				// 6:0	Device Address
	Uint16	rsvd1:1;			// 7	Reserved
};

union USBRXFUNCADDR2_REG
{
	Uint16	all;
	struct USBRXFUNCADDR2_BITS	bit;
};

struct USBRXHUBADDR2_BITS
{
	Uint16	ADDR:7;				// 6:0	Hub Address
	Uint16	MULTTRAN:1;			// 7	Hub has Multiple Translators
};

union USBRXHUBADDR2_REG
{
	Uint16 	all;
	struct USBRXHUBADDR2_BITS	bit;
};

struct USBRXHUBPORT2_BITS
{
	Uint16	PORT:7;				// 6:0	Hub Port
	Uint16	rsvd1:1;			// 7	Reserved
};

union USBRXHUBPORT2_REG
{
	Uint16 	all;
	struct USBRXHUBPORT2_BITS	bit;
};

struct USBTXFUNCADDR3_BITS
{
	Uint16	ADDR:7;				// 6:0	Device Address
	Uint16	rsvd1:1;			// 7	Reserved
};

union USBTXFUNCADDR3_REG
{
	Uint16 	all;
	struct USBTXFUNCADDR3_BITS	bit;
};

struct USBTXHUBADDR3_BITS
{
	Uint16	ADDR:7;				// 6:0	Hub Address
	Uint16	MULTTRAN:1;			// 7	Hub has Multiple Translators
};

union USBTXHUBADDR3_REG
{
	Uint16 	all;
	struct USBTXHUBADDR3_BITS	bit;
};

struct USBTXHUBPORT3_BITS
{
	Uint16	PORT:7;				// 6:0	Hub Port
	Uint16	rsvd1:1;			// 7	Reserved
};

union USBTXHUBPORT3_REG
{
	Uint16 	all;
	struct USBTXHUBPORT3_BITS	bit;
};

struct USBRXFUNCADDR3_BITS
{
	Uint16	ADDR:7;				// 6:0	Device Address
	Uint16	rsvd1:1;			// 7	Reserved
};

union USBRXFUNCADDR3_REG
{
	Uint16	all;
	struct USBRXFUNCADDR3_BITS	bit;
};

struct USBRXHUBADDR3_BITS
{
	Uint16	ADDR:7;				// 6:0	Hub Address
	Uint16	MULTTRAN:1;			// 7	Hub has Multiple Translators
};

union USBRXHUBADDR3_REG
{
	Uint16 	all;
	struct USBRXHUBADDR3_BITS	bit;
};

struct USBRXHUBPORT3_BITS
{
	Uint16	PORT:7;				// 6:0	Hub Port
	Uint16	rsvd1:1;			// 7	Reserved
};

union USBRXHUBPORT3_REG
{
	Uint16 	all;
	struct USBRXHUBPORT3_BITS	bit;
};

struct USBCSRL0_BITS
{
	Uint16	RXRDY:1;				// 0	Receive Packet Ready
	Uint16	TXRDY:1;				// 1	Transmit Packet Ready
	Uint16	STALLED:1;				// 2	Endpoint Stalled
	Uint16	DATAEND_SETUP:1;		// 3	Data End/Setup Packet
	Uint16	SETEND_ERROR:1;			// 4	Setup End/Error
	Uint16	STALL_RQPKT:1;			// 5	Send Stall /Request Packet
	Uint16	RXRDYC_STATUS:1;		// 6	RXRDY Clear/STATUS Packet
	Uint16	SETENDC_NAKTO:1;		// 7	Setup End Clear/NAK Timeout
};

union USBCSRL0_REG
{
	Uint16 	all;
	struct USBCSRL0_BITS	bit;
};

struct USBCSRH0_BITS
{
	Uint16	FLUSH:1;			// 0	Flush FIFO
	Uint16	DT:1;				// 1	Data Toggle
	Uint16	DTWE:1;				// 2	Data Toggle Write Enable
	Uint16	rsvd1:5;			// 7:3	Reserved
};

union USBCSRH0_REG
{
	Uint16 	all;
	struct USBCSRH0_BITS	bit;
};

struct USBCOUNT0_BITS
{
	Uint16	COUNT:7;			// 6:0	FIFO Count
	Uint16	rsvd1:1;			// 7	Reserved
};

union USBCOUNT0_REG
{
	Uint16 	all;
	struct USBCOUNT0_BITS	bit;
};

struct USBTYPE0_BITS
{
	Uint16	rsvd1:6;			// 5:0	Reserved
	Uint16	SPEED:2;			// 7:6	Operating Speed
};

union USBTYPE0_REG
{
	Uint16 	all;
	struct USBTYPE0_BITS	bit;
};

struct USBNAKLMT_BITS
{
	Uint16	NAKLMT:5;			// 4:0	EP0 NAK Limit
	Uint16	rsvd1:3;			// 7:5	Reserved
};

union USBNAKLMT_REG
{
	Uint16 	all;
	struct USBNAKLMT_BITS	bit;
};

struct USBTXMAXP1_BITS
{
	Uint16	MAXLOAD:11;			// 10:0	Maximum Payload
	Uint16	rsvd1:5;			// 15:11	Reserved
};

union USBTXMAXP1_REG
{
	Uint32 all;
	struct USBTXMAXP1_BITS	bit;
};

struct USBTXCSRL1_BITS
{
	Uint16	TXRDY:1;			// 0	Transmit Packet Ready
	Uint16	FIFONE:1;			// 1	FIFO Not Empty
	Uint16	UNDRN_ERROR1:1;		// 2	Underun/Error
	Uint16	FLUSH:1;			// 3	Flush FIFO
	Uint16	STALL_SETUP:1;		// 4	Send Stall/Setup Packet
	Uint16	STALLED:1;			// 5	Endpoint Stalled
	Uint16	CLRDT:1;			// 6	Clear Data Toggle
	Uint16	NAKTO:1;			// 7	NAK Timeout
};

union USBTXCSRL1_REG
{
    Uint16 	all;
	struct USBTXCSRL1_BITS	bit;
};

struct USBTXCSRH1_BITS
{
	Uint16	DT:1;			// 0	Data Toggle
	Uint16	DTWE:1;			// 1	Data Toggle Write Enable
	Uint16	DMAMOD:1;		// 2	DMA Request Mode
	Uint16	FDT:1;			// 3	Force Data Toggle
	Uint16	DMAEN:1;		// 4	DMA Request Enable
	Uint16	MODE:1;			// 5	Mode
	Uint16	ISO:1;			// 6	Isochronous Transfers
	Uint16	AUTOSET:1;		// 7	Auto Set
};

union USBTXCSRH1_REG
{
	Uint16 	all;
	struct USBTXCSRH1_BITS	bit;
};

struct USBRXMAXP1_BITS
{
	Uint16	MAXLOAD:11;			// 10:0	Maximum Payload
	Uint16	rsvd1:5;			// 15:11	Reserved
};

union USBRXMAXP1_REG
{
	Uint32 all;
	struct USBRXMAXP1_BITS	bit;
};

struct USBRXCSRL1_BITS
{
	Uint16	RXRDY:1;			// 0	Recieve Packet Ready
	Uint16	FULL:1;				// 1	FIFO Full
	Uint16	OVERERROR1:1;		// 2	Overrun/Error
	Uint16	DATAERRNAKTO:1;	    // 3	Data Error/NAK Timeout
	Uint16	FLUSH:1;			// 4	Flush FIFO
	Uint16	STALLREQPKT:1;		// 5	Send Stall/Request Packet
	Uint16	STALLED:1;			// 6	Endpoint Stalled
	Uint16	CLRDT:1;			// 7	Clear Data Toggle
};

union USBRXCSRL1_REG
{
	Uint16 	all;
	struct USBRXCSRL1_BITS	bit;
};

struct USBRXCSRH1_BITS
{
	Uint16	rsvd1:1;			// 0	Reserved
	Uint16	DT:1;				// 1	Data Toggle
	Uint16	DTWE:1;				// 2	Data Toggle Write Enable
	Uint16	DMAMOD:1;			// 3	DMA Request Mode
	Uint16	DISNYETPIDERR:1;	// 4	Disable NYET / PID Error
	Uint16	DMAEN:1;			// 5	DMA Request Enable
	Uint16	ISOAUTORQ:1;		// 6	Isochronous Transfers/Auto Request
	Uint16	AUTOCL:1;			// 7	Auto Clear
};

union USBRXCSRH1_REG
{
	Uint16 	all;
	struct USBRXCSRH1_BITS	bit;
};

struct USBRXCOUNT1_BITS
{
	Uint16	COUNT:13;			// 12:0	Receive Packet Count
	Uint16	rsvd1:3;			// 15:13	Reserved
};

union USBRXCOUNT1_REG
{
	Uint32 	all;
	struct USBRXCOUNT1_BITS	bit;
};

struct USBTXTYPE1_BITS
{
	Uint16	TEP:4;				// 3:0	Target Endpoint Number
	Uint16	PROTO:2;			// 5:4	Protocol
	Uint16	SPEED:2;			// 7:6	Operating Speed
};

union USBTXTYPE1_REG
{
    Uint16 	all;
	struct USBTXTYPE1_BITS	bit;
};

struct USBRXTYPE1_BITS
{
	Uint16	TEP:4;				// 3:0	Target Endpoint Number
	Uint16	PROTO:2;			// 5:4	Protocol
	Uint16	SPEED:2;			// 7:6	Operating Speed
};

union USBRXTYPE1_REG
{
	Uint16 	all;
	struct USBRXTYPE1_BITS	bit;
};

struct USBTXMAXP2_BITS
{
	Uint16	MAXLOAD:11;			// 10:0	Maximum Payload
	Uint16	rsvd1:5;			// 15:11	Reserved
};

union USBTXMAXP2_REG
{
	Uint32 all;
	struct USBTXMAXP2_BITS	bit;
};

struct USBTXCSRL2_BITS
{
	Uint16	TXRDY:1;			// 0	Transmit Packet Ready
	Uint16	FIFONE:1;			// 1	FIFO Not Empty
	Uint16	UNDRNERROR2:1;		// 2	Underun/Error
	Uint16	FLUSH:1;			// 3	Flush FIFO
	Uint16	STALLSETUP:1;		// 4	Send Stall/Setup Packet
	Uint16	STALLED:1;			// 5	Endpoint Stalled
	Uint16	CLRDT:1;			// 6	Clear Data Toggle
	Uint16	NAKTO:1;			// 7	NAK Timeout
};

union USBTXCSRL2_REG
{
	Uint16 	all;
	struct USBTXCSRL2_BITS	bit;
};

struct USBTXCSRH2_BITS
{
	Uint16	DT:1;			// 0	Data Toggle
	Uint16	DTWE:1;			// 1	Data Toggle Write Enable
	Uint16	DMAMOD:1;		// 2	DMA Request Mode
	Uint16	FDT:1;			// 3	Force Data Toggle
	Uint16	DMAEN:1;		// 4	DMA Request Enable
	Uint16	MODE:1;			// 5	Mode
	Uint16	ISO:1;			// 6	Isochronous Transfers
	Uint16	AUTOSET:1;		// 7	Auto Set
};

union USBTXCSRH2_REG
{
	Uint16 	all;
	struct USBTXCSRH2_BITS	bit;
};

struct USBRXMAXP2_BITS
{
	Uint16	MAXLOAD:11;			// 10:0	Maximum Payload
	Uint16	rsvd1:5;			// 15:11	Reserved
};

union USBRXMAXP2_REG
{
	Uint32 all;
	struct USBRXMAXP2_BITS	bit;
};

struct USBRXCSRL2_BITS
{
	Uint16	RXRDY:1;			// 0	Recieve Packet Ready
	Uint16	FULL:1;				// 1	FIFO Full
	Uint16	OVERERROR2:1;		// 2	Overrun/Error
	Uint16	DATAERRNAKTO:1;	    // 3	Data Error/NAK Timeout
	Uint16	FLUSH:1;			// 4	Flush FIFO
	Uint16	STALLREQPKT:1;		// 5	Send Stall/Request Packet
	Uint16	STALLED:1;			// 6	Endpoint Stalled
	Uint16	CLRDT:1;			// 7	Clear Data Toggle
};

union USBRXCSRL2_REG
{
	Uint16 all;
	struct USBRXCSRL2_BITS	bit;
};

struct USBRXCSRH2_BITS
{
	Uint16	rsvd1:1;			// 0	Reserved
	Uint16	DT:1;				// 1	Data Toggle
	Uint16	DTWE:1;				// 2	Data Toggle Write Enable
	Uint16	DMAMOD:1;			// 3	DMA Request Mode
	Uint16	DISNYETPIDERR:1;	// 4	Disable NYET / PID Error
	Uint16	DMAEN:1;			// 5	DMA Request Enable
	Uint16	ISOAUTORQ:1;		// 6	Isochronous Transfers/Auto Request
	Uint16	AUTOCL:1;			// 7	Auto Clear
};

union USBRXCSRH2_REG
{
	Uint16 all;
	struct USBRXCSRH2_BITS	bit;
};

struct USBRXCOUNT2_BITS
{
	Uint16	COUNT:13;			// 12:0	Receive Packet Count
	Uint16	rsvd1:3;			// 15:13	Reserved
};

union USBRXCOUNT2_REG
{
	Uint32 all;
	struct USBRXCOUNT2_BITS	bit;
};

struct USBTXTYPE2_BITS
{
	Uint16	TEP:4;				// 3:0	Target Endpoint Number
	Uint16	PROTO:2;			// 5:4	Protocol
	Uint16	SPEED:2;			// 7:6	Operating Speed
};

union USBTXTYPE2_REG
{
	Uint16 	all;
	struct USBTXTYPE2_BITS	bit;
};

struct USBRXTYPE2_BITS
{
	Uint16	TEP:4;				// 3:0	Target Endpoint Number
	Uint16	PROTO:2;			// 5:4	Protocol
	Uint16	SPEED:2;			// 7:6	Operating Speed
};

union USBRXTYPE2_REG
{
	Uint16 	all;
	struct USBRXTYPE2_BITS	bit;
};

struct USBTXMAXP3_BITS
{
	Uint16	MAXLOAD:11;			// 10:0	Maximum Payload
	Uint16	rsvd1:5;			// 15:11	Reserved
};

union USBTXMAXP3_REG
{
	Uint32 all;
	struct USBTXMAXP3_BITS	bit;
};

struct USBTXCSRL3_BITS
{
	Uint16	TXRDY:1;			// 0	Transmit Packet Ready
	Uint16	FIFONE:1;			// 1	FIFO Not Empty
	Uint16	UNDRNERROR3:1;		// 2	Underun/Error
	Uint16	FLUSH:1;			// 3	Flush FIFO
	Uint16	STALLSETUP:1;		// 4	Send Stall/Setup Packet
	Uint16	STALLED:1;			// 5	Endpoint Stalled
	Uint16	CLRDT:1;			// 6	Clear Data Toggle
	Uint16	NAKTO:1;			// 7	NAK Timeout
};

union USBTXCSRL3_REG
{
	Uint16 	all;
	struct USBTXCSRL3_BITS	bit;
};

struct USBTXCSRH3_BITS
{
	Uint16	DT:1;			// 0	Data Toggle
	Uint16	DTWE:1;			// 1	Data Toggle Write Enable
	Uint16	DMAMOD:1;		// 2	DMA Request Mode
	Uint16	FDT:1;			// 3	Force Data Toggle
	Uint16	DMAEN:1;		// 4	DMA Request Enable
	Uint16	MODE:1;			// 5	Mode
	Uint16	ISO:1;			// 6	Isochronous Transfers
	Uint16	AUTOSET:1;		// 7	Auto Set
};

union USBTXCSRH3_REG
{
	Uint16 	all;
	struct USBTXCSRH3_BITS	bit;
};

struct USBRXMAXP3_BITS
{
	Uint16	MAXLOAD:11;			// 10:0	Maximum Payload
	Uint16	rsvd1:5;			// 15:11	Reserved
};

union USBRXMAXP3_REG
{
	Uint32 all;
	struct USBRXMAXP3_BITS	bit;
};

struct USBRXCSRL3_BITS
{
	Uint16	RXRDY:1;			// 0	Recieve Packet Ready
	Uint16	FULL:1;				// 1	FIFO Full
	Uint16	OVERERROR3:1;		// 2	Overrun/Error
	Uint16	DATAERRNAKTO:1;	    // 3	Data Error/NAK Timeout
	Uint16	FLUSH:1;			// 4	Flush FIFO
	Uint16	STALLREQPKT:1;		// 5	Send Stall/Request Packet
	Uint16	STALLED:1;			// 6	Endpoint Stalled
	Uint16	CLRDT:1;			// 7	Clear Data Toggle
};

union USBRXCSRL3_REG
{
	Uint16 	all;
	struct USBRXCSRL3_BITS	bit;
};

struct USBRXCSRH3_BITS
{
	Uint16	rsvd1:1;			// 0	Reserved
	Uint16	DT:1;				// 1	Data Toggle
	Uint16	DTWE:1;				// 2	Data Toggle Write Enable
	Uint16	DMAMOD:1;			// 3	DMA Request Mode
	Uint16	DISNYETPIDERR:1;	// 4	Disable NYET / PID Error
	Uint16	DMAEN:1;			// 5	DMA Request Enable
	Uint16	ISOAUTORQ:1;		// 6	Isochronous Transfers/Auto Request
	Uint16	AUTOCL:1;			// 7	Auto Clear
};

union USBRXCSRH3_REG
{
	Uint16 	all;
	struct USBRXCSRH3_BITS	bit;
};

struct USBRXCOUNT3_BITS
{
	Uint16	COUNT:13;			// 12:0	Receive Packet Count
	Uint16	rsvd1:3;			// 15:13	Reserved
};

union USBRXCOUNT3_REG
{
	Uint32 all;
	struct USBRXCOUNT3_BITS	bit;
};

struct USBTXTYPE3_BITS
{
	Uint16	TEP:4;				// 3:0	Target Endpoint Number
	Uint16	PROTO:2;			// 5:4	Protocol
	Uint16	SPEED:2;			// 7:6	Operating Speed
};

union USBTXTYPE3_REG
{
	Uint16 	all;
	struct USBTXTYPE3_BITS	bit;
};

struct USBRXTYPE3_BITS
{
	Uint16	TEP:4;				// 3:0	Target Endpoint Number
	Uint16	PROTO:2;			// 5:4	Protocol
	Uint16	SPEED:2;			// 7:6	Operating Speed
};

union USBRXTYPE3_REG
{
	Uint16 	all;
	struct USBRXTYPE3_BITS	bit;
};

struct USBRXDPKTBUFDIS_BITS
{
	Uint16	rsvd1:1;			// 0	Reserved
	Uint16	EP1:1;				// 1	EP1 RX Double Packet Buffer Disable
	Uint16	EP2:1;				// 2	EP2 RX Double Packet Buffer Disable
	Uint16	EP3:1;				// 3	EP3 RX Double Packet Buffer Disable
	Uint16	rsvd2:12;			// 15:4	Reserved
};

union USBRXDPKTBUFDIS_REG
{
	Uint32 all;
    struct USBRXDPKTBUFDIS_BITS	bit;
};

struct USBTXDPKTBUFDIS_BITS
{
	Uint16	rsvd1:1;			// 0	Reserved
	Uint16	EP1:1;				// 1	EP1 TX Double Packet Buffer Disable
	Uint16	EP2:1;				// 2	EP2 TX Double Packet Buffer Disable
	Uint16	EP3:1;				// 3	EP3 TX Double Packet Buffer Disable
	Uint16	rsvd2:12;			// 15:4	Reserved
};

union USBTXDPKTBUFDIS_REG
{
	Uint32 all;
	struct USBTXDPKTBUFDIS_BITS	bit;
};

struct USBEPC_BITS
{
	Uint16	EPEN:2;			// 1:0	External Power Supply Enable Configuration
	Uint16	EPENDE:1;		// 2	EPEN Drive Enable
	Uint16	rsvd1:1;		// 3	Reserved
	Uint16	PFLTEN:1;		// 4	Power Fault Input Enable
	Uint16	PFLTSEN:1;		// 5	Power Fault Sense
	Uint16	PFLTAEN:1;		// 6	Power Fault Action Enable
	Uint16	rsvd2:1;		// 7	Reserved
	Uint16	PFLTACT:2;		// 9:8	Power Fault Action
	Uint16	rsvd3:6;		// 15:10	Reserved
	Uint16	rsvd4:16;		// 31:16	Reserved
};

union USBEPC_REG
{
	Uint64 all;
	struct USBEPC_BITS	bit;
};

struct USBEPCRIS_BITS
{
	Uint16	PF:1;			// 0	Power Fault Interrupt Status
	Uint16	rsvd1:15;		// 15:1	Reserved
	Uint16	rsvd2:16;		// 31:16	Reserved
};

union USBEPCRIS_REG
{
	Uint64 all;
	struct USBEPCRIS_BITS	bit;
};

struct USBEPCIM_BITS
{
	Uint16	PF:1;				// 0	Power Fault Interrupt Mask
	Uint16	rsvd1:15;			// 15:1	Reserved
	Uint16	rsvd2:16;			// 31:16	Reserved
};

union USBEPCIM_REG
{
	Uint64 all;
	struct USBEPCIM_BITS	bit;
};

struct USBEPCISC_BITS
{
	Uint16	PF:1;				// 0	Power Fault Interrupt Status and Clear
	Uint16	rsvd1:15;			// 15:1	Reserved
	Uint16	rsvd2:16;			// 31:16	Reserved
};

union USBEPCISC_REG
{
	Uint64 all;
	struct USBEPCISC_BITS	bit;
};

struct USBDRRIS_BITS
{
	Uint16	RESUME:1;			// 0	Resume Interrupt Status
	Uint16	rsvd1:15;			// 15:1	Reserved
	Uint16	rsvd2:16;			// 31:16	Reserved
};

union USBDRRIS_REG
{
	Uint64 all;
	struct USBDRRIS_BITS	bit;
};

struct USBDRIM_BITS
{
	Uint16	RESUME:1;			// 0	Resume Interrupt Mask
	Uint16	rsvd1:15;			// 15:1	Reserved
	Uint16	rsvd2:16;			// 31:16	Reserved
};

union USBDRIM_REG
{
	Uint64 all;
	struct USBDRIM_BITS	bit;
};

struct USBDRISC_BITS
{
	Uint16	RESUME:1;			// 0	Resume Interrupt Status and Clear
	Uint16	rsvd1:15;			// 15:1	Reserved
	Uint16	rsvd2:16;			// 31:16	Reserved
};

union USBDRISC_REG
{
	Uint64 all;
	struct USBDRISC_BITS	bit;
};

struct USBGPCS_BITS
{
	Uint16	DEVMOD:1;			// 0	Device Mode
	Uint16	DEVMODOTG:1;		// 1	Enable Device Mode
	Uint16	rsvd1:14;			// 15:2	Reserved
	Uint16	rsvd2:16;			// 31:16	Reserved
};

union USBGPCS_REG
{
	Uint64 all;
	struct USBGPCS_BITS	bit;
};

struct USBVDC_BITS
{
	Uint16	VBDEN:1;			// 0	Vbus Droop Enable
	Uint16	rsvd1:15;			// 15:1	Reserved
	Uint16	rsvd2:16;			// 31:16	Reserved
};

union USBVDC_REG
{
	Uint64 all;
	struct USBVDC_BITS	bit;
};

struct USBVDCRIS_BITS
{
	Uint16	VD:1;				// 0	Vbus Droop Raw Interrupt Status
	Uint16	rsvd1:15;			// 15:1	Reserved
	Uint16	rsvd2:16;			// 31:16	Reserved
};

union USBVDCRIS_REG
{
	Uint64 all;
	struct USBVDCRIS_BITS	bit;
};

struct USBVDCIM_BITS
{
	Uint16	VD:1;				// 0	Vbus Droop Interrupt Mask
	Uint16	rsvd1:15;			// 15:1	Reserved
	Uint16	rsvd2:16;			// 31:16	Reserved
};

union USBVDCIM_REG
{
	Uint64 all;
	struct USBVDCIM_BITS	bit;
};

struct USBVDCISC_BITS
{
	Uint16	VD:1;				// 0	Vbus Droop Interrupt Status and Clear
	Uint16	rsvd1:15;			// 15:1	Reserved
	Uint16	rsvd2:16;			// 31:16	Reserved
};

union USBVDCISC_REG
{
	Uint64 all;
	struct USBVDCISC_BITS	bit;
};

struct USBIDVRIS_BITS
{
	Uint16	ID:1;				// 0	ID Valid Detect Raw Interrupt Status
	Uint16	rsvd1:15;			// 15:1	Reserved
	Uint16	rsvd2:16;			// 31:16	Reserved
};

union USBIDVRIS_REG
{
	Uint64 all;
	struct USBIDVRIS_BITS	bit;
};

struct USBIDVIM_BITS
{
	Uint16	ID:1;				// 0	ID Valid Detect Interrupt mask
	Uint16	rsvd1:15;			// 15:1	Reserved
	Uint16	rsvd2:16;			// 31:16	Reserved
};

union USBIDVIM_REG
{
	Uint64 all;
	struct USBIDVIM_BITS	bit;
};

struct USBIDVISC_BITS
{
	Uint16	ID:1;			// 0	ID Valid Detect Interrupt Status and Clear
    Uint16	rsvd1:15;		// 15:1	Reserved
	Uint16	rsvd2:16;		// 31:16	Reserved
};

union USBIDVISC_REG
{
	Uint64 all;
	struct USBIDVISC_BITS	bit;
};

struct USBDMASEL_BITS
{
	Uint16	DMAARX:4;			// 3:0	DMA A RX Select
	Uint16	DMAATX:4;			// 7:4	DMA A TX Select
	Uint16	DMABRX:4;			// 11:8	DMA B RX Select
	Uint16	DMABTX:4;			// 15:12	DMA B TX Select
	Uint16	DMACRX:4;			// 19:16	DMA C RX Select
	Uint16	DMACTX:4;			// 23:20	DMA C TX Select
	Uint16	rsvd1:8;			// 31:24	Reserved
};

union USBDMASEL_REG
{
	Uint64 all;
	struct USBDMASEL_BITS	bit;
};

struct USB_REGS
{
	union	USBFADDR_REG		USBFADDR;	// USB Device Functional Address
	union	USBPOWER_REG		USBPOWER;	// USB Power
	union	USBTXIS_REG			USBTXIS;	// USB Transmit Interrupt Status
	union	USBRXIS_REG			USBRXIS;	// USB Receive Interrupt Status
	union	USBTXIE_REG			USBTXIE;	// USB Transmit Interrupt Enable
	union	USBRXIE_REG			USBRXIE;	// USB Receive Interrupt Enable
	union	USBIS_REG			USBIS;		// USB General Interrupt Status
	union	USBIE_REG			USBIE;		// USB Interrupt Enable
	union	USBFRAME_REG		USBFRAME;	// USB Frame Value
	union	USBEPIDX_REG		USBEPIDX;	// USB Endpoint Index
	union	USBTEST_REG			USBTEST;	// USB Test Mode
	Uint32						rsvd1[8];	// Reserved
	Uint64						USBFIFO0;	// USB FIFO Endpoint 0
	Uint64						USBFIFO1;	// USB FIFO Endpoint 1
	Uint64						USBFIFO2;	// USB FIFO Endpoint 2
	Uint64						USBFIFO3;	// USB FIFO Endpoint 3
	Uint32						rsvd2[24];	// Reserved
	union	USBDEVCTL_REG		USBDEVCTL;	// USB Device Control
	union	USBTXFIFOSZ_REG		USBTXFIFOSZ;// USB Transmit Dynamic FIFO Sizing
	union	USBRXFIFOSZ_REG		USBRXFIFOSZ;// USB Receive Dynamic FIFO Sizing
	
    //
    // USB Transmit FIFO Start Address
    //
    union	USBTXFIFOADD_REG	USBTXFIFOADD;
    
	//
    // USB Receive FIFO Start Address
    //
    union	USBRXFIFOADD_REG	USBRXFIFOADD;
    
	Uint32						rsvd3[9];		// Reserved
	union	USBCONTIM_REG		USBCONTIM;		// USB Connect Timing
	Uint16						USBVPLEN;		// USB OTG VBUS Pulse Timing
	Uint16						rsvd4[1];		// Reserved
	
    //
    // USB Full-Speed Last Transaction to End of Frame Timing
    //
    Uint16						USBFSEOF;		
    
	//
    // USB Low-Speed Last Transaction to End of Frame Timing
    //
    Uint16						USBLSEOF;		
    
	Uint16						rsvd5[1];		// Reserved
	
    //
    // USB Transmit Functional Address Endpoint 0
    //
    union	USBTXFUNCADDR0_REG	USBTXFUNCADDR0;	
    
	Uint16						rsvd6[1];		// Reserved
	
    //
    // USB Transmit Hub Address Endpoint 0
    //
    union	USBTXHUBADDR0_REG	USBTXHUBADDR0;	
    
	//
    // USB Transmit Hub Port Endpoint 0
    //
    union	USBTXHUBPORT0_REG	USBTXHUBPORT0;	
	Uint32						rsvd7[2];		// Reserved
	
    //
    // USB Transmit Functional Address Endpoint 1
    //
    union	USBTXFUNCADDR1_REG	USBTXFUNCADDR1;	
    
	Uint16						rsvd8[1];		// Reserved
	
    //
    // USB Transmit Hub Address Endpoint 1
    //
    union	USBTXHUBADDR1_REG	USBTXHUBADDR1;	
    
	//
    // USB Transmit Hub Port Endpoint 1
    //
    union	USBTXHUBPORT1_REG	USBTXHUBPORT1;
	
    //
    // USB Receive Functional Address Endpoint 1
    //
    union	USBRXFUNCADDR1_REG	USBRXFUNCADDR1;	
    
	Uint16						rsvd9[1];		// Reserved
	
    //
    // USB Receive Hub Address Endpoint 1
    //
    union	USBRXHUBADDR1_REG	USBRXHUBADDR1;
    
	//
    // USB Receive Hub Port Endpoint 1
    //
    union	USBRXHUBPORT1_REG	USBRXHUBPORT1;	
    
    //
    // USB Transmit Functional Address Endpoint 2
    //
	union	USBTXFUNCADDR2_REG	USBTXFUNCADDR2;	
    
    Uint16						rsvd10[1];		// Reserved
	
    //
    // USB Transmit Hub Address Endpoint 2
    //
    union	USBTXHUBADDR2_REG	USBTXHUBADDR2;	
	
    //
    // USB Transmit Hub Port Endpoint 2
    //
    union	USBTXHUBPORT2_REG	USBTXHUBPORT2;
    
    //
    // USB Receive Functional Address Endpoint 2
    //
	union	USBRXFUNCADDR2_REG	USBRXFUNCADDR2;	
    
	Uint16						rsvd11[1];		// Reserved
	
    //
    // USB Receive Hub Address Endpoint 2
    //
    union	USBRXHUBADDR2_REG	USBRXHUBADDR2;
    
    //
    // USB Receive Hub Port Endpoint 2
    //
	union	USBRXHUBPORT2_REG	USBRXHUBPORT2;	
    
    //
    // USB Transmit Functional Address Endpoint 3
    //
	union	USBTXFUNCADDR3_REG	USBTXFUNCADDR3;
    

	Uint16						rsvd12[1];		// Reserved
	
    //
    // USB Transmit Hub Address Endpoint 3
    //
    union	USBTXHUBADDR3_REG	USBTXHUBADDR3;
    
	//
    // USB Transmit Hub Port Endpoint 3
    //
    union	USBTXHUBPORT3_REG	USBTXHUBPORT3;
    
    //
    // USB Receive Functional Address Endpoint 3
    //
	union	USBRXFUNCADDR3_REG	USBRXFUNCADDR3;
	Uint16						rsvd13[1];		// Reserved
	
    //
    // USB Receive Hub Address Endpoint 3
    //
    union	USBRXHUBADDR3_REG	USBRXHUBADDR3;
    
	//
    // USB Receive Hub Port Endpoint 3
    //
    union	USBRXHUBPORT3_REG	USBRXHUBPORT3;
	Uint32						rsvd14[49];		// Reserved
	
    //
    // USB Control and Status Endpoint 0 Low
    //
    union	USBCSRL0_REG		USBCSRL0;		
    
    //
    // USB Control and Status Endpoint 0 High
    //
	union	USBCSRH0_REG		USBCSRH0;		
    
	Uint32						rsvd15[2];		// Reserved
	
    //
    // USB Receive Byte Count Endpoint 0
    //
    union	USBCOUNT0_REG		USBCOUNT0;		
    
	Uint16						rsvd16[1];		// Reserved
	union	USBTYPE0_REG		USBTYPE0;		// USB Type Endpoint 0
	union	USBNAKLMT_REG		USBNAKLMT;		// USB NAK Limit
	Uint32						rsvd17[2];		// Reserved
	
    //
    // USB Maximum Transmit Data Endpoint 1
    //
    union	USBTXMAXP1_REG		USBTXMAXP1;		
    
    //
    // USB Transmit Control and Status Endpoint 1 Low
    //
	union	USBTXCSRL1_REG		USBTXCSRL1;		
    
    //
    // USB Transmit Control and Status Endpoint 1 High
    //
	union	USBTXCSRH1_REG		USBTXCSRH1;
    
    //
    // USB Maximum Receive Data Endpoint 1
    //
	union	USBRXMAXP1_REG		USBRXMAXP1;		
    
    //
    // USB Receive Control and Status Endpoint 1 Low
    //
	union	USBRXCSRL1_REG		USBRXCSRL1;
    
    //
    // USB Receive Control and Status Endpoint 1 High
    //
	union	USBRXCSRH1_REG		USBRXCSRH1;		
	
    //
    // USB Receive Byte Count Endpoint 1
    //
    union	USBRXCOUNT1_REG		USBRXCOUNT1;	
    
    //
    // USB Host Transmit Configure Type Endpoint 1
    //
	union	USBTXTYPE1_REG		USBTXTYPE1;		
    
    //
    // USB Host Transmit Interval Endpoint 1
    //
	Uint16						USBTXINTERVAL1;	
    
    //
    // USB Host Configure Receive Type Endpoint 1
    //
	union	USBRXTYPE1_REG		USBRXTYPE1;		
	
    //
    // USB Host Receive Polling Interval Endpoint 1
    //
    Uint16						USBRXINTERVAL1;	
	
    Uint32						rsvd18;			// Reserved
	
    //
    // USB Maximum Transmit Data Endpoint 2
    //
    union	USBTXMAXP2_REG		USBTXMAXP2;		
	
    //
    // USB Transmit Control and Status Endpoint 2 Low
    //
    union	USBTXCSRL2_REG		USBTXCSRL2;		
    
    //
    // USB Transmit Control and Status Endpoint 2 High
    //
	union	USBTXCSRH2_REG		USBTXCSRH2;		
	
    //
    // USB Maximum Receive Data Endpoint 2
    //
    union	USBRXMAXP2_REG		USBRXMAXP2;		
	
    //
    // USB Receive Control and Status Endpoint 2 Low
    //
    union	USBRXCSRL2_REG		USBRXCSRL2;		
	
    //
    // USB Receive Control and Status Endpoint 2 High
    //
    union	USBRXCSRH2_REG		USBRXCSRH2;		
    
    //
    // USB Receive Byte Count Endpoint 2
    //
	union	USBRXCOUNT2_REG		USBRXCOUNT2;	
	
    //
    // USB Host Transmit Configure Type Endpoint 2
    //
    union	USBTXTYPE2_REG		USBTXTYPE2;		
    
    //
    // USB Host Transmit Interval Endpoint 2
    //
	Uint16						USBTXINTERVAL2;	
    
    //
    // USB Host Configure Receive Type Endpoint 2
    //
	union	USBRXTYPE2_REG		USBRXTYPE2;		
    
    //
    // USB Host Receive Polling Interval Endpoint 2
    //
	Uint16						USBRXINTERVAL2;	
	
    Uint32						rsvd19;			// Reserved
	
    //
    // USB Maximum Transmit Data Endpoint 3
    //
    union	USBTXMAXP3_REG		USBTXMAXP3;		
    
    //
    // USB Transmit Control and Status Endpoint 3 Low
    //
	union	USBTXCSRL3_REG		USBTXCSRL3;		
	
    //
    // USB Transmit Control and Status Endpoint 3 High
    //
    union	USBTXCSRH3_REG		USBTXCSRH3;		
	
    //
    // USB Maximum Receive Data Endpoint 3
    //
    union	USBRXMAXP3_REG		USBRXMAXP3;		
	
    //
    // USB Receive Control and Status Endpoint 3 Low
    //
    union	USBRXCSRL3_REG		USBRXCSRL3;		
	
    //
    // USB Receive Control and Status Endpoint 3 High
    //
    union	USBRXCSRH3_REG		USBRXCSRH3;		
	
    //
    // USB Receive Byte Count Endpoint 3
    //
    union	USBRXCOUNT3_REG		USBRXCOUNT3;	
	
    //
    // USB Host Transmit Configure Type Endpoint 3
    //
    union	USBTXTYPE3_REG		USBTXTYPE3;		
	
    //
    // USB Host Transmit Interval Endpoint 3
    //
    Uint16						USBTXINTERVAL3;	
	
    //
    // USB Host Configure Receive Type Endpoint 3
    //
    union	USBRXTYPE3_REG		USBRXTYPE3;		
	
    //
    // USB Host Receive Polling Interval Endpoint 3
    //
    Uint16						USBRXINTERVAL3;	
	
    Uint32						rsvd20[227];	// Reserved
	
    //
    // USB Request Packet Count in Block Transfer Endpoint 1
    //
    Uint32						USBRQPKTCOUNT1;	
    
	Uint32						rsvd21;			// Reserved
	
    //
    // USB Request Packet Count in Block Transfer Endpoint 2
    //
    Uint32						USBRQPKTCOUNT2;
    
	Uint32						rsvd22;			// Reserved
	
    //
    // USB Request Packet Count in Block Transfer Endpoint 3
    //
    Uint32						USBRQPKTCOUNT3;	
    
    Uint32						rsvd23[25];		// Reserved
	
    //
    // USB Receive Double Packet Buffer Disable
    //
    union	USBRXDPKTBUFDIS_REG	USBRXDPKTBUFDIS;
	
    //
    // USB Transmit Double Packet Buffer Disable
    //
    union	USBTXDPKTBUFDIS_REG	USBTXDPKTBUFDIS;
    
	Uint32						rsvd24[94];		// Reserved
	union	USBEPC_REG			USBEPC;			// USB External Power Control
	
    //
    // USB External Power Control Raw Interrupt Status
    //
    union	USBEPCRIS_REG		USBEPCRIS;		

    //
    // USB External Power Control Interrupt Mask
    //
	union	USBEPCIM_REG		USBEPCIM;		
	
    //
    // USB External Power Control Interrupt Status and Clear
    //
    union	USBEPCISC_REG		USBEPCISC;		
	
    //
    // USB Device RESUME Raw Interrupt Status
    //
    union	USBDRRIS_REG		USBDRRIS;		
    
	//
    // USB Device RESUME Interrupt Mask
    //
    union	USBDRIM_REG			USBDRIM;		
    
    //
    // USB Device RESUME Interrupt Status and Clear
    //
	union	USBDRISC_REG		USBDRISC;		
    
    //
    // USB General-Purpose Control and Status
    //
	union	USBGPCS_REG			USBGPCS;		
    
	Uint32						rsvd25[8];		// Reserved
	union	USBVDC_REG			USBVDC;			// USB VBUS Droop Control
	
    //
    // USB VBUS Droop Control Raw Interrupt Status
    //
    union	USBVDCRIS_REG		USBVDCRIS;		
	
    //
    // USB VBUS Droop Control Interrupt Mask
    //
    union	USBVDCIM_REG		USBVDCIM;		
	
    //
    // USB VBUS Droop Control Interrupt Status and Clear
    //
    union	USBVDCISC_REG		USBVDCISC;		
    
	Uint32						rsvd26[2];		// Reserved
	
    //
    // USB ID Valid Detect Raw Interrupt Status
    //
    union	USBIDVRIS_REG		USBIDVRIS;		
	
    //
    // USB ID Valid Detect Interrupt Mask
    //
    union	USBIDVIM_REG		USBIDVIM;		
	
    //
    // USB ID Valid Detect Interrupt Status and Clear
    //
    union	USBIDVISC_REG		USBIDVISC;		
    
	union	USBDMASEL_REG		USBDMASEL;		// USB DMA Select
};

//
// Usb External References & Function Declarations:
//
extern volatile struct	USB_REGS	Usb0Regs;

#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of F2806x_USB_H definition

//
// End of file
//

