#pragma once

#include QMK_KEYBOARD_H

#define FR_AE ALGR(FR_A)
#define FR_TM SAGR(FR_8)
#define FR_OE UP(OE1,OE2)
#define FR_LAQT ALGR(FR_Z)
#define FR_RAQT ALGR(FR_X)
#define FR_LARW ALGR(FR_Y)
#define FR_RARW ALGR(FR_I)
#define FR_1CRC ALGR(FR_CCED)
#define FR_MDOT ALGR(FR_COLN)
#define FR_BDOT ALGR(FR_SCLN)
#define FR_CROS SAGR(FR_SCLN)
#define FR_IQES SAGR(FR_RPRN)
#define FR_CPRT SAGR(FR_C)

typedef enum {
    circonflexe,
    trema,
} accent_t;

void dead_key_accent(uint16_t keycode, accent_t accent, keyrecord_t *record);

// Uppercase accented letters: use caps lock instead of shift (Linux only)
bool uppercase_accent(uint16_t keycode, keyrecord_t *record);

bool french_caps_word_fix(uint16_t keycode, keyrecord_t *record);
