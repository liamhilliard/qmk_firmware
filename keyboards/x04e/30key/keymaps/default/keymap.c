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


/*
 Q* W  E* R  T  Y  U  I* O  P*
 A* S* D* F* G  H  J* K* L* ;*
 Z  X  C* V  B  N  M  ,* .  /

 * Custom QWERTY codes */
#define _Q_LALT    LALT_T(_Q)
#define _E_LARR    LT(LAYER_LEFT_ARROW, _E)
#define _I_RARR    LT(LAYER_RIGHT_ARROW, _I)
#define _P_RALT    RALT_T(_P)
/* --- */
#define _A_LGUI    LGUI_T(_A)
#define _S_LCTL    LCTL_T(_S)
#define _D_LSYM    LT(LAYER_LEFT_SYMBOL, _D)
#define _F_LSFT    LSFT_T(_F)
#define _J_RSFT    RSFT_T(_J)
#define _K_RSYM    LT(LAYER_RIGHT_SYMBOL, _K)
#define _L_RCTL    RCTL_T(_L)
#define _SCN_RGUI  LGUI_T(_SCN) // RGUI is MediaKey, so just use LGUI
/* --- */
#define _C_LNUM    LT(LAYER_LEFT_NUMBER, _C)
#define _COM_RNUM  LT(LAYER_RIGHT_NUMBER, _COM)


/*
 Q* W  F* P  B  J  L  U* Y  ;*
 A* R* S* T* G  M  N* E* I* O*
 Z  X  C* D  V  K  H  ,* .  /

 * Custom COLEMAK DH codes */
#define _F_LARR    LT(LAYER_LEFT_ARROW, _F)
#define _U_RARR    LT(LAYER_RIGHT_ARROW, _U)
#define _SCN_RALT  RALT_T(_SCN)
/* --- */
#define _R_LCTL    LCTL_T(_R)
#define _S_LSYM    LT(LAYER_LEFT_SYMBOL, _S)
#define _T_LSFT    LSFT_T(_T)
#define _N_RSFT    RSFT_T(_N)
#define _E_RSYM    LT(LAYER_RIGHT_SYMBOL, _E)
#define _I_RCTL    RCTL_T(_I)
#define _O_LGUI    LGUI_T(_O)

// TODO: Create adjust layer for changing keymaps/resetting?

