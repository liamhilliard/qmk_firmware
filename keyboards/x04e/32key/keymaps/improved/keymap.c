#include QMK_KEYBOARD_H
#include <print.h>
#include <shortcuts.h>

enum layers {
    LAYER_QWERTY,
    LAYER_COLEMAK_DH,
    LAYER_GAMING,
    LAYER_LEFT_SYMBOL,
    LAYER_RIGHT_SYMBOL,
    LAYER_LEFT_NUMBER,
    LAYER_RIGHT_NUMBER,
    LAYER_LEFT_ARROW,
    LAYER_RIGHT_ARROW
};


enum keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    _UPPR
};


/* ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ───────
 * _MQ_Q,  _MQ_W,  _MQ_E,  _MQ_R,  _MQ_T,  _MQ_Y,  _MQ_U,  _MQ_I,  _MQ_O,  _MQ_P,
 * _MQ_A,  _MQ_S,  _MQ_D,  _MQ_F,  _MQ_G,  _MQ_H,  _MQ_J,  _MQ_K,  _MQ_L,  _MQ_SCN,
 * _MQ_Z,  _MQ_X,  _MQ_C,  _MQ_V,  _MQ_B,  _MQ_N,  _MQ_M,  _MQ_COM,_MQ_DOT,_MQ_SL,
 *
 * Custom QWERTY codes */
#define _MQ_Q    LALT_T(_Q)
#define _MQ_W    _W
#define _MQ_E    LT(LAYER_RIGHT_ARROW, _E)
#define _MQ_R    _R
#define _MQ_T    _T
#define _MQ_Y    _Y
#define _MQ_U    _U
#define _MQ_I    LT(LAYER_LEFT_ARROW, _I)
#define _MQ_O    _O
#define _MQ_P    LALT_T(_P)
/* --- */
#define _MQ_A    LCTL_T(_A)
#define _MQ_S    LSFT_T(_S)
#define _MQ_D    LT(LAYER_RIGHT_SYMBOL, _D)
#define _MQ_F    _F
#define _MQ_G    _G
#define _MQ_H    _H
#define _MQ_J    _J
#define _MQ_K    LT(LAYER_LEFT_SYMBOL, _K)
#define _MQ_L    LSFT_T(_L)
#define _MQ_SCN  LCTL_T(_SCN)
/* --- */
#define _MQ_Z    LGUI_T(_Z)
#define _MQ_X    _X
#define _MQ_C    LT(LAYER_RIGHT_NUMBER, _C)
#define _MQ_V    _V
#define _MQ_B    _B
#define _MQ_N    _N
#define _MQ_M    _M
#define _MQ_COM  LT(LAYER_LEFT_NUMBER, _COM)
#define _MQ_DOT  _DOT
#define _MQ_SL   LGUI_T(_SL)


/* ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ───────
 * _MC_Q,  _MC_W,  _MC_F,  _MC_P,  _MC_B,  _MC_J,  _MC_L,  _MC_U,  _MC_Y,  _MC_SCN,
 * _MC_A,  _MC_R,  _MC_S,  _MC_T,  _MC_G,  _MC_M,  _MC_N,  _MC_E,  _MC_I,  _MC_O,
 * _MC_Z,  _MC_X,  _MC_C,  _MC_D,  _MC_V,  _MC_K,  _MC_H,  _MC_COM,_MC_DOT,_MC_SL,
 *
 * Custom COLEMAK DH codes */
#define _MC_Q   LALT_T(_Q)
#define _MC_W   _W
#define _MC_F   LT(LAYER_RIGHT_ARROW, _F)
#define _MC_P   _P
#define _MC_B   _B
#define _MC_J   _J
#define _MC_L   _L
#define _MC_U   LT(LAYER_LEFT_ARROW, _U)
#define _MC_Y   _Y
#define _MC_SCN LALT_T(_SCN)
/* --- */
#define _MC_A   LCTL_T(_A)
#define _MC_R   LSFT_T(_R)
#define _MC_S   LT(LAYER_RIGHT_SYMBOL, _S)
#define _MC_T   _T
#define _MC_G   _G
#define _MC_M   _M
#define _MC_N   _N
#define _MC_E   LT(LAYER_LEFT_SYMBOL, _E)
#define _MC_I   LSFT_T(_I)
#define _MC_O   LCTL_T(_O)
/* --- */
#define _MC_Z   LGUI_T(_Z)
#define _MC_X   _X
#define _MC_C   LT(LAYER_RIGHT_NUMBER, _C)
#define _MC_D   _D
#define _MC_V   _V
#define _MC_K   _K
#define _MC_H   _H
#define _MC_COM LT(LAYER_LEFT_NUMBER, _COM)
#define _MC_DOT _DOT
#define _MC_SL  LGUI_T(_SL)


