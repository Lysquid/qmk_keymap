#include "french.h"
#include "unicodes.h"
#include "azerty_keycodes.h"
#include "action.h"
#include "keycodes.h"
#include "keymap_french.h"
#include "../features.h"
#include "../keymap.h"


void dead_key_accents(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
    case KF_ACRC: dead_key_accent(FR_A, CIRCUMFLEX, record); break;
    case KF_ECRC: dead_key_accent(FR_E, CIRCUMFLEX, record); break;
    case KF_ICRC: dead_key_accent(FR_I, CIRCUMFLEX, record); break;
    case KF_OCRC: dead_key_accent(FR_O, CIRCUMFLEX, record); break;
    case KF_UCRC: dead_key_accent(FR_U, CIRCUMFLEX, record); break;
    case KF_EDIA: dead_key_accent(FR_E, DIAERESIS, record); break;
    case KF_IDIA: dead_key_accent(FR_I, DIAERESIS, record); break;
    case KF_UDIA: dead_key_accent(FR_U, DIAERESIS, record); break;
    }
}

uint16_t diaeresis_conversion(uint16_t keycode, bool lowercase) {
    switch (keycode)
    {
    case KF_A: return lowercase ? AD1 : AD2;
    case KF_E: return lowercase ? ED1 : ED2;
    case KF_I: return lowercase ? ID1 : ID2;
    case KF_O: return lowercase ? OD1 : OD2;
    case KF_U: return lowercase ? UD1 : UD2;
    case KF_Y: return lowercase ? YD1 : YD2;
    default: return 0;
    }
}
