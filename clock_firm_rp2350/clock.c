#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/structs/clocks.h"
#include "hardware/xosc.h"
#include "hardware/clocks.h"

#define  FW_VERSION 3 

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

    while (true)
    {
        printf("\n[clock_out_gpio21] XOSC / %.1f --> %.3f MHz GPIO %d (sniff '-')\n", divisor, 12.0f / divisor,
               gpio_clock_out);
        sleep_ms(1000);
    }
}
