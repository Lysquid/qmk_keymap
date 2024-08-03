#include "keycodes.h"
#include "keymap_french.h"
#include "azerty_keycodes.h"
#include "french.h"
#include "../keymap.h"


// QMK Callback to choose which key cancels or continue caps word.
// Useful to fix caps word for french layout, and add accented letters.
bool caps_word_press_user(uint16_t keycode) {
    #ifdef FRENCH
    // There is a special function to handle dead key accents, so we don't have to apply caps word
    if (is_uppercase_dk_accent(keycode)) {
        return true;
    }
    #endif
    switch (keycode)
    {
    // Keycodes that continue Caps Word, with shift applied.
    #ifdef FRENCH
    case KC_A ... KC_L:
    case KC_N ... KC_Z:
    case FR_M:
    #else
    case KC_A ... KC_Z:
    case KC_MINS:
    #endif
    case KF_AGRV:
    case KF_ACRC:
    case KF_EDIA:
    case KF_EACU:
    case KF_EGRV:
    case KF_ECRC:
    case KF_ICRC:
    case KF_IDIA:
    case KF_OCRC:
    case KF_UGRV:
    case KF_UCRC:
    case KF_UDIA:
    case KF_AE:
    case KF_OE:
    case KF_CCED:
        add_weak_mods(MOD_BIT_LSHIFT);  // Apply shift to next key.
        return true;

    // Keycodes that continue Caps Word, without shifting.
    case KF_1 ... KF_0:
    case KC_BSPC:
    case KC_DEL:
    case KF_UNDS:
    case KF_MDOT:
        return true;

    default:
        return false;  // Deactivate Caps Word.
    }
}
