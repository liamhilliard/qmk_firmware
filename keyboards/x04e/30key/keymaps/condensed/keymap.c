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
 Z* X  C* V* B  N  M* ,* .  ?*

 * Custom QWERTY codes */
#define _Q_LALT    LALT_T(_Q)
#define _P_RALT    RALT_T(_P)
/* --- */
#define _A_LCTL    LCTL_T(_A)
#define _S_LSFT    LSFT_T(_S)
#define _D_LSYM    LT(LAYER_LEFT_SYMBOL, _D)
#define _F_SPC     LT(LAYER_QWERTY, _F)
#define _J_SPC     LT(LAYER_QWERTY, _J)
#define _K_RSYM    LT(LAYER_RIGHT_SYMBOL, _K)
#define _L_RSFT    LSFT_T(_L)
#define _SCN_RCTL  LCTL_T(_SCN)
/* --- */
#define _Z_LGUI    LGUI_T(_Z)
#define _C_ARR     LT(LAYER_ARROW, _C)
#define _V_BSPC    LT(LAYER_QWERTY, _V)
#define _M_BSPC    LT(LAYER_QWERTY, _M)
#define _COM_NUM   LT(LAYER_NUMBER, _COM)
#define _SL_RGUI   LGUI_T(_SL)

/*
 Q* W  F  P  B  J  L  U  Y  ;*
 A* R* S* T* G  M  N* E* I* O*
 Z* X  C* D* V  K  H* ,* .  ?*

 * Custom COLEMAK DH codes */
#define _SCN_RALT  RALT_T(_SCN)
/* --- */
#define _R_LSFT    LSFT_T(_R)
#define _S_LSYM    LT(LAYER_LEFT_SYMBOL, _S)
#define _T_SPC     LT(LAYER_COLEMAK_DH, _T)
#define _N_SPC     LT(LAYER_COLEMAK_DH, _N)
#define _E_RSYM    LT(LAYER_RIGHT_SYMBOL, _E)
#define _I_RSFT    LSFT_T(_I)
#define _O_RCTL    LCTL_T(_O)
/* --- */
#define _D_BSPC    LT(LAYER_COLEMAK_DH, _D)
#define _H_BSPC    LT(LAYER_COLEMAK_DH, _H)
#define _SL_RGUI   LGUI_T(_SL)

/* CAPS Word functionality */
#define _CPS_WD    LT(0, KC_NO)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_QWERTY] = LAYOUT( \
     /* ────────── ────────── ────────── ────────── ──────────|────────── ────────── ────────── ────────── ────────── */
        _Q_LALT,   _W,        _E,        _R,        _T,        _Y,        _U,        _I,         _O,       _P_RALT,   \
        _A_LCTL,   _S_LSFT,   _D_LSYM,   _F_SPC,    _G,        _H,        _J_SPC,    _K_RSYM,   _L_RSFT,   _SCN_RCTL, \
        _Z_LGUI,   _X,        _C_ARR,    _V_BSPC,   _B,        _N,        _M_BSPC,   _COM_NUM,  _DOT,      _SL_RGUI   \
    ),

    [LAYER_COLEMAK_DH] = LAYOUT( \
     /* ────────── ────────── ────────── ────────── ──────────|────────── ────────── ────────── ────────── ────────── */
        _Q_LALT,   _W,        _F,        _P,        _B,        _J,        _L,        _U,        _Y,        _SCN_RALT, \
        _A_LCTL,   _R_LSFT,   _S_LSYM,   _T_SPC,    _G,        _M,        _N_SPC,    _E_RSYM,   _I_RSFT,   _O_RCTL,   \
        _Z_LGUI,   _X,        _C_ARR,    _D_BSPC,   _V,        _K,        _H_BSPC,   _COM_NUM,  _DOT,      _SL_RGUI   \
    ),

    [LAYER_LEFT_SYMBOL] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        xxx,    xxx,    xxx,    _TAB,   _DEL,   _RSB,   _PLS,   _AMP,   _LAB,   _RAB,   \
        xxx,    LADJ,   xxx,    _ESC,   _CPS_WD,_RPR,   _DQT,   _USD,   _EX,    xxx,    \
        xxx,    xxx,    xxx,    _ENT,   xxx,    _RCB,   _EQ,    _AST,   _HSH,   _AT     \
    ),

    [LAYER_RIGHT_SYMBOL] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        _GBP,   _BTK,   _PIP,   _UND,   _LSB,   _DEL,   _TAB,   xxx,    xxx,    xxx,    \
        xxx,    _PRC,   _SQT,   _MIN,   _LPR,   _CPS_WD,_ESC,   xxx,    RADJ,   xxx,    \
        _EUR,   _CRT,   _BSL,   _TLD,   _LCB,   xxx,    _ENT,   xxx,    xxx,    xxx     \
    ),

    [LAYER_ARROW] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        xxx,    xxx,    xxx,    _TAB,   _DEL,   xxx,    xxx,    xxx,    xxx,    xxx,    \
        xxx,    LADJ,   xxx,    _ESC,   _CPS_WD,xxx,    _AR_L,  _AR_D,  _AR_U,  _AR_R,  \
        xxx,    xxx,    xxx,    _ENT,   xxx,    xxx,    _HOME,  _PG_D,  _PG_U,  _END    \
    ),

    [LAYER_NUMBER] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        xxx,    _7,     _8,     _9,     xxx,    _DEL,   _TAB,   xxx,    xxx,    xxx,    \
        _0,     _4,     _5,     _6,     xxx,    _CPS_WD,_ESC,   xxx,    RADJ,   xxx,    \
        xxx,    _1,     _2,     _3,     xxx,    xxx,    _ENT,   xxx,    xxx,    xxx     \
    ),

    [LAYER_LEFT_ADJUST] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        COLEMAK,QWERTY, xxx,    _TAB,   _DEL,   _F6,    _F7,    _F8,    _F9,    _F10,   \
        xxx,    TRNS,   xxx,    _ESC,   _CPS_WD,_F12,   _V_P,   _V_VD,  _V_VU,  xxx,    \
        RESET,  xxx,    xxx,    _ENT,   xxx,    xxx,    xxx,    xxx,    xxx,    xxx     \
    ),

    [LAYER_RIGHT_ADJUST] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        _F1,    _F2,    _F3,    _F4,    _F5,    _DEL,   _TAB,   xxx,    QWERTY, COLEMAK,\
        xxx,    _V_VD,  _V_VU,  _V_P,   _F12,   _CPS_WD,_ESC,   xxx,    TRNS,   xxx,    \
        xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    _ENT,   xxx,    xxx,    RESET   \
    )

};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _C_ARR:
        case _COM_NUM:
            return 180;

        /* Important symbol layer keys get short tapping term */
        case _D_LSYM:   case _S_LSYM:
        case _K_RSYM:   case _E_RSYM:
            return 120;

        case _CPS_WD:
            return 200;

        case _F_SPC: case _J_SPC: case _T_SPC: case _N_SPC:
        case _V_BSPC: case _M_BSPC: case _D_BSPC: case _H_BSPC:
            return 100;

        default:
            return TAPPING_TERM;
    }
}

