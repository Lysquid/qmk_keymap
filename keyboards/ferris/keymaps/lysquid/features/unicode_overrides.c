#include "../keymap.h"
#include "../features.h"
#include "../../../../users/lysquid/azerty_keycodes.h"

bool overrides_with_unicode(uint16_t keycode, keyrecord_t *record) {
    if (keycode == KF_QUOT && get_mods() & MOD_MASK_SHIFT && (IS_LAYER_ON(SPC) || IS_LAYER_ON(SPC2))) {
        if (record->event.pressed) {
            register_unicodemap(NNBSP);
        }
        return true;
    }
    return false;
}
