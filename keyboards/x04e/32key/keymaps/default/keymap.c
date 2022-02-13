#include QMK_KEYBOARD_H
#include <print.h>
#include <shortcuts.h>

enum layers {
    LAYER_QWERTY,
    LAYER_COLEMAK_DH,
    LAYER_GAMING,
    LAYER_SYMBOL,
    LAYER_NUMBER,
    LAYER_ADJUST
};


enum keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK
};


/* ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ───────
 * _MQ_Q,  _MQ_W,  _MQ_E,  _MQ_R,  _MQ_T,  _MQ_Y,  _MQ_U,  _MQ_I,  _MQ_O,  _MQ_P,
 * _MQ_A,  _MQ_S,  _MQ_D,  _MQ_F,  _MQ_G,  _MQ_H,  _MQ_J,  _MQ_K,  _MQ_L,  _MQ_SCN,
 * _MQ_Z,  _MQ_X,  _MQ_C,  _MQ_V,  _MQ_B,  _MQ_N,  _MQ_M,  _MQ_COM,_MQ_DOT,_MQ_SL,
 *
 * Custom QWERTY codes */
#define _MQ_Q    LALT_T(_Q)
#define _MQ_W    _W
#define _MQ_E    _E
#define _MQ_R    _R
#define _MQ_T    LT(LAYER_QWERTY, KC_T)
#define _MQ_Y    LT(LAYER_QWERTY, KC_Y)
#define _MQ_U    _U
#define _MQ_I    _I
#define _MQ_O    _O
#define _MQ_P    LALT_T(_P)
/* --- */
#define _MQ_A    LT(LAYER_SYMBOL, _A)
#define _MQ_S    LGUI_T(_S)
#define _MQ_D    LCTL_T(_D)
#define _MQ_F    LSFT_T(_F)
#define _MQ_G    LT(LAYER_QWERTY, KC_G)
#define _MQ_H    LT(LAYER_QWERTY, KC_H)
#define _MQ_J    LSFT_T(_J)
#define _MQ_K    LCTL_T(_K)
#define _MQ_L    LGUI_T(_L)
#define _MQ_SCN  LT(LAYER_SYMBOL, _SCN)
/* --- */
#define _MQ_Z    LT(LAYER_NUMBER, _Z)
#define _MQ_X    _X
#define _MQ_C    _C
#define _MQ_V    _V
#define _MQ_B    LT(LAYER_QWERTY, KC_B)
#define _MQ_N    LT(LAYER_QWERTY, KC_N)
#define _MQ_M    _M
#define _MQ_COM  _COM
#define _MQ_DOT  _DOT
#define _MQ_SL   LT(LAYER_NUMBER, _SL)


/* ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ───────
 * _MC_Q,  _MC_W,  _MC_F,  _MC_P,  _MC_B,  _MC_J,  _MC_L,  _MC_U,  _MC_Y,  _MC_SCN,
 * _MC_A,  _MC_R,  _MC_S,  _MC_T,  _MC_G,  _MC_M,  _MC_N,  _MC_E,  _MC_I,  _MC_O,
 * _MC_Z,  _MC_X,  _MC_C,  _MC_D,  _MC_V,  _MC_K,  _MC_H,  _MC_COM,_MC_DOT,_MC_SL,
 *
 * Custom COLEMAK DH codes */
