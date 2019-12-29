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
#define TAPPING_TERM 200

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    #define RGBLIGHT_ANIMATIONS
    #define RGBLED_NUM 27
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#define AdafruitBleSCKPin   F0
#define AdafruitBleMOSIPin  F1 
#define AdafruitBleCSPin    C7
#define AdafruitBleIRQPin   D5
#define AdafruitBleResetPin B7

// #define MK_3_SPEED
#define MOUSEKEY_DELAY              300
#define MOUSEKEY_INTERVAL           50
#define MOUSEKEY_MAX_SPEED          10
#define MOUSEKEY_TIME_TO_MAX        20
#define MOUSEKEY_WHEEL_MAX_SPEED	8	
#define MOUSEKEY_WHEEL_TIME_TO_MAX	40	