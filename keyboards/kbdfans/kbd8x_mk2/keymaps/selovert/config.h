/*
Copyright 2019 Ryota Goto

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

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xA103
#define PRODUCT_ID      0x0005
#define DEVICE_VER      0x0001
#define MANUFACTURER    KBDfans
#define PRODUCT         KBD8X-MKII

/* key matrix size */
#define MATRIX_ROWS 12
#define MATRIX_COLS 9

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/
#define MATRIX_ROW_PINS { C6, B6, B5, B4, D7, D6, D4, D5, D3, D2, D1, D0 }
#define MATRIX_COL_PINS { F0, F1, F4, F5, F6, F7, C7, B0, B1 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

#define LED_CAPS_LOCK_PIN E6
#define LED_SCROLL_LOCK_PIN B2
#define LED_PIN_ON_STATE 0

#define BACKLIGHT_PIN B7
#ifdef BACKLIGHT_PIN
#define BACKLIGHT_ON_STATE 1
#define BACKLIGHT_DRIVER = pwm
// #define BACKLIGHT_BREATHING
// #define BACKLIGHT_LEVELS 8
#endif
#define RGB_DI_PIN B3
#ifdef RGB_DI_PIN
  #define RGBLED_NUM 20
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_LIMIT_VAL 200 /* The maximum brightness level */
  #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
/*== all animations enable ==*/
  #define RGBLIGHT_ANIMATIONS
// /*== or choose animations ==*/
//   #define RGBLIGHT_EFFECT_BREATHING
//   #define RGBLIGHT_EFFECT_RAINBOW_MOOD
//   #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//   #define RGBLIGHT_EFFECT_SNAKE
//   #define RGBLIGHT_EFFECT_KNIGHT
//   #define RGBLIGHT_EFFECT_CHRISTMAS
//   #define RGBLIGHT_EFFECT_STATIC_GRADIENT
//   #define RGBLIGHT_EFFECT_RGB_TEST
//   #define RGBLIGHT_EFFECT_ALTERNATING
// /*== customize breathing effect ==*/
//   /*==== (DEFAULT) use fixed table instead of exp() and sin() ====*/
//   #define RGBLIGHT_BREATHE_TABLE_SIZE 256      // 256(default) or 128 or 64
//   /*==== use exp() and sin() ====*/
//   #define RGBLIGHT_EFFECT_BREATHE_CENTER 1.85  // 1 to 2.7
//   #define RGBLIGHT_EFFECT_BREATHE_MAX    255   // 0 to 255
#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* If defined, GRAVE_ESC will always act as ESC when CTRL is held.
 * This is userful for the Windows task manager shortcut (ctrl+shift+esc).
 */
// #define GRAVE_ESC_CTRL_OVERRIDE

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during a
 * power-up.
 *
 */
//#define FORCE_NKRO

/*
 * Magic Key Options
 *
 * Magic keys are hotkey commands that allow control over firmware functions of
 * the keyboard. They are best used in combination with the HID Listen program,
 * found here: https://www.pjrc.com/teensy/hid_listen.html
 *
 * The options below allow the magic key functionality to be changed. This is
 * useful if your keyboard/keypad is missing keys and you want magic key support.
 *
 */

/* key combination for magic key command */
/* defined by default; to change, uncomment and set to the combination you want */
// #define IS_COMMAND() (get_mods() == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)))

/* control how magic key switches layers */
//#define MAGIC_KEY_SWITCH_LAYER_WITH_FKEYS  true
//#define MAGIC_KEY_SWITCH_LAYER_WITH_NKEYS  true
//#define MAGIC_KEY_SWITCH_LAYER_WITH_CUSTOM false

/* override magic key keymap */
//#define MAGIC_KEY_SWITCH_LAYER_WITH_FKEYS
//#define MAGIC_KEY_SWITCH_LAYER_WITH_NKEYS
//#define MAGIC_KEY_SWITCH_LAYER_WITH_CUSTOM
//#define MAGIC_KEY_HELP           H
//#define MAGIC_KEY_HELP_ALT       SLASH
//#define MAGIC_KEY_DEBUG          D
//#define MAGIC_KEY_DEBUG_MATRIX   X
//#define MAGIC_KEY_DEBUG_KBD      K
//#define MAGIC_KEY_DEBUG_MOUSE    M
//#define MAGIC_KEY_VERSION        V
//#define MAGIC_KEY_STATUS         S
//#define MAGIC_KEY_CONSOLE        C
//#define MAGIC_KEY_LAYER0         0
//#define MAGIC_KEY_LAYER0_ALT     GRAVE
//#define MAGIC_KEY_LAYER1         1
//#define MAGIC_KEY_LAYER2         2
//#define MAGIC_KEY_LAYER3         3
//#define MAGIC_KEY_LAYER4         4
//#define MAGIC_KEY_LAYER5         5
//#define MAGIC_KEY_LAYER6         6
//#define MAGIC_KEY_LAYER7         7
//#define MAGIC_KEY_LAYER8         8
//#define MAGIC_KEY_LAYER9         9
//#define MAGIC_KEY_BOOTLOADER     B
//#define MAGIC_KEY_BOOTLOADER_ALT ESC
//#define MAGIC_KEY_LOCK           CAPS
//#define MAGIC_KEY_EEPROM         E
//#define MAGIC_KEY_EEPROM_CLEAR   BSPACE
//#define MAGIC_KEY_NKRO           N
//#define MAGIC_KEY_SLEEP_LED      Z

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/
//#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 1

/* Bootmagic Lite key configuration */
// #define BOOTMAGIC_LITE_ROW 0
// #define BOOTMAGIC_LITE_COLUMN 0