#define LSYM    MO(LAYER_LEFT_SYMBOL)
#define RSYM    MO(LAYER_RIGHT_SYMBOL)
#define LNUM    MO(LAYER_LEFT_NUMBER)
#define RNUM    MO(LAYER_RIGHT_NUMBER)
#define LARR    MO(LAYER_LEFT_ARROW)
#define RARR    MO(LAYER_RIGHT_ARROW)
#define GAMING  DF(LAYER_GAMING) /* GAMING layer shouldn't be set persistently */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_QWERTY] = LAYOUT( \
     /* ────────── ────────── ────────── ────────── ──────────|────────── ────────── ────────── ────────── ────────── */
        _Q_LALT,   _W,        _E_LARR,   _R,        _T,        _Y,        _U,        _I_RARR,   _O,        _P_RALT,   \
        _A_LGUI,   _S_LCTL,   _D_LSYM,   _F_LSFT,   _G,        _H,        _J_RSFT,   _K_RSYM,   _L_RCTL,   _SCN_RGUI, \
        _Z,        _X,        _C_LNUM,   _V,        _B,        _N,        _M,        _COM_RNUM, _DOT,      _SL        \
    ),

    [LAYER_COLEMAK_DH] = LAYOUT( \
     /* ────────── ────────── ────────── ────────── ──────────|────────── ────────── ────────── ────────── ────────── */
        _Q_LALT,   _W,        _F_LARR,   _P,        _B,        _J,        _L,        _U_RARR,   _Y,        _SCN_RALT, \
        _A_LGUI,   _R_LCTL,   _S_LSYM,   _T_LSFT,   _G,        _M,        _N_RSFT,   _E_RSYM,   _R_LCTL,   _O_LGUI,   \
        _Z,        _X,        _C_LNUM,   _D,        _V,        _K,        _H,        _COM_RNUM, _DOT,      _SL        \
    ),

    [LAYER_LEFT_SYMBOL] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        xxx,    xxx,    xxx,    _TAB,   _DEL,   _RSB,   _PLS,   _AMP,   _LAB,   _RAB,   \
        xxx,    xxx,    TRNS,   _ESC,   _UPPR,  _RPR,   _DQT,   _USD,   _EX,    xxx,    \
        xxx,    xxx,    xxx,    _ENT,   xxx,    _RCB,   _EQ,    _AST,   _HSH,   _AT     \
    ),

    [LAYER_RIGHT_SYMBOL] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        _GBP,   _BTK,   _PIP,   _UND,   _LSB,   _DEL,   _TAB,   xxx,    xxx,    xxx,    \
        xxx,    _PRC,   _SQT,   _MIN,   _LPR,   _UPPR,  _ESC,   TRNS,   xxx,    xxx,    \
        _EUR,   _CRT,   _BSL,   _TLD,   _LCB,   xxx,    _ENT,   xxx,    xxx,    xxx     \
    ),

    [LAYER_LEFT_NUMBER] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        xxx,    xxx,    xxx,    _TAB,   _DEL,   xxx,    _7,     _8,     _9,     xxx,    \
        xxx,    xxx,    xxx,    _ESC,   _UPPR,  xxx,    _4,     _5,     _6,     _0,     \
        xxx,    xxx,    TRNS,   _ENT,   xxx,    xxx,    _1,     _2,     _3,     xxx     \
    ),

    [LAYER_RIGHT_NUMBER] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        xxx,    _7,     _8,     _9,     xxx,    _DEL,   _TAB,   xxx,    xxx,    xxx,    \
        _0,     _4,     _5,     _6,     xxx,    _UPPR,  _ESC,   xxx,    xxx,    xxx,    \
        xxx,    _1,     _2,     _3,     xxx,    xxx,    _ENT,   TRNS,   xxx,    xxx     \
    ),

    [LAYER_LEFT_ARROW] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        COLEMAK,QWERTY, TRNS,   _TAB,   _DEL,   _F6,    _F7,    _F8,    _F9,    _F10,   \
        _V_P,   _V_VD,  _V_VU,  _ESC,   _UPPR,  _F12,   _AR_L,  _AR_D,  _AR_U,  _AR_R,  \
        RESET,  xxx,    GAMING, _ENT,   xxx,    xxx,    _HOME,  _PG_D,  _PG_U,  _END    \
    ),

    [LAYER_RIGHT_ARROW] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        _F1,    _F2,    _F3,    _F4,    _F5,    _DEL,   _TAB,   TRNS,   QWERTY, COLEMAK,\
        _AR_L,  _AR_D,  _AR_U,  _AR_R,  _F12,   _UPPR,  _ESC,   _V_P,   _V_VD,  _V_VU,  \
        _HOME,  _PG_D,  _PG_U,  _END,   xxx,    xxx,    _ENT,   GAMING, xxx,    RESET   \
    ),

    [LAYER_GAMING] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── ─────── */
        _TAB,   _Q,     _W,     _E,     _R,     _T,     _Y,     _U,     _I,     _O,     \
        _ESC,   _A,     _S,     _D,     _F,     _G,     _H,     _J,     _K,     QWERTY, \
        _CTL,   _Z,     _X,     _C,     _V,     _B,     _N,     _M,     _COM,   COLEMAK \
    )

};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _E_LARR:   case _F_LARR:
        case _C_LNUM:   case _I_RARR:
        case _U_RARR:   case _COM_RNUM:
            return 180;
            break;

        /* Important symbol layer keys get short tapping term */
        case _D_LSYM:   case _S_LSYM:
        case _K_RSYM:   case _E_RSYM:
            return 120;

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
        case _Q_LALT:
        case _E_LARR:
        case _I_RARR:
        case _P_RALT:
        case _A_LGUI:
        case _S_LCTL:
        case _D_LSYM:
        case _F_LSFT:
        case _J_RSFT:
        case _K_RSYM:
        case _L_RCTL:
        case _C_LNUM:
        case _F_LARR:
        case _U_RARR:
        case _R_LCTL:
        case _S_LSYM:
        case _T_LSFT:
        case _N_RSFT:
        case _E_RSYM:
        case _I_RCTL:
        case _O_LGUI:

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
        case _SCN_RGUI:
        case _COM_RNUM:
        case _SCN_RALT:
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

