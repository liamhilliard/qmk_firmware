#include QMK_KEYBOARD_H
#include <print.h>
#include <shortcuts.h>

enum layers { QWERTY, LOWER, RAISE, ADJUST };

/* --- Row 1 --- */
#define _Q_M      LGUI_T(_Q)
#define _P_M      LGUI_T(_P)
/* --- Row 2 --- */
#define _A_M      LCTL_T(_A)
#define _S_M      LSFT_T(_S)
#define _L_M      LSFT_T(_L)
#define _SCN_M    LCTL_T(_SCN)
/* --- Row 3 --- */
#define _Z_M      LALT_T(_Z)
#define _SL_M     LALT_T(_SL)
/* --- Row 4 --- */
#define LWR       LT(LOWER, _SPC)
#define RSE       LT(RAISE, _BSPC)
/**/

/* Other mods */
#define ADJ       MO(ADJUST)
#define _DOT_M    LT(0, _DOT)
#define _UPPR     LT(0, KC_NO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [QWERTY] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── ─────── */
        _TAB,   _Q_M,   _W,     _E,     _R,     _T,     _Y,     _U,     _I,     _O,     _P_M,   _DEL,   \
        _ESC,   _A_M,   _S_M,   _D,     _F,     _G,     _H,     _J,     _K,     _L_M,   _SCN_M, _BSPC,  \
        _UPPR,  _Z_M,   _X,     _C,     _V,     _B,     _N,     _M,     _SPC,   _DOT_M, _SL_M,  _ENT,   \
        xxx,    xxx,    xxx,    xxx,    xxx,    LWR,    RSE,    xxx,    xxx,    xxx,    xxx,    xxx     \
    ),

    [LOWER] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── ─────── */
        ___,    _CRT,   _BTK,   _PIP,   _UND,   _LSB,   xxx,    xxx,    xxx,    xxx,    xxx,    ___,    \
        ___,    xxx,    _EX,    _SQT,   _MIN,   _LPR,   xxx,    _AR_L,  _AR_D,  _AR_U,  _AR_R,  ___,    \
        ___,    _EUR,   _AT,    _BSL,   _TLD,   _LCB,   xxx,    _HOME,  _PG_D,  _PG_U,  _END,   ___,    \
        xxx,    xxx,    xxx,    xxx,    xxx,    TRNS,   ADJ,    xxx,    xxx,    xxx,    xxx,    xxx     \
    ),

    [RAISE] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── ─────── */
        ___,    xxx,    _7,     _8,     _9,     xxx,    _RSB,   _PLS,   _AMP,   _LAB,   _PRC,   ___,    \
        ___,    _0,     _4,     _5,     _6,     xxx,    _RPR,   _DQT,   _USD,   _RAB,   xxx,    ___,    \
        ___,    xxx,    _1,     _2,     _3,     xxx,    _RCB,   _EQ,    _AST,   _HSH,   _GBP,   ___,    \
        xxx,    xxx,    xxx,    xxx,    xxx,    ADJ,    TRNS,   xxx,    xxx,    xxx,    xxx,    xxx     \
    ),

    [ADJUST] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── ─────── */
        ___,    _F1,    _F2,    _F3,    _F4,    _F5,    _F6,    _F7,    _F8,    _F9,    _F10,   ___,    \
        ___,    xxx,    _V_VD,  _V_VU,  _V_P,   _F11,   _F12,   _V_P,   _V_VD,  _V_VU,  xxx,    ___,    \
        ___,    RESET,  xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    RESET,  ___,    \
        xxx,    xxx,    xxx,    xxx,    xxx,    TRNS,   TRNS,   xxx,    xxx,    xxx,    xxx,    xxx     \
    )

};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* Important symbol layer keys get short tapping term */
        case _DOT_M:
            return 120;

        case _UPPR:
            return 200;

        case LWR: case RSE:
            return 180;

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
        case _A_M: case _S_M: case _L_M:
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
        case _SL_M:
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

//static uint16_t oneshot_timer; //static is persisted between function calls

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /* Custom handlers that don't stop key processing */
    process_capslock(keycode, record);

    // Time out oneshot mods
    /*if(timer_elapsed(oneshot_timer) > 1500){
        clear_oneshot_mods();
    }*/

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

