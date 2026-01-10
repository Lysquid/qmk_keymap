#include "../keymap.h"
#include "../features.h"


bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode)
    {
    case MO(SYM):
        return IS_LAYER_OFF(NAV);
    case MO(NAV):
        return IS_LAYER_OFF(SYM);
    case KC_MPLY:
    case KC_MNXT:
    case KC_MPRV:
        // Won't work without cancelling the mod on Gnome
        return true;
    default:
        return false;
    }
}


bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode)
    {
    case MO(SYM):
    case MO(NAV):
    case OSL(SPC): // because you might want to do one shot shift + special character
    case KC_LSFT:
    case KC_RSFT:
    case OC_LSFT:
    case OC_RSFT:
    case OC_LCTL:
    case OC_RCTL:
    case OC_LALT:
    case OC_RALT:
    case OC_LGUI:
    case OC_RGUI:
        return true;
    default:
        return false;
    }
}


oneshot_state oc_lsft_state = oc_up_unqueued;
oneshot_state oc_rsft_state = oc_up_unqueued;
oneshot_state oc_lctl_state = oc_up_unqueued;
oneshot_state oc_rctl_state = oc_up_unqueued;
oneshot_state oc_lalt_state = oc_up_unqueued;
oneshot_state oc_ralt_state = oc_up_unqueued;
oneshot_state oc_lgui_state = oc_up_unqueued;
oneshot_state oc_rgui_state = oc_up_unqueued;

// Custom oneshot mod implementation with no timers
void update_oneshots(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(&oc_lsft_state, KC_LSFT, OC_LSFT, keycode, record);
    update_oneshot(&oc_rsft_state, KC_RSFT, OC_RSFT, keycode, record);
    update_oneshot(&oc_lctl_state, KC_LCTL, OC_LCTL, keycode, record);
    update_oneshot(&oc_rctl_state, KC_RCTL, OC_RCTL, keycode, record);
    update_oneshot(&oc_lalt_state, KC_LALT, OC_LALT, keycode, record);
    update_oneshot(&oc_ralt_state, KC_RALT, OC_RALT, keycode, record);
    update_oneshot(&oc_lgui_state, KC_LGUI, OC_LGUI, keycode, record);
    update_oneshot(&oc_rgui_state, KC_RGUI, OC_RGUI, keycode, record);
}


void instant_gui(uint16_t keycode, keyrecord_t *record) {

    if (oc_lgui_state == oc_down_unused && oc_lctl_state == oc_down_unused) {
        unregister_code(KC_LCTL);
        unregister_code(KC_LGUI);
        uint8_t saved_shift = get_mods() & MOD_BIT_LSHIFT;
        del_mods(saved_shift);
        tap_code(KC_LGUI);
        add_mods(saved_shift);
        register_code(KC_LCTL);
        register_code(KC_LGUI);
        oc_lgui_state = oc_down_used;
        oc_lctl_state = oc_down_used;
    }
}

bool is_any_oneshot_in_state(oneshot_state state) {
    return (
        oc_lsft_state == state ||
        oc_rsft_state == state ||
        oc_lctl_state == state ||
        oc_rctl_state == state ||
        oc_lalt_state == state ||
        oc_ralt_state == state ||
        oc_lgui_state == state ||
        oc_rgui_state == state
    );
}
