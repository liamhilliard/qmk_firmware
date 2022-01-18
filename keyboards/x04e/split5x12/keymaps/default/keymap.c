#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT( \
//  ESC       1           2           3           4           5                 6          7           8           9           0           '@
    KC_ESC,  KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       /**/  KC_6,      KC_7,       KC_8,       KC_9,       KC_0,       KC_QUOT, \
//  TAB      Q           W           E           R           T           /**/  Y          U           I           O           P           DEL
    KC_TAB,  KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       /**/  KC_Y,      KC_U,       KC_I,       KC_O,       KC_P,       KC_DEL, \
//  CAPS     A           S           D           F           G           /**/  H          J           K           L           ;:          BSPC
    KC_CAPS, KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       /**/  KC_H,      KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_BSPC, \
//  SHFT     Z           X           C           V           B           /**/  N          M           ,<          .>          /?          ENT
    KC_LSFT, KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       /**/  KC_N,      KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_ENT , \
//  CTRL     ALT         RALT        GUI         LOWER       SPC         /**/  SHFT       RAISE       L-ARR       D-ARR       U-ARR       R-ARR
    KC_LCTL, KC_LCTL,    KC_RALT,    KC_LGUI,    LOWER,      KC_SPC,     /**/  KC_LSFT,   RAISE,      KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT \
),
[_LOWER] = LAYOUT( \
//  `        !              "           £           $              %             /**/ ^              &           *           (           )
    KC_GRV,  LSFT(KC_1),    LSFT(KC_2), LSFT(KC_3), LSFT(KC_4),    LSFT(KC_5),   /**/ LSFT(KC_6),    LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0),  _______, \
//           |              #           €           _              +             /**/   ~            =           \           [           ]
    _______, LSFT(KC_NUBS), KC_NUHS,    RALT(KC_4), LSFT(KC_MINS), LSFT(KC_EQL), /**/ LSFT(KC_NUHS), KC_EQL,     KC_NUBS,    KC_LBRC,    KC_RBRC,     _______, \
//                                                  -                            /**/                            /           {           }
    _______, XXXXXXX,       XXXXXXX,    XXXXXXX,    KC_MINS,       XXXXXXX,      /**/ XXXXXXX,       XXXXXXX,    KC_SLSH,    KC_LCBR,    KC_RCBR,     _______, \
//                                                                               /**/                INSERT      M-PLY       M-VOLUP     M-VOLDN
    _______, XXXXXXX,       XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX,      /**/ XXXXXXX,       KC_INS,     KC_MPLY,	 KC__VOLUP,	 KC__VOLDOWN, _______, \
//                                                                               /**/                ADJUST      HOME        PGDN        PGUP         END
    _______, _______,       _______,    _______,    _______,       _______,      /**/ _______,       ADJUST,     KC_HOME,    KC_PGDN,    KC_PGUP,     KC_END \
),
[_RAISE] = LAYOUT( \
//  F1       F2       F3       F4       F5       F6       /**/  F7       F8       F9        F10        F11       F12
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   /**/  KC_F7,   KC_F8,   KC_F9,    KC_F10,    KC_F11,    KC_F12, \
//                                                        /**/           7        8         9
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/  XXXXXXX, KC_7,    KC_8,     KC_9,      XXXXXXX,  _______, \
//                                                        /**/  0        4        5         6
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/  KC_0,    KC_4,    KC_5,     KC_6,      XXXXXXX,  _______, \
//                                                        /**/           1        2         3
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/  XXXXXXX, KC_1,    KC_2,     KC_3,      XXXXXXX,  _______, \
//                                                        /**/
    _______, _______, _______, _______, ADJUST, _______,  /**/  _______, _______, _______,  _______,   _______,  _______ \
),
[_ADJUST] =  LAYOUT( \
//                                                        /**/
    _______, _______, _______, _______, _______, _______, /**/  _______, _______, _______, _______, _______, _______, \
//                                                        /**/
    _______, _______, _______, _______, _______, _______, /**/  _______, _______, _______, _______, _______, _______, \
//                                                        /**/
    _______, _______, _______, _______, _______, _______, /**/  _______, _______, _______, _______, _______, _______, \
//                                                        /**/
    _______, _______, _______, _______, _______, _______, /**/  _______, _______, _______, _______, _______, _______, \
//  RESET                                                 /**/                                               RESET
    RESET,   _______, _______, _______, _______, _______, /**/  _______, _______, _______, _______, _______, RESET \
)

};
