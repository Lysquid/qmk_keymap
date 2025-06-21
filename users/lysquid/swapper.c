#include "swapper.h"

bool update_swapper(
    bool *active,
    uint16_t cmdish,
    uint16_t tabish,
    uint16_t trigger,
    uint16_t reverse_trigger,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                register_code(cmdish);
            }
            register_code(tabish);
        } else {
            unregister_code(tabish);
            // Don't unregister cmdish until some other key is hit or released.
        }
    } else if (keycode == reverse_trigger) {
        if (*active) {
            if (record->event.pressed) {
                del_mods(MOD_MASK_CTRL);
                register_code(KC_LSFT);
                register_code(tabish);
                return true;
            } else {
                unregister_code(KC_LSFT);
                unregister_code(tabish);
            }
        }
    } else if (*active) {
        if (!is_swapper_ignored_key(keycode, record)) {
            unregister_code(cmdish);
            *active = false;
        }
    }
    return false;
}
