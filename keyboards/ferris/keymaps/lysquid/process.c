#include "keycodes.h"
#include "keymap_french.h"
#include "process_key_override.h"
#include "quantum_keycodes.h"
#include "oneshot.h"
#include "french.h"
#include "keymap.h"
#include QMK_KEYBOARD_H

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case MO(SYM):
    case MO(NAV):
        return true;
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


bool is_layer_toggle_canceld(uint16_t keycode) {
    switch (keycode) {
    case MO(NAV):
    case MO(SYM):
        return false;
    default:
        return true;
    }
}

bool tap_toggle_layer(uint8_t layer, bool* layer_only, uint16_t keycode, keyrecord_t *record) {
    if (keycode == MO(layer)) {
        if (record->event.pressed) {
            *layer_only = true;
        } else {
            if (*layer_only) {
                layer_on(layer);
                return true;
            }
        }
    } else if (is_layer_toggle_canceld(keycode)) {
        *layer_only = false;
    }
    return false;
}

bool nav_only = false;
bool sym_only = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool override = false;

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

    // Custom oneshot mod implementation with no timers.
    update_oneshot(&os_lsft_state, KC_LSFT, OS_LSFT, keycode, record);
    update_oneshot(&os_rsft_state, KC_RSFT, OS_RSFT, keycode, record);
    update_oneshot(&os_lctl_state, KC_LCTL, OS_LCTL, keycode, record);
    update_oneshot(&os_rctl_state, KC_RCTL, OS_RCTL, keycode, record);
    update_oneshot(&os_lalt_state, KC_LALT, OS_LALT, keycode, record);
    update_oneshot(&os_ralt_state, KC_RALT, OS_RALT, keycode, record);
    update_oneshot(&os_lgui_state, KC_LGUI, OS_LGUI, keycode, record);
    update_oneshot(&os_rgui_state, KC_RGUI, OS_RGUI, keycode, record);


    override |= uppercase_accent(keycode, record);

    override |= tap_toggle_layer(NAV, &nav_only, keycode, record);
    override |= tap_toggle_layer(SYM, &sym_only, keycode, record);

    return !override;
}

void oneshot_layer_changed_user(uint8_t layer) {
    // Disable hold one shot layer
    if (layer == SPC || layer == SPC2) {
        clear_oneshot_layer_state(ONESHOT_PRESSED);
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYM, NAV, NUM);
}
