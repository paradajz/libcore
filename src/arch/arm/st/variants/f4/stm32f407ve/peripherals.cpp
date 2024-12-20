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

#include "core/arch/arm/st/common/peripherals.h"

namespace
{
    class UARTdescriptor0 : public core::mcu::peripherals::Descriptor
    {
        public:
        UARTdescriptor0() = default;

        std::vector<core::mcu::io::pin_t> pins() override
        {
            return _pins;
        }

        void* interface() override
        {
            return USART1;
        }

        IRQn_Type irqn() override
        {
            return _irqn;
        }

        void enableClock() override
        {
            __HAL_RCC_USART1_CLK_ENABLE();
        }

        void disableClock() override
        {
            __HAL_RCC_USART1_CLK_DISABLE();
        }

        private:
        std::vector<core::mcu::io::pin_t> _pins = {
            // rx
            {
                CORE_MCU_IO_PIN_PORT_DEF(A),
                CORE_MCU_IO_PIN_INDEX_DEF(10),
                core::mcu::io::pinMode_t::ALTERNATE_PP,
                core::mcu::io::pullMode_t::NONE,
                core::mcu::io::gpioSpeed_t::VERY_HIGH,
                GPIO_AF7_USART1,
            },

            // tx
            {
                CORE_MCU_IO_PIN_PORT_DEF(A),
                CORE_MCU_IO_PIN_INDEX_DEF(9),
                core::mcu::io::pinMode_t::ALTERNATE_PP,
                core::mcu::io::pullMode_t::NONE,
                core::mcu::io::gpioSpeed_t::VERY_HIGH,
                GPIO_AF7_USART1,
            },
        };

        const IRQn_Type _irqn = USART1_IRQn;
    } _uartDescriptor0;

    class UARTdescriptor1 : public core::mcu::peripherals::Descriptor
    {
        public:
        UARTdescriptor1() = default;

        std::vector<core::mcu::io::pin_t> pins() override
        {
            return _pins;
        }

        void* interface() override
        {
            return USART2;
        }

        IRQn_Type irqn() override
        {
            return _irqn;
        }

        void enableClock() override
        {
            __HAL_RCC_USART2_CLK_ENABLE();
        }

        void disableClock() override
        {
            __HAL_RCC_USART2_CLK_DISABLE();
        }

        private:
        std::vector<core::mcu::io::pin_t> _pins = {
            // rx
            {
                CORE_MCU_IO_PIN_PORT_DEF(D),
                CORE_MCU_IO_PIN_INDEX_DEF(6),
                core::mcu::io::pinMode_t::ALTERNATE_PP,
                core::mcu::io::pullMode_t::NONE,
                core::mcu::io::gpioSpeed_t::VERY_HIGH,
                GPIO_AF7_USART2,
            },

            // tx
            {
                CORE_MCU_IO_PIN_PORT_DEF(D),
                CORE_MCU_IO_PIN_INDEX_DEF(5),
                core::mcu::io::pinMode_t::ALTERNATE_PP,
                core::mcu::io::pullMode_t::NONE,
                core::mcu::io::gpioSpeed_t::VERY_HIGH,
                GPIO_AF7_USART2,
            },
        };

        const IRQn_Type _irqn = USART2_IRQn;
    } _uartDescriptor1;

    class UARTdescriptor2 : public core::mcu::peripherals::Descriptor
    {
        public:
        UARTdescriptor2() = default;

        std::vector<core::mcu::io::pin_t> pins() override
        {
            return _pins;
        }

        void* interface() override
        {
            return USART3;
        }

        IRQn_Type irqn() override
        {
            return _irqn;
        }

        void enableClock() override
        {
            __HAL_RCC_USART3_CLK_ENABLE();
        }

        void disableClock() override
        {
            __HAL_RCC_USART3_CLK_DISABLE();
        }

        private:
        std::vector<core::mcu::io::pin_t> _pins = {
            // rx
            {
                CORE_MCU_IO_PIN_PORT_DEF(D),
                CORE_MCU_IO_PIN_INDEX_DEF(9),
                core::mcu::io::pinMode_t::ALTERNATE_PP,
                core::mcu::io::pullMode_t::NONE,
                core::mcu::io::gpioSpeed_t::VERY_HIGH,
                GPIO_AF7_USART3,
            },

            // tx
            {
                CORE_MCU_IO_PIN_PORT_DEF(D),
                CORE_MCU_IO_PIN_INDEX_DEF(8),
                core::mcu::io::pinMode_t::ALTERNATE_PP,
                core::mcu::io::pullMode_t::NONE,
                core::mcu::io::gpioSpeed_t::VERY_HIGH,
                GPIO_AF7_USART3,
            },
        };

        const IRQn_Type _irqn = USART3_IRQn;
    } _uartDescriptor2;

    class UARTdescriptor3 : public core::mcu::peripherals::Descriptor
    {
        public:
        UARTdescriptor3() = default;

