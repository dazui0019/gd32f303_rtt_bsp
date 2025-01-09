/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-08-20     BruceOu      first implementation
 */

#include <stdio.h>
#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>

#include "driver_w25qxx_basic.h"

/* defined the LED0 pin: PC13 */
#define LED0_PIN GET_PIN(C, 13)

int main(void)
{
    int count = 1;

    /* set LED2 pin mode to output */
    rt_pin_mode(LED0_PIN, PIN_MODE_OUTPUT);
    rt_pin_write(LED0_PIN, PIN_HIGH);

    w25qxx_basic_init(W25Q128, W25QXX_INTERFACE_SPI, W25QXX_BOOL_FALSE);
    // w25qxx_interface_spi_qspi_init();

    while (count++)
    {
        rt_pin_write(LED0_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED0_PIN, PIN_LOW);
        rt_thread_mdelay(500);
    }

    return RT_EOK;
}
