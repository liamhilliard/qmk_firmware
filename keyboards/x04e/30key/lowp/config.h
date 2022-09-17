// Copyright 2022 x04e (@x04e)
// SPDX-License-Identifier: GPL-2.0-or-later
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
#define MATRIX_ROW_PINS { D1, D0, D4 }
#define MATRIX_COL_PINS { C6, D7, E6, B4, B5, B6, B2, B3, B1, F7 }

