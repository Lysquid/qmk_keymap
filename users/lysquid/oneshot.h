#pragma once

#include QMK_KEYBOARD_H

// Based on Callum's keymap:
// https://github.com/qmk/qmk_firmware/tree/user-keymaps-still-present/users/callum

// Represents the five states a oneshot key can be in
typedef enum {
    oc_up_unqueued,
    oc_up_queued,
    oc_up_used,
    oc_down_unused,
    oc_down_used,
} oneshot_state;

// Custom oneshot mod implementation that doesn't rely on timers. If a mod is
// used while it is held it will be unregistered on keyup as normal, otherwise
// it will be queued and only released after the next non-mod keyup.
void update_oneshot(
    oneshot_state *state,
    uint16_t mod,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record,
    bool held_when_queued
);

// To be implemented by the consumer. Defines keys to cancel oneshot mods.
bool is_oneshot_cancel_key(uint16_t keycode);

// To be implemented by the consumer. Defines keys to ignore when determining
// whether a oneshot mod has been used. Setting this to modifiers and layer
// change keys allows stacking multiple oneshot modifiers, and carrying them
// between layers.
bool is_oneshot_ignored_key(uint16_t keycode);
