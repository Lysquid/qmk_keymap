#pragma once

#include QMK_KEYBOARD_H
#include "../../../../users/lysquid/azerty_keycodes.h"
#include "../../../../users/lysquid/custom_keycodes.h"


enum layers {
    DEF,
    DEF2,
    NAV,
    NAV_ALT,
    NAV_CTL,
    NAV_GUI,
    SYM,
    SYM_SFT,
    NUM,
    SPC,
    SPC2,
    MOS,
};

enum keycodes {
    OC_LSFT = SAFE_RANGE,
    OC_RSFT,
    OC_LCTL,
    OC_RCTL,
    OC_LALT,
    OC_RALT,
    OC_LGUI,
    OC_RGUI,
    OS_BTN1,
    OS_BTN2,
    OS_BTN3,
    NAV_LCK,
    SW_ESC,
    SW_TAB,
    SW_GRV,
    KC_HSCL,
    #ifdef AZERTY
    KF_ACRC,
    KF_ECRC,
    KF_OCRC,
    KF_ICRC,
    KF_UCRC,
    KF_EDIA,
    KF_IDIA,
    KF_UDIA,
    #endif
};
