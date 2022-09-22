#include QMK_KEYBOARD_H
#include <print.h>
#include <shortcuts.h>

enum layers {
    LAYER_QWERTY,
    LAYER_LEFT_SYMBOL,  LAYER_RIGHT_SYMBOL,
    LAYER_ARROW,
    LAYER_NUMBER,
    LAYER_LEFT_ADJUST,  LAYER_RIGHT_ADJUST
};

#define LADJ       MO(LAYER_LEFT_ADJUST)
#define RADJ       MO(LAYER_RIGHT_ADJUST)

/* Custom QWERTY codes */
#define _Q_LGUI    LGUI_T(_Q)
#define _P_RGUI    LGUI_T(_P)
/* --- */
#define _A_LCTL    LCTL_T(_A)
#define _S_LSFT    LSFT_T(_S)
#define _D_LSYM    LT(LAYER_LEFT_SYMBOL, _D)
#define _F_LARR    LT(LAYER_ARROW, _F)
#define _J_RNUM    LT(LAYER_NUMBER, _J)
#define _K_RSYM    LT(LAYER_RIGHT_SYMBOL, _K)
#define _L_RSFT    LSFT_T(_L)
#define _SCN_RCTL  LCTL_T(_SCN)
/* --- */
#define _Z_LALT    LALT_T(_Z)
#define _SL_RALT   LALT_T(_SL)

/* Other mods */
#define _UPPR      LT(0, KC_NO)
#define _COM_DOT   LT(0, _DOT)
#define _R_TAB     LT(0, _R)
#define _V_ESC     LT(0, _V)
#define _U_DEL     LT(0, _U)
#define _M_ENT     LT(0, _M)
#define _C_BSPC    LT(0, _C)
#define _SPC_BSPC  LT(0, _SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_QWERTY] = LAYOUT( \
     /* ────────── ────────── ────────── ────────── ──────────|────────── ────────── ────────── ────────── ────────── */
        _Q_LGUI,   _W,        _E,        _R_TAB,    _T,        _Y,        _U_DEL,    _I,        _O,        _P_RGUI,   \
        _A_LCTL,   _S_LSFT,   _D_LSYM,   _F_LARR,   _G,        _H,        _J_RNUM,   _K_RSYM,   _L_RSFT,   _SCN_RCTL, \
        _Z_LALT,    _X,       _C_BSPC,   _V_ESC,    _B,        _N,        _M_ENT,    _SPC_BSPC, _COM_DOT,  _SL_RALT   \
    ),

    [LAYER_LEFT_SYMBOL] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        xxx,    xxx,    xxx,    xxx,    xxx,    _RSB,   _PLS,   _AMP,   _LAB,   _RAB,   \
        _UPPR,  LADJ,   xxx,    xxx,    xxx,    _RPR,   _DQT,   _USD,   _EX,    xxx,    \
        xxx,    xxx,    xxx,    xxx,    xxx,    _RCB,   _EQ,    _AST,   _HSH,   _AT     \
    ),

    [LAYER_RIGHT_SYMBOL] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        _GBP,   _BTK,   _PIP,   _UND,   _LSB,   xxx,    xxx,    xxx,    xxx,    xxx,    \
        xxx,    _PRC,   _SQT,   _MIN,   _LPR,   xxx,    xxx,    xxx,    RADJ,   _UPPR,  \
        _EUR,   _CRT,   _BSL,   _TLD,   _LCB,   xxx,    xxx,    xxx,    xxx,    xxx     \
    ),

    [LAYER_ARROW] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    \
        _UPPR,  LADJ,   xxx,    xxx,    xxx,    xxx,    _AR_L,  _AR_D,  _AR_U,  _AR_R,  \
        xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    _HOME,  _PG_D,  _PG_U,  _END    \
    ),

    [LAYER_NUMBER] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        xxx,    _7,     _8,     _9,     xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    \
        _0,     _4,     _5,     _6,     xxx,    xxx,    xxx,    xxx,    RADJ,   _UPPR,  \
        xxx,    _1,     _2,     _3,     xxx,    xxx,    xxx,    xxx,    xxx,    xxx     \
    ),

    [LAYER_LEFT_ADJUST] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        xxx,    xxx,    xxx,    xxx,    xxx,    _F6,    _F7,    _F8,    _F9,    _F10,   \
        _UPPR,  TRNS,   xxx,    xxx,    xxx,    _F12,   _V_P,   _V_VD,  _V_VU,  xxx,    \
        RESET,  xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx     \
    ),

    [LAYER_RIGHT_ADJUST] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        _F1,    _F2,    _F3,    _F4,    _F5,    xxx,    xxx,    xxx,    xxx,    xxx,    \
        xxx,    _V_VD,  _V_VU,  _V_P,   _F11,   xxx,    xxx,    xxx,    TRNS,   _UPPR,  \
        xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    RESET   \
    )

};

