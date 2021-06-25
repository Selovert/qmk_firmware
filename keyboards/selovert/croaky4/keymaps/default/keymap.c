
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
#include "print.h"

bool micMuted = 0; // Track mic mute state
#define n_led 7 // number of LEDs to toggle while muting
int target_leds[n_led] = {0, 1, 2, 3, 4, 5, 6}; // define LEDs to toggle while muting

// Tapdance states
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD
} td_state_t;

// Create a global instance of the tapdance state type
typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap Dance keycodes
enum td_keycodes {
    TEAMS_MT
};

// Function to determine the current tapdance state
td_state_t cur_dance(qk_tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void teams_mt_finished(qk_tap_dance_state_t *state, void *user_data);
void teams_mt_reset(qk_tap_dance_state_t *state, void *user_data);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
                     KC_MPRV       , KC_MNXT ,
        LT(1,KC_MUTE),
                     TD(TEAMS_MT)  , KC_MPLY
    ),

    [1] = LAYOUT(
                     RESET   , _______ ,
        _______ ,
                     _______ , _______
    )
};

void keyboard_post_init_user(void) {
    debug_enable=true;
}
 // Encoder functions
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch(biton32(layer_state)){ // check layer state
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

// Toggle state of LEDs in array
void toggle_led(int leds[], bool mute_state) {
    if (mute_state) {
        for (int i_led = 0; i_led < n_led; ++i_led) {
            rgblight_setrgb_at(0, 0, 0, leds[i_led]);
        }
    }
    else {
        rgblight_enable();
    }
}

// Teams mute handler
void teams_mute(bool mute_state) {
    if (mute_state) {
        toggle_led(target_leds, mute_state);
        print("Muting");
        tap_code16(C(KC_F13));
    }
    else {
        toggle_led(target_leds, mute_state);
        print("Unmuting");
        tap_code16(C(KC_F13));
    }
}

// Determine the tapdance state to return
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }
    else if (state->count == 2) {
      if (state->interrupted || !state->pressed) return TD_DOUBLE_TAP;
      else return TD_DOUBLE_HOLD;
    }
    else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t'
static td_tap_t td_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Trigger when tapdance finishes (fires at beginning of a hold)
void teams_mt_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state.state = cur_dance(state); // pull number of clicks and hold state
    switch (td_state.state) {
        case TD_SINGLE_TAP:
            micMuted = !micMuted;
            teams_mute(micMuted);
            break;
        case TD_SINGLE_HOLD:
            micMuted = !micMuted;
            teams_mute(micMuted);
            break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
            // Flip state to match computer
            micMuted = !micMuted;
            toggle_led(target_leds, micMuted);
            break;
        case TD_NONE:
        case TD_UNKNOWN:
            break;
    }
}

// Trigger when tapdance resets (fires at end of a hold)
void teams_mt_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state.state) {
        case TD_SINGLE_TAP:
            break;
        case TD_SINGLE_HOLD:
            micMuted = !micMuted;
            teams_mute(micMuted);
            break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
        case TD_NONE:
        case TD_UNKNOWN:
            break;
    }
    td_state.state = TD_NONE;
}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TEAMS_MT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, teams_mt_finished, teams_mt_reset)
};
