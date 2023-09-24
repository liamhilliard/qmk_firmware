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
#define THM1      LSFT_T(_DEL)
#define THM2      LT(LOWER, _SPC)
#define THM3      LT(RAISE, _BSPC)
#define THM4      LSFT_T(_ENT)
/**/

/* Other mods */
#define ADJ       MO(ADJUST)
#define _BTK_M    LT(0, _BTK)
#define _AT_M     LT(0, _AT)
#define _LAB_M    LT(0, _LAB)
#define _HSH_M    LT(0, _HSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [QWERTY] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── ─────── */
        xxx,    _Q_M,   _W,     _E,     _R,     _T,     _Y,     _U,     _I,     _O,     _P_M,   xxx,    \
        xxx,    _A_M,   _S_M,   _D,     _F,     _G,     _H,     _J,     _K,     _L_M,   _SCN_M, xxx,    \
        xxx,    _Z_M,   _X,     _C,     _V,     _B,     _N,     _M,     _COM,   _DOT,   _SL_M,  xxx,    \
        xxx,    xxx,    xxx,    xxx,    THM1,   THM2,   THM3,   THM4,   xxx,    xxx,    xxx,    xxx     \
    ),

    [LOWER] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── ─────── */
        xxx,    xxx,    _7,     _8,     _9,     _TAB,   _RSB,   _PLS,   _AMP,   _LAB_M, _BSPC,  xxx,    \
        xxx,    _0,     _4,     _5,     _6,     _ESC,   _RPR,   _DQT,   _USD,   _RAB,   _ENT,   xxx,    \
        xxx,    xxx,    _1,     _2,     _3,     xxx,    _RCB,   _EQ,    _AST,   _HSH_M, _DEL,   xxx,    \
        xxx,    xxx,    xxx,    xxx,    TRNS,   TRNS,   ADJ,    ADJ,    xxx,    xxx,    xxx,    xxx     \
    ),

    [RAISE] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── ─────── */
        xxx,    _TAB,   _BTK_M, _PIP,   _UND,   _LSB,   _BSPC,  xxx,    xxx,    xxx,    xxx,    xxx,    \
        xxx,    _ESC,   _EX,    _SQT,   _MIN,   _LPR,   _ENT,   _AR_L,  _AR_D,  _AR_U,  _AR_R,  xxx,    \
        xxx,    xxx,    _AT_M,  _BSL,   _TLD,   _LCB,   _DEL,   _HOME,  _PG_D,  _PG_U,  _END,   xxx,    \
        xxx,    xxx,    xxx,    xxx,    ADJ,    ADJ,    TRNS,   TRNS,   xxx,    xxx,    xxx,    xxx     \
    ),

    [ADJUST] = LAYOUT( \
     /* ─────── ─────── ─────── ─────── ─────── ───────|─────── ─────── ─────── ─────── ─────── ─────── */
        xxx,    _F1,    _F2,    _F3,    _F4,    _F5,    _F6,    _F7,    _F8,    _F9,    _F10,   xxx,    \
        xxx,    xxx,    _V_VD,  _V_VU,  _V_P,   _F11,   _F12,   _V_P,   _V_VD,  _V_VU,  xxx,    xxx,    \
        xxx,    xxx,    xxx,    xxx,    xxx,    RESET,   RESET, xxx,    xxx,    xxx,    xxx,    xxx,    \
        xxx,    xxx,    xxx,    xxx,    TRNS,   TRNS,   TRNS,   TRNS,   xxx,    xxx,    xxx,    xxx     \
    )

};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* Important symbol layer keys get short tapping term */
        case _UPPR:
            return 200;

        case _BTK_M: case _AT_M:
        case _LAB_M: case _HSH_M:
        case THM1: case THM2:
        case THM3: case THM4:
            return 180;

        default:
            return TAPPING_TERM;
    }
}

bool is_pressed(keyrecord_t *record) { return record->event.pressed; }
bool is_released(keyrecord_t *record) { return !is_pressed(record); }
bool is_tapped(keyrecord_t *record) { return record->tap.count; }
bool is_held(keyrecord_t *record) { return !is_tapped(record); }

bool tap_hold(keyrecord_t *record, uint16_t tap_keycode, uint16_t hold_keycode){
    if(is_tapped(record)){
        if(is_pressed(record)) {
            register_code16(tap_keycode);
        } else {
            unregister_code16(tap_keycode);
        }
    } else {
        if(is_pressed(record)) {
            register_code16(hold_keycode);
        } else {
            unregister_code16(hold_keycode);
        }
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case _BTK_M: return tap_hold(record, _BTK, _GBP);
        case _AT_M:  return tap_hold(record, _AT,  _CRT);
        case _LAB_M: return tap_hold(record, _LAB, _PRC);
        case _HSH_M: return tap_hold(record, _HSH, _EUR);
    }
    return true;
}
