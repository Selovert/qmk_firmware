#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID     0xFEED
#define PRODUCT_ID    0x6611
#define DEVICE_VER    0x0001
#define MANUFACTURER  Selovert
#define PRODUCT       Selovert
#define DESCRIPTION   A macropad with 4 keys and an encoder

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 5

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
#define DIODE_DIRECTION COL2ROW
#define MATRIX_ROW_PINS { D4 }
#define MATRIX_COL_PINS { D0, D1, D3, D2 , D5}
#define UNUSED_PINS

#define RGB_DI_PIN D6
#define RGBLED_NUM 7

#define ENCODERS_PAD_A { B2 }
#define ENCODERS_PAD_B { B1 }
#define ENCODER_RESOLUTION 2
