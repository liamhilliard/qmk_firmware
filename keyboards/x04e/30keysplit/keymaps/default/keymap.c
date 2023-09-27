#include QMK_KEYBOARD_H
#include <print.h>
#include <shortcuts.h>

enum layers {
    LAYER_QWERTY,
    LAYER_LEFT_SYMBOL,  LAYER_RIGHT_SYMBOL,
    LAYER_LEFT_ARROW,   LAYER_RIGHT_NUMBER,
    LAYER_LEFT_ADJUST,  LAYER_RIGHT_ADJUST
};

#define LADJ      MO(LAYER_LEFT_ADJUST)
#define RADJ      MO(LAYER_RIGHT_ADJUST)

/* Custom QWERTY codes */
#define _Q_M      LGUI_T(_Q)
#define _P_M      LGUI_T(_P)
/* --- */
#define _A_M      LCTL_T(_A)
#define _S_M      LSFT_T(_S)
#define _D_M      LT(LAYER_LEFT_SYMBOL, _D)
#define _F_M      LT(LAYER_LEFT_ARROW, _F)
#define _J_M      LT(LAYER_RIGHT_NUMBER, _J)
#define _K_M      LT(LAYER_RIGHT_SYMBOL, _K)
#define _L_M      LSFT_T(_L)
#define _SCN_M    LCTL_T(_SCN)
/* --- */
#define _Z_M      LALT_T(_Z)
#define _SL_M     LALT_T(_SL)

/* Other mods */
#define _UPPR     LT(0, KC_NO)
#define _DOT_M    LT(0, _DOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_QWERTY] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ───────  ─────── ─────── */
        _TAB,   _Q_M,   _W,     _E,     _R,     _T,     _Y,     _U,     _I,     _O,      _P_M,   _DEL,   \
        _ESC,   _A_M,   _S_M,   _D_M,   _F_M,   _G,     _H,     _J_M,   _K_M,   _L_M,    _SCN_M, _BSPC,  \
        _UPPR,  _Z_M,   _X,     _C,     _V,     _B,     _N,     _M,     _SPC,   _DOT_M,  _SL_M,  _ENT    \
    ),


    [LAYER_LEFT_SYMBOL] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ───────  ─────── ─────── */
        xxx,    xxx,    xxx,    xxx,    _TAB,    xxx,    _RSB,   _PLS,   _AMP,   _LAB,    _AT,     xxx,   \
        xxx,    xxx,    LADJ,   xxx,    _ESC,    xxx,    _RPR,   _DQT,   _USD,   _RAB,    _BSPC,   xxx,   \
        xxx,    xxx,    xxx,    xxx,    xxx,     xxx,    _RCB,   _EQ,    _AST,   _HSH,    _EX,     xxx    \
    ),

    [LAYER_RIGHT_SYMBOL] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ───────  ─────── ─────── */
        xxx,    _GBP,   _BTK,   _PIP,   _UND,   _LSB,   xxx,    xxx,    xxx,    xxx,     xxx,    xxx,    \
        xxx,    _BSPC,  _PRC,   _SQT,   _MIN,   _LPR,   xxx,    _ENT,   xxx,    RADJ,    xxx,    xxx,    \
        xxx,    _EUR,   _CRT,   _BSL,   _TLD,   _LCB,   xxx,    _DEL,   xxx,    xxx,     xxx,    xxx     \
    ),

    [LAYER_LEFT_ARROW] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ───────  ─────── ─────── */
        xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,     xxx,    xxx,    \
        xxx,    xxx,    xxx,    LADJ,   xxx,    xxx,    xxx,    _AR_L,  _AR_D,  _AR_U,   _AR_R,  xxx,    \
        xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    _HOME,  _PG_D,  _PG_U,   _END,   xxx     \
    ),

    [LAYER_RIGHT_NUMBER] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ───────  ─────── ─────── */
        xxx,    xxx,    _7,     _8,     _9,     xxx,    xxx,    xxx,    xxx,    xxx,     xxx,    xxx,    \
        xxx,    _0,     _4,     _5,     _6,     xxx,    xxx,    xxx,    xxx,    RADJ,    xxx,    xxx,    \
        xxx,    xxx,    _1,     _2,     _3,     xxx,    xxx,    xxx,    xxx,    xxx,     xxx,    xxx     \
    ),

    [LAYER_LEFT_ADJUST] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ───────  ─────── ─────── */
        xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    _F6,    _F7,    _F8,    _F9,     _F10,   xxx,    \
        xxx,    xxx,    TRNS,   TRNS,   xxx,    xxx,    _F12,   _V_P,   _V_VD,  _V_VU,   xxx,    xxx,    \
        xxx,    RESET,  xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,     xxx,    xxx     \
    ),

    [LAYER_RIGHT_ADJUST] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ───────  ─────── ─────── */
        xxx,    _F1,    _F2,    _F3,    _F4,    _F5,    xxx,    xxx,    xxx,    xxx,     xxx,    xxx,    \
        xxx,    xxx,    _V_VD,  _V_VU,  _V_P,   _F11,   xxx,    xxx,    TRNS,   TRNS,    xxx,    xxx,    \
        xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,     RESET,  xxx     \
    )

};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _Z_M: case _SL_M:
            return 180;

        /* Important symbol layer keys get short tapping term */
        case _DOT_M:
        case _D_M: case _K_M:
            return 120;

        case _UPPR:
            return 200;

        default:
            return TAPPING_TERM;
    }
}

