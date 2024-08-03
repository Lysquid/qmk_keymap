#include "../keymap.h"
#include "../features.h"


static bool lock_nav = false;  // skip process next time MO(NAV) goes up
static bool nav_down = false;
static bool shift_unused = false;  // whether shift was used for a letter, so it does not lock the layer accidentally

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
                // If NAV is pressed while shift is down and was not used for any letter, lock the layer
                lock_nav = true;
                unregister_code(KC_RSFT);
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


static uint16_t key_timer;
static bool nav_block = false;

bool nav_time_block(uint16_t keycode, keyrecord_t *record) {
    if (keycode == MO(NAV)) {
        if (record->event.pressed) {
            // If NAV has been pressed, start the timer
            key_timer = timer_read();
        } else {
            // If NAV has been released, disable the block
            nav_block = false;
        }
    }
    if (nav_down && keycode == MO(SYM) && !record->event.pressed) {
        // If we are typing numbers, reset the timer once we get back to the NAV layer
        key_timer = timer_read();
    }
    if (nav_down && timer_elapsed(key_timer) > 1000 && IS_LAYER_OFF(NUM)) {
        // If NAV is down, the timer is elapsed and the NUM layer is off, block further keys on the NAV layer
        nav_block = true;
    }
    if (nav_block && record->event.pressed) {
        if (keycode == KC_RSFT) {
            // If shift is pressed while the block is active, disable the block
            nav_block = false;
        } else {
            // If any other key is pressed while the block is active, ignore it
            return true;
        }
    }
    return false;
}
