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
        _Q,     _W,     _E,     _R,     _T,     _Y,     _U,     _I,     _O,     _P,     \
        _A_HQ,  _S_HQ,  _D_HQ,  _F_HQ,  _G,     _H,     _J_HQ,  _K_HQ,  _L_HQ,  _SCN_HQ,\
        _Z,     _X,     _C,     _V,     _B,     _N,     _M,     _COM,   _DOT,   _SL,    \
                                SYMBOL, _SPC,   _SFT,   NUMBER                          \
    ),

    [LAYER_COLEMAK_DH] = LAYOUT( \
    /*
        Q       W       F       P       B      │J       L       U       Y       ;:
        A       R       S       T       G      │M       N       E       I       O
        Z       X       C       D       V      │K       H       ,<      .>      /?
                                SYMBOL  SPACE  │SHIFT   NUMBER
        ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        _Q,     _W,     _F,     _P,     _B,     _J,     _L,     _U,     _Y,     _SCN,   \
        _A,     _R_HC,  _S_HC,  _T_HC,  _G,     _M,     _N_HC,  _E_HC,  _I_HC,  _O_HC,  \
        _Z,     _X,     _C,     _D,     _V,     _K,     _H,     _COM,   _DOT,   _SL,    \
                                SYMBOL, _SPC,   _SFT,   NUMBER                          \
    ),

    [LAYER_SYMBOL] = LAYOUT( \
    /*  TAB     `       |       _       [      │]       +       &       ENT    DEL
        ESC     %       '       -       (      │)       "       $       !      BSPC
        €       ^       \       ~       {      │}       =       *       #      @
                                TRNS    ___    │___     ADJUST
        ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        _BTK,   _PIP,   _UND,   _LSB,   _TAB,   _DEL,   _RSB,   _PLS,   _AMP,   _AT,    \
        _PRC,   _SQT,   _MIN,   _LPR,   _ESC,   _BSPC,  _RPR,   _DQT,   _USD,   _EX,    \
        _CRT,   _BSL,   _TLD,   _LCB,   _EUR,   _ENT,   _RCB,   _EQ,    _AST,   _HSH,   \
                                TRNS,   ___,    ___,    ADJUST                          \
    ),

    [LAYER_NUMBER] = LAYOUT( \
    /*  xxx     7       8       9       TAB    │DEL     xxx     UP      ENT     DEL
        xxx     4       5       6       ESC    │BKSPC   LEFT    DOWN    UP      BSPC
        xxx     1       2       3       0      │ENT     HOME    PGDN    PGUP    END
                                ADJUST  ___    │___     TRNS
        ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        xxx,    _7,     _8,     _9,     _TAB,   _DEL,   xxx,    xxx,    xxx,    xxx,    \
        _0,     _4,     _5,     _6,     _ESC,   _BSPC,  _AR_L,  _AR_D,  _AR_U,  _AR_R,  \
        xxx,    _1,     _2,     _3,     xxx,    _ENT,   _HOME,  _PG_D,  _PG_U,  _END,   \
                                ADJUST, ___,    ___,    TRNS                            \
    ),

    [LAYER_ADJUST] = LAYOUT( \
    /*  F1      F2      F3      F4      F5     │F6      F7      F8      F9      F10
        CAPS    xxx     xxx     xxx     F11    │F12     _V_P    _V_VD   _V_VU   xxx
        QWERTY  COLEMAK GAMING  xxx     xxx    │xxx     xxx     xxx     xxx     RESET
                                TRNS    xxx    │xxx     TRNS
        ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        _F1,    _F2,    _F3,    _F4,    _F5,    _F6,    _F7,    _F8,    _F9,    _F10,   \
        _CAPS,  xxx,    xxx,    xxx,    _F11,   _F12,   _V_P,   _V_VD,  _V_VU,  xxx,    \
        QWERTY, COLEMAK,GAMING, xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    RESET,  \
                                TRNS,   xxx,    xxx,    TRNS                            \
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
                                SYMBOL, _SPC,   _SFT,   NUMBER                          \
    )

};

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
    }
    return true;
}

