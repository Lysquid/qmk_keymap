#include "../../../ferris/keymaps/lysquid/keymap.h"
#include "../../../../users/lysquid/azerty_keycodes.h"
#include "../../../../users/lysquid/custom_keycodes.h"

#include "../../../ferris/keymaps/lysquid/overrides.h"
#ifdef AZERTY
#include "sendstring_french.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[DEF] = LAYOUT(
    XXXXXXX,        KF_Y,       OSL(SPC),   KF_O,       KF_F,       KF_K,       KF_V,       KF_P,       KF_L,       KF_C,       KF_Q,       XXXXXXX,
    XXXXXXX,        KF_I,       KF_A,       KF_E,       KF_U,       KF_COMM,    KF_G,       KF_T,       KF_N,       KF_S,       KF_R,       XXXXXXX,
    XXXXXXX,        KF_J,       KF_DOT,     KF_MINS,    KF_H,       KF_Z,       KF_B,       KF_D,       KF_M,       KF_W,       KF_X,       XXXXXXX,
                                            XXXXXXX,    MO(NAV),    KC_SPC,     KC_RSFT,    MO(SYM),    XXXXXXX
),

[SPC] = LAYOUT(
    XXXXXXX,        KF_OE,      KF_DIAE,    KF_OCRC,    KF_EGRV,    KF_UGRV,    KF_LAQT,    KF_RAQT,    KF_MDOT,    KF_CCED,    KF_DEG,     XXXXXXX,
    XXXXXXX,        KF_ICRC,    KF_AE,      KF_ECRC,    KF_EACU,    KF_UCRC,    KF_EURO,    KF_AGRV,    KF_ACRC,    KF_UNDS,    CW_TOGG,        XXXXXXX,
    XXXXXXX,        KF_SUP2,    KF_BDOT,    KF_IQES,    KF_LARW,    KF_RARW,    KF_LDQT,    KF_RDQT,    KF_MICR,    KF_PSMS,    KF_CROS,        XXXXXXX,
                                            XXXXXXX,    _______,    KF_QUOT,    _______,    _______,    XXXXXXX
),

[DEF2] = LAYOUT(
    XXXXXXX,        KF_A,       KF_Z,       KF_E,       KF_R,       KF_T,       KF_Y,       KF_U,       KF_I,       KF_O,       KF_P,       XXXXXXX,
    XXXXXXX,        KF_Q,       KF_S,       KF_D,       KF_F,       KF_G,       KF_H,       KF_J,       KF_K,       KF_L,       KF_M,       XXXXXXX,
    XXXXXXX,        KF_W,       KF_X,       KF_C,       KF_V,       KF_B,       KF_N,       KF_COMM,    KF_DOT,     KF_MINS,    OSL(SPC2),      XXXXXXX,
                                            XXXXXXX,    MO(NAV),    KC_SPC,     KC_RSFT,    MO(SYM),    XXXXXXX
),

[SPC2] = LAYOUT(
    XXXXXXX,        KF_AE,      KF_EACU,    KF_EGRV,    KF_SUP2,    KF_LDQT,    KF_RDQT,     KF_UGRV,    KF_PSMS,    KF_OE,      KF_DEG,        XXXXXXX,
    XXXXXXX,        KF_AGRV,    KF_ACRC,    KF_ECRC,    KF_EURO,    KF_LAQT,    KF_RAQT,     KF_UCRC,    KF_ICRC,    KF_OCRC,    KF_IQES,       XXXXXXX,
    XXXXXXX,        KF_PSMS,    KF_CROS,    KF_CCED,    KF_UNDS,    KF_LARW,    KF_RARW,     KF_MICR,    KF_MDOT,    KF_BDOT,    KF_DIAE,       XXXXXXX,
                                            XXXXXXX,    _______,    KF_QUOT,    _______,     _______,   XXXXXXX
),

[NAV] = LAYOUT(
    XXXXXXX,        SW_GRV,     NAV_LCK,    SW_TAB,     KF_UNDO,    KF_REDO,    KC_HOME,    KC_BSPC,    KC_UP,      KC_DEL,     KC_END,     XXXXXXX,
    XXXXXXX,        OC_LALT,    OC_LGUI,    OC_LSFT,    OC_LCTL,    KC_ESC,     KC_TAB,     KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_ENT,     XXXXXXX,
    XXXXXXX,        KF_SLCT,    KF_CUT,     KF_COPY,    KF_PSTE,    KC_PSCR,    KC_HSCL,    KC_PGUP,    KC_PGDN,    KC_APP,     TO(MOS),        XXXXXXX,
                                            XXXXXXX,    _______,    _______,    _______,    _______,    XXXXXXX
),

