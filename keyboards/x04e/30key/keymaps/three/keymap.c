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
#define _S_M      LALT_T(_S)
#define _D_M      LSFT_T(_D)
#define _F_M      LT(LAYER_LEFT_ARROW, _F)
#define _J_M      LT(LAYER_RIGHT_NUMBER, _J)
#define _K_M      LSFT_T(_K)
#define _L_M      LALT_T(_L)
#define _SCN_M    LCTL_T(_SCN)
/* --- */
#define _Z_M      LT(LAYER_LEFT_SYMBOL, _Z)
#define _V_M      LT(LAYER_LEFT_SYMBOL, _V)
#define _M_M      LT(LAYER_RIGHT_SYMBOL, _M)
#define _DOT_M    LALT_T(_DOT)
#define _SL_M     LT(LAYER_RIGHT_SYMBOL, _SL)

/* Other mods */
#define _UPPR     LT(0, KC_NO)
#define _BTK_M    LT(0, _BTK)
#define _PLS_M    LT(0, _PLS)
#define _AMP_M    LT(0, _AMP)
#define _AST_M    LT(0, _AST)

const uint16_t PROGMEM tab_combo[] =  { _W,     _E,     COMBO_END };
const uint16_t PROGMEM esc_combo[] =  { _S_M,   _D_M,   COMBO_END };
const uint16_t PROGMEM del_combo[] =  { _I,     _O,     COMBO_END };
const uint16_t PROGMEM bspc_combo[] = { _K_M,   _L_M,   COMBO_END };
const uint16_t PROGMEM ent_combo[] =  { _SPC,   _DOT_M, COMBO_END };
combo_t key_combos[COMBO_COUNT] = {
    COMBO(tab_combo,  _TAB),
    COMBO(esc_combo,  _ESC),
    COMBO(del_combo,  _DEL),
    COMBO(bspc_combo, _BSPC),
    COMBO(ent_combo,  _ENT)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_QWERTY] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        _Q_M,   _W,     _E,     _R,     _T,     _Y,     _U,     _I,     _O,     _P_M,    \
        _A_M,   _S_M,   _D_M,   _F_M,   _G,     _H,     _J_M,   _K_M,   _L_M,   _SCN_M,  \
        _Z_M,   _X,     _C,     _V_M,   _B,     _N,     _M_M,   _SPC,   _DOT_M, _SL_M    \
    ),

    [LAYER_LEFT_SYMBOL] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        xxx,    xxx,    xxx,    xxx,    xxx,    _RAB,   _UND,   _AMP_M, _AST_M, _DEL,    \
        xxx,    xxx,    xxx,    xxx,    xxx,    _LAB,   _MIN,   _DQT,   _USD,   _BSPC,   \
        xxx,    xxx,    xxx,    xxx,    xxx,    _EX,    _PIP,   _TLD,   _HSH,   _ENT     \
    ),

    [LAYER_RIGHT_SYMBOL] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        _TAB,   _BTK_M, _PLS_M, _LSB,   _RSB,   xxx,    xxx,   xxx,    xxx,    xxx,    \
        _ESC,   _EQ,    _SQT,   _LPR,   _RPR,   xxx,    xxx,   xxx,    xxx,    xxx,    \
        _UPPR,  _AT,    _BSL,   _LCB,   _RCB,   xxx,    xxx,   xxx,    xxx,    xxx     \
    ),

    [LAYER_LEFT_ARROW] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    \
        xxx,    xxx,    LADJ,   xxx,    xxx,    xxx,    _AR_L,  _AR_D,  _AR_U,  _AR_R,  \
        xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    _HOME,  _PG_D,  _PG_U,  _END    \
    ),

    [LAYER_RIGHT_NUMBER] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        xxx,    _7,     _8,     _9,     xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    \
        _0,     _4,     _5,     _6,     xxx,    xxx,    xxx,    RADJ,   xxx,    xxx,    \
        xxx,    _1,     _2,     _3,     xxx,    xxx,    xxx,    xxx,    xxx,    xxx     \
    ),

    [LAYER_LEFT_ADJUST] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        xxx,    xxx,    xxx,    xxx,    xxx,    _F6,    _F7,    _F8,    _F9,    _F10,   \
        xxx,    xxx,    TRNS,   xxx,    xxx,    _F12,   _V_P,   _V_VD,  _V_VU,  xxx,    \
        RESET,  xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx     \
    ),

    [LAYER_RIGHT_ADJUST] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        _F1,    _F2,    _F3,    _F4,    _F5,    xxx,    xxx,    xxx,    xxx,    xxx,    \
        xxx,    _V_VD,  _V_VU,  _V_P,   _F11,   xxx,    xxx,    TRNS,   xxx,    xxx,    \
        xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    RESET   \
    )

};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _BTK_M: case _PLS_M:
        case _AMP_M: case _AST_M:
            return 180;

        /* Important symbol layer keys get short tapping term */
        case _M_M: case _SL_M:
        case _Z_M: case _V_M:
        case _F_M: case _J_M:
            return 120;

        case _UPPR:
            return 300;

        default:
            return TAPPING_TERM;
    }
}

static bool caps_on = false; /* Tracks state of CAPSLOCK */
static bool caps_word_on = false; /* Tracks whether caps word is active */

bool is_pressed(keyrecord_t *record) { return record->event.pressed; }
bool is_released(keyrecord_t *record) { return !is_pressed(record); }
bool is_tapped(keyrecord_t *record) { return record->tap.count; }
bool is_held(keyrecord_t *record) { return !is_tapped(record); }


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
        case _Z_M: case _V_M: case _M_M:
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
        case _BTK_M:
            if(is_tapped(record)){
                if(is_pressed(record)) {
                    register_code16(_BTK);
                } else {
                    unregister_code16(_BTK);
                }
            } else {
                if(is_pressed(record)) {
                    register_code16(_GBP);
                } else {
                    unregister_code16(_GBP);
                }
            }
            return false;
            break;
        case _PLS_M:
            if(is_tapped(record)){
                if(is_pressed(record)) {
                    register_code16(_PLS);
                } else {
                    unregister_code16(_PLS);
                }
            } else {
                if(is_pressed(record)) {
                    register_code16(_CRT);
                } else {
                    unregister_code16(_CRT);
                }
            }
            return false;
            break;
        case _AMP_M:
            if(is_tapped(record)){
                if(is_pressed(record)) {
                    register_code16(_AMP);
                } else {
                    unregister_code16(_AMP);
                }
            } else {
                if(is_pressed(record)) {
                    register_code16(_PRC);
                } else {
                    unregister_code16(_PRC);
                }
            }
            return false;
            break;
        case _AST_M:
            if(is_tapped(record)){
                if(is_pressed(record)) {
                    register_code16(_AST);
                } else {
                    unregister_code16(_AST);
                }
            } else {
                if(is_pressed(record)) {
                    register_code16(_EUR);
                } else {
                    unregister_code16(_EUR);
                }
            }
            return false;
            break;
    }
    return true;
}


