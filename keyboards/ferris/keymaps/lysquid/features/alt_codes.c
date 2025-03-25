#include "../keymap.h"
#include "../features.h"
#include "os_detection.h"

uint8_t keypad_nums[10] = {
    KC_KP_0,
    KC_KP_1,
    KC_KP_2,
    KC_KP_3,
    KC_KP_4,
    KC_KP_5,
    KC_KP_6,
    KC_KP_7,
    KC_KP_8,
    KC_KP_9,
};

const uint8_t _ = -1;

static void tap_alt_code(uint8_t n1, uint8_t n2, uint8_t n3, uint8_t n4) {
    uint16_t saved_mods = get_mods() & MOD_MASK_SHIFT;
    del_mods(saved_mods);
    register_code(KC_LALT);
    if (n1 != _) tap_code(keypad_nums[n1]);
    if (n2 != _) tap_code(keypad_nums[n2]);
    if (n3 != _) tap_code(keypad_nums[n3]);
    if (n4 != _) tap_code(keypad_nums[n4]);
    unregister_code(KC_LALT);
    add_mods(saved_mods);
}

bool diaeresis = false;

static bool alt_codes(uint16_t keycode, bool shift) {
    #ifndef FRENCH
    if (diaeresis) {
        switch (keycode)
        {
        case KF_A: if (shift) tap_alt_code(0,1,9,6); else tap_alt_code(_,1,3,2); break;
        case KF_E: if (shift) tap_alt_code(0,2,0,3); else tap_alt_code(_,1,3,7); break;
        case KF_I: if (shift) tap_alt_code(0,2,0,7); else tap_alt_code(_,1,3,9); break;
        case KF_O: if (shift) tap_alt_code(_,1,5,3); else tap_alt_code(_,1,4,8); break;
        case KF_U: if (shift) tap_alt_code(_,1,5,4); else tap_alt_code(_,1,2,9); break;
        case KF_Y: if (shift) tap_alt_code(0,1,5,9); else tap_alt_code(_,1,5,2); break;
        case KC_LSFT: return false;
        case KC_RSFT: return false;
        case OS_LSFT: return false;
        case OS_RSFT: return false;
        default: diaeresis = false; return false;
        }
        diaeresis = false;
        return true;
    }
    #endif
    switch (keycode)
    {
    #ifdef FRENCH
    case KF_AGRV: if (shift) tap_alt_code(0,1,9,2); else return false; break;
    case KF_EACU: if (shift) tap_alt_code(_,1,4,4); else return false; break;
    case KF_EGRV: if (shift) tap_alt_code(0,2,0,0); else return false; break;
    case KF_UGRV: if (shift) tap_alt_code(0,2,1,7); else return false; break;
    case KF_CCED: if (shift) tap_alt_code(_,1,2,8); else return false; break;
    #else
    case KF_AGRV: if (shift) tap_alt_code(0,1,9,2); else tap_alt_code(_,1,3,3); break;
    case KF_EACU: if (shift) tap_alt_code(_,1,4,4); else tap_alt_code(_,1,3,0); break;
    case KF_EGRV: if (shift) tap_alt_code(0,2,0,0); else tap_alt_code(_,1,3,8); break;
    case KF_UGRV: if (shift) tap_alt_code(0,2,1,7); else tap_alt_code(_,1,5,1); break;
    case KF_CCED: if (shift) tap_alt_code(_,1,2,8); else tap_alt_code(_,1,3,5); break;
    case KF_ACRC: if (shift) tap_alt_code(0,1,9,4); else tap_alt_code(_,1,3,1); break;
    case KF_ECRC: if (shift) tap_alt_code(0,2,0,2); else tap_alt_code(_,1,3,6); break;
    case KF_ICRC: if (shift) tap_alt_code(0,2,0,6); else tap_alt_code(_,1,4,0); break;
    case KF_OCRC: if (shift) tap_alt_code(0,2,1,2); else tap_alt_code(_,1,4,7); break;
    case KF_UCRC: if (shift) tap_alt_code(0,2,1,9); else tap_alt_code(_,1,5,0); break;
    case KF_MICR: tap_alt_code(0,1,8,1); break;
    case KF_EURO: tap_alt_code(0,1,2,8); break;
    case KF_SUP2: tap_alt_code(0,1,7,8); break;
    case KF_DEG:  tap_alt_code(0,1,7,6); break;
    case KF_DCRC: break;
    case KF_DIAE: diaeresis = true; break;
    #endif
    case KF_AE:   if (shift) tap_alt_code(_,1,4,6); else tap_alt_code(_,1,4,5); break;
    case KF_OE:   if (shift) tap_alt_code(0,1,4,0); else tap_alt_code(0,1,5,6); break;
    case KF_NTLD: if (shift) tap_alt_code(_,1,6,5); else tap_alt_code(_,1,6,4); break;
    case KF_IQES: tap_alt_code(_,1,6,8); break;
    case KF_LAQT: tap_alt_code(_,1,7,4); break;
    case KF_RAQT: tap_alt_code(_,1,7,5); break;
    case KF_LDQT: tap_alt_code(0,1,4,7); break;
    case KF_RDQT: tap_alt_code(0,1,4,8); break;
    case KF_CPRT: tap_alt_code(0,1,6,9); break;
    case KF_TM:   tap_alt_code(0,1,5,3); break;
    case KF_BDOT: tap_alt_code(_,_,_,7); break;
    case KF_MDOT: tap_alt_code(0,1,8,3); break;
    case KF_LARW: tap_alt_code(_,_,2,7); break;
    case KF_RARW: tap_alt_code(_,_,2,6); break;
    case KF_CROS: tap_alt_code(0,2,1,5); break;
    case KF_PSMS: tap_alt_code(0,1,7,7); break;
    case KF_DIFF: break;
    default: return false;
    }
    return true;
}

bool windows_alt_codes(uint16_t keycode, keyrecord_t *record) {
    if (detected_host_os() == OS_WINDOWS && record->event.pressed) {
        if (!get_mods() || get_mods() == MOD_BIT_LSHIFT || get_mods() == MOD_BIT_RSHIFT) {
            bool shift = get_mods() & MOD_MASK_SHIFT;
            return alt_codes(keycode, shift);
        }
    }
    return false;
}
