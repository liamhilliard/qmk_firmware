/*
Copyright 2017 Danny Nguyen <danny@hexwire.com>

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

// #define USE_I2C

/* Select hand configuration */
// #define MASTER_RIGHT
// #define EE_HANDS

#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 12
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8



#define MK_3_SPEED         // Enable constant cursor speeds
#define MK_MOMENTARY_ACCEL // Enable momentary mode with constant speeds

#define MOUSEKEY_DELAY 0                // default: 300 - Delay between pressing a movement key and cursor movement
#define MOUSEKEY_INTERVAL 16            // default: 50 - Time between cursor movements
#define MOUSEKEY_MAX_SPEED 30           // default: 10 - Maximum cursor speed at which acceleration stops
#define MOUSEKEY_TIME_TO_MAX 0         // default: 20 - Time until maximum cursor speed is reached
//#define MOUSEKEY_WHEEL_MAX_SPEED 3      // default:  8 - Maximum number of scroll steps per scroll action
//#define MOUSEKEY_WHEEL_TIME_TO_MAX 0    // default: 40 - Time until maximum scroll speed is reached

#define MK_C_INTERVAL_UNMOD	16   // default: 16 - Time between cursor movements (unmodified)
#define MK_C_INTERVAL_0	16       // default: 32 - Time between cursor movements (KC_ACL0)
#define MK_C_INTERVAL_1	16       // default: 16 - Time between cursor movements (KC_ACL1)
#define MK_C_INTERVAL_2	16       // default: 16 - Time between cursor movements (KC_ACL2)
#define MK_C_OFFSET_UNMOD 26     // default: 16 - Cursor offset per movement (unmodified)
#define MK_C_OFFSET_0 5          // default: 1 - Cursor offset per movement (KC_ACL0)
#define MK_C_OFFSET_1 26         // default: 4 - Cursor offset per movement (KC_ACL1)
#define MK_C_OFFSET_2 64         // default: 32 - Cursor offset per movement (KC_ACL2)

//#define MK_W_INTERVAL_UNMOD 40   // default: 40 - Time between scroll steps (unmodified)
//#define MK_W_INTERVAL_0 360      // default: 360 - Time between scroll steps (KC_ACL0)
//#define MK_W_INTERVAL_1 120      // default: 120 - Time between scroll steps (KC_ACL1)
//#define MK_W_INTERVAL_2 20       // default: 20 - Time between scroll steps (KC_ACL2)
//#define MK_W_OFFSET_UNMOD 1      // default: 1 - Scroll steps per scroll action (unmodified)
//#define MK_W_OFFSET_0 1          // default: 1 - Scroll steps per scroll action (KC_ACL0)
//#define MK_W_OFFSET_1 1          // default: 1 - Scroll steps per scroll action (KC_ACL1)
//#define MK_W_OFFSET_2 1          // default: 1 - Scroll steps per scroll action (KC_ACL2)

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

// Custom
#define TAPPING_TERM 5000
#define AUTO_SHIFT_TIMEOUT 350
#define NO_AUTO_SHIFT_SPECIAL
#define NO_AUTO_SHIFT_NUMERIC

