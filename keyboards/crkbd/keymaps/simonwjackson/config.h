/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 1000
//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT

// #define EE_HANDS

// #define SSD1306OLED

#define USE_SERIAL_PD2

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM_PER_KEY
#define TAPPING_TERM 150
#define COMBO_TERM 120 

#define AdafruitBleSCKPin   F0
#define AdafruitBleMOSIPin  F1 
#define AdafruitBleCSPin    C7
#define AdafruitBleIRQPin   D5
#define AdafruitBleResetPin B7

// #define MK_3_SPEED
#define MK_MOMENTARY_ACCEL
#define MMOUSEKEY_DELAY 	1000 	
#define MMOUSEKEY_INTERVAL 	1000 
#define MMOUSEKEY_MAX_SPEED 	1
#define MMOUSEKEY_TIME_TO_MAX 	1000
#define MOUSEKEY_WHEEL_MAX_SPEED	  8	
#define MOUSEKEY_WHEEL_TIME_TO_MAX	40	

// Combos
#define COMBO_COUNT 5

#define IGNORE_MOD_TAP_INTERRUPT
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY
#define PERMISSIVE_HOLD
#undef PREVENT_STUCK_MODIFIERS
