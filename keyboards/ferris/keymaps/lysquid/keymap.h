#pragma once

#include QMK_KEYBOARD_H
#include "config.h"

enum layers {
    DEF,
    DEF2,
    SYM,
    SYM_SFT,
    NAV,
    NAV_ALT,
    NAV_CTL,
    NAV_GUI,
    NUM,
    NUM_SFT,
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
    SW_ESC,
    SW_TAB,
    SW_GRV,
    KC_HSCL,
    #ifdef FRENCH
    KF_ACRC,
    KF_ECRC,
    KF_OCRC,
    KF_ICRC,
    KF_UCRC,
    KF_EDIA,
    KF_IDIA,
    KF_UDIA,
    #else
    KF_DIAE,
    #endif
};

// Lock the NAV layer with MO(NAV) + shift
bool nav_layer_lock(uint16_t keycode, keyrecord_t *record);

// If the NAV key is held too long without using the nav lock, block further keypress
bool nav_time_block(uint16_t keycode, keyrecord_t *record);