#define _MC_Q   LALT_T(_Q)
#define _MC_W   _W
#define _MC_F   _F
#define _MC_P   _P
#define _MC_B   LT(LAYER_COLEMAK_DH, KC_B)
#define _MC_J   LT(LAYER_COLEMAK_DH, KC_J)
#define _MC_L   _L
#define _MC_U   _U
#define _MC_Y   _Y
#define _MC_SCN LALT_T(_SCN)
/* --- */
#define _MC_A   LT(LAYER_SYMBOL, _A)
#define _MC_R   LGUI_T(_R)
#define _MC_S   LCTL_T(_S)
#define _MC_T   LSFT_T(_T)
#define _MC_G   LT(LAYER_COLEMAK_DH, KC_G)
#define _MC_M   LT(LAYER_COLEMAK_DH, KC_M)
#define _MC_N   LSFT_T(_N)
#define _MC_E   LCTL_T(_E)
#define _MC_I   LGUI_T(_I)
#define _MC_O   LT(LAYER_SYMBOL, _O)
/* --- */
#define _MC_Z   LT(LAYER_NUMBER, _Z)
#define _MC_X   _X
#define _MC_C   _C
#define _MC_D   _D
#define _MC_V   LT(LAYER_COLEMAK_DH, KC_V)
#define _MC_K   LT(LAYER_COLEMAK_DH, KC_K)
#define _MC_H   _H
#define _MC_COM _COM
#define _MC_DOT _DOT
#define _MC_SL  LT(LAYER_NUMBER, _SL)