static bool caps_on = false; /* Tracks state of CAPSLOCK */
static bool caps_word_on = false; /* Tracks whether caps word is active */

void process_capslock(uint16_t keycode, keyrecord_t *record){
    #ifdef CONSOLE_ENABLE
        uprintf("0x%04X,%u,%u,%u,%b,0x%02X,0x%02X,%u\n",
             keycode,
             record->event.key.row,
             record->event.key.col,
             get_highest_layer(layer_state),
             record->event.pressed,
             get_mods(),
             get_oneshot_mods(),
             record->tap.count
         );
    #endif

    switch(keycode) {

        case _UPPR:
            if(is_pressed(record)) {
                tap_code16(_CAPS);
                caps_on = !caps_on;

                if(is_tapped(record)) {
                    //tapped - treated as caps word
                    caps_word_on = caps_on;

                } else {
                    //held - treated as caps lock
                    caps_word_on = false;
                }
            }
            break;

        // Keep capslock on for the following keys
        case _Q_M: case _P_M:
        case _A_M: case _S_M: case _D_M: case _F_M: case _J_M: case _K_M: case _L_M:
        case _Z_M: case _SL_M:
        case _A: case _B: case _C: case _D: case _E: case _F: case _G: case _H:
        case _I: case _J: case _K: case _L: case _M: case _N: case _O: case _P:
        case _Q: case _R: case _S: case _T: case _U: case _V: case _W: case _X:
        case _Y: case _Z:
        case _1: case _2: case _3: case _4: case _5: case _6: case _7: case _8:
        case _9: case _0:
        case _UND: case _MIN: case _BSPC: case _DEL:
            break;

        // Don't disable capslock when symbol keys are held for layers/mods
        case _SCN_M:
            if(is_tapped(record) && is_pressed(record)) {
                if(caps_word_on){
                    tap_code16(_CAPS);
                    caps_on = !caps_on;
                    caps_word_on = false;
                }
            }
            break;

        // Disable capslock for all other key presses
        default:
            if(is_pressed(record)) {
                if(caps_word_on){
                    tap_code16(_CAPS);
                    caps_on = !caps_on;
                    caps_word_on = false;
                }
            }
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /* Custom handlers that don't stop key processing */
    process_capslock(keycode, record);

    switch(keycode) {

        case _DOT_M:
            if(is_held(record)){
                if(is_pressed(record)) {
                    register_code16(_COM);
                } else {
                    unregister_code16(_COM);
                }
                return false;
            }
            break;
    }
    return true;
}


