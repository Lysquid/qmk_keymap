#include "keycodes.h"
#include "keymap_french.h"
#include "quantum_keycodes.h"
#include "french.h"
#include "keymap.h"
#include "unicodes.h"
#include QMK_KEYBOARD_H

// TODO switch layer keys with space/shift (at least try this setup)
// TODO better position for ctrl+Z, useful macro instead of insert

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [DEF] = LAYOUT(
        FR_Y,       OSL(SPC),   FR_O,       FR_F,       FR_K,       FR_B,       FR_P,       FR_L,       FR_C,       FR_W,
        FR_I,       FR_A,       FR_E,       FR_U,       FR_COMM,    FR_G,       FR_T,       FR_N,       FR_S,       FR_R,
        FR_J,       FR_DOT,     FR_MINS,    FR_H,       FR_Z,       FR_Q,       FR_D,       FR_M,       FR_V,       FR_X,
                                            MO(NAV),    KC_SPC,     KC_RSFT,    MO(SYM)
    ),

    [DEF2] = LAYOUT(
        FR_A,       FR_Z,       FR_E,       FR_R,       FR_T,       FR_Y,       FR_U,       FR_I,       FR_O,       FR_P,
        FR_Q,       FR_S,       FR_D,       FR_F,       FR_G,       FR_H,       FR_J,       FR_K,       FR_L,       FR_M,
        FR_W,       FR_X,       FR_C,       FR_V,       FR_B,       FR_N,       FR_COMM,    FR_DOT,     FR_MINS,    OSL(SPC2),
                                            MO(NAV),    KC_SPC,     KC_RSFT,    MO(SYM)
    ),

    [SYM] = LAYOUT(
        FR_PERC,    KC_PPLS,    FR_LBRC,    FR_RBRC,    FR_HASH,    FR_1CRC,    FR_COLN,    FR_DQUO,    FR_QUOT,    FR_DLR,
        FR_LCBR,    FR_LPRN,    FR_RPRN,    FR_RCBR,    KC_PSLS,    FR_EQL,     OS_RCTL,    OS_RSFT,    OS_RGUI,    OS_LALT,
        FR_TILD,    FR_BSLS,    FR_LABK,    FR_RABK,    FR_PIPE,    FR_AMPR,    FR_SCLN,    FR_ASTR,    FR_GRV,     FR_AT,
                                            _______,    _______,    _______,    _______
    ),

    [NAV] = LAYOUT(
        KC_MPLY,    KC_TAB,     KC_VOLD,    KC_VOLU,    KC_MUTE,    KC_HOME,    KC_BSPC,    KC_UP,      KC_DEL,     KC_END,
        OS_LALT,    OS_LGUI,    OS_LSFT,    OS_LCTL,    KC_ESC,     KC_TAB,     KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_ENT,
        C(FR_Z),    C(FR_X),    C(FR_C),    C(FR_V),    C(FR_A),    KC_INS,     KC_PGDN,    KC_PGUP,    KC_APP,     KC_PSCR,
                                            _______,    _______,    _______,    _______
    ),

    [NUM] = LAYOUT(
        KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F12,     FR_7,       FR_8,       FR_9,       FR_COMM,
        OS_LALT,    OS_LGUI,    OS_LSFT,    OS_LCTL,    KC_SPC,     XXXXXXX,    FR_4,       FR_5,       FR_6,       FR_0,
        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F11,     FR_1,       FR_2,       FR_3,       FR_DOT,
                                            _______,    _______,    _______,    _______
    ),

    [SPC] = LAYOUT(
        FR_ITRM,    TO(MOS),    FR_OCRC,    FR_EGRV,    FR_UGRV,    FR_LAQT,    FR_RAQT,    FR_CPRT,    FR_CCED,    FR_TM,
        FR_ICRC,    FR_SUP2,    FR_ECRC,    FR_EACU,    FR_UCRC,    FR_EURO,    FR_ACRC,    FR_AGRV,    FR_AE,      FR_OE,
        FR_BDOT,    FR_MDOT,    FR_IQES,    FR_ETRM,    FR_UTRM,    FR_LARW,    FR_RARW,    FR_MICR,    FR_DEG,     FR_CROS,
                                            _______,    FR_QUOT,    _______,    _______
    ),

    [SPC2] = LAYOUT(
        FR_AE,      FR_EACU,    FR_EGRV,    FR_SUP2,    FR_TM,     FR_UTRM,     FR_UGRV,    FR_ITRM,    FR_OE,      FR_DEG,
        FR_AGRV,    FR_ETRM,    FR_ECRC,    FR_EURO,    FR_LAQT,   FR_RAQT,     FR_UCRC,    FR_ICRC,    FR_OCRC,    FR_IQES,
        FR_ACRC,    FR_CROS,    FR_CCED,    FR_CPRT,    FR_LARW,   FR_RARW,     FR_MICR,    FR_MDOT,    FR_BDOT,    TO(MOS),
                                            _______,    FR_QUOT,    _______,     _______
    ),

    [MOS] = LAYOUT(
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    DF(DEF),    DF(DEF2),   KC_WH_L,    KC_MS_U,    KC_WH_R,    XXXXXXX,
        XXXXXXX,    KC_BTN2,    KC_BTN3,    KC_BTN1,    XXXXXXX,    XXXXXXX,    KC_MS_L,    KC_MS_D,    KC_MS_R,    XXXXXXX,
        OS_LALT,    OS_LGUI,    OS_LSFT,    OS_LCTL,    QK_RBT,     QK_BOOT,    KC_WH_D,    KC_WH_U,    XXXXXXX,    XXXXXXX,
                                            _______,    KC_ACL0,    KC_ACL1,    _______
    ),

};
