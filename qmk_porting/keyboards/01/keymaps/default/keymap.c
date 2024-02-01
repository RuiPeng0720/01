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

#include QMK_KEYBOARD_H
#include "extra_keycode.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_all(/* 0: qwerty */
                    KC_ESC, KC_1, KC_2, KC_3, KC_4,KC_5,  
                    MO(1) , KC_Q, KC_W, KC_E, KC_R, KC_T,  
                    KC_CAPS, KC_A, KC_S, KC_D, KC_F,KC_G,  
                    KC_LSFT, KC_Z, KC_Z, KC_X, KC_C,KC_V,  
                    RGB_MOD, KC_LGUI, KC_LALT, KC_C, KC_V, KC_SPC
                    ),
    [1] = LAYOUT_all(/* 1: fn */
                    KC_ESC, KC_1, KC_2, KC_3, KC_4,
                    MO(1) , KC_G, KC_W, KC_E, KC_R, 
                    KC_CAPS, KC_A, KC_S, KC_D, KC_F,
                    KC_LSFT, KC_Z, KC_X, KC_C, KC_V,
                    KC_LSFT, KC_Z, KC_X, KC_C, KC_V,
                    KC_LSFT, KC_Z, KC_X, KC_C, KC_V  
                    ),                   
    [2] = LAYOUT_all(/* 2: fn */
                    QK_GESC, KC_1, KC_2, KC_3, KC_4,
                    MO(1) , KC_Q, KC_W, KC_E, KC_R, 
                    KC_CAPS, KC_A, KC_S, KC_D, KC_F,
                    KC_LSFT, KC_Z, KC_X, KC_C, KC_V,
                    KC_LSFT, KC_Z, KC_X, KC_C, KC_V,
                    KC_LSFT, KC_Z, KC_X, KC_C, KC_V  
                    ),
    [3] = LAYOUT_all(/* 3: fn */
                    QK_GESC, KC_1, KC_2, KC_3, KC_4,
                    MO(1) , KC_Q, KC_W, KC_E, KC_R, 
                    KC_CAPS, KC_A, KC_S, KC_D, KC_F,
                    KC_LSFT, KC_Z, KC_X, KC_C, KC_V,
                    KC_LSFT, KC_Z, KC_X, KC_C, KC_V,
                    KC_LSFT, KC_Z, KC_X, KC_C, KC_V  
                    ),
};
