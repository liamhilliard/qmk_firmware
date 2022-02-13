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
        TAB     Q       W       E       R       T      │Y       U       I       O       P       '@
        ESC     A       S       D       F       G      │H       J       K       L       ;:      BCSP
        SHIFT   Z       X       C       V       B      │N       M       ,<      .>      /?      ENT
        CTRL    ALT     xxx     xxx     SYMBOL  SPACE  │SHIFT   NUMBER  PLAY    VOL+    VOL-    DEL
        ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        _TAB,   _Q,     _W,     _E,     _R,     _T,     _Y,     _U,     _I,     _O,     _P,     _SQT,   \
        _ESC,   _A_HQ,  _S_HQ,  _D_HQ,  _F_HQ,  _G,     _H,     _J_HQ,  _K_HQ,  _L_HQ,  _SCN_HQ,_BSPC,  \
        _SFT,   _Z,     _X,     _C,     _V,     _B,     _N,     _M,     _COM,   _DOT,   _SL,    _ENT,   \
        _CTL,   _ALT,   xxx,    xxx,    SYMBOL, _SPC,   _SFT,   NUMBER, _V_P,   _V_VD,  _V_VU,  _DEL    \
    ),

    [LAYER_COLEMAK_DH] = LAYOUT( \
    /*
        TAB     Q       W       F       P       B      │J       L       U       Y       ;:       '@
        ESC     A       R       S       T       G      │M       N       E       I       O       BCSP
        SHIFT   Z       X       C       D       V      │K       H       ,<      .>      /?      ENT
        CTRL    ALT     xxx     xxx     SYMBOL  SPACE  │SHIFT   NUMBER  PLAY    VOL+    VOL-    DEL
        ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        _TAB,   _Q,     _W,     _F,     _P,     _B,     _J,     _L,     _U,     _Y,     _SCN,   _SQT,   \
        _ESC,   _A_HC,  _R_HC,  _S_HC,  _T_HC,  _G,     _M,     _N_HC,  _E_HC,  _I_HC,  _O_HC,  _BSPC,  \
        _SFT,   _Z,     _X,     _C,     _D,     _V,     _K,     _H,     _COM,   _DOT,   _SL,    _ENT,   \
        _CTL,   _ALT,   xxx,    xxx,    SYMBOL, _SPC,   _SFT,   NUMBER, _V_P,   _V_VU,  _V_VD,  _DEL    \
    ),

    [LAYER_SYMBOL] = LAYOUT( \
    /*  £       `       |       /       _       [      │]       +       $       &       <       >
        %       ?       ;       '       -       (      │)       .       "       ,       !       ___
        €       ^       :       \       ~       {      │}       =       *       #       @       ___
        ___     ___     ___     ___     TRNS    ___    │___     ADJUST  ___     ___     ___     ___
        ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        _GBP,   _BTK,   _PIP,   _SL,    _UND,   _LSB,   _RSB,   _PLS,   _USD,   _AMP,   _LAB,   _RAB,   \
        _PRC,   _QS,    _SCN,   _SQT,   _MIN,   _LPR,   _RPR,   _DOT,   _DQT,   _COM,   _EX,    ___,    \
        _EUR,   _CRT,   _CN,    _BSL,   _TLD,   _LCB,   _RCB,   _EQ,    _AST,   _HSH,   _AT,    ___,    \
        ___,    ___,    ___,    ___,    TRNS,   ___,    ___,    ADJUST, ___,    ___,    ___,    ___     \
    ),

    [LAYER_NUMBER] = LAYOUT( \
    /*  ___     xxx     7       8       9       xxx    │xxx     xxx     xxx     xxx     xxx     xxx
        ___     0       4       5       6       xxx    │xxx     LEFT    DOWN    UP      RIGHT   xxx
        ___     xxx     1       2       3       xxx    │xxx     HOME    PGDN    PGUP    END     xxx
        ___     xxx     xxx     xxx     ADJUST  ___    │___     TRNS    ADJUST  ___     ___     ___
        ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        ___,    xxx,    _7,     _8,     _9,     xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    \
        ___,    _0,     _4,     _5,     _6,     xxx,    xxx,    _AR_L,  _AR_D,  _AR_U,  _AR_R,  ___,    \
        ___,    xxx,    _1,     _2,     _3,     xxx,    xxx,    _HOME,  _PG_D,  _PG_U,  _END,   ___,    \
        ___,    ___,    ___,    ___,    ADJUST, ___,    ___,    TRNS,   ___,    ___,    ___,    ___     \
    ),

    [LAYER_ADJUST] = LAYOUT( \
    /*  F1      F2      F3      F4      F5      F6     │F7      F8      F9      F10     F11     F12
        CAPS    FAST    SLOW    RCLK    LCLK    xxx    │xxx     MLEFT   MDOWN   MUP     MRIGHT  xxx
        xxx     xxx     xxx     xxx     xxx     xxx    │xxx     xxx     WHDOWN  WHUP    xxx     xxx
        QWERTY  COLEMAK GAMING  xxx     TRNS    xxx    │xxx     TRNS    PLAY    VOL+    VOL-    RESET
        ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        _F1,    _F2,    _F3,    _F4,    _F5,    _F6,    _F7,    _F8,    _F9,    _F10,   _F11,   _F12,   \
        _CAPS,  _M_A2,  _M_A0,  _M_B2,  _M_B1,  xxx,    xxx,    _M_L,   _M_D,   _M_U,   _M_R,   xxx,    \
        xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    _M_WD,  _M_WU,  xxx,    DEBUG,  \
        QWERTY, COLEMAK,GAMING, xxx,    TRNS,   xxx,    xxx,    TRNS,   _V_P,   _V_VU,  _V_VD,  RESET   \
    ),

    [LAYER_GAMING] = LAYOUT( \
    /*
        TAB     Q       W       E       R       T      │Y       U       I       O       P       '@
        ESC     A       S       D       F       G      │H       J       K       L       ;:      BCSP
        SHIFT   Z       X       C       V       B      │N       M       ,<      .>      /?      ENT
        CTRL    ALT     xxx     xxx     SYMBOL  SPACE  │SHIFT   NUMBER  PLAY    VOL+    VOL-    DEL
        ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        _TAB,   _Q,     _W,     _E,     _R,     _T,     _Y,     _U,     _I,     _O,     _P,     _SQT,   \
        _ESC,   _A,     _S,     _D,     _F,     _G,     _H,     _J,     _K,     _L,     _SCN,   _BSPC,  \
        _SFT,   _Z,     _X,     _C,     _V,     _B,     _N,     _M,     _COM,   _DOT,   _SL,    _ENT,   \
        _CTL,   _ALT,   xxx,    _GUI,   SYMBOL, _SPC,   _SFT,   NUMBER, _V_P,   _V_VU,  _V_VD,  _DEL    \
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