void keyboard_post_init_user(void){
    debug_enable = true;
    //debug_matrix = true;
    //debug_keyboard = true;
    //debug_mouse = true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _F_LARR:
        case _J_RNUM:
            return 180;

        /* Important symbol layer keys get short tapping term */
        case _R_TAB:    case _U_DEL:
        case _D_LSYM:   case _K_RSYM:
        case _C_BSPC:   case _V_ESC:
        case _M_ENT:    case _SPC_BSPC:
        case _COM_DOT:
            return 120;

        case _UPPR:
            return 200;

        default:
            return TAPPING_TERM;
    }
}

//static bool caps_on = false; /* Tracks state of CAPSLOCK */
//static bool caps_word_on = false; /* Tracks whether caps word is active */

bool is_pressed(keyrecord_t *record) { return record->event.pressed; }
bool is_released(keyrecord_t *record) { return !is_pressed(record); }
bool is_tapped(keyrecord_t *record) { return record->tap.count; }
bool is_held(keyrecord_t *record) { return !is_tapped(record); }

/*
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
        case _Q_LGUI: case _P_RGUI: case _A_LALT: case _S_LCTL: case _D_LSYM:
        case _F_SFT:  case _J_SFT:  case _K_RSYM: case _L_RCTL: case _C_ARR:
        case _R_LCTL: case _S_LSYM: case _T_SFT:  case _N_SFT:  case _E_RSYM:
        case _I_RCTL: case _O_RALT:
        case _A: case _B: case _C: case _D: case _E: case _F: case _G: case _H:
        case _I: case _J: case _K: case _L: case _M: case _N: case _O: case _P:
        case _Q: case _R: case _S: case _T: case _U: case _V: case _W: case _X:
        case _Y: case _Z:
        case _1: case _2: case _3: case _4: case _5: case _6: case _7: case _8:
        case _9: case _0:
        case _UND: case _MIN: case _BSPC: case _DEL:
            break;

        // Don't disable capslock when symbol keys are held for layers/mods
        case _SCN_RALT:
        case _SPC_NUM:
        case _SCN_RGUI:
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
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /* Custom handlers that don't stop key processing */
    //process_capslock(keycode, record);
    //process_persistent_layer(keycode, record);

    switch(keycode) {
        case _C_BSPC:
        case _SPC_BSPC:
            if(is_held(record)){
                if(is_pressed(record)) {
                    register_code16(_BSPC);
                } else {
                    unregister_code16(_BSPC);
                }
                return false;
            }
            break;
        case _COM_DOT:
            if(is_held(record)){
                if(is_pressed(record)) {
                    register_code16(_COM);
                } else {
                    unregister_code16(_COM);
                }
                return false;
            }
            break;
        case _R_TAB:
            if(is_held(record)){
                if(is_pressed(record)) {
                    register_code16(_TAB);
                } else {
                    unregister_code16(_TAB);
                }
                return false;
            }
            break;
        case _U_DEL:
            if(is_held(record)){
                if(is_pressed(record)) {
                    register_code16(_DEL);
                } else {
                    unregister_code16(_DEL);
                }
                return false;
            }
            break;
        case _V_ESC:
            if(is_held(record)){
                if(is_pressed(record)) {
                    register_code16(_ESC);
                } else {
                    unregister_code16(_ESC);
                }
                return false;
            }
            break;
        case _M_ENT:
            if(is_held(record)){
                if(is_pressed(record)) {
                    register_code16(_ENT);
                } else {
                    unregister_code16(_ENT);
                }
                return false;
            }
            break;
    }
    return true;
}

