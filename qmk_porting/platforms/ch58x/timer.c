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

#include "timer.h"

static uint32_t ticks_offset = 0;

// Generate out-of-line copies for inline functions defined in timer.h.
extern inline fast_timer_t timer_read_fast(void);
extern inline fast_timer_t timer_elapsed_fast(fast_timer_t last);

inline void timer_init(void)
{
    timer_clear();
}

__HIGH_CODE inline uint16_t timer_read(void)
{
    return (uint16_t)(timer_read32() & 0xFFFF);
}

__HIGH_CODE uint32_t timer_read32(void)
{
    return RTC_TO_MS(timer_readraw() - ticks_offset);
}

__HIGH_CODE inline uint64_t timer_read64(void)
{
    return (uint64_t)timer_read32();
}

__HIGH_CODE inline uint16_t timer_elapsed(uint16_t tlast)
{
    return TIMER_DIFF_16(timer_read(), tlast);
}

__HIGH_CODE inline uint32_t timer_elapsed32(uint32_t tlast)
{
    return TIMER_DIFF_32(timer_read32(), tlast);
}

__HIGH_CODE void timer_clear(void)
{
    ticks_offset = timer_readraw();
}

__HIGH_CODE uint32_t timer_readraw(void)
{
    uint32_t i;

    do {
        i = R32_RTC_CNT_32K;
    } while (i != R32_RTC_CNT_32K);

    return (i);
}
