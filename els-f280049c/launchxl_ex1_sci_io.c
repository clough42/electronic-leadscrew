//#############################################################################
//
// FILE:   launchxl_ex1_sci_io.c
//
// TITLE:  Contains the various functions related to the serial 
//         communications interface (SCI) object
//
//#############################################################################
// $TI Release: F28004x Support Library v1.10.00.00 $
// $Release Date: Tue May 26 17:06:03 IST 2020 $
// $Copyright:
// Copyright (C) 2020 Texas Instruments Incorporated - http://www.ti.com/
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

//
// Included Files
//
#include <stdio.h>
#include <file.h>
#include <stdint.h>
#include <stdbool.h>

#include "F28x_Project.h"
#include "launchxl_ex1_sci_io.h"

//
// Defines
//

//
// Globals
//
uint16_t deviceOpen = 0;
uint16_t deviceOpenB = 0;

//
// Functions
//

//
// SCI_open -
//
int SCI_open(const char * path, unsigned flags, int llv_fd)
{
    if(deviceOpen)
    {
        return (-1);
    }
    else
    {
        deviceOpen = 1;
        return (1);    
    }      
}

//
// SCI_close - 
//
int SCI_close(int dev_fd)
{
    if((dev_fd != 1) || (!deviceOpen))
    {
        return (-1);
    }
    else
    {
        deviceOpen = 0;
        return (0);
    }    
}

//
// SCI_read - 
//
int SCI_read(int dev_fd, char * buf, unsigned count)
{
    uint16_t readCount = 0;
    uint16_t * bufPtr = (uint16_t *) buf;
    
    if(count == 0)
    {
        return (0);
    }
    
    while((readCount < count) && SciaRegs.SCIRXST.bit.RXRDY)
    {
        *bufPtr = SciaRegs.SCIRXBUF.all;
        readCount++;
        bufPtr++;
    }
    
    return (readCount);
}

//
// SCI_write - 
//
int SCI_write(int dev_fd, const char * buf, unsigned count)
{
    uint16_t writeCount = 0;
    uint16_t * bufPtr = (uint16_t *) buf;
    
    if(count == 0)
    {
        return (0);
    }
    
    while(writeCount < count)
    {
        while(!SciaRegs.SCICTL2.bit.TXRDY);
        SciaRegs.SCITXBUF.all = *bufPtr;
        writeCount++;
        bufPtr++;
    }
    
    return (writeCount);
}

//
// SCI_lseek - 
//
off_t SCI_lseek(int dev_fd, off_t offset, int origin)
{
    return (0);   
}

//
// SCI_unlink -
//
int SCI_unlink(const char * path)
{
    return (0);
}

//
// SCI_rename - 
//
int SCI_rename(const char * old_name, const char * new_name)
{
    return (0);    
}






// KVV
//
// SCI_open -
//
int SCIB_open(const char * path, unsigned flags, int llv_fd)
{
    if(deviceOpenB)
    {
        return (-1);
    }
    else
    {
        deviceOpenB = 1;
        return (1);
    }
}

//
// SCI_close -
//
int SCIB_close(int dev_fd)
{
    if((dev_fd != 1) || (!deviceOpenB))
    {
        return (-1);
    }
    else
    {
        deviceOpenB = 0;
        return (0);
    }
}

//
// SCI_read -
//
int SCIB_read(int dev_fd, char * buf, unsigned count)
{
    uint16_t readCount = 0;
    uint16_t * bufPtr = (uint16_t *) buf;

    if(count == 0)
    {
        return (0);
    }

    while((readCount < count) && ScibRegs.SCIRXST.bit.RXRDY)
    {
        *bufPtr = ScibRegs.SCIRXBUF.all;
        readCount++;
        bufPtr++;
    }

    return (readCount);
}

//
// SCI_write -
//
int SCIB_write(int dev_fd, const char * buf, unsigned count)
{
    uint16_t writeCount = 0;
    uint16_t * bufPtr = (uint16_t *) buf;

    if(count == 0)
    {
        return (0);
    }

    while(writeCount < count)
    {
        while(!ScibRegs.SCICTL2.bit.TXRDY);
        ScibRegs.SCITXBUF.all = *bufPtr;
        writeCount++;
        bufPtr++;
    }

    return (writeCount);
}

//
// SCI_lseek -
//
off_t SCIB_lseek(int dev_fd, off_t offset, int origin)
{
    return (0);
}

//
// SCI_unlink -
//
int SCIB_unlink(const char * path)
{
    return (0);
}

//
// SCI_rename -
//
int SCIB_rename(const char * old_name, const char * new_name)
{
    return (0);
}

//
// End of File
//