#define SYMBOL MO(LAYER_SYMBOL)
#define NUMBER MO(LAYER_NUMBER)
#define ADJUST MO(LAYER_ADJUST)
#define GAMING DF(LAYER_GAMING) /* GAMING layer shouldn't be set persistently */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_QWERTY] = LAYOUT( \
    /*
        Q       W       E       R       T      │Y       U       I       O       P
        A       S       D       F       G      │H       J       K       L       ;:
        Z       X       C       V       B      │N       M       ,<      .>      /?
                                SYMBOL  SPACE  │SHIFT   NUMBER
        ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        _MQ_Q,  _MQ_W,  _MQ_E,  _MQ_R,  _MQ_T,  _MQ_Y,  _MQ_U,  _MQ_I,  _MQ_O,  _MQ_P,
        _MQ_A,  _MQ_S,  _MQ_D,  _MQ_F,  _MQ_G,  _MQ_H,  _MQ_J,  _MQ_K,  _MQ_L,  _MQ_SCN,
        _MQ_Z,  _MQ_X,  _MQ_C,  _MQ_V,  _MQ_B,  _MQ_N,  _MQ_M,  _MQ_COM,_MQ_DOT,_MQ_SL,
                                        _SPC,   _SFT                                    \
    ),

    [LAYER_COLEMAK_DH] = LAYOUT( \
    /*
        Q       W       F       P       B      │J       L       U       Y       ;:
        A       R       S       T       G      │M       N       E       I       O
        Z       X       C       D       V      │K       H       ,<      .>      /?
                                SYMBOL  SPACE  │SHIFT   NUMBER
        ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        _MC_Q,  _MC_W,  _MC_F,  _MC_P,  _MC_B,  _MC_J,  _MC_L,  _MC_U,  _MC_Y,  _MC_SCN,
        _MC_A,  _MC_R,  _MC_S,  _MC_T,  _MC_G,  _MC_M,  _MC_N,  _MC_E,  _MC_I,  _MC_O,
        _MC_Z,  _MC_X,  _MC_C,  _MC_D,  _MC_V,  _MC_K,  _MC_H,  _MC_COM,_MC_DOT,_MC_SL,
                                        _SPC,   _SFT                                    \
    ),

    [LAYER_SYMBOL] = LAYOUT( \
    /*  TAB     `       |       _       [      │]       +       &       ENT    DEL
        ESC     %       '       -       (      │)       "       $       !      BSPC
        €       ^       \       ~       {      │}       =       *       #      @
                                TRNS    ___    │___     ADJUST
        ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        xxx,    _BTK,   _PIP,   _UND,   _LSB,   _RSB,   _PLS,   _AMP,   _AT,    xxx,    \
        TRNS,   _PRC,   _SQT,   _MIN,   _LPR,   _RPR,   _DQT,   _USD,   _EX,    TRNS,   \
        ADJUST, _CRT,   _BSL,   _TLD,   _LCB,   _RCB,   _EQ,    _AST,   _HSH,   ADJUST, \
                                        ___,    ___                                     \
    ),

    [LAYER_NUMBER] = LAYOUT( \
    /*  xxx     7       8       9       TAB    │DEL     xxx     UP      ENT     DEL
        xxx     4       5       6       ESC    │BKSPC   LEFT    DOWN    UP      BSPC
        xxx     1       2       3       0      │ENT     HOME    PGDN    PGUP    END
                                ADJUST  ___    │___     TRNS
        ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        xxx,    _7,     _8,     _9,     xxx,    xxx,    _HOME,  _PG_D,  _PG_U,  _END,   \
        _0,     _4,     _5,     _6,     xxx,    xxx,    _AR_L,  _AR_D,  _AR_U,  _AR_R,  \
        TRNS,   _1,     _2,     _3,     xxx,    xxx,    xxx,    xxx,    xxx,    TRNS,   \
                                        ___,    ___                                     \
    ),

    [LAYER_ADJUST] = LAYOUT( \
    /*  F1      F2      F3      F4      F5     │F6      F7      F8      F9      F10
        CAPS    xxx     xxx     xxx     F11    │F12     _V_P    _V_VD   _V_VU   xxx
        QWERTY  COLEMAK GAMING  xxx     xxx    │xxx     xxx     xxx     xxx     RESET
                                TRNS    xxx    │xxx     TRNS
        ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        _F1,    _F2,    _F3,    _F4,    _F5,    _F6,    _F7,    _F8,    _F9,    _F10,   \
        TRNS,   _CAPS,  xxx,    xxx,    _F11,   _F12,   _V_P,   _V_VD,  _V_VU,  TRNS,   \
        TRNS,   QWERTY, COLEMAK,GAMING, xxx,    xxx,    xxx,    xxx,    RESET,  TRNS,   \
                                        xxx,    xxx                                     \
    ),

    [LAYER_GAMING] = LAYOUT( \
    /*
        TAB     Q       W       E       R       T      │Y       U       I       O
        ESC     A       S       D       F       G      │H       J       K       L
        CTRL    Z       X       C       V       B      │N       M       ,<      .>
                                SYMBOL  SPACE  │BKSPC   NUMBER
        ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        _TAB,   _Q,     _W,     _E,     _R,     _T,     _Y,     _U,     _I,     _O,     \
        _ESC,   _A,     _S,     _D,     _F,     _G,     _H,     _J,     _K,     _L,     \
        _CTL,   _Z,     _X,     _C,     _V,     _B,     _N,     _M,     _COM,   _DOT,   \
                                        _SPC,   _SFT                                    \
    )

};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _MQ_T:
        case _MC_B:
        case _MQ_Y:
        case _MC_J:
        case _MQ_G:
        case _MC_G:
        case _MQ_H:
        case _MC_M:
        case _MQ_B:
        case _MC_V:
        case _MQ_N:
        case _MC_K:
            return 140;
            break;

        default:
            return TAPPING_TERM;
            break;
    }
}

bool custom_tap_hold(keyrecord_t *record, uint16_t keycode){
    if (!record -> tap.count && record -> event.pressed) {
        register_code(keycode);
        return false;
    } else {
        unregister_code(keycode);
        return true;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) { set_single_persistent_default_layer(LAYER_QWERTY); }
            return false;
            break;
        case COLEMAK:
            if (record->event.pressed) { set_single_persistent_default_layer(LAYER_COLEMAK_DH); }
            return false;
            break;

        case _MQ_T:
        case _MC_B:
            return custom_tap_hold(record, _TAB);
            break;

        case _MQ_Y:
        case _MC_J:
            return custom_tap_hold(record, _DEL);
            break;

        case _MQ_G:
        case _MC_G:
            return custom_tap_hold(record, _ESC);
            break;

        case _MQ_H:
        case _MC_M:
            return custom_tap_hold(record, _BSPC);
            break;

        case _MQ_B:
        case _MC_V:
            return custom_tap_hold(record, _CAPS);
            break;

        case _MQ_N:
        case _MC_K:
            return custom_tap_hold(record, _ENT);
            break;

    }
    return true;
}

