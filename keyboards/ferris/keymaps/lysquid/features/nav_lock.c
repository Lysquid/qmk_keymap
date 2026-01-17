#include "../keymap.h"
#include "../features.h"

static bool nav_locked = false;
static bool nav_down = false;
static bool shift_down_unused = false;  // whether shift was used for a letter, so it does not lock the layer accidentally

bool nav_layer_lock(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
    case KC_RSFT:
        if (record->event.pressed) {
            // SHIFT DOWN
            if (nav_down) {
                // If shift is pressed while NAV is down, lock the layer (NAV UP will be skipped)
                nav_locked = true;
                return true;        // Don't actually shift
            } else {
                if (nav_locked) {
                    // If shift is pressed while the layer is locked, exit the layer
                    layer_off(NAV);
                    nav_locked = false;
                }
                // Mark shift as unused: if the next key is NAV, it will lock the layer
                // Any other key will mark it as used
                shift_down_unused = true;
            }
        } else {
            // SHIFT UP
            shift_down_unused = false;
        }
        break;
    case MO(NAV):
        nav_down = record->event.pressed;
        if (record->event.pressed) {
            // NAV DOWN
            if (shift_down_unused) {
                // If NAV is pressed while shift is down and was not used for any letter, lock the layer
                nav_locked = true;
                unregister_code(KC_RSFT);
            }
        } else {
            // NAV UP
            if (nav_locked) {
                if (is_any_oneshot_in_state(oc_up_queued) || is_any_oneshot_in_state(oc_down_unused)) {
                    // If NAV is released and a oneshot mod is queued on down, momentarily disable the layer for the mod
                } else {
                    // NAV is locked, so we don't want it to be turned off -> skip NAV UP
                    return true;
                }
            }
        }
        break;
    case MO(SYM):
        if (!record->event.pressed) {
            // SYM UP
            if (nav_locked && (is_any_oneshot_in_state(oc_up_queued) || is_any_oneshot_in_state(oc_down_unused))) {
                // If SYM is released and a oneshot mod is queued or down, momentarily disable the layer for the mod
                layer_off(NAV);
            }
        }
        break;
    case NAV_LCK:
        if (record->event.pressed) {
            // NAV LOCK DOWN
            if (nav_down) {
                nav_locked = true;
            } else {
                layer_off(NAV);
                nav_locked = false;
                // Override to prevent the underlying DEF key to be down
                return true;
            }
        }
        break;
    case CW_TOGG:
        if (IS_LAYER_ON(NAV) && !nav_down) {
            // If caps word is pressed while the layer is locked, exit the layer
            layer_off(NAV);
            nav_locked = false;
        }
        break;
    default:
        // Any other key marks shift as used (if shift was down)
        shift_down_unused = false;
    }

    // If NAV layer has been momentarily unlocked for a oneshot mod and it's done, turn the layer back on
    if (nav_locked && IS_LAYER_OFF(NAV) &&
        !is_any_oneshot_in_state(oc_up_queued) &&
        !is_any_oneshot_in_state(oc_down_unused) &&
        !is_any_oneshot_in_state(oc_down_used)
    ) {
        layer_on(NAV);
    }

    return false;
}


bool nav_lock_allows_tri_layer(layer_state_t state) {
    // FIXME: release NAV when NAV locked and SYM down -> NUM instead of SYM
    return !nav_locked || (nav_locked && nav_down) || IS_LAYER_ON_STATE(state, NUM);
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
