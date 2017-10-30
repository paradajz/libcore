#pragma once

#include <util/atomic.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/cpufunc.h>
#include <avr/wdt.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include <assert.h>

#include "helpers/Helpers.h"
#include "timing/Timing.h"
#include "uart/UART.h"
#include "adc/ADC.h"
#include "reset/Reset.h"
#include "spi/SPI.h"