static bool caps_on = false; /* Tracks state of CAPSLOCK */
static bool caps_word_on = false; /* Tracks whether caps word is active */

void process_capslock(uint16_t keycode, keyrecord_t *record){

    switch(keycode) {

        case _CPS_WD:
            if(record -> event.pressed){
                tap_code16(_CAPS);
                caps_on = !caps_on;

                if(record -> tap.count){
                    //tapped - treated as caps word
                    caps_word_on = caps_on;

                } else {
                    //held - treated as caps lock
                    caps_word_on = false;
                }
            }
            break;

        /* Keep capslock on for the following keys */
        case _Q_LALT: case _P_RALT: case _A_LCTL: case _S_LSFT: case _D_LSYM:
        case _K_RSYM: case _L_RSFT: case _Z_LGUI: case _C_ARR:
        case _R_LSFT: case _S_LSYM:
        case _E_RSYM: case _I_RSFT: case _O_RCTL: case _D_BSPC: case _H_BSPC:

        case _A: case _B: case _C: case _D: case _E: case _F: case _G: case _H:
        case _I: case _J: case _K: case _L: case _M: case _N: case _O: case _P:
        case _Q: case _R: case _S: case _T: case _U: case _V: case _W: case _X:
        case _Y: case _Z:
        case _1: case _2: case _3: case _4: case _5: case _6: case _7: case _8:
        case _9: case _0:
        case _UND: case _MIN:
        case _BSPC: case _DEL:
            break;

        /* Don't disable capslock when symbol keys are held for layers/mods */
        case _SCN_RCTL:
        case _COM_NUM:
        case _SL_RGUI:
        case _SCN_RALT:
            if(record->tap.count && record->event.pressed){
                if(caps_word_on){
                    tap_code16(_CAPS);
                    caps_on = !caps_on;
                    caps_word_on = false;
                }
            }
            break;

        /* Disable capslock when custom space keys are held */
        case _F_SPC:
        case _J_SPC:
        case _T_SPC:
        case _N_SPC:
            if(!record -> tap.count && record -> event.pressed){
                if(caps_word_on){
                    tap_code16(_CAPS);
                    caps_on = !caps_on;
                    caps_word_on = false;
                }
            }
            break;

        /* Disable capslock for all other key presses */
        default:
            if(record->event.pressed) {
                if(caps_word_on){
                    tap_code16(_CAPS);
                    caps_on = !caps_on;
                    caps_word_on = false;
                }
            }
    }
}

void process_persistent_layer(uint16_t keycode, keyrecord_t *record){
    switch(keycode){
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(LAYER_QWERTY);
            }

        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(LAYER_COLEMAK_DH);
            }
    }
}

void process_custom_hold(uint16_t keycode, keyrecord_t *record){
    switch(keycode){
        case _F_SPC:
        case _J_SPC:
        case _T_SPC:
        case _N_SPC:
            if(!record -> tap.count && record -> event.pressed){
                register_code(_SPC);
            } else if(!record -> event.pressed){
                unregister_code(_SPC);
            }
            break;

        case _V_BSPC:
        case _M_BSPC:
        case _D_BSPC:
        case _H_BSPC:
            if(!record -> tap.count && record -> event.pressed){
                register_code(_BSPC);
            } else if(!record -> event.pressed){
                unregister_code(_BSPC);
            }
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /* Custom handlers that don't stop key processing */
    process_capslock(keycode, record);
    process_persistent_layer(keycode, record);
    process_custom_hold(keycode, record);
    return true;
}


