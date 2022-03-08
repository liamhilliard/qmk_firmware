#include QMK_KEYBOARD_H
#include <print.h>
#include <shortcuts.h>

enum layers {
    LAYER_QWERTY,
    LAYER_COLEMAK_DH,
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
#define _P_RALT    RALT_T(_P)
/* --- */
#define _A_LCTL    LCTL_T(_A)
#define _S_LSFT    LSFT_T(_S)
#define _D_LSYM    LT(LAYER_LEFT_SYMBOL, _D)
#define _QF_SPC    LT(LAYER_QWERTY, _F)
#define _QG_BSPC   LT(LAYER_QWERTY, _G)
#define _QH_BSPC   LT(LAYER_QWERTY, _H)
#define _QJ_SPC    LT(LAYER_QWERTY, _J)
#define _K_RSYM    LT(LAYER_RIGHT_SYMBOL, _K)
#define _L_RSFT    RSFT_T(_L)
#define _SCN_RCTL  RCTL_T(_SCN)
/* --- */
#define _Z_LGUI    LGUI_T(_Z)
#define _C_LNUM    LT(LAYER_LEFT_NUMBER, _C)
#define _V_LARR    LT(LAYER_LEFT_ARROW, _V)
#define _M_RARR    LT(LAYER_RIGHT_ARROW, _M)
#define _COM_RNUM  LT(LAYER_RIGHT_NUMBER, _COM)
#define _SL_RGUI   LGUI_T(_SL)


/*
 Q* W  F* P  B  J  L  U* Y  ;*
 A* R* S* T* G  M  N* E* I* O*
 Z  X  C* D  V  K  H  ,* .  /

 * Custom COLEMAK DH codes */
#define _SCN_RALT  RALT_T(_SCN)
/* --- */
#define _R_LSFT    LSFT_T(_R)
#define _S_LSYM    LT(LAYER_LEFT_SYMBOL, _S)
#define _CT_SPC    LT(LAYER_COLEMAK_DH, _T)
#define _CG_BSPC   LT(LAYER_COLEMAK_DH, _G)
#define _CM_BSPC   LT(LAYER_COLEMAK_DH, _M)
#define _CN_SPC    LT(LAYER_COLEMAK_DH, _N)
#define _E_RSYM    LT(LAYER_RIGHT_SYMBOL, _E)
#define _I_RSFT    RSFT_T(_I)
#define _O_RCTL    RCTL_T(_O)
/* --- */
#define _D_LARR    LT(LAYER_LEFT_ARROW, _D)
#define _H_RARR    LT(LAYER_RIGHT_ARROW, _H)

// TODO: Create adjust layer for changing keymaps/resetting?

#define LSYM    MO(LAYER_LEFT_SYMBOL)
#define RSYM    MO(LAYER_RIGHT_SYMBOL)
#define LNUM    MO(LAYER_LEFT_NUMBER)
#define RNUM    MO(LAYER_RIGHT_NUMBER)
#define LARR    MO(LAYER_LEFT_ARROW)
#define RARR    MO(LAYER_RIGHT_ARROW)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_QWERTY] = LAYOUT( \
     /* ────────── ────────── ────────── ────────── ──────────|────────── ────────── ────────── ────────── ────────── */
        _Q_LALT,   _W,        _E,        _R,        _T,        _Y,        _U,        _I,         _O,       _P_RALT,   \
        _A_LCTL,   _S_LSFT,   _D_LSYM,   _QF_SPC,   _QG_BSPC,  _QH_BSPC,  _QJ_SPC,   _K_RSYM,   _L_RSFT,   _SCN_RCTL, \
        _Z_LGUI,   _X,        _C_LNUM,   _V_LARR,   _B,        _N,        _M_RARR,   _COM_RNUM, _DOT,      _SL_RGUI   \
    ),

    [LAYER_COLEMAK_DH] = LAYOUT( \
     /* ────────── ────────── ────────── ────────── ──────────|────────── ────────── ────────── ────────── ────────── */
        _Q_LALT,   _W,        _F,        _P,        _B,        _J,        _L,        _U,        _Y,        _SCN_RALT, \
        _A_LCTL,   _R_LSFT,   _S_LSYM,   _CT_SPC,  _CG_BSPC,   _CM_BSPC,  _CN_SPC,   _E_RSYM,   _I_RSFT,   _O_RCTL,   \
        _Z_LGUI,   _X,        _C_LNUM,   _D_LARR,   _V,        _K,        _H_RARR,   _COM_RNUM, _DOT,      _SL_RGUI   \
    ),

    [LAYER_LEFT_SYMBOL] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        xxx,    xxx,    xxx,    _TAB,   _DEL,   _RSB,   _PLS,   _AMP,   _LAB,   _RAB,   \
        xxx,    xxx,    TRNS,   _ESC,   _UPPR,  _RPR,   _DQT,   _USD,   _EX,    xxx,    \
        xxx,    xxx,    xxx,    _ENT,   _CAPS,  _RCB,   _EQ,    _AST,   _HSH,   _AT     \
    ),

    [LAYER_RIGHT_SYMBOL] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        _GBP,   _BTK,   _PIP,   _UND,   _LSB,   _DEL,   _TAB,   xxx,    xxx,    xxx,    \
        xxx,    _PRC,   _SQT,   _MIN,   _LPR,   _UPPR,  _ESC,   TRNS,   xxx,    xxx,    \
        _EUR,   _CRT,   _BSL,   _TLD,   _LCB,   _CAPS,  _ENT,   xxx,    xxx,    xxx     \
    ),

    [LAYER_LEFT_NUMBER] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        xxx,    xxx,    xxx,    _TAB,   _DEL,   xxx,    _7,     _8,     _9,     xxx,    \
        xxx,    xxx,    xxx,    _ESC,   _UPPR,  xxx,    _4,     _5,     _6,     _0,     \
        xxx,    xxx,    TRNS,   _ENT,   _CAPS,  xxx,    _1,     _2,     _3,     xxx     \
    ),

    [LAYER_RIGHT_NUMBER] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        xxx,    _7,     _8,     _9,     xxx,    _DEL,   _TAB,   xxx,    xxx,    xxx,    \
        _0,     _4,     _5,     _6,     xxx,    _UPPR,  _ESC,   xxx,    xxx,    xxx,    \
        xxx,    _1,     _2,     _3,     xxx,    _CAPS,  _ENT,   TRNS,   xxx,    xxx     \
    ),

    [LAYER_LEFT_ARROW] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        COLEMAK,QWERTY, xxx,    xxx,    xxx,    _F6,    _F7,    _F8,    _F9,    _F10,   \
        _V_VU,  _V_VD,  _V_P,   xxx,    xxx,    _F12,   _AR_L,  _AR_D,  _AR_U,  _AR_R,  \
        RESET,  xxx,    xxx,    TRNS,   xxx,    xxx,    _HOME,  _PG_D,  _PG_U,  _END    \
    ),

    [LAYER_RIGHT_ARROW] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        _F1,    _F2,    _F3,    _F4,    _F5,    xxx,    xxx,    xxx,    QWERTY, COLEMAK,\
        _AR_L,  _AR_D,  _AR_U,  _AR_R,  _F12,   xxx,    xxx,    _V_P,   _V_VD,  _V_VU,  \
        _HOME,  _PG_D,  _PG_U,  _END,   xxx,    xxx,    TRNS,   xxx,    xxx,    RESET   \
    )

};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _V_LARR:   case _D_LARR:
        case _M_RARR:   case _H_RARR:
        case _C_LNUM:   case _COM_RNUM:
            return 180;
            break;

        /* Important symbol layer keys get short tapping term */
        case _D_LSYM:   case _S_LSYM:
        case _K_RSYM:   case _E_RSYM:
            return 120;

        /* Space and Backspace get short tapping term */
        case _CT_SPC:
        case _CN_SPC:
        case _QF_SPC:
        case _QJ_SPC:
        case _CG_BSPC:
        case _CM_BSPC:
        case _QG_BSPC:
        case _QH_BSPC:
            return 120;


        default:
            return TAPPING_TERM;
            break;
    }
}

bool custom_tap_hold(keyrecord_t *record, uint16_t keycode){
    if (!record -> tap.count && record -> event.pressed) {
        register_code(keycode);
        return false;
    } else {
        unregister_code(keycode);
        return true;
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


        case _CT_SPC:
        case _CN_SPC:
        case _QF_SPC:
        case _QJ_SPC:
            return custom_tap_hold(record, _SPC);

        case _CG_BSPC:
        case _CM_BSPC:
        case _QG_BSPC:
        case _QH_BSPC:
            return custom_tap_hold(record, _BSPC);


        /* Keep capslock on for the following keys */
        case _Q_LALT:
        case _P_RALT:
        case _A_LCTL:
        case _S_LSFT:
        case _D_LSYM:
        case _K_RSYM:
        case _L_RSFT:
        case _Z_LGUI:
        case _C_LNUM:
        case _V_LARR:
        case _M_RARR:
        case _R_LSFT:
        case _S_LSYM:
        case _E_RSYM:
        case _I_RSFT:
        case _O_RCTL:
        case _D_LARR:
        case _H_RARR:

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
        case _COM_RNUM:
        case _SL_RGUI:
        case _SCN_RCTL:
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

