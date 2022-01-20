#include QMK_KEYBOARD_H
#include "print.h"
#include "shortcuts.h"

#define LAYER_QWERTY     0
#define LAYER_COLEMAK_DH 1
#define LAYER_HALMAK     2
#define LAYER_GAMING     3

#define LAYER_SYMBOL     10
#define LAYER_NUMBER     11
#define LAYER_ADJUST     12

#define QWERTY      DF(LAYER_QWERTY)
#define COLMAK      DF(LAYER_COLEMAK_DH)
#define HALMAK      DF(LAYER_HALMAK)
#define GAMING      DF(LAYER_GAMING)
#define SYMBOL      MO(LAYER_SYMBOL)
#define NUMBER      MO(LAYER_NUMBER)
#define ADJUST      MO(LAYER_ADJUST)

#undef _CTRL
#undef _SHFT
#undef _ALT
#define _CTRL       OSM(MOD_LCTL)
#define _SHFT       OSM(MOD_LSFT)
#define _ALT        OSM(MOD_LALT)

enum custom_keycodes { TODEF };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_QWERTY] = LAYOUT( \
    /*
        TAB     Q       W       E       R       T      │Y       U       I       O       P       '@
        ESC     A       S       D       F       G      │H       J       K       L       ;:      BCSP
        SHIFT   Z       X       C       V       B      │N       M       ,<      .>      /?      ENT
        CTRL    ALT     xxx     GUI     CTRL    SPACE  │SHIFT   SYMBOL  PLAY    VOL+    VOL-    DEL
        ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        _TAB,   _Q,     _W,     _E,     _R,     _T,     _Y,     _U,     _I,     _O,     _P,     _SQT,   \
        _ESC,   _A,     _S,     _D,     _F,     _G,     _H,     _J,     _K,     _L,     _SCN,   _BSPC,  \
        _SHFT,  _Z,     _X,     _C,     _V,     _B,     _N,     _M,     _COM,   _DOT,   _SL,    _ENT,   \
        _CTRL,  _ALT,   xxx,    _GUI,   _CTRL,  _SPC,   _SHFT,  SYMBOL, _V_P,   _V_VU,  _V_VD,  _DEL    \
    ),

    [LAYER_COLEMAK_DH] = LAYOUT( \
    /*
        TAB     Q       W       F       P       B      │J       L       U       Y       ;:       '@
        ESC     A       R       S       T       G      │M       N       E       I       O       BCSP
        SHIFT   Z       X       C       D       V      │K       H       ,<      .>      /?      ENT
        CTRL    ALT     xxx     GUI     CTRL    SPACE  │SHIFT   SYMBOL  PLAY    VOL+    VOL-    DEL
        ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        _TAB,   _Q,     _W,     _F,     _P,     _B,     _J,     _L,     _U,     _Y,     _SCN,   _SQT,   \
        _ESC,   _A,     _R,     _S,     _T,     _G,     _M,     _N,     _E,     _I,     _O,     _BSPC,  \
        _SHFT,  _Z,     _X,     _C,     _D,     _V,     _K,     _H,     _COM,   _DOT,   _SL,    _ENT,   \
        _CTRL,  _ALT,   xxx,    _GUI,   _CTRL,  _SPC,   _SHFT,  SYMBOL, _V_P,   _V_VU,  _V_VD,  _DEL    \
    ),

    [LAYER_HALMAK] = LAYOUT( \
    /*
        TAB     W       L       R       B       Z      │;:      Q       U       D       J       '@
        ESC     S       H       N       T       ,<     │.>      A       E       O       I       BCSP
        SHIFT   F       M       V       C       /?     │G       P       X       K       Y       ENT
        CTRL    ALT     xxx     GUI     CTRL    SPACE  │SHIFT   SYMBOL  PLAY    VOL+    VOL-    DEL
        ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        _TAB,   _W,     _L,     _R,     _B,     _Z,     _SCN,   _Q,     _U,     _D,     _J,     _SQT,   \
        _ESC,   _S,     _H,     _N,     _T,     _COM,   _DOT,   _A,     _E,     _O,     _I,     _BSPC,  \
        _SHFT,  _F,     _M,     _V,     _C,     _SL,    _G,     _P,     _X,     _K,     _Y,     _ENT,   \
        _CTRL,  _ALT,   xxx,    _GUI,   _CTRL,  _SPC,   _SHFT,  SYMBOL, _V_P,   _V_VU,  _V_VD,  _DEL    \
    ),

    [LAYER_SYMBOL] = LAYOUT( \
    /*  £       `       |       /       _       [      │]       +       $       &       <       >
        %       ?       ;       '       -       (      │)       .       "       ,       !       ___
        €       ^       :       \       ~       {      │}       =       *       #       @       ___
        ___     ___     ___     ___     ___     TODEF  │___     NUMBER  ___     ___     ___     ___
        ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        _GBP,   _BTK,   _PIP,   _SL,    _UND,   _LSB,   _RSB,   _PLS,   _USD,   _AMP,   _LAB,   _RAB,   \
        _CEN,   _QS,    _SCN,   _SQT,   _MIN,   _LPR,   _RPR,   _DOT,   _DQT,   _COM,   _EX,    ___,    \
        _EUR,   _CRT,   _CN,    _BSL,   _TLD,   _LCB,   _RCB,   _EQ,    _AST,   _HSH,   _AT,    ___,    \
        ___,    ___,    ___,    ___,    ___,    TODEF,  ___,    NUMBER, ADJUST, ___,    ___,    ___     \
    ),

    [LAYER_NUMBER] = LAYOUT( \
    /*  ___     xxx     7       8       9       xxx    │xxx     xxx     xxx     xxx     xxx     xxx
        ___     0       4       5       6       xxx    │xxx     LEFT    DOWN    UP      RIGHT   xxx
        ___     xxx     1       2       3       xxx    │xxx     HOME    PGDN    PGUP    END     xxx
        ___     xxx     xxx     xxx     ___     TODEF  │___     SYMBOL  ADJUST  ___     ___     ___
        ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        ___,    xxx,    _7,     _8,     _9,     xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    \
        ___,    _0,     _4,     _5,     _6,     xxx,    xxx,    _AR_L,  _AR_D,  _AR_U,  _AR_R,  ___,    \
        ___,    xxx,    _1,     _2,     _3,     xxx,    xxx,    _HOME,  _PG_D,  _PG_U,  _END,   ___,    \
        ___,    ___,    ___,    ___,    ___,    TODEF,  ___,    SYMBOL, ADJUST, ___,    ___,    ___     \
    ),

    [LAYER_ADJUST] = LAYOUT( \
    /*  F1      F2      F3      F4      F5      F6     │F7      F8      F9      F10     F11     F12
        CAPS    FAST    SLOW    RCLK    LCLK    xxx    │xxx     MLEFT   MDOWN   MUP     MRIGHT  xxx
        xxx     xxx     xxx     xxx     xxx     xxx    │xxx     xxx     WHDOWN  WHUP    xxx     xxx
        xxx     QWERTY  COLMAK  HALMAK  xxx     TODEF  │xxx     SYMBOL  PLAY    VOL+    VOL-    RESET
        ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        _F1,    _F2,    _F3,    _F4,    _F5,    _F6,    _F7,    _F8,    _F9,    _F10,   _F11,   _F12,   \
        _CAPS,  _M_A2,  _M_A0,  _M_B2,  _M_B1,  xxx,    xxx,    _M_L,   _M_D,   _M_U,   _M_R,   xxx,    \
        xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    _M_WD,  _M_WU,  xxx,    xxx,    \
        xxx,    QWERTY, COLMAK, HALMAK, xxx,    TODEF,  xxx,    SYMBOL, _V_P,   _V_VU,  _V_VD,  RESET   \
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* Reset the layer to default. Will work with any number of default layers */
        case TODEF:
            if(record->event.pressed){
                /* default_layer_state is 0 until DF() is used to change it,
                 * then it is 2*<layer> (no idea why). We shift it to the
                 * right (divide by 2) to get the layer code
                 */
                layer_move(default_layer_state >> 1);
            }
    }
    return true;
}

