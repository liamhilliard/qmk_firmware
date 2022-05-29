#include QMK_KEYBOARD_H
#include <print.h>
#include <shortcuts.h>

enum layers {
    LAYER_QWERTY,       LAYER_COLEMAK_DH,
    LAYER_LEFT_SYMBOL,  LAYER_RIGHT_SYMBOL,
    LAYER_ARROW,
    LAYER_NUMBER,
    LAYER_LEFT_ADJUST,  LAYER_RIGHT_ADJUST
};

enum keycodes { QWERTY = SAFE_RANGE, COLEMAK };

#define LADJ       MO(LAYER_LEFT_ADJUST)
#define RADJ       MO(LAYER_RIGHT_ADJUST)

/*
 Q* W  E  R  T  Y  U  I  O  P*
 A* S* D* F* G  H  J* K* L* ;*
 Z  X  C* V  B  N  M  ,* .  ?
 * Custom QWERTY codes */
#define _Q_LGUI    LGUI_T(_Q)
#define _P_RGUI    LGUI_T(_P)
/* --- */
#define _A_LALT    LALT_T(_A)
#define _S_LCTL    LCTL_T(_S)
#define _D_LSYM    LT(LAYER_LEFT_SYMBOL, _D)
#define _F_SFT     LSFT_T(_F)
#define _J_SFT     LSFT_T(_J)
#define _K_RSYM    LT(LAYER_RIGHT_SYMBOL, _K)
#define _L_RCTL    LCTL_T(_L)
#define _SCN_RALT  LALT_T(_SCN)
/* --- */
#define _C_ARR     LT(LAYER_ARROW, _C)
#define _SPC_NUM   LT(LAYER_NUMBER, _SPC)

/*
 Q* W  F  P  B  J  L  U  Y  ;*
 A* R* S* T* G  M  N* E* I* O*
 Z  X  C* D  V  K  H  ,* .  ?
 * Custom COLEMAK DH codes */
#define _SCN_RGUI  LGUI_T(_SCN)
/* --- */
#define _R_LCTL    LCTL_T(_R)
#define _S_LSYM    LT(LAYER_LEFT_SYMBOL, _S)
#define _T_SFT     LSFT_T(_T)
#define _N_SFT     LSFT_T(_N)
#define _E_RSYM    LT(LAYER_RIGHT_SYMBOL, _E)
#define _I_RCTL    LCTL_T(_I)
#define _O_RALT    LALT_T(_O)
/* --- */

