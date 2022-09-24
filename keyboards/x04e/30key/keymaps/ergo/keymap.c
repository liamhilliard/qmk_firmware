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
#define _BSPC_CTL  LCTL_T(_BSPC)
/* --- */
#define _Z_LALT    LALT_T(_Z)
#define _SL_RALT   LALT_T(_SL)

/* Other mods */
#define _UPPR      LT(0, KC_NO)
#define _COM_DOT   LT(0, _DOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_QWERTY] = LAYOUT( \
     /* ────────── ────────── ────────── ────────── ──────────|────────── ────────── ────────── ────────── ────────── */
        _Q_LGUI,   _W,        _E,        _R,        _T,        _Y,        _U,        _I,        _O,        _P_RGUI,   \
        _A_LCTL,   _S_LSFT,   _D_LSYM,   _F_LARR,   _G,        _H,        _J_RNUM,   _K_RSYM,   _L_RSFT,   _BSPC_CTL, \
        _Z_LALT,    _X,       _C,        _V,        _B,        _N,        _M,        _SPC,      _COM_DOT,  _SL_RALT   \
    ),

    [LAYER_LEFT_SYMBOL] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        xxx,    xxx,    xxx,    _TAB,   xxx,    _RSB,   _PLS,   _AMP,   _LAB,   _RAB,   \
        _UPPR,  LADJ,   xxx,    _BSPC,  xxx,    _RPR,   _DQT,   _USD,   _EX,    _CN,   \
        xxx,    xxx,    xxx,    _ESC,   xxx,    _RCB,   _EQ,    _AST,   _HSH,   _AT     \
    ),

    [LAYER_RIGHT_SYMBOL] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        _GBP,   _BTK,   _PIP,   _UND,   _LSB,   xxx,    _DEL,   xxx,    xxx,    xxx,    \
        _SCN,   _PRC,   _SQT,   _MIN,   _LPR,   xxx,    xxx,    xxx,    RADJ,   _UPPR,  \
        _EUR,   _CRT,   _BSL,   _TLD,   _LCB,   xxx,    _ENT,   xxx,    xxx,    xxx     \
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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _F_LARR:
        case _J_RNUM:
            return 180;

        /* Important symbol layer keys get short tapping term */
        case _D_LSYM:   case _K_RSYM:
        case _COM_DOT:
            return 120;

        case _UPPR:
            return 200;

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
        case _Q_LGUI: case _P_RGUI:
        case _A_LCTL: case _S_LSFT: case _D_LSYM: case _F_LARR:
        case _J_RNUM: case _K_RSYM: case _L_RSFT:
        case _Z_LALT:
        case _A: case _B: case _C: case _D: case _E: case _F: case _G: case _H:
        case _I: case _J: case _K: case _L: case _M: case _N: case _O: case _P:
        case _Q: case _R: case _S: case _T: case _U: case _V: case _W: case _X:
        case _Y: case _Z:
        case _1: case _2: case _3: case _4: case _5: case _6: case _7: case _8:
        case _9: case _0:
        case _UND: case _MIN: case _BSPC: case _DEL:
            break;

        // Don't disable capslock when symbol keys are held for layers/mods
        case _BSPC_CTL:
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
    }
    return true;
}

