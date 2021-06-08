/* Copyright 2019 Ryota Goto
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
 */
#include QMK_KEYBOARD_H


enum custom_keycodes {
  KC_AE = SAFE_RANGE,
  KC_AE_C,
  KC_UE,
  KC_UE_C,
  KC_OE,
  KC_OE_C,
  KC_SS,
  KC_P_M,
  KC_DEG,
  KC_BLLT,
};

#define KC_LOCK LGUI(KC_L) // Windows lock keycombo
#define DSKTP_L LCTL(LGUI(KC_LEFT)) // Windows switch desktops left
#define DSKTP_R LCTL(LGUI(KC_RIGHT)) // Windows switch desktops left
#define T_CAPS LT(10, KC_CAPS) // combo caps / layer 2 button

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( /* Base */

  	KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,        KC_F5,   KC_F6,   KC_F7,   KC_F8,       KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_PSCR, KC_SLCK, KC_LOCK, \
  	KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,           KC_INS,  KC_HOME, KC_PGUP, \
  	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSLS,          KC_DEL,  KC_END,  KC_PGDN, \
  	T_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                   KC_ENT,                                      \
  	KC_LSFT, KC_BSLS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_DEL,                    KC_UP,            \
  	KC_LCTL, KC_LGUI, KC_LALT,                           KC_SPC,                                       KC_RALT, MO(1)  , MO(2)  , KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT  \
    ),

    [1] = LAYOUT(
  	_______,          _______, _______, _______, _______,      _______, _______, _______, _______,     _______, _______, _______, _______,         _______, KC_NLCK, _______, \
  	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, \
  	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,         _______, _______, _______, \
  	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,                                    \
  	MO(3)  , _______, _______, _______, _______, _______, _______, _______, KC_MUTE, _______, _______, _______,          MO(3)  , _______,                  KC_VOLU,          \
  	_______, _______, _______,                            KC_MPLY,                                     _______, _______, KC_APP,  _______,         KC_MPRV, KC_VOLD, KC_MNXT  \
    ),

    [2] = LAYOUT( /* Windows features */
  	_______,          _______, _______, _______, _______,      _______, _______, _______, _______,     _______, _______, _______, _______,         _______, _______, _______, \
  	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEG , _______, KC_P_M , _______, _______,         _______, _______, _______, \
  	_______, _______, _______, _______, _______, _______, _______, KC_UE  , _______, KC_OE  , _______, _______, _______,          _______,         _______, _______, _______, \
  	_______, KC_AE  , KC_SS  , _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,                                    \
  	MO(3)  , _______, _______, _______, _______, _______, _______, _______, KC_MUTE, _______, KC_BLLT, _______,          MO(3)  , _______,                  _______,          \
  	_______, _______, _______,                            KC_MPLY,                                     _______, _______, _______, _______,         DSKTP_L, _______, DSKTP_R  \
    ),

    [3] = LAYOUT( /* Windows features shifted */
  	_______,          _______, _______, _______, _______,      _______, _______, _______, _______,     _______, _______, _______, _______,         _______, _______, _______, \
  	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, \
  	_______, _______, _______, _______, _______, _______, _______, KC_UE_C, _______, KC_OE_C, _______, _______, _______,          _______,         _______, _______, _______, \
  	_______, KC_AE_C, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,                                    \
  	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,                  _______,          \
  	_______, _______, _______,                            _______,                                     _______, _______, _______, _______,         _______, _______, _______  \
    ),

    [10] = LAYOUT( /* Keyboard config layer */
  	_______,          _______, _______, _______, _______,      _______, _______, _______, _______,     _______, _______, _______, _______,         _______, _______, _______, \
  	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, \
  	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,         _______, _______, _______, \
  	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,                                    \
  	_______, _______, _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______,          _______, _______,                  BL_INC ,          \
  	_______, _______, _______,                            _______,                                     _______, _______, _______, _______,         _______, BL_DEC , _______  \
    ),

    /*
    [x] = LAYOUT(
  	_______,          _______, _______, _______, _______,      _______, _______, _______, _______,     _______, _______, _______, _______,         _______, _______, _______, \
  	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, \
  	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,         _______, _______, _______, \
  	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,                                    \
  	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,                  _______,          \
  	_______, _______, _______,                            _______,                                     _______, _______, _______, _______,         _______, _______, _______  \
    ),
    */
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case KC_AE:
        if (record->event.pressed) {
          SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_3) SS_TAP(X_KP_2)));
        }
        break;
      case KC_UE:
        if (record->event.pressed) {
          SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_2) SS_TAP(X_KP_9)));
        }
        break;
      case KC_OE:
        if (record->event.pressed) {
          SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_8)));
        }
        break;
      case KC_AE_C:
        if (record->event.pressed) {
          SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_6)));
        }
        break;
      case KC_UE_C:
        if (record->event.pressed) {
          SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_0)));
        }
        break;
      case KC_OE_C:
        if (record->event.pressed) {
          SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_4)));
        }
        break;
      case KC_SS:
        if (record->event.pressed) {
          SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_3)));
        }
        break;
      case KC_P_M: // plus-minus
        if (record->event.pressed) {
          SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_7)));
        }
        break;
      case KC_DEG: // degree symbol
        if (record->event.pressed) {
          SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_6)));
        }
        break;
      case KC_BLLT: // BULLET symbol
        if (record->event.pressed) {
          SEND_STRING(SS_LALT(SS_TAP(X_KP_7)));
        }
        break;
    }
    return true;
}

void matrix_init_user(void) {
    //backlight_disable();
}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