#define LSYM   MO(LAYER_LEFT_SYMBOL)
#define RSYM   MO(LAYER_RIGHT_SYMBOL)
#define LNUM   MO(LAYER_LEFT_NUMBER)
#define RNUM   MO(LAYER_RIGHT_NUMBER)
#define LARR   MO(LAYER_LEFT_ARROW)
#define RARR   MO(LAYER_RIGHT_ARROW)
#define GAMING DF(LAYER_GAMING) /* GAMING layer shouldn't be set persistently */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_QWERTY] = LAYOUT( \
        _MQ_Q,  _MQ_W,  _MQ_E,  _MQ_R,  _MQ_T,  _MQ_Y,  _MQ_U,  _MQ_I,  _MQ_O,  _MQ_P,  \
        _MQ_A,  _MQ_S,  _MQ_D,  _MQ_F,  _MQ_G,  _MQ_H,  _MQ_J,  _MQ_K,  _MQ_L,  _MQ_SCN,\
        _MQ_Z,  _MQ_X,  _MQ_C,  _MQ_V,  _MQ_B,  _MQ_N,  _MQ_M,  _MQ_COM,_MQ_DOT,_MQ_SL, \
                                        _SPC,   _BSPC                                   \
    ),

    [LAYER_COLEMAK_DH] = LAYOUT( \
        _MC_Q,  _MC_W,  _MC_F,  _MC_P,  _MC_B,  _MC_J,  _MC_L,  _MC_U,  _MC_Y,  _MC_SCN,\
        _MC_A,  _MC_R,  _MC_S,  _MC_T,  _MC_G,  _MC_M,  _MC_N,  _MC_E,  _MC_I,  _MC_O,  \
        _MC_Z,  _MC_X,  _MC_C,  _MC_D,  _MC_V,  _MC_K,  _MC_H,  _MC_COM,_MC_DOT,_MC_SL, \
                                        _SPC,   _BSPC                                   \
    ),

    [LAYER_LEFT_SYMBOL] = LAYOUT( \
        _GBP,   _BTK,   _PIP,   _UND,   _LSB,   _DEL,   _TAB,   xxx,    xxx,    xxx,    \
        xxx,    _PRC,   _SQT,   _MIN,   _LPR,   _UPPR,  _ESC,   TRNS,   xxx,    xxx,    \
        _EUR,   _CRT,   _BSL,   _TLD,   _LCB,   xxx,    _ENT,   xxx,    xxx,    xxx,    \
                                        ___,    ___                                     \
    ),

    [LAYER_RIGHT_SYMBOL] = LAYOUT( \
        xxx,    xxx,    xxx,    _TAB,   _DEL,   _RSB,   _PLS,   _AMP,   _LAB,   _RAB,   \
        xxx,    xxx,    TRNS,   _ESC,   _UPPR,  _RPR,   _DQT,   _USD,   _EX,    xxx,    \
        xxx,    xxx,    xxx,    _ENT,   xxx,    _RCB,   _EQ,    _AST,   _HSH,   _AT,    \
                                        ___,    ___                                     \
    ),

    [LAYER_LEFT_NUMBER] = LAYOUT( \
        xxx,    _7,     _8,     _9,     xxx,    _DEL,   _TAB,   xxx,    xxx,    xxx,    \
        _0,     _4,     _5,     _6,     xxx,    _UPPR,  _ESC,   TRNS,   xxx,    xxx,    \
        xxx,    _1,     _2,     _3,     xxx,    xxx,    _ENT,   xxx,    xxx,    xxx,    \
                                        ___,    ___                                     \
    ),

    [LAYER_RIGHT_NUMBER] = LAYOUT( \
        xxx,    xxx,    xxx,    _TAB,   _DEL,   xxx,    _7,     _8,     _9,     xxx,    \
        xxx,    xxx,    TRNS,   _ESC,   _UPPR,  xxx,    _4,     _5,     _6,     _0,     \
        xxx,    xxx,    xxx,    _ENT,   xxx,    xxx,    _1,     _2,     _3,     xxx,    \
                                        ___,    ___                                     \
    ),

    [LAYER_LEFT_ARROW] = LAYOUT( \
        _F1,    _F2,    _F3,    _F4,    _F5,    _DEL,   _TAB,   QWERTY, COLEMAK,GAMING, \
        _AR_L,  _AR_D,  _AR_U,  _AR_R,  _F12,   _UPPR,  _ESC,   _V_P,   _V_VD,  _V_VU,  \
        _HOME,  _PG_D,  _PG_U,  _END,   xxx,    xxx,    _ENT,   TRNS,   xxx,    RESET,  \
                                        ___,    ___                                     \
    ),

    [LAYER_RIGHT_ARROW] = LAYOUT( \
        QWERTY, COLEMAK,GAMING, _TAB,   _DEL,   _F6,    _F7,    _F8,    _F9,    _F10,   \
        _V_P,   _V_VD,  _V_VU,  _ESC,   _UPPR,  _F12,   _AR_L,  _AR_D,  _AR_U,  _AR_R,  \
        RESET,  xxx,    TRNS,   _ENT,   xxx,    xxx,    _HOME,  _PG_D,  _PG_U,  _END,   \
                                        ___,    ___                                     \
    ),

    [LAYER_GAMING] = LAYOUT( \
        _TAB,   _Q,     _W,     _E,     _R,     _T,     _Y,     _U,     _I,     _O,     \
        _ESC,   _A,     _S,     _D,     _F,     _G,     _H,     _J,     _K,     QWERTY, \
        _CTL,   _Z,     _X,     _C,     _V,     _B,     _N,     _M,     _COM,   COLEMAK,\
                                        _SPC,   _SFT                                    \
    )

};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _MQ_E:   case _MC_F:
        case _MQ_D:   case _MC_S:
        case _MQ_C:   /*case _MC_C:*/
        case _MQ_I:   case _MC_U:
        case _MQ_K:   case _MC_E:
        case _MQ_COM: /*case _MC_COM:*/
            return 160;
            break;

        default:
            return TAPPING_TERM;
            break;
    }
}