        std::vector<core::mcu::io::pin_t> pins() override
        {
            return _pins;
        }

        void* interface() override
        {
            return UART4;
        }

        IRQn_Type irqn() override
        {
            return _irqn;
        }

        void enableClock() override
        {
            __HAL_RCC_UART4_CLK_ENABLE();
        }

        void disableClock() override
        {
            __HAL_RCC_UART4_CLK_DISABLE();
        }

        private:
        std::vector<core::mcu::io::pin_t> _pins = {
            // rx
            {
                CORE_MCU_IO_PIN_PORT_DEF(C),
                CORE_MCU_IO_PIN_INDEX_DEF(11),
                core::mcu::io::pinMode_t::ALTERNATE_PP,
                core::mcu::io::pullMode_t::NONE,
                core::mcu::io::gpioSpeed_t::VERY_HIGH,
                GPIO_AF8_UART4,
            },

            // tx
            {
                CORE_MCU_IO_PIN_PORT_DEF(C),
                CORE_MCU_IO_PIN_INDEX_DEF(10),
                core::mcu::io::pinMode_t::ALTERNATE_PP,
                core::mcu::io::pullMode_t::NONE,
                core::mcu::io::gpioSpeed_t::VERY_HIGH,
                GPIO_AF8_UART4,
            },
        };

        const IRQn_Type _irqn = UART4_IRQn;
    } _uartDescriptor3;

    class UARTdescriptor4 : public core::mcu::peripherals::Descriptor
    {
        public:
        UARTdescriptor4() = default;

        std::vector<core::mcu::io::pin_t> pins() override
        {
            return _pins;
        }

        void* interface() override
        {
            return UART5;
        }

        IRQn_Type irqn() override
        {
            return _irqn;
        }

        void enableClock() override
        {
            __HAL_RCC_UART5_CLK_ENABLE();
        }

        void disableClock() override
        {
            __HAL_RCC_UART5_CLK_DISABLE();
        }

        private:
        std::vector<core::mcu::io::pin_t> _pins = {
            // rx
            {
                CORE_MCU_IO_PIN_PORT_DEF(D),
                CORE_MCU_IO_PIN_INDEX_DEF(2),
                core::mcu::io::pinMode_t::ALTERNATE_PP,
                core::mcu::io::pullMode_t::NONE,
                core::mcu::io::gpioSpeed_t::VERY_HIGH,
                GPIO_AF8_UART5,
            },

            // tx
            {
                CORE_MCU_IO_PIN_PORT_DEF(C),
                CORE_MCU_IO_PIN_INDEX_DEF(12),
                core::mcu::io::pinMode_t::ALTERNATE_PP,
                core::mcu::io::pullMode_t::NONE,
                core::mcu::io::gpioSpeed_t::VERY_HIGH,
                GPIO_AF8_UART5,
            },
        };

        const IRQn_Type _irqn = UART5_IRQn;
    } _uartDescriptor4;

    class UARTdescriptor5 : public core::mcu::peripherals::Descriptor
    {
        public:
        UARTdescriptor5() = default;

        std::vector<core::mcu::io::pin_t> pins() override
        {
            return _pins;
        }

        void* interface() override
        {
            return USART6;
        }

        IRQn_Type irqn() override
        {
            return _irqn;
        }

        void enableClock() override
        {
            __HAL_RCC_USART6_CLK_ENABLE();
        }

        void disableClock() override
        {
            __HAL_RCC_USART6_CLK_DISABLE();
        }

        private:
        std::vector<core::mcu::io::pin_t> _pins = {
            // rx
            {
                CORE_MCU_IO_PIN_PORT_DEF(C),
                CORE_MCU_IO_PIN_INDEX_DEF(7),
                core::mcu::io::pinMode_t::ALTERNATE_PP,
                core::mcu::io::pullMode_t::NONE,
                core::mcu::io::gpioSpeed_t::VERY_HIGH,
                GPIO_AF8_USART6,
            },

            // tx
            {
                CORE_MCU_IO_PIN_PORT_DEF(C),
                CORE_MCU_IO_PIN_INDEX_DEF(6),
                core::mcu::io::pinMode_t::ALTERNATE_PP,
                core::mcu::io::pullMode_t::NONE,
                core::mcu::io::gpioSpeed_t::VERY_HIGH,
                GPIO_AF8_USART6,
            },
        };

        const IRQn_Type _irqn = USART6_IRQn;
    } _uartDescriptor5;

    class I2Cdescriptor0 : public core::mcu::peripherals::Descriptor
    {
        public:
        I2Cdescriptor0() = default;

        std::vector<core::mcu::io::pin_t> pins() override
        {
            return _pins;
        }

        void* interface() override
        {
            return I2C1;
        }

        IRQn_Type irqn() override
        {
            return _irqn;
        }

        void enableClock() override
        {
            __HAL_RCC_I2C1_CLK_ENABLE();
        }