[NAV_ALT] = LAYOUT(
    XXXXXXX,        _______,    KC_MPLY,    KC_VOLD,    KC_VOLU,    KC_MUTE,    _______,    _______,    _______,    _______,    _______,        XXXXXXX,
    XXXXXXX,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,        XXXXXXX,
    XXXXXXX,        _______,    _______,    KC_MPRV,    KC_MNXT,    _______,    _______,    _______,    _______,    _______,    _______,        XXXXXXX,
                                            XXXXXXX,    _______,    _______,    _______,    _______,    XXXXXXX
),

[NAV_GUI] = LAYOUT(
    XXXXXXX,        _______,    _______,    KF_WPRV,    KF_WNXT,    KC_WREF,    _______,    _______,    _______,    _______,    _______,        XXXXXXX,
    XXXXXXX,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,        XXXXXXX,
    XXXXXXX,        _______,    _______,    KF_WBAK,    KF_WFWD,    _______,    _______,    _______,    _______,    _______,    _______,        XXXXXXX,
                                            XXXXXXX,    _______,    _______,    _______,    _______,    XXXXXXX
),

[NAV_CTL] = LAYOUT(
    XXXXXXX,        _______,    KC_DEL,     KF_CL_T,    _______,    _______,    _______,    _______,    _______,    _______,    _______,        XXXXXXX,
    XXXXXXX,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,        XXXXXXX,
    XXXXXXX,        _______,    KF_SAVE,    KF_TCPY,    _______,    _______,    _______,    _______,    _______,    _______,    _______,        XXXXXXX,
        XXXXXXX,    _______,    _______,    _______,    _______,    XXXXXXX
),

[SYM] = LAYOUT(
    XXXXXXX,        KF_PERC,    KF_PLUS,    KF_LBRC,    KF_RBRC,    KF_HASH,    KF_CIRC,    KF_COLN,    KF_DQUO,    KF_QUOT,    KF_DLR,     XXXXXXX,
    XXXXXXX,        KF_LCBR,    KF_LPRN,    KF_RPRN,    KF_RCBR,    KF_SLSH,    KF_EQL,     OC_RCTL,    OC_RSFT,    OC_RGUI,    OC_LALT,        XXXXXXX,
    XXXXXXX,        KF_TILD,    KF_BSLS,    KF_LABK,    KF_RABK,    KF_AMPR,    KF_PIPE,    KF_SCLN,    KF_ASTR,    KF_GRV,     KF_AT,      XXXXXXX,
                                            XXXXXXX,    _______,    _______,    _______,    _______,    XXXXXXX
),

[SYM_SFT] = LAYOUT(
    XXXXXXX,        _______,    ZM_RS_2,    ZM_OU_2,    ZM_IN_2,    _______,    _______,    _______,    _______,    _______,    _______,        XXXXXXX,
    XXXXXXX,        _______,    ZM_RS_1,    ZM_OU_1,    ZM_IN_1,    _______,    _______,    _______,    _______,    _______,    _______,        XXXXXXX,
    XXXXXXX,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,        XXXXXXX,
                                            XXXXXXX,    _______,    _______,    _______,    _______,    XXXXXXX
),

[NUM] = LAYOUT(
    XXXXXXX,        KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F12,     KF_7,       KF_8,       KF_9,       KF_COMM,        XXXXXXX,
    XXXXXXX,        OC_LALT,    OC_LGUI,    OC_LSFT,    OC_LCTL,    KC_SPC,     KC_TAB,     KF_4,       KF_5,       KF_6,       KF_0,       XXXXXXX,
    XXXXXXX,        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F11,     KF_1,       KF_2,       KF_3,       KF_DOT,     XXXXXXX,
                                            XXXXXXX,    _______,    _______,    _______,    _______,    XXXXXXX
),

[MOS] = LAYOUT(
    XXXXXXX,        XXXXXXX,    OS_BTN2,    OS_BTN3,    OS_BTN1,    KC_BRIU,    DF(DEF2),   MS_WHLL,    MS_UP,      MS_WHLR,    XXXXXXX,        XXXXXXX,
    XXXXXXX,        XXXXXXX,    MS_BTN2,    MS_BTN3,    MS_BTN1,    KC_BRID,    DF(DEF),    MS_LEFT,    MS_DOWN,    MS_RGHT,    XXXXXXX,        XXXXXXX,
    XXXXXXX,        OC_LALT,    OC_LGUI,    OC_LSFT,    OC_LCTL,    QK_RBT,     QK_BOOT,    MS_WHLU,    MS_WHLD,    XXXXXXX,    XXXXXXX,        XXXXXXX,
                                            XXXXXXX,    _______,    MS_ACL0,    _______,    _______,    XXXXXXX
),

};
