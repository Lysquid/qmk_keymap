#pragma once

#include QMK_KEYBOARD_H

typedef enum {
    circonflexe,
    trema,
} accent_t;

void dead_key_accent(uint16_t keycode, accent_t accent, keyrecord_t *record);

// Uppercase accented letters: use caps lock instead of shift (Linux only)
bool uppercase_accents(uint16_t keycode, keyrecord_t *record);

bool french_caps_word_fix(uint16_t keycode, keyrecord_t *record);
