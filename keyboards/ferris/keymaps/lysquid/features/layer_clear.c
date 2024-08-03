#include "action.h"
#include "action_layer.h"
#include "keycodes.h"
#include "../features.h"
#include "../keymap.h"


void cancel_one_shot_hold(uint8_t layer) {
    if (layer == SPC || layer == SPC2) {
        clear_oneshot_layer_state(ONESHOT_PRESSED);
    }
}

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
            break;
        case KC_RSFT:
            layer_off(MOS);
            break;
        }
    }
}

void clear_mouse_layer(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
    case DF(DEF):
    case DF(DEF2):
        layer_off(MOS);
        break;
    }
}
