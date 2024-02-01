/*
Copyright 2022 Huckies <https://github.com/Huckies>
Copyright 2023 OctopusZ <https://github.com/OctopusZ>

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

#include QMK_KEYBOARD_H

#ifdef RGB_MATRIX_ENABLE
/* clang-format off */
const aw20216s_led_t g_aw20216s_leds[RGB_MATRIX_LED_COUNT] = {
/* Refer to AW20216S manual for these locations
 *   driver
 *   |     R location
 *   |     |          G location
 *   |     |          |          B location
 *   |     |          |          | */
	{0, CS3_SW3 ,   CS1_SW3 ,   CS2_SW3	},
	{0, CS3_SW2 ,   CS1_SW2 ,   CS2_SW2	},
	{0, CS3_SW1 ,   CS1_SW1 ,   CS2_SW1	},
	{1, CS3_SW3 ,   CS1_SW3 ,   CS2_SW3	},
	{1, CS3_SW2 ,   CS1_SW2 ,   CS2_SW2	},
	{1, CS3_SW1 ,   CS1_SW1 ,   CS2_SW1	},

	{0, CS6_SW3 ,   CS4_SW3 ,   CS5_SW3	},
	{0, CS6_SW2 ,   CS4_SW2 ,   CS5_SW2	},
	{0, CS6_SW1 ,   CS4_SW1 ,   CS5_SW1	},
	{1, CS6_SW3 ,   CS4_SW3 ,   CS5_SW3	},
	{1, CS6_SW2 ,   CS4_SW2 ,   CS5_SW2	},
	{1, CS6_SW1 ,   CS4_SW1 ,   CS5_SW1	},

	{0, CS9_SW3 ,   CS7_SW3 ,   CS8_SW3	},
	{0, CS9_SW2 ,   CS7_SW2 ,   CS8_SW2	},
	{0, CS9_SW1 ,   CS7_SW1 ,   CS8_SW1	},
	{1, CS9_SW3 ,   CS7_SW3 ,   CS8_SW3	},
	{1, CS9_SW2 ,   CS7_SW2 ,   CS8_SW2	},
	{1, CS9_SW1 ,   CS7_SW1 ,   CS8_SW1 },

	{0, CS12_SW3 ,   CS10_SW3 ,   CS11_SW3	},
	{0, CS12_SW2 ,   CS10_SW2 ,   CS11_SW2	},
	{0, CS12_SW1 ,   CS10_SW1 ,   CS11_SW1	},
	{1, CS12_SW3 ,   CS10_SW3 ,   CS11_SW3	},
	{1, CS12_SW2 ,   CS10_SW2 ,   CS11_SW2	},
	{1, CS12_SW1 ,   CS10_SW1 ,   CS11_SW1 	},

	{0, CS15_SW3 ,   CS13_SW3 ,   CS14_SW3	},
	{0, CS15_SW2 ,   CS13_SW2 ,   CS14_SW2	},
	{0, CS15_SW1 ,   CS13_SW1 ,   CS14_SW1	},
	{1, CS15_SW3 ,   CS13_SW3 ,   CS14_SW3	},
	{1, CS15_SW2 ,   CS13_SW2 ,   CS14_SW2	},
	{1, CS15_SW1 ,   CS13_SW1 ,   CS14_SW1 	}
};
led_config_t g_led_config = {
	{
		{0, 1, 2, 3, 4, 5}, 
		{6, 7, 8, 9, 10, 11}, 
		{12, 13, 14, 15, 16, 17}, 
		{18, 19, 20, 21, 22, 23}, 
		{24, 25, 26, 27, 28, 29}

	}, {
		{0,0},{75,0},{149,0},{200,0},{224,0},
		{0,16},{75,16},{149,16},{200,16},{224,16},    
		{0,32},{75,32},{149,32},{200,32},{224,32},
		{0,48},{75,48},{149,48},{200,48},{224,48},
		{0,64},{75,64},{149,64},{200,64},{224,64}

	}, {
		4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4
	}
};
/* clang-format on */
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max)
{
    if (led_min <= 0 && led_max > 0 && host_keyboard_led_state().num_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(0, 0xFF, 0x00, 0x00);
    }

    return true;
}
#endif


int main()
{
    extern void protocol_setup();
    extern void protocol_init();
    extern void protocol_task();

    platform_setup();

    protocol_setup();
#if !defined ESB_ENABLE || ESB_ENABLE != 2
    keyboard_setup();
#endif

    protocol_init();

    /* Main loop */
    for (;;) {
        protocol_task();
        //! housekeeping_task() is handled by platform
    }
}
