#include QMK_KEYBOARD_H
#include <print.h>
#include <shortcuts.h>

enum layers {
    LAYER_QWERTY,
    LAYER_COLEMAK_DH,
    LAYER_KEYS,
    LAYER_LEFT_SYMBOL,
    LAYER_RIGHT_SYMBOL,
    LAYER_NUMBER,
    LAYER_ARROW,
    LAYER_LEFT_ADJUST,
    LAYER_RIGHT_ADJUST
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
#define _A_LGUI    LGUI_T(_A)
#define _S_LCTL    LCTL_T(_S)
#define _D_LSYM    LT(LAYER_LEFT_SYMBOL, _D)
#define _F_LSFT    LSFT_T(_F)
#define _J_RSFT    RSFT_T(_J)
#define _K_RSYM    LT(LAYER_RIGHT_SYMBOL, _K)
#define _L_RCTL    LCTL_T(_L)
#define _SCN_RGUI  LGUI_T(_SCN)
/* --- */
#define _C_ARR     LT(LAYER_ARROW, _C)
#define _COM_NUM   LT(LAYER_NUMBER, _COM)


/*
 Q* W  F* P  B  J  L  U* Y  ;*
 A* R* S* T* G  M  N* E* I* O*
 Z  X  C* D  V  K  H  ,* .  /

 * Custom COLEMAK DH codes */
#define _SCN_RALT  RALT_T(_SCN)
/* --- */
#define _R_LCTL    LCTL_T(_R)
#define _S_LSYM    LT(LAYER_LEFT_SYMBOL, _S)
#define _T_LSFT    LSFT_T(_T)
#define _N_RSFT    RSFT_T(_N)
#define _E_RSYM    LT(LAYER_RIGHT_SYMBOL, _E)
#define _I_RCTL    LCTL_T(_I)
#define _O_RGUI    RGUI_T(_O)


#define LADJ       MO(LAYER_LEFT_ADJUST)
#define RADJ       MO(LAYER_RIGHT_ADJUST)
#define _CPS_WD    LT(0, KC_NO)
#define _SP_TB     LT(0, _SPC)
#define _BS_DL     LT(0, _BSPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_QWERTY] = LAYOUT( \
     /* ────────── ────────── ────────── ────────── ──────────|────────── ────────── ────────── ────────── ────────── */
        _Q_LALT,   _W,        _E,        _R,        _T,        _Y,        _U,        _I,         _O,       _P_RALT,   \
        _A_LGUI,   _S_LCTL,   _D_LSYM,   _F_LSFT,   _G,        _H,        _J_RSFT,   _K_RSYM,   _L_RCTL,   _SCN_RGUI, \
        _Z,        _X,        _C_ARR,    _V,        _B,        _N,        _M,        _COM_NUM,  _DOT,      _SL        \
    ),

    [LAYER_COLEMAK_DH] = LAYOUT( \
     /* ────────── ────────── ────────── ────────── ──────────|────────── ────────── ────────── ────────── ────────── */
        _Q_LALT,   _W,        _F,        _P,        _B,        _J,        _L,        _U,        _Y,        _SCN_RALT, \
        _A_LGUI,   _R_LCTL,   _S_LSYM,   _T_LSFT,   _G,        _M,        _N_RSFT,   _E_RSYM,   _I_RCTL,   _O_RGUI,   \
        _Z,        _X,        _C_ARR,    _D,        _V,        _K,        _H,        _COM_NUM,  _DOT,      _SL        \
    ),

    [LAYER_LEFT_SYMBOL] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        xxx,    xxx,    xxx,    _ESC,   _CPS_WD,_RSB,   _PLS,   _AMP,   _LAB,   _RAB,   \
        xxx,    LADJ,   xxx,    _SP_TB, _ENT,   _RPR,   _DQT,   _USD,   _EX,    xxx,    \
        xxx,    xxx,    xxx,    _BS_DL, xxx,    _RCB,   _EQ,    _AST,   _HSH,   _AT     \
    ),

    [LAYER_RIGHT_SYMBOL] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        _GBP,   _BTK,   _PIP,   _UND,   _LSB,   _CPS_WD,_ESC,   xxx,    xxx,    xxx,    \
        xxx,    _PRC,   _SQT,   _MIN,   _LPR,   _ENT,   _SP_TB, xxx,    RADJ,   xxx,    \
        _EUR,   _CRT,   _BSL,   _TLD,   _LCB,   xxx,    _BS_DL, xxx,    xxx,    xxx     \
    ),

    [LAYER_NUMBER] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        xxx,    _7,     _8,     _9,     xxx,    _CPS_WD,_ESC,   xxx,    xxx,    xxx,    \
        _0,     _4,     _5,     _6,     xxx,    _ENT,   _SP_TB, xxx,    RADJ,   xxx,    \
        xxx,    _1,     _2,     _3,     xxx,    xxx,    _BS_DL, xxx,    xxx,    xxx     \
    ),

    [LAYER_ARROW] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        xxx,    xxx,    xxx,    _ESC,   _CPS_WD,xxx,    xxx,    xxx,    xxx,    xxx,    \
        xxx,    LADJ,   xxx,    _SP_TB, _ENT,   xxx,    _AR_L,  _AR_D,  _AR_U,  _AR_R,  \
        xxx,    xxx,    xxx,    _BS_DL, xxx,    xxx,    _HOME,  _PG_D,  _PG_U,  _END    \
    ),

    [LAYER_LEFT_ADJUST] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        COLEMAK,QWERTY, xxx,    _ESC,   _CPS_WD,_F6,    _F7,    _F8,    _F9,    _F10,   \
        xxx,    TRNS,   xxx,    _SP_TB, _ENT,   _F12,   _V_P,   _V_VD,  _V_VU,  xxx,    \
        RESET,  xxx,    xxx,    _BS_DL, xxx,    xxx,    xxx,    xxx,    xxx,    xxx     \
    ),

    [LAYER_RIGHT_ADJUST] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── */
        _F1,    _F2,    _F3,    _F4,    _F5,    _CPS_WD,_ESC,   xxx,    QWERTY, COLEMAK,\
        xxx,    _V_VD,  _V_VU,  _V_P,   _F12,   _ENT,   _SP_TB, xxx,    TRNS,   xxx,    \
        xxx,    xxx,    xxx,    xxx,    xxx,    xxx,    _BS_DL, xxx,    xxx,    RESET   \
    )

};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _C_ARR:
        case _COM_NUM:
            return 180;
            break;

        /* Important symbol layer keys get short tapping term */
        case _D_LSYM:   case _S_LSYM:
        case _K_RSYM:   case _E_RSYM:
            return 120;

        /* Custom keys */
        case _SP_TB:
        case _BS_DL:
            return 120;


        default:
            return TAPPING_TERM;
            break;
    }
}

