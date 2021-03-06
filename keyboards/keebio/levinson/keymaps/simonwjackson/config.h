/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2018 Danny Nguyen <danny@keeb.io>

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

#include QMK_KEYBOARD_CONFIG_H

/* USB Device descriptor parameter */
#define VENDOR_ID       0xCB10
#define PRODUCT_ID      0x1146
#define DEVICE_VER      0x0200
#define MANUFACTURER    Keebio
#define PRODUCT         Levinson
#define DESCRIPTION     Split 40 percent ortholinear keyboard

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_ROW_PINS { D4, D7, E6, B4 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* serial.c configuration for split keyboard */
#define SOFT_SERIAL_PIN D0

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define TAPPING_TERM 200
// #define LEADER_TIMEOUT 300

#define AdafruitBleCSPin    F4
#define AdafruitBleIRQPin   C7
#define AdafruitBleResetPin F5

#define MK_3_SPEED
#define MOUSEKEY_DELAY	0
#define MOUSEKEY_INTERVAL	50
#define MOUSEKEY_MAX_SPEED	10
#define MOUSEKEY_TIME_TO_MAX	0
#define MOUSEKEY_WHEEL_MAX_SPEED	8	
#define MOUSEKEY_WHEEL_TIME_TO_MAX	40	

// Combos
#define COMBO_COUNT 4

// LEDs
// #define RGB_DI_PIN	F6
// #define RGBLED_NUM	52
// #define RGBLED_SPLIT  26

// Reduce Size
#define NO_ACTION_ONESHOT  // 470b
#define NO_ACTION_MACRO    // 326b
#define NO_ACTION_FUNCTION //  58b
