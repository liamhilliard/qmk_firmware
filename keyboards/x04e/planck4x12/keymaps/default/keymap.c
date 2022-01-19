#include QMK_KEYBOARD_H

#define _QWERTY     0
#define _COLEMAK_DH 1
#define _LOWER      3
#define _RAISE      4
#define _ADJUST     5

#define QWERTY      DF(_QWERTY)
#define COLMDH      DF(_COLEMAK_DH)
#define LOWER       TO(_LOWER)
#define RAISE       TO(_RAISE)
#define ADJUST      TO(_ADJUST)

enum custom_keycodes { MY_GUI };

#define _CTL        OSM(MOD_LCTL)
#define _SFT        OSM(MOD_LSFT)
#define _ALT        OSM(MOD_LALT)
#define _GUI        MY_GUI


/*
    Note
    KC_NUHS         #
    Shift+KC_NUHS   ~
    KC_NUBS         \
    Shift+KC_NUBS   |
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT( \
    //  TAB         Q           W           E           R           T           Y           U           I           O           P           '@
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_QUOT,    \
    //  ESC         A           S           D           F           G           H           J           K           L           ;:          BACKSPACE
        KC_ESC,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_BSPC,    \
    //  LSHIFT      Z           X           C           V           B           N           M           ,<          .>          /?          ENTER
        _SFT,       KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_ENT,     \
    //  LCTRL       LALT                    LGUI        LOWER       SPACE       LSHIFT      RAISE       MEDIA PLAY  VOL +       VOL -       DELETE
        _CTL,       _ALT,       XXXXXXX,    _GUI,       MO(_LOWER), KC_SPC,     _SFT,    MO(_RAISE), KC_MPLY,    KC__VOLUP,  KC__VOLDOWN,KC_DEL  \
    ),

    [_RAISE] = LAYOUT( \
    //                          7           8           9
        _______,    XXXXXXX,    KC_7,       KC_8,       KC_9,       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    //              0           4           5           6                                   LEFT ARR    DOWN ARR    UP ARR      RIGHT ARR
        _______,    KC_0,       KC_4,       KC_5,       KC_6,       XXXXXXX,    XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   _______,    \
    //                          1           2           3                                   HOME        PAGE DOWN   PAGE UP     END
        _______,    XXXXXXX,    KC_1,       KC_2,       KC_3,       XXXXXXX,    XXXXXXX,    KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     _______,    \
    //                                                  ADJUST                              RAISE
        _______,    _______,    _______,    _______,    MO(_ADJUST),_______,    _______,    KC_TRNS,    _______,    _______,    _______,    _______     \
    ),

    [_LOWER] = LAYOUT( \
    //  £           `           |           /           _           [           ]           +           $           &           <           >
        LSFT(KC_3), KC_GRV,     LSFT(KC_NUBS),KC_SLSH,  LSFT(KC_MINS),KC_LBRC,  KC_RBRC,    LSFT(KC_EQL),LSFT(KC_4),LSFT(KC_7), LSFT(KC_COMM),LSFT(KC_DOT),\
    //  %           ?           ;           '           -           (           )           .           "           ,           !
        LSFT(KC_5), LSFT(KC_SLSH),KC_SCLN,  KC_QUOT,    KC_MINS,    LSFT(KC_9), LSFT(KC_0), KC_DOT,     LSFT(KC_2), KC_COMM,    LSFT(KC_1),   _______,  \
    //  €           ^           :           \           ~           {           }           =           *           #           @
        RALT(KC_4), LSFT(KC_6), LSFT(KC_SCLN),KC_NUBS,  LSFT(KC_NUHS),KC_LCBR,  KC_RCBR,    KC_EQL,     LSFT(KC_8), KC_NUHS,    LSFT(KC_QUOT),_______,  \
    //                                                  LOWER                               ADJUST
        _______,    _______,    _______,    _______,    KC_TRNS,    _______,    _______,    MO(_ADJUST),_______,    _______,    _______,    _______     \
    ),

    [_ADJUST] = LAYOUT( \
    //  F1          F2          F3          F4          F5          F6          F7          F8          F9          F10         F11         F12
        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     \
    //  CAPSLOCK    MS FAST     MS SLOW     MS RCLICK   MS LCLICK                           MS LEFT     MS DOWN     MS UP       MS RIGHT
        KC_CAPS,    KC_ACL2,    KC_ACL0,    KC_BTN2,    KC_BTN1,    XXXXXXX,    XXXXXXX,    KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R,    XXXXXXX,    \
    //                                                                                                  MS WHL DN   MS WHL UP
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_WH_D,    KC_WH_U,    XXXXXXX,    XXXXXXX,    \
    //                                                                                                  PLAY        VOL+        VOL-        #RESET
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_TRNS,    XXXXXXX,    XXXXXXX,    KC_TRNS,    KC_MPLY,    KC__VOLUP,  KC__VOLDOWN,RESET       \
    )

};


// Allow GUI key to be toggled or held
#define GUI_DELAY 500
bool gui_active = false;
uint32_t gui_timer = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MY_GUI:
            if(record->event.pressed){
                gui_active = !gui_active;
                if(gui_active) {
                    println("process_record_user: gui_active = true");
                    register_code(KC_LGUI);
                } else {
                    println("process_record_user: gui_active = false");
                    unregister_code(KC_LGUI);
                }
            } else {
                if(timer_elapsed32(gui_timer) > GUI_DELAY){
                    gui_active = false;
                    unregister_code(KC_LGUI);
                }
            }
            gui_timer = timer_read32();
            break;
    }
    return true;
}

