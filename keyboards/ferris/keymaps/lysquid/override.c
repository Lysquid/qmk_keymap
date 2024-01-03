#include "keycodes.h"
#include "keymap_french.h"
#include "process_key_override.h"
#include "quantum_keycodes.h"
#include "override.h"
#include "keymap.h"
#include QMK_KEYBOARD_H

// Azerty window manager compatibility
const key_override_t override_1 = ko_make_basic(MOD_MASK_GUI, FR_1, G(FR_AMPR));
const key_override_t override_2 = ko_make_basic(MOD_MASK_GUI, FR_2, G(FR_EACU));
const key_override_t override_3 = ko_make_basic(MOD_MASK_GUI, FR_3, G(FR_DQUO));
const key_override_t override_4 = ko_make_basic(MOD_MASK_GUI, FR_4, G(FR_QUOT));
const key_override_t override_5 = ko_make_basic(MOD_MASK_GUI, FR_5, G(FR_LPRN));
const key_override_t override_6 = ko_make_basic(MOD_MASK_GUI, FR_6, G(FR_MINS));
const key_override_t override_7 = ko_make_basic(MOD_MASK_GUI, FR_7, G(FR_EGRV));
const key_override_t override_8 = ko_make_basic(MOD_MASK_GUI, FR_8, G(FR_UNDS));
const key_override_t override_9 = ko_make_basic(MOD_MASK_GUI, FR_9, G(FR_CCED));
const key_override_t override_0 = ko_make_basic(MOD_MASK_GUI, FR_0, G(FR_AGRV));

// Azerty shorcuts compatibility
const key_override_t slash_override = ko_make_basic(MOD_MASK_CS, FR_SLSH, C(KC_PSLS));

// Zoom key
const key_override_t keypad_zoom_reset_override = ko_make_basic(MOD_MASK_AG, KC_PPLS, C(KC_P0));
const key_override_t keypad_zoom_out_override = ko_make_basic(MOD_MASK_CA, KC_PPLS, C(KC_PMNS));
const key_override_t keypad_zoom_in_override = ko_make_basic(MOD_MASK_ALT, KC_PPLS, C(KC_PPLS));
const key_override_t zoom_reset_override = ko_make_basic(MOD_MASK_GUI, KC_PPLS, C(FR_AGRV));
const key_override_t zoom_out_override = ko_make_basic(MOD_MASK_CTRL, KC_PPLS, C(FR_MINS));
const key_override_t zoom_in_override = ko_make_basic(0, KC_PPLS, C(FR_EQL));

// Erglace
const key_override_t colon_override = ko_make_basic(MOD_MASK_SHIFT, FR_COMM, FR_QUES);
const key_override_t dot_override = ko_make_basic(MOD_MASK_SHIFT, FR_DOT, FR_EXLM);
const key_override_t minus_override = ko_make_basic(MOD_MASK_SHIFT, FR_MINS, FR_UNDS);

// Nav combinations
const key_override_t media_prev_override = ko_make_basic(MOD_MASK_GUI, KC_VOLD, KC_MPRV);
const key_override_t media_next_override = ko_make_basic(MOD_MASK_GUI, KC_VOLU, KC_MNXT);
const key_override_t brightness_down_override = ko_make_basic(MOD_MASK_ALT, KC_VOLD, KC_BRID);
const key_override_t brightness_up_override = ko_make_basic(MOD_MASK_ALT, KC_VOLU, KC_BRIU);
const key_override_t system_sleep_override = ko_make_basic(MOD_MASK_CSG, KC_MPLY, KC_SLEP);
const key_override_t system_power_override = ko_make_basic(MOD_MASK_CSG, KC_MUTE, KC_PWR);
const key_override_t undo_override = ko_make_basic(MOD_MASK_GUI, C(FR_Z), C(FR_Y));

// Invert page up and page when used with no mod
const key_override_t page_up_override = ko_make_basic_no_suppressed_mods_with_options(MOD_MASK_CSAG, KC_PGUP, KC_PGDN, ko_option_one_mod);
const key_override_t page_down_override = ko_make_basic_no_suppressed_mods_with_options(MOD_MASK_CSAG, KC_PGDN, KC_PGUP, ko_option_one_mod);


const key_override_t **key_overrides = (const key_override_t *[]) {
    &override_1,
    &override_2,
    &override_3,
    &override_4,
    &override_5,
    &override_6,
    &override_7,
    &override_8,
    &override_9,
    &override_0,
    &colon_override,
    &dot_override,
    &minus_override,
    &media_prev_override,
    &media_next_override,
    &brightness_down_override,
    &brightness_up_override,
    &system_sleep_override,
    &system_power_override,
    &undo_override,
    &page_up_override,
    &page_down_override,
    &slash_override,
    &keypad_zoom_reset_override,
    &keypad_zoom_out_override,
    &keypad_zoom_reset_override,
    &zoom_reset_override,
    &zoom_out_override,
    &zoom_in_override,
    NULL
};
