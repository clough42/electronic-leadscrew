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

#include "TestKeys.h"

Uint16 light_cycle[][4] = {
       { 0,0,0,1 },
       { 0,0,1,0 },
       { 0,1,0,0 },
       { 1,0,0,0 },
       { 0,1,0,0 },
       { 0,0,1,0 }
};

TestKeys :: TestKeys( void )
{
    this->cycle = 0;
    this->desiredKeys.all = 0;
    this->desiredKeys.bit.KS5K3 = 1;
    this->desiredKeys.bit.KS6K3 = 1;
}

void TestKeys :: initHardware(void)
{

}

void TestKeys :: test(KEY_REG keys, LED_REG *output)
{
    if( keys.all == this->desiredKeys.all ) {
        output->bit.A = light_cycle[cycle][0];
        output->bit.B = light_cycle[cycle][1];
        output->bit.C = light_cycle[cycle][2];
        output->bit.D = light_cycle[cycle][3];

        if( ++cycle >= (sizeof(light_cycle)/sizeof(light_cycle[0])) ) cycle = 0;
    }
}
