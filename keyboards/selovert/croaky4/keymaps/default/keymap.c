
/* Copyright 2020 Selovert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.

 * qmk compile -kb selovert/croaky4 -km default

 */
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
                     LT(1,KC_MPRV) , KC_MNXT ,
        KC_MUTE    ,
                     XXXXXXX       , KC_MPLY
    ),

    [1] = LAYOUT(
                     _______ , _______ ,
        RGB_TOG    ,
                     _______ , _______
    )
};

void encoder_update_user(uint8_t index, bool clockwise) {
    switch(biton32(layer_state)){
        case 0:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        case 1:
            if (clockwise) {
                rgblight_increase_val();
            } else {
                rgblight_decrease_val();
            }
    }
}
