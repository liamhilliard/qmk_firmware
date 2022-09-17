// Copyright 2022 x04e (@x04e)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"
/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, \
    k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, \
    k31, k32, k33, k34, k35, k36, k37, k38, k39, k3A  \
) { \
    { k11,   k12,   k13,   k14,   k15,   k16,   k17,   k18,   k19,   k1A   }, \
    { k21,   k22,   k23,   k24,   k25,   k26,   k27,   k28,   k29,   k2A   }, \
    { k31,   k32,   k33,   k34,   k35,   k36,   k37,   k38,   k39,   k3A   }  \
}