bool custom_tap_hold(keyrecord_t *record, uint16_t keycode){
    if (!record -> tap.count && record -> event.pressed) {
        register_code(keycode);
    } else {
        unregister_code(keycode);
    }
    return true;
}

static bool caps_word_on = false;

void process_capslock(uint16_t keycode, keyrecord_t *record){

    switch(keycode) {

        case _CPS_WD:
            if(record -> tap.count && record -> event.pressed){
                //tapped - treated as caps word
                tap_code16(_CAPS);

                if(caps_word_on) {
                    /* Only set to false when it is true, rather than toggling
                       to stop us accidentally turning CAPSLOCK on below in
                       cases where it was on and the user wants to toggle
                       it off */
                    caps_word_on = false;
                }

            } else if (record -> event.pressed){
                //held - treated as caps lock
                tap_code16(_CAPS);
                caps_word_on = false;
            }

        /* Keep capslock on for the following keys */
        case _Q_LALT: case _P_RALT: case _A_LGUI: case _S_LCTL: case _D_LSYM:
        case _F_LSFT: case _J_RSFT: case _K_RSYM: case _L_RCTL: case _C_ARR:
        case _R_LCTL: case _S_LSYM: case _T_LSFT: case _N_RSFT: case _E_RSYM:
        case _I_RCTL: case _O_RGUI:
        case _A: case _B: case _C: case _D: case _E: case _F: case _G: case _H:
        case _I: case _J: case _K: case _L: case _M: case _N: case _O: case _P:
        case _Q: case _R: case _S: case _T: case _U: case _V: case _W: case _X:
        case _Y: case _Z:
        case _1: case _2: case _3: case _4: case _5: case _6: case _7: case _8:
        case _9: case _0:
        case _UND: case _MIN:
        case _BSPC:
        case _BS_DL:
            break;

        /* Don't disable capslock when symbol keys are held for layers/mods */
        case _COM_NUM:
        case _SCN_RGUI:
        case _SCN_RALT:
            if(record->tap.count && record->event.pressed){
                if(caps_word_on){
                    tap_code16(_CAPS);
                    caps_word_on = false;
                }
            }
            break;

        /* Disable capslock for all other key presses */
        default:
            if(record->event.pressed) {
                if(caps_word_on){
                    tap_code16(_CAPS);
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    /* Custom handlers that don't stop key processing */
    process_capslock(keycode, record);
    process_persistent_layer(keycode, record);

    switch (keycode) {
        /* Custom keys */
        case _SP_TB:
            return custom_tap_hold(record, _TAB);
        case _BS_DL:
            return custom_tap_hold(record, _DEL);
    }
    return true;
}

