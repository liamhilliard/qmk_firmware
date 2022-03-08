// Copyright 2022 x04e (@x04e)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0xFEED
#define PRODUCT_ID   0x0000
#define DEVICE_VER   0x0001
#define MANUFACTURER x04e
#define PRODUCT      30key

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 10
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

/*
 * Pro Micro Pinout (front side up)
 *            ╔════╗
 * ┌──────────╨────╨──────────┐
 * │ D3/TX0               RAW │
 * │                          │
 * │ D2/RX1               GND │
 * │                          │
 * │ GND                  RST │
 * │                          │
 * │ GND                  VCC │
 * │                          │
 * │ D1/2               F4/A3 │
 * │            ╱╲            │
 * │ D0/3      ╱  ╲     F5/A2 │
 * │           ╲  ╱           │
 * │ D4/4       ╲╱      F6/A1 │
 * │                          │
 * │ C6/5               F7/A0 │
 * │                          │
 * │ D7/6               B1/15 │
 * │                          │
 * │ E6/7               B3/14 │
 * │                          │
 * │ B4/8               B2/16 │
 * │                          │
 * │ B5/9               B6/10 │
 * └──────────────────────────┘
 *
 */
#define MATRIX_ROW_PINS { F4, F5, F6 }
#define MATRIX_COL_PINS { F7, B1, B3, B2, B6, B5, B4, E6, D7, C6 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
#define SOFT_SERIAL_PIN D0  // or D1, D2, D3, E6

// Home row mods configs
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 180
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM_PER_KEY

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

