#include "../keymap.h"
#include "../features.h"


void persistent_default_layer(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        switch (keycode)
        {
        case DF(DEF):  set_single_persistent_default_layer(DEF);  break;
        case DF(DEF2): set_single_persistent_default_layer(DEF2); break;
        }
    }
}
