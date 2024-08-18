#include "keymap.h"
#include "keycodes.h"
#ifdef FRENCH
#include "sendstring_french.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[DEF] = LAYOUT(
    XXXXXXX,    KF_Y,       OSL(SPC),   KF_O,       KF_F,       KF_K,                                                       KF_V,       KF_P,       KF_L,       KF_C,       KF_Q,       XXXXXXX,
    XXXXXXX,    KF_I,       KF_A,       KF_E,       KF_U,       KF_COMM,                                                    KF_G,       KF_T,       KF_N,       KF_S,       KF_R,       XXXXXXX,
    XXXXXXX,    KF_J,       KF_DOT,     KF_MINS,    KF_H,       KF_Z,       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KF_B,       KF_D,       KF_M,       KF_W,       KF_X,       XXXXXXX,
                                        XXXXXXX,    XXXXXXX,    MO(NAV),    KC_SPC,     XXXXXXX,    XXXXXXX,    KC_BSPC,    MO(SYM),    XXXXXXX,    XXXXXXX
),

[SPC] = LAYOUT(
    XXXXXXX,    KF_OE,      KF_DIAE,    KF_OCRC,    KF_EGRV,    KF_UGRV,                                                    KF_LAQT,    KF_RAQT,    KF_MDOT,    KF_CCED,    KF_DEG,     XXXXXXX,
    XXXXXXX,    KF_ICRC,    KF_AE,      KF_ECRC,    KF_EACU,    KF_UCRC,                                                    KF_EURO,    KF_AGRV,    KF_ACRC,    KF_UNDS,    CW_TOGG,    XXXXXXX,
    XXXXXXX,    KF_SUP2,    KF_BDOT,    KF_IQES,    KF_LARW,    KF_RARW,    _______,    _______,    _______,    _______,    KF_LDQT,    KF_RDQT,    KF_MICR,    KF_DIFF,    KF_CROS,    XXXXXXX,
                                        _______,    _______,    _______,    KF_QUOT,    _______,    _______,    _______,    _______,    _______,    _______
),

[DEF2] = LAYOUT(
    XXXXXXX,    KF_B,       KF_M,       KF_P,       KF_O,       KF_W,                                                       KF_Z,       KF_V,       KF_D,       KF_L,       KF_J,       XXXXXXX,
    XXXXXXX,    KF_A,       KF_U,       KF_I,       KF_E,       KF_COMM,                                                    KF_C,       KF_T,       KF_S,       KF_R,       KF_N,       XXXXXXX,
    XXXXXXX,    KF_MINS,    KF_Y,       KF_X,       KF_DOT,     KF_K,       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    OSL(SPC2),  KF_Q,       KF_G,       KF_H,       KF_F,       XXXXXXX,
                                        XXXXXXX,    XXXXXXX,    MO(NAV),    KC_SPC,     XXXXXXX,    XXXXXXX,    KC_BSPC,    MO(SYM),    XXXXXXX,    XXXXXXX
),

[SPC2] = LAYOUT(
    XXXXXXX,    KF_ACRC,    KF_UCRC,    KF_ICRC,    KF_OCRC,    KF_OE,                                                      KF_LARW,     KF_RARW,    KF_LDQT,    KF_RDQT,    KF_DEG,    XXXXXXX,
    XXXXXXX,    KF_AGRV,    KF_UGRV,    KF_EACU,    KF_EGRV,    KF_ECRC,                                                    KF_CCED,     KF_EURO,    KF_LAQT,    KF_RAQT,    KF_NTLD,   XXXXXXX,
    XXXXXXX,    KF_MINS,    KF_IQES,    KF_UNDS,    KF_MDOT,    KF_AE,      _______,    _______,    _______,    _______,    KF_DIAE,     KF_BDOT,    KF_MICR,    KF_DIFF,    KF_CROS,   XXXXXXX,
                                        _______,    _______,    _______,    KF_QUOT,    _______,    _______,    _______,    _______,    _______,    _______
),

