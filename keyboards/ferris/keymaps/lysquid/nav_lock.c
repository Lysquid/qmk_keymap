#include QMK_KEYBOARD_H
#include "keymap.h"
#include "keycodes.h"

bool lock_nav = false;  // skip process next time MO(NAV) goes up
bool nav_down = false;
bool shift_unused = false;  // whether shift was used for a letter, so it does not lock the layer accidentally

bool nav_layer_lock(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
    case KC_RSFT:
        if (record->event.pressed) {
            if (IS_LAYER_ON(NAV)) {
                if (nav_down) {
                    // If shift is pressed while NAV is down, lock the layer
                    lock_nav = true;
                    return true;
                } else {
                    // If shift is pressed while the layer is locked, exit the layer
                    layer_off(NAV);
                    lock_nav = false;
                    shift_unused = true;
                }
            } else {
                shift_unused = true;
            }
        }
        break;
    case MO(NAV):
        nav_down = record->event.pressed;
        if (record->event.pressed) {
            if (shift_unused) {
                // If NAV if pressed while shift is down and was not used for any letter, lock the layer
                lock_nav = true;
            }
        } else {
            if (lock_nav) {
                // If NAV is pressed while the layer is locked, unlock the layer
                lock_nav = false;
                return true;
            }
        }
        break;
    case MO(SYM):
        if (IS_LAYER_ON(NAV) && !nav_down && !get_mods() && record->event.pressed) {
            // If SYM is pressed while the layer is locked and no mods are down, unlock the layer
            layer_off(NAV);
        }
        // If a mod is down, keep the layer down (useful for window manager navigation)
        break;
    case CW_TOGG:
        if (IS_LAYER_ON(NAV) && !nav_down) {
            // If caps word is pressed while the layer is locked, exit the layer
            layer_off(NAV);
        }
        break;
    default:
        shift_unused = false;
    }
    return false;
}
