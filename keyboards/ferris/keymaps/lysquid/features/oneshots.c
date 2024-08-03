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
    case OSL(SPC):
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


void instant_gui(uint16_t keycode, keyrecord_t *record) {

    if (os_lgui_state == os_down_unused && os_lctl_state == os_down_unused) {
        unregister_code(KC_LCTL);
        unregister_code(KC_LGUI);
        uint8_t saved_shift = get_mods() & MOD_BIT_LSHIFT;
        del_mods(saved_shift);
        tap_code(KC_LGUI);
        add_mods(saved_shift);
        register_code(KC_LCTL);
        register_code(KC_LGUI);
        os_lgui_state = os_down_used;
        os_lctl_state = os_down_used;
    }
}
