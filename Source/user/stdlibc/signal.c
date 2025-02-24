/*
*  license and disclaimer for the use of this source code as per statement below
*  Lizenz und Haftungsausschluss f�r die Verwendung dieses Sourcecodes siehe unten
*/

#include "signal.h"
#include "stdlib.h"


static void dummy(int i) {}

void (*SIG_DFL)(int) = (void*)1; // HACK, but maybe best way to solve the problem of having different standard functions for different signals
void (*SIG_IGN)(int) = &dummy;

void (*signals[_SIGNUM])(int) = {&exit, &dummy, &dummy, &dummy, &dummy, &exit};
void (*signal_defaults[_SIGNUM])(int) = {&exit, &dummy, &dummy, &dummy, &dummy, &exit};


void (*signal(int sig, void (*func)(int)))(int)
{
    if (func == SIG_DFL)
        signals[sig] = signal_defaults[sig];
    else
        signals[sig] = func;
    return (signals[sig]);
}

int raise(int sig)
{
    if (sig < _SIGNUM)
    {
        signals[sig](sig);
        return (0);
    }
    return (-1);
}


/*
* Copyright (c) 2010-2013 The PrettyOS Project. All rights reserved.
*
* http://www.c-plusplus.de/forum/viewforum-var-f-is-62.html
*
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
*
* 1. Redistributions of source code must retain the above copyright notice,
*    this list of conditions and the following disclaimer.
*
* 2. Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the distribution.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
* TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
* PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR
* CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
* OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
* OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
* ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
