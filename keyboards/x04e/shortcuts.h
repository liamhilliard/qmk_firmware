// Custom codes for QMK
// Each begins with an underscore
// and is no more than 5 character long

// QMK codes
#define ___        KC_TRNS
#define TRNS       KC_TRNS
#define xxx        KC_NO


// Control keys
#define _ESC        KC_ESCAPE
#define _TAB        KC_TAB
#define _CTL        KC_LCTRL
#define _SFT        KC_LSFT
#define _ALT        KC_LALT
#define _GUI        KC_LGUI
#define _DEL        KC_DELETE
#define _ENT        KC_ENTER
#define _BSPC       KC_BACKSPACE
#define _SPC        KC_SPACE
#define _AR_L       KC_LEFT
#define _AR_D       KC_DOWN
#define _AR_U       KC_UP
#define _AR_R       KC_RIGHT
#define _HOME       KC_HOME
#define _PG_D       KC_PAGE_DOWN
#define _PG_U       KC_PAGE_UP
#define _END        KC_END
#define _INS        KC_INSERT
#define _CAPS       KC_CAPS


// OneShot modifiers
#define _OS_CTL     OSM(MOD_LCTL)
#define _OS_SFT     OSM(MOD_LSFT)
#define _OS_ALT     OSM(MOD_LALT)


// Home row mods
// QWERTY
#define _A_HQ       LGUI_T(_A)
#define _S_HQ       LALT_T(_S)
#define _D_HQ       LCTL_T(_D)
#define _F_HQ       LSFT_T(_F)
//-----------
#define _J_HQ       LSFT_T(_J)
#define _K_HQ       LCTL_T(_K)
#define _L_HQ       LALT_T(_L)
#define _SCN_HQ     LGUI_T(_SCN)
// COLEMAK
#define _A_HC       LGUI_T(_A)
#define _R_HC       LALT_T(_R)
#define _S_HC       LCTL_T(_S)
#define _T_HC       LSFT_T(_T)
//-----------
#define _N_HC       LSFT_T(_N)
#define _E_HC       LCTL_T(_E)
#define _I_HC       LALT_T(_I)
#define _O_HC       LGUI_T(_O)


// Function keys
#define _F1         KC_F1
#define _F2         KC_F2
#define _F3         KC_F3
#define _F4         KC_F4
#define _F5         KC_F5
#define _F6         KC_F6
#define _F7         KC_F7
#define _F8         KC_F8
#define _F9         KC_F9
#define _F10        KC_F10
#define _F11        KC_F11
#define _F12        KC_F12

// Alphabet
#define _A          KC_A
#define _B          KC_B
#define _C          KC_C
#define _D          KC_D
#define _E          KC_E
#define _F          KC_F
#define _G          KC_G
#define _H          KC_H
#define _I          KC_I
#define _J          KC_J
#define _K          KC_K
#define _L          KC_L
#define _M          KC_M
#define _N          KC_N
#define _O          KC_O
#define _P          KC_P
#define _Q          KC_Q
#define _R          KC_R
#define _S          KC_S
#define _T          KC_T
#define _U          KC_U
#define _V          KC_V
#define _W          KC_W
#define _X          KC_X
#define _Y          KC_Y
#define _Z          KC_Z

// Numbers
#define _1          KC_1
#define _2          KC_2
#define _3          KC_3
#define _4          KC_4
#define _5          KC_5
#define _6          KC_6
#define _7          KC_7
#define _8          KC_8
#define _9          KC_9
#define _0          KC_0

// Symbols
#define _SQT        KC_QUOT //          ' @
#define _SCN        KC_SCLN //          ; :
#define _COM        KC_COMM //          , <
#define _DOT        KC_DOT  //          . >
#define _SL         KC_SLSH //          / ?
#define _GBP        LSFT(KC_3) //       £
#define _CEN        LSFT(KC_5) //       %
#define _EUR        RALT(KC_4) //       €
#define _BTK        KC_GRV //           `
#define _QS         LSFT(KC_SLSH) //    ?
#define _CRT        LSFT(KC_6) //       ^
#define _PIP        LSFT(KC_NUBS) //    |
#define _CN         LSFT(KC_SCLN) //    :
#define _UND        LSFT(KC_MINS) //    _
#define _MIN        KC_MINS //          -
#define _TLD        LSFT(KC_NUHS) //    ~
#define _LSB        KC_LBRC //          [
#define _RSB        KC_RBRC //          ]
#define _LCB        KC_LCBR //          {
#define _RCB        KC_RCBR //          }
#define _LPR        LSFT(KC_9) //       (
#define _RPR        LSFT(KC_0) //       )
#define _LAB        LSFT(KC_COMM) //    <
#define _RAB        LSFT(KC_DOT) //     >
#define _PLS        LSFT(KC_EQL) //     +
#define _EQ         KC_EQL //           =
#define _USD        LSFT(KC_4) //       $
#define _AMP        LSFT(KC_7) //       &
#define _DQT        LSFT(KC_2) //       "
#define _AST        LSFT(KC_8) //       *
#define _HSH        KC_NUHS //          #
#define _AT         LSFT(KC_QUOT) //    @
#define _EX         LSFT(KC_1) //       !
#define _BSL        KC_NUBS /*          \
*/

// Media keys
#define _V_P        KC_MEDIA_PLAY_PAUSE
#define _V_VD       KC_AUDIO_VOL_DOWN
#define _V_VU       KC_AUDIO_VOL_UP
#define _V_NT       KC_MEDIA_NEXT_TRACK
#define _V_PT       KC_MEDIA_PREV_TRACK

// Mouse keys
#define _M_L        KC_MS_LEFT
#define _M_D        KC_MS_DOWN
#define _M_U        KC_MS_UP
#define _M_R        KC_MS_RIGHT
#define _M_B1       KC_MS_BTN1
#define _M_B2       KC_MS_BTN2
#define _M_B3       KC_MS_BTN3
#define _M_B4       KC_MS_BTN4
#define _M_B5       KC_MS_BTN5
#define _M_WL       KC_MS_WH_LEFT
#define _M_WD       KC_MS_WH_DOWN
#define _M_WU       KC_MS_WH_UP
#define _M_WR       KC_MS_WH_RIGHT
#define _M_A0       KC_ACL0
#define _M_A1       KC_ACL1
#define _M_A2       KC_ACL2

