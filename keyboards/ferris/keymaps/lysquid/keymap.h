#pragma once

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
    FR_ACRC,
    FR_ECRC,
    FR_OCRC,
    FR_ICRC,
    FR_UCRC,
    FR_ETRM,
    FR_ITRM,
    FR_UTRM,
};