/* CAPS Word functionality */
#define _UPPR      LT(0, KC_NO)
#define _COM_DOT   LT(0, _DOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_QWERTY] = LAYOUT( \
     /* ────────── ────────── ────────── ────────── ──────────|────────── ────────── ────────── ────────── ────────── */
        _Q_LGUI,   _W,        _E,        _R,        _T,        _Y,        _U,        _I,         _O,       _P_RGUI,   \
        _A_LALT,   _S_LCTL,   _D_LSYM,   _F_SFT,    _G,        _H,        _J_SFT,    _K_RSYM,   _L_RCTL,   _SCN_RALT, \
        _Z,        _X,        _C_ARR,    _V,        _B,        _N,        _M,        _SPC_NUM,  _COM_DOT,  _SL        \
    ),

    [LAYER_COLEMAK_DH] = LAYOUT( \
     /* ────────── ────────── ────────── ────────── ──────────|────────── ────────── ────────── ────────── ────────── */
        _Q_LGUI,   _W,        _F,        _P,        _B,        _J,        _L,        _U,        _Y,        _SCN_RGUI, \
        _A_LALT,   _R_LCTL,   _S_LSYM,   _T_SFT,    _G,        _M,        _N_SFT,    _E_RSYM,   _I_RCTL,   _O_RALT,   \
        _Z,        _X,        _C_ARR,    _D,        _V,        _K,        _H,        _SPC_NUM,  _COM_DOT,  _SL        \
    ),

    [LAYER_LEFT_SYMBOL] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        xxx,    xxx,    xxx,    _TAB,   xxx,    _RSB,   _PLS,   _AMP,   _LAB,   _RAB,   \
        _UPPR,  LADJ,   xxx,    _BSPC,  xxx,    _RPR,   _DQT,   _USD,   _EX,    xxx,    \
        xxx,    xxx,    xxx,    _ESC,   xxx,    _RCB,   _EQ,    _AST,   _HSH,   _AT     \
    ),

    [LAYER_RIGHT_SYMBOL] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        _GBP,   _BTK,   _PIP,   _UND,   _LSB,   xxx,    _DEL,   xxx,    xxx,    xxx,    \
        xxx,    _PRC,   _SQT,   _MIN,   _LPR,   xxx,    _BSPC,  xxx,    RADJ,   _UPPR,  \
        _EUR,   _CRT,   _BSL,   _TLD,   _LCB,   xxx,    _ENT,   xxx,    xxx,    xxx     \
    ),

    [LAYER_ARROW] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        xxx,    xxx,    xxx,    _TAB,   xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    \
        _UPPR,  LADJ,   xxx,    _BSPC,  xxx,    xxx,    _AR_L,  _AR_D,  _AR_U,  _AR_R,  \
        xxx,    xxx,    xxx,    _ESC,   xxx,    xxx,    _HOME,  _PG_D,  _PG_U,  _END    \
    ),

    [LAYER_NUMBER] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        xxx,    _7,     _8,     _9,     xxx,    xxx,    _DEL,   xxx,    xxx,    xxx,    \
        _0,     _4,     _5,     _6,     xxx,    xxx,    _BSPC,  xxx,    RADJ,   _UPPR,  \
        xxx,    _1,     _2,     _3,     xxx,    xxx,    _ENT,   xxx,    xxx,    xxx     \
    ),

    [LAYER_LEFT_ADJUST] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        COLEMAK,QWERTY, xxx,    _TAB,   xxx,    _F6,    _F7,    _F8,    _F9,    _F10,   \
        _UPPR,  TRNS,   xxx,    _BSPC,  xxx,    _F12,   _V_P,   _V_VD,  _V_VU,  xxx,    \
        RESET,  xxx,    xxx,    _ESC,   xxx,    xxx,    xxx,    xxx,    xxx,    xxx     \
    ),

    [LAYER_RIGHT_ADJUST] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        _F1,    _F2,    _F3,    _F4,    _F5,    xxx,    _DEL,   xxx,    QWERTY, COLEMAK,\
        xxx,    _V_VD,  _V_VU,  _V_P,   _F12,   xxx,    _BSPC,  xxx,    TRNS,   _UPPR,  \
        xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    _ENT,   xxx,    xxx,    RESET   \
    )

};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _C_ARR:
        case _SPC_NUM:
            return 180;

        /* Important symbol layer keys get short tapping term */
        case _D_LSYM:   case _S_LSYM:
        case _K_RSYM:   case _E_RSYM:
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

        /* Keep capslock on for the following keys */
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

        /* Don't disable capslock when symbol keys are held for layers/mods */
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

        /* Disable capslock for all other key presses */
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

void process_persistent_layer(uint16_t keycode, keyrecord_t *record){
    if (is_released(record)) return;

    switch(keycode){
        case QWERTY:
            set_single_persistent_default_layer(LAYER_QWERTY);

        case COLEMAK:
            set_single_persistent_default_layer(LAYER_COLEMAK_DH);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /* Custom handlers that don't stop key processing */
    process_capslock(keycode, record);
    process_persistent_layer(keycode, record);

    switch(keycode) {
        case _COM_DOT:
            if(is_held(record) && is_pressed(record)) {
                tap_code16(_COM);
                return false;
            }
            break;
    }
    return true;
}

