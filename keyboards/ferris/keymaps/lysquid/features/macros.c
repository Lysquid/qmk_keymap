#include "action.h"
#include "keycodes.h"
#include "../features.h"
#include "../keymap.h"


void half_scroll(uint16_t keycode, keyrecord_t *record) {
    if (keycode == KC_HSCL && record->event.pressed) {
        uint16_t direction_key;
        uint8_t saved_ctrl_mod = get_mods() & MOD_MASK_CTRL;
        if (saved_ctrl_mod) {
            direction_key = KC_UP;
        } else {
            direction_key = KC_DOWN;
        }
        unregister_mods(saved_ctrl_mod);
        for (int i=0; i<5; i++) {
            tap_code(direction_key);
        }
        register_mods(saved_ctrl_mod);
    }
}
