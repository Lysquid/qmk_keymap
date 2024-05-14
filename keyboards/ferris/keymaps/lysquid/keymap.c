#include "keymap.h"
#include "azerty.h"
#include "sendstring_french.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [DEF] = LAYOUT(
        KF_Y,       OSL(SPC),   KF_O,       KF_F,       KF_K,       KF_V,       KF_P,       KF_L,       KF_C,       KF_Q,
        KF_I,       KF_A,       KF_E,       KF_U,       KF_COMM,    KF_G,       KF_T,       KF_N,       KF_S,       KF_R,
        KF_J,       KF_DOT,     KF_MINS,    KF_H,       KF_Z,       KF_B,       KF_D,       KF_M,       KF_W,       KF_X,
                                            MO(NAV),    KC_SPC,     KC_RSFT,    MO(SYM)
    ),

    [DEF2] = LAYOUT(
        KF_A,       KF_Z,       KF_E,       KF_R,       KF_T,       KF_Y,       KF_U,       KF_I,       KF_O,       KF_P,
        KF_Q,       KF_S,       KF_D,       KF_F,       KF_G,       KF_H,       KF_J,       KF_K,       KF_L,       KF_M,
        KF_W,       KF_X,       KF_C,       KF_V,       KF_B,       KF_N,       KF_COMM,    KF_DOT,     KF_MINS,    OSL(SPC2),
                                            MO(NAV),    KC_SPC,     KC_RSFT,    MO(SYM)
    ),

    [SYM] = LAYOUT(
        KF_PERC,    KF_PLUS,    KF_LBRC,    KF_RBRC,    KF_HASH,    KF_CIRC,    KF_COLN,    KF_DQUO,    KF_QUOT,    KF_DLR,
        KF_LCBR,    KF_LPRN,    KF_RPRN,    KF_RCBR,    KF_SLSH,    KF_EQL,     OS_RCTL,    OS_RSFT,    OS_RGUI,    OS_LALT,
        KF_TILD,    KF_BSLS,    KF_LABK,    KF_RABK,    KF_AMPR,    KF_PIPE,    KF_SCLN,    KF_ASTR,    KF_GRV,     KF_AT,
                                            _______,    _______,    _______,    _______
    ),

    [NAV] = LAYOUT(
        TO(MOS),    KC_ESC,     KF_REDO,    KF_UNDO,    KC_VOLU,    KC_HOME,    KC_BSPC,    KC_UP,      KC_DEL,     KC_END,
        OS_LALT,    OS_LGUI,    OS_LSFT,    OS_LCTL,    KC_VOLD,    KC_TAB,     KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_ENT,
        KF_SLCT,    KF_CUT,     KF_COPY,    KF_PSTE,    KC_MPLY,    CW_TOGG,    KC_PGDN,    KC_PGUP,    KC_APP,     KC_PSCR,
                                            _______,    _______,    _______,    _______
    ),

    [NUM] = LAYOUT(
        KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F12,     KF_7,       KF_8,       KF_9,       KF_COMM,
        OS_LALT,    OS_LGUI,    OS_LSFT,    OS_LCTL,    KC_SPC,     KC_TAB,     KF_4,       KF_5,       KF_6,       KF_0,
        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F11,     KF_1,       KF_2,       KF_3,       KF_DOT,
                                            _______,    _______,    _______,    _______
    ),

    [SPC] = LAYOUT(
        KF_SUP2,    KF_DIAE,    KF_OCRC,    KF_EGRV,    KF_UGRV,    KF_LAQT,    KF_RAQT,    KF_MDOT,    KF_CCED,    KF_DEG,
        KF_ICRC,    KF_AE,      KF_ECRC,    KF_EACU,    KF_UCRC,    KF_EURO,    KF_AGRV,    KF_ACRC,    KF_UNDS,    KF_OE,
        KF_PSMS,    KF_BDOT,    KF_IQES,    KF_LARW,    KF_RARW,    KF_LDQT,    KF_RDQT,    KF_MICR,    KF_DIFF,    KF_CROS,
                                            _______,    KF_QUOT,    _______,    _______
    ),

    [SPC2] = LAYOUT(
        KF_AE,      KF_EACU,    KF_EGRV,    KF_SUP2,    KF_LDQT,    KF_RDQT,     KF_UGRV,    KF_DIFF,    KF_OE,      KF_DEG,
        KF_AGRV,    KF_ACRC,    KF_ECRC,    KF_EURO,    KF_LAQT,    KF_RAQT,     KF_UCRC,    KF_ICRC,    KF_OCRC,    KF_IQES,
        KF_PSMS,    KF_CROS,    KF_CCED,    KF_UNDS,    KF_LARW,    KF_RARW,     KF_MICR,    KF_MDOT,    KF_BDOT,    KF_DIAE,
                                            _______,    KF_QUOT,    _______,     _______
    ),

    [MOS] = LAYOUT(
        XXXXXXX,    OS_BTN2,    OS_BTN3,    OS_BTN1,    DF(DEF),    DF(DEF2),   KC_WH_L,    KC_MS_U,    KC_WH_R,    XXXXXXX,
        KC_BTN4,    KC_BTN2,    KC_BTN3,    KC_BTN1,    KC_BTN5,    XXXXXXX,    KC_MS_L,    KC_MS_D,    KC_MS_R,    XXXXXXX,
        OS_LALT,    OS_LGUI,    OS_LSFT,    OS_LCTL,    QK_RBT,     QK_BOOT,    KC_WH_D,    KC_WH_U,    XXXXXXX,    XXXXXXX,
                                            _______,    KC_ACL0,    _______,    _______
    ),

};
