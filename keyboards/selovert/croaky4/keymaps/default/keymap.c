
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

enum custom_keycodes {
    MUTEMIC = SAFE_RANGE,
};

bool micMuted = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
                     LT(1,KC_MPRV) , KC_MNXT ,
        KC_MUTE    ,
                     MUTEMIC       , KC_MPLY
    ),

    [1] = LAYOUT(
                     _______ , _______ ,
        RESET      ,
                     _______ , _______
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch(biton32(layer_state)){
        case 0:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;
        case 1:
            if (clockwise) {
                rgblight_increase_val();
            } else {
                rgblight_decrease_val();
            }
            break;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MUTEMIC:
        if (record->event.pressed) {
          micMuted = !micMuted;
            if (micMuted) {
              rgblight_setrgb_at(0, 0, 0, 2);
            } else {
              // rgblight_setrgb_at(255, 255, 255, 2);
              rgblight_enable();
            }
        } else {
          break;
        }
            break;
    }
    return true;
}
