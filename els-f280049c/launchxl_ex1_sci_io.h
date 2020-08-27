#ifndef _SCI_IO_H_
#define _SCI_IO_H_

//#############################################################################
//
// FILE:   launchxl_ex1_sci_io.h
//
// TITLE:  Contains public interface to various functions related
//         to the serial communications interface (SCI) object
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

#ifdef __cplusplus
extern "C" {
#endif

//
// Globals
//

// 
// Function prototypes
//
int SCI_open(const char * path, unsigned flags, int llv_fd);
int SCI_close(int dev_fd);
int SCI_read(int dev_fd, char * buf, unsigned count);
int SCI_write(int dev_fd, const char * buf, unsigned count);
off_t SCI_lseek(int dev_fd, off_t offset, int origin);
int SCI_unlink(const char * path);
int SCI_rename(const char * old_name, const char * new_name);

// KVV
int SCIB_open(const char * path, unsigned flags, int llv_fd);
int SCIB_close(int dev_fd);
int SCIB_read(int dev_fd, char * buf, unsigned count);
int SCIB_write(int dev_fd, const char * buf, unsigned count);
off_t SCIB_lseek(int dev_fd, off_t offset, int origin);
int SCIB_unlink(const char * path);
int SCIB_rename(const char * old_name, const char * new_name);


#ifdef __cplusplus
}
#endif // extern "C"

#endif // end of _SCI_H_ definition

//
// End of File
//

