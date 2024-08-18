#include "../keymap.h"
#include "../features.h"


bool oneshot_mouse_buttons(uint16_t keycode, keyrecord_t *record) {
    uint16_t btn_code = 0;
    switch (keycode)
    {
    case OS_BTN1:
        btn_code = KC_BTN1;
        break;
    case OS_BTN2:
        btn_code = KC_BTN2;
        break;
    case OS_BTN3:
        btn_code = KC_BTN3;
        break;
    }
    if (btn_code && record->event.pressed) {
        tap_code(btn_code);
        layer_off(MOS);
        return true;
    }
    return false;
}
