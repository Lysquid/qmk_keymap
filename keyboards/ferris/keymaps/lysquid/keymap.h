#pragma once

#include "config.h"
#include QMK_KEYBOARD_H

enum layers {
    DEF,
    DEF2,
    SYM,
    NAV,
    NUM,
    SPC,
    SPC2,
    MOS,
};

enum keycodes {
    OS_LSFT = SAFE_RANGE,
    OS_RSFT,
    OS_LCTL,
    OS_RCTL,
    OS_LALT,
    OS_RALT,
    OS_LGUI,
    OS_RGUI,
    OS_BTN1,
    OS_BTN2,
    OS_BTN3,
    #ifdef FRENCH
    KF_ACRC,
    KF_ECRC,
    KF_OCRC,
    KF_ICRC,
    KF_UCRC,
    KF_ETRM,
    KF_ITRM,
    KF_UTRM,
    #endif
};

bool nav_layer_lock(uint16_t keycode, keyrecord_t *record);
