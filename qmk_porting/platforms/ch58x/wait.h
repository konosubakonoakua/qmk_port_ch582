/*
Copyright 2022 Huckies <https://github.com/Huckies>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

#define wait_ms(ms) DelayMs(ms)
#define wait_us(us) DelayUs(us)

#ifndef GPIO_INPUT_PIN_DELAY
#define GPIO_INPUT_PIN_DELAY (FREQ_SYS / 1000000L / 8)
#endif
#ifndef MATRIX_IO_DELAY
#define MATRIX_IO_DELAY 5
#endif

#define waitInputPinDelay() SAFEOPERATE;

#ifdef __cplusplus
}
#endif