[SYM] = LAYOUT(
    XXXXXXX,    KF_PERC,    KF_PLUS,    KF_LBRC,    KF_RBRC,    KF_HASH,                                                    KF_CIRC,    KF_COLN,    KF_DQUO,    KF_QUOT,    KF_DLR,     XXXXXXX,
    XXXXXXX,    KF_LCBR,    KF_LPRN,    KF_RPRN,    KF_RCBR,    KF_SLSH,                                                    KF_EQL,     OS_RCTL,    OS_RSFT,    OS_RGUI,    OS_LALT,    XXXXXXX,
    XXXXXXX,    KF_TILD,    KF_BSLS,    KF_LABK,    KF_RABK,    KF_AMPR,    _______,    _______,    _______,    _______,    KF_PIPE,    KF_SCLN,    KF_ASTR,    KF_GRV,     KF_AT,      XXXXXXX,
                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
),

[SYM_SFT] = LAYOUT(
    _______,    _______,    ZM_RS_2,    ZM_OU_2,    ZM_IN_2,    _______,                                                    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    ZM_RS_1,    ZM_OU_1,    ZM_IN_1,    _______,                                                    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
),

[NAV] = LAYOUT(
    XXXXXXX,    SW_GRV,     SW_ESC,     SW_TAB,     KF_UNDO,    KF_REDO,                                                    KC_HOME,    CW_TOGG,    KC_UP,      KC_DEL,     KC_END,     XXXXXXX,
    XXXXXXX,    OS_LALT,    OS_LGUI,    OS_LSFT,    OS_LCTL,    KC_ESC,                                                     KC_TAB,     KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_ENT,     XXXXXXX,
    XXXXXXX,    KF_SLCT,    KF_CUT,     KF_COPY,    KF_PSTE,    KC_PSCR,    _______,    _______,    _______,    _______,    KC_HSCL,    KC_PGUP,    KC_PGDN,    KC_APP,     TO(MOS),    XXXXXXX,
                                        _______,    _______,    _______,    _______,    _______,    _______,    C(KC_BSPC), _______,    _______,    _______
),

[NAV_ALT] = LAYOUT(
    _______,    _______,    KC_MPLY,    KC_VOLD,    KC_VOLU,    KC_MUTE,                                                    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                                                    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    KC_MPRV,    KC_MNXT,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
),

[NAV_GUI] = LAYOUT(
    _______,    _______,    _______,    KF_WPRV,    KF_WNXT,    KC_WREF,                                                    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                                                    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    KC_WBAK,    KC_WFWD,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
),

[NAV_CTL] = LAYOUT(
    _______,    _______,    KF_SAVE,    KF_CL_T,    _______,    _______,                                                    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                                                    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    KC_DEL,     KF_CL_A,    KF_TCPY,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
),

[NUM] = LAYOUT(
    XXXXXXX,    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,                                                     KC_F12,     KF_7,       KF_8,       KF_9,       KF_COMM,    XXXXXXX,
    XXXXXXX,    OS_LALT,    OS_LGUI,    OS_LSFT,    OS_LCTL,    KC_SPC,                                                     KC_TAB,     KF_4,       KF_5,       KF_6,       KF_0,       XXXXXXX,
    XXXXXXX,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      _______,    _______,    _______,    _______,    KC_F11,     KF_1,       KF_2,       KF_3,       KF_DOT,     XXXXXXX,
                                        _______,    _______,    _______,    _______,    _______,    _______,    KC_BSPC,    _______,    _______,    _______
),

[NUM_SFT] = LAYOUT(
    _______,    _______,    _______,    _______,    _______,    _______,                                                    _______,    WP_MV_1,    WP_MV_2,    WP_MV_3,    WP_MV_4,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                                                    _______,    WP_GO_1,    WP_GO_2,    WP_GO_3,    WP_GO_4,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    WP_GO_P,    WP_GO_N,    WP_MV_P,    WP_MV_N,    _______,
                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
),

[MOS] = LAYOUT(
    XXXXXXX,    XXXXXXX,    OS_BTN2,    OS_BTN3,    OS_BTN1,    KC_BRIU,                                                    DF(DEF2),   KC_WH_L,    KC_MS_U,    KC_WH_R,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    KC_BTN2,    KC_BTN3,    KC_BTN1,    KC_BRID,                                                    DF(DEF),    KC_MS_L,    KC_MS_D,    KC_MS_R,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    OS_LALT,    OS_LGUI,    OS_LSFT,    OS_LCTL,    QK_RBT,     _______,    _______,    _______,    _______,    QK_BOOT,    KC_WH_U,    KC_WH_D,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                        _______,    _______,    _______,    KC_ACL0,    _______,    _______,    _______,    _______,    _______,    _______
),

};
