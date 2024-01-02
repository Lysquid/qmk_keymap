#include "keycodes.h"
#include "keymap_french.h"
#include "quantum_keycodes.h"
#include "oneshot.h"
#include "french.h"
#include "keymap.h"
#include QMK_KEYBOARD_H

// #################
// # ONE SHOT KEYS #
// #################

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case MO(SYM):
        return IS_LAYER_OFF(NAV);
        break;
    case MO(NAV):
        return IS_LAYER_OFF(SYM);
        break;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case MO(SYM):
    case MO(NAV):
    case KC_LSFT:
    case KC_RSFT:
    case OS_LSFT:
    case OS_RSFT:
    case OS_LCTL:
    case OS_RCTL:
    case OS_LALT:
    case OS_RALT:
    case OS_LGUI:
    case OS_RGUI:
        return true;
    default:
        return false;
    }
}

oneshot_state os_lsft_state = os_up_unqueued;
oneshot_state os_rsft_state = os_up_unqueued;
oneshot_state os_lctl_state = os_up_unqueued;
oneshot_state os_rctl_state = os_up_unqueued;
oneshot_state os_lalt_state = os_up_unqueued;
oneshot_state os_ralt_state = os_up_unqueued;
oneshot_state os_lgui_state = os_up_unqueued;
oneshot_state os_rgui_state = os_up_unqueued;

// Custom oneshot mod implementation with no timers
void update_oneshots(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(&os_lsft_state, KC_LSFT, OS_LSFT, keycode, record);
    update_oneshot(&os_rsft_state, KC_RSFT, OS_RSFT, keycode, record);
    update_oneshot(&os_lctl_state, KC_LCTL, OS_LCTL, keycode, record);
    update_oneshot(&os_rctl_state, KC_RCTL, OS_RCTL, keycode, record);
    update_oneshot(&os_lalt_state, KC_LALT, OS_LALT, keycode, record);
    update_oneshot(&os_ralt_state, KC_RALT, OS_RALT, keycode, record);
    update_oneshot(&os_lgui_state, KC_LGUI, OS_LGUI, keycode, record);
    update_oneshot(&os_rgui_state, KC_RGUI, OS_RGUI, keycode, record);
}

// ############
// # NAV LOCK #
// ############

bool nav_lock = false;
bool nav_down = false;
bool shift_unused = false;

bool nav_layer_lock(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
    case KC_RSFT:
        if (record->event.pressed) {
            if (IS_LAYER_ON(NAV)) {
                if (nav_down) {
                    nav_lock = true;
                    return true;
                } else {
                    layer_off(NAV);
                    nav_lock = false;
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
                nav_lock = true;
            }
        } else {
            if (nav_lock) {
                return true;
            }
        }
        break;
    case KC_SPC:
        if (record->event.pressed && IS_LAYER_ON(NAV) && IS_LAYER_OFF(NUM)) {
            layer_off(NAV);
            nav_lock = false;
            return true;
        }
    default:
        shift_unused = false;
    }
    return false;
}

// ########################
// # SPECIALS LAYER CLEAR #
// ########################

// Disable hold one shot layer
void cancel_one_shot_hold(uint8_t layer) {
    if (layer == SPC || layer == SPC2) {
        clear_oneshot_layer_state(ONESHOT_PRESSED);
    }
}

// Clear up layers when NAV or SYM are pressed
void special_layers_clear(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode)
        {
        case MO(NAV):
        case MO(SYM):
            layer_off(MOS);
            layer_off(SPC);
            layer_off(SPC2);
            reset_oneshot_layer();
        }
    }
}

// ##########
// # FRENCH #
// ##########

void dead_key_accents(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
    case FR_ACRC: dead_key_accent(FR_A, circonflexe, record); break;
    case FR_ECRC: dead_key_accent(FR_E, circonflexe, record); break;
    case FR_ICRC: dead_key_accent(FR_I, circonflexe, record); break;
    case FR_OCRC: dead_key_accent(FR_O, circonflexe, record); break;
    case FR_UCRC: dead_key_accent(FR_U, circonflexe, record); break;
    case FR_ETRM: dead_key_accent(FR_E, trema, record); break;
    case FR_ITRM: dead_key_accent(FR_I, trema, record); break;
    case FR_UTRM: dead_key_accent(FR_U, trema, record); break;
    }
}

// ###########
// # ALT TAB #
// ###########

// One hand alt tab to use with mouse
bool alt_tab(uint16_t keycode, keyrecord_t *record) {
    if (IS_LAYER_ON(NAV) && (
        (keycode == C(FR_V) && (get_mods() & (MOD_MASK_ALT | MOD_MASK_GUI))) ||
        (keycode == C(FR_X) && (get_mods() & (MOD_MASK_CTRL)))
        )) {
        if (record->event.pressed) {
            register_code(KC_TAB);
        } else {
            unregister_code(KC_TAB);
        }
        return true;
    }
    return false;
}

// #################
// # QMK FUNCTIONS #
// #################

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool override = false;

    special_layers_clear(keycode, record);
    dead_key_accents(keycode, record);
    override |= uppercase_accent(keycode, record);
    override |= nav_layer_lock(keycode, record);
    override |= alt_tab(keycode, record);
    update_oneshots(keycode, record);

    return !override;
}

void oneshot_layer_changed_user(uint8_t layer) {
    cancel_one_shot_hold(layer);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYM, NAV, NUM);
}
