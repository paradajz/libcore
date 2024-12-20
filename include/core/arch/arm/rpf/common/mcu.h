/*
    Copyright 2017-2022 Igor Petrovic

    Permission is hereby granted, free of charge, to any person obtaining
    a copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
    sell copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
    OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

#include <array>
#include "atomic.h"
#include "peripherals.h"
#include "core/arch/common/adc.h"
#include "core/arch/common/bootloader.h"
#include "core/arch/common/i2c.h"
#include "core/arch/common/clocks.h"
#include "core/arch/common/flash.h"
#include "core/arch/common/isr.h"
#include "core/arch/common/timers.h"
#include "core/arch/common/timing.h"
#include "core/arch/common/uart.h"
#include "core/error_handler.h"
#include "core/arch/common/usb/usb.h"
#include "core/arch/common/mcu.h"
#include "RP2040/Include/RP2040.h"
#include "pico/unique_id.h"
#include "hardware/irq.h"

namespace core::mcu
{
    inline void init(initType_t initType = initType_t::APP)
    {
        // Clear out most of the ISR handlers on startup:
        // relevant when jumping from bootloader to app.
        irq_remove_handler(TIMER_IRQ_0, irq_get_vtable_handler(TIMER_IRQ_0));
        irq_remove_handler(TIMER_IRQ_1, irq_get_vtable_handler(TIMER_IRQ_1));
        irq_remove_handler(TIMER_IRQ_2, irq_get_vtable_handler(TIMER_IRQ_2));
        irq_remove_handler(TIMER_IRQ_3, irq_get_vtable_handler(TIMER_IRQ_3));
        irq_remove_handler(PWM_IRQ_WRAP, irq_get_vtable_handler(PWM_IRQ_WRAP));
        irq_remove_handler(USBCTRL_IRQ, irq_get_vtable_handler(USBCTRL_IRQ));
        irq_remove_handler(XIP_IRQ, irq_get_vtable_handler(XIP_IRQ));
        irq_remove_handler(PIO0_IRQ_0, irq_get_vtable_handler(PIO0_IRQ_0));
        irq_remove_handler(PIO0_IRQ_1, irq_get_vtable_handler(PIO0_IRQ_1));
        irq_remove_handler(PIO1_IRQ_0, irq_get_vtable_handler(PIO1_IRQ_0));
        irq_remove_handler(PIO1_IRQ_1, irq_get_vtable_handler(PIO1_IRQ_1));
        irq_remove_handler(DMA_IRQ_0, irq_get_vtable_handler(DMA_IRQ_0));
        irq_remove_handler(DMA_IRQ_1, irq_get_vtable_handler(DMA_IRQ_1));
        irq_remove_handler(IO_IRQ_BANK0, irq_get_vtable_handler(IO_IRQ_BANK0));
        irq_remove_handler(IO_IRQ_QSPI, irq_get_vtable_handler(IO_IRQ_QSPI));
        irq_remove_handler(SIO_IRQ_PROC0, irq_get_vtable_handler(SIO_IRQ_PROC0));
        irq_remove_handler(SIO_IRQ_PROC1, irq_get_vtable_handler(SIO_IRQ_PROC1));
        irq_remove_handler(CLOCKS_IRQ, irq_get_vtable_handler(CLOCKS_IRQ));
        irq_remove_handler(SPI0_IRQ, irq_get_vtable_handler(SPI0_IRQ));
        irq_remove_handler(SPI1_IRQ, irq_get_vtable_handler(SPI1_IRQ));
        irq_remove_handler(I2C0_IRQ, irq_get_vtable_handler(I2C0_IRQ));
        irq_remove_handler(I2C1_IRQ, irq_get_vtable_handler(I2C1_IRQ));
        irq_remove_handler(RTC_IRQ, irq_get_vtable_handler(RTC_IRQ));
        irq_remove_handler(ADC_IRQ_FIFO, irq_get_vtable_handler(ADC_IRQ_FIFO));
        irq_remove_handler(UART0_IRQ, irq_get_vtable_handler(UART0_IRQ));
        irq_remove_handler(UART1_IRQ, irq_get_vtable_handler(UART1_IRQ));

        irq_set_exclusive_handler(
            UART0_IRQ, []()
            {
                core::mcu::isr::uart(0);
            });

        irq_set_exclusive_handler(
            UART1_IRQ, []()
            {
                core::mcu::isr::uart(1);
            });

        timers::init();
        timing::init();
    }

    inline void deInit()
    {
        core::mcu::timers::stopAll();
    }

    inline void reset()
    {
        NVIC_SystemReset();
    }

    inline void uniqueID(uniqueID_t& uid)
    {
        pico_unique_board_id_t pico_uid;
        pico_get_unique_board_id(&pico_uid);

        for (int i = 0; i < 8; i++)
        {
            uid[i] = pico_uid.id[i];
        }
    }

    inline void idle()
    {
    }
}    // namespace core::mcu