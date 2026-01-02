/*
MIT License - okhi - Open Keylogger Hardware Implant
---------------------------------------------------------------------------
Copyright (c) [2024] by David Reguera Garcia aka Dreg
https://github.com/therealdreg/pico-freq-meter-tcxo-ref
https://github.com/therealdreg/okhi
https://www.rootkit.es
X @therealdreg
dreg@rootkit.es
---------------------------------------------------------------------------
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
---------------------------------------------------------------------------
WARNING: BULLSHIT CODE X-)
---------------------------------------------------------------------------
*/

// I'm still a novice with the Pico SDK & RP2040, so please bear with me if there are unnecessary things ;-)

// This project assumes that copy_to_ram is enabled, so ALL code is running from RAM
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/structs/clocks.h"
#include "hardware/xosc.h"
#include "hardware/clocks.h"

#define FW_VERSION 3

int main()
{
       const uint gpio_clock_out = 21;
       const float divisor = 1.0f;
       clock_gpio_init(gpio_clock_out, CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_VALUE_XOSC_CLKSRC, divisor);

       sleep_ms(500);
       stdio_init_all();
       sleep_ms(3000);

       printf("\nCLOCK OUTPUT for OKHI v%s by Dreg\n"
              "https://github.com/therealdreg/pico-freq-meter-tcxo-ref\n"
              "https://github.com/therealdreg/okhi\n"
              "https://www.rootkit.es\n"
              "X @therealdreg\n\n",
              FW_VERSION);

       gpio_init(20);
       gpio_init(19);
       gpio_init(18);
       gpio_set_dir(20, GPIO_OUT);
       gpio_set_dir(19, GPIO_OUT);
       gpio_set_dir(18, GPIO_OUT);
       gpio_put(20, false);
       gpio_put(19, false);
       gpio_put(18, false);

       printf("GPIO pins 18, 19, 20 set to LOW (connect oscilloscope ground to spring clip)\n");

       while (true)
       {
              printf("\n[clock_out_gpio21] XOSC / %.1f --> %.3f MHz GPIO %d (sniff '-')\n", divisor, 12.0f / divisor,
                     gpio_clock_out);
              sleep_ms(1000);
       }
}