static bool caps_on = false;

void toggle_capslock(void){
    tap_code16(_CAPS);
    caps_on = !caps_on;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(LAYER_QWERTY);
            }
            return false;

        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(LAYER_COLEMAK_DH);
            }
            return false;

        case _UPPR:
            if(record -> event.pressed) {
                toggle_capslock();
            }
            return true;

        /* Keep capslock on for the following keys */
        case LALT_T(_Q): case LALT_T(_P): case LCTL_T(_A):
        case LCTL_T(_O): case LSFT_T(_S): case LSFT_T(_L):
        case LSFT_T(_R): case LSFT_T(_I): case LGUI_T(_Z):
        case LT(LAYER_RIGHT_ARROW, _E): case LT(LAYER_RIGHT_ARROW, _F):
        case LT(LAYER_LEFT_ARROW, _I): case LT(LAYER_LEFT_ARROW, _U):
        case LT(LAYER_RIGHT_SYMBOL, _D): case LT(LAYER_LEFT_SYMBOL, _K):
        case LT(LAYER_RIGHT_NUMBER, _C): case LT(LAYER_RIGHT_SYMBOL, _S):
        case LT(LAYER_LEFT_SYMBOL, _E):
        case _A: case _B: case _C: case _D: case _E: case _F: case _G: case _H:
        case _I: case _J: case _K: case _L: case _M: case _N: case _O: case _P:
        case _Q: case _R: case _S: case _T: case _U: case _V: case _W: case _X:
        case _Y: case _Z:
        case _1: case _2: case _3: case _4: case _5: case _6: case _7: case _8:
        case _9: case _0:
        case _UND: case _MIN:
        case _BSPC:
            return true;

        /* Don't disable capslock when symbol keys are held for layers/mods */
        case LCTL_T(_SCN):
        case LT(LAYER_LEFT_NUMBER, _COM):
        case LGUI_T(_SL):
            if(caps_on && record->tap.count && record->event.pressed){
                toggle_capslock();
            }
            return true;

        /* Disable capslock for all other key presses */
        default:
            if(record->event.pressed) {
                if(caps_on){
                    toggle_capslock();
                }
            }
    }
    return true;
}