        void disableClock() override
        {
            __HAL_RCC_I2C1_CLK_DISABLE();
        }

        private:
        std::vector<core::mcu::io::pin_t> _pins = {
            // sda
            {
                CORE_MCU_IO_PIN_PORT_DEF(B),
                CORE_MCU_IO_PIN_INDEX_DEF(7),
                core::mcu::io::pinMode_t::ALTERNATE_OD,
                core::mcu::io::pullMode_t::UP,
                core::mcu::io::gpioSpeed_t::VERY_HIGH,
                GPIO_AF4_I2C1,
            },

            // scl
            {
                CORE_MCU_IO_PIN_PORT_DEF(B),
                CORE_MCU_IO_PIN_INDEX_DEF(6),
                core::mcu::io::pinMode_t::ALTERNATE_OD,
                core::mcu::io::pullMode_t::UP,
                core::mcu::io::gpioSpeed_t::VERY_HIGH,
                GPIO_AF4_I2C1,
            },

        };

        const IRQn_Type _irqn = static_cast<IRQn_Type>(0);
    } _i2cDescriptor0;

    class I2Cdescriptor1 : public core::mcu::peripherals::Descriptor
    {
        public:
        I2Cdescriptor1() = default;

        std::vector<core::mcu::io::pin_t> pins() override
        {
            return _pins;
        }

        void* interface() override
        {
            return I2C2;
        }

        IRQn_Type irqn() override
        {
            return _irqn;
        }

        void enableClock() override
        {
            __HAL_RCC_I2C2_CLK_ENABLE();
        }

        void disableClock() override
        {
            __HAL_RCC_I2C2_CLK_DISABLE();
        }

        private:
        std::vector<core::mcu::io::pin_t> _pins = {
            // sda
            {
                CORE_MCU_IO_PIN_PORT_DEF(B),
                CORE_MCU_IO_PIN_INDEX_DEF(11),
                core::mcu::io::pinMode_t::ALTERNATE_OD,
                core::mcu::io::pullMode_t::UP,
                core::mcu::io::gpioSpeed_t::VERY_HIGH,
                GPIO_AF4_I2C2,
            },

            // scl
            {
                CORE_MCU_IO_PIN_PORT_DEF(B),
                CORE_MCU_IO_PIN_INDEX_DEF(10),
                core::mcu::io::pinMode_t::ALTERNATE_OD,
                core::mcu::io::pullMode_t::UP,
                core::mcu::io::gpioSpeed_t::VERY_HIGH,
                GPIO_AF4_I2C2,
            },
        };

        const IRQn_Type _irqn = static_cast<IRQn_Type>(0);
    } _i2cDescriptor1;

    class I2Cdescriptor2 : public core::mcu::peripherals::Descriptor
    {
        public:
        I2Cdescriptor2() = default;

        std::vector<core::mcu::io::pin_t> pins() override
        {
            return _pins;
        }

        void* interface() override
        {
            return I2C3;
        }

        IRQn_Type irqn() override
        {
            return _irqn;
        }

        void enableClock() override
        {
            __HAL_RCC_I2C3_CLK_ENABLE();
        }

        void disableClock() override
        {
            __HAL_RCC_I2C3_CLK_DISABLE();
        }

        private:
        std::vector<core::mcu::io::pin_t> _pins = {
            // sda
            {
                CORE_MCU_IO_PIN_PORT_DEF(C),
                CORE_MCU_IO_PIN_INDEX_DEF(9),
                core::mcu::io::pinMode_t::ALTERNATE_OD,
                core::mcu::io::pullMode_t::UP,
                core::mcu::io::gpioSpeed_t::VERY_HIGH,
                GPIO_AF4_I2C3,
            },

            // scl
            {
                CORE_MCU_IO_PIN_PORT_DEF(A),
                CORE_MCU_IO_PIN_INDEX_DEF(8),
                core::mcu::io::pinMode_t::ALTERNATE_OD,
                core::mcu::io::pullMode_t::UP,
                core::mcu::io::gpioSpeed_t::VERY_HIGH,
                GPIO_AF4_I2C3,
            },
        };

        const IRQn_Type _irqn = static_cast<IRQn_Type>(0);
    } _i2cDescriptor2;

    core::mcu::peripherals::Descriptor* _uartDescriptor[CORE_MCU_MAX_UART_INTERFACES] = {
        &_uartDescriptor0,
        &_uartDescriptor1,
        &_uartDescriptor2,
        &_uartDescriptor3,
        &_uartDescriptor4,
        &_uartDescriptor5,
    };

    core::mcu::peripherals::Descriptor* _i2cDescriptor[CORE_MCU_MAX_I2C_INTERFACES] = {
        &_i2cDescriptor0,
        &_i2cDescriptor1,
        &_i2cDescriptor2
    };
}    // namespace

#include "../common/peripherals.cpp.include"