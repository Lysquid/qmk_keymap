#pragma once

#include QMK_KEYBOARD_H

// Based on Callum's keymap:
// https://github.com/qmk/qmk_firmware/tree/user-keymaps-still-present/users/callum

// Implements cmd-tab like behaviour on a single key. On first tap of trigger
// cmdish is held and tabish is tapped -- cmdish then remains held until some
// other key is hit or released. For example:
//
//     trigger, trigger, a -> cmd down, tab, tab, cmd up, a
//     nav down, trigger, nav up -> nav down, cmd down, tab, cmd up, nav up
//
// This behaviour is useful for more than just cmd-tab, hence: cmdish, tabish.
void update_swapper(
    bool *active,
    uint16_t cmdish,
    uint16_t tabish,
    uint16_t trigger,
    uint16_t reverse_trigger,
    uint16_t keycode,
    keyrecord_t *record
);

// To be implemented by the consumer. Defines keys to ignore when determining
// if the cmdish should be released.
bool is_swapper_ignored_key(uint16_t keycode, keyrecord_t *record);
