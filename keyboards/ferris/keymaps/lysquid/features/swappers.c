#include "../keymap.h"
#include "../features.h"


bool sw_tab_active = false;
bool sw_esc_active = false;
bool sw_grv_active = false;

bool is_swapper_ignored_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
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
    case KC_LEFT:
    case KC_RIGHT:
    case KC_UP:
    case KC_DOWN:
    case SW_TAB:
    case SW_ESC:
    case SW_GRV:
    case KF_CL_T:
    case KF_SAVE:
        return true;
    case KC_ESC:
        if (record->event.pressed) {
            return true;
        }
    default:
        return false;
    }
}


void update_swappers(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &sw_tab_active, KC_LALT, KC_TAB, SW_TAB, KF_CL_T,
        keycode, record
    );
    if (!sw_tab_active) {
        update_swapper(
            &sw_esc_active, KC_LALT, KC_ESC, SW_ESC, KF_SAVE,
            keycode, record
        );
    }
    if (!sw_esc_active) {
        update_swapper(
            &sw_grv_active, KC_LALT, KC_GRV, SW_GRV, XXXXXXX,
            keycode, record
        );
    }
}
