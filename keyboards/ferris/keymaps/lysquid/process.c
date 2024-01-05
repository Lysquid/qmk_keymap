#include "azerty.h"
#include "oneshot.h"
#include "french.h"
#include "keymap.h"

// #################
// # ONE SHOT MODS #
// #################

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case MO(SYM):
        return IS_LAYER_OFF(NAV);
        break;
    case MO(NAV):
        return IS_LAYER_OFF(SYM);
        break;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case MO(SYM):
    case MO(NAV):
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
        return true;
    default:
        return false;
    }
}

oneshot_state os_lsft_state = os_up_unqueued;
oneshot_state os_rsft_state = os_up_unqueued;
oneshot_state os_lctl_state = os_up_unqueued;
oneshot_state os_rctl_state = os_up_unqueued;
oneshot_state os_lalt_state = os_up_unqueued;
oneshot_state os_ralt_state = os_up_unqueued;
oneshot_state os_lgui_state = os_up_unqueued;
oneshot_state os_rgui_state = os_up_unqueued;

// Custom oneshot mod implementation with no timers
void update_oneshots(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(&os_lsft_state, KC_LSFT, OS_LSFT, keycode, record);
    update_oneshot(&os_rsft_state, KC_RSFT, OS_RSFT, keycode, record);
    update_oneshot(&os_lctl_state, KC_LCTL, OS_LCTL, keycode, record);
    update_oneshot(&os_rctl_state, KC_RCTL, OS_RCTL, keycode, record);
    update_oneshot(&os_lalt_state, KC_LALT, OS_LALT, keycode, record);
    update_oneshot(&os_ralt_state, KC_RALT, OS_RALT, keycode, record);
    update_oneshot(&os_lgui_state, KC_LGUI, OS_LGUI, keycode, record);
    update_oneshot(&os_rgui_state, KC_RGUI, OS_RGUI, keycode, record);
}

// ########################
// # SPECIALS LAYER CLEAR #
// ########################

// Disable hold one shot layer
void cancel_one_shot_hold(uint8_t layer) {
    if (layer == SPC || layer == SPC2) {
        clear_oneshot_layer_state(ONESHOT_PRESSED);
    }
}

// Clear up higher layers when NAV, SYM or shift are pressed
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

// Clear mouse layer after switching layout
void clear_mouse_layer(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
    case DF(DEF):
    case DF(DEF2):
        layer_off(MOS);
        break;
    }
}

// ##########
// # FRENCH #
// ##########

void dead_key_accents(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
    case KF_ACRC: dead_key_accent(FR_A, circonflexe, record); break;
    case KF_ECRC: dead_key_accent(FR_E, circonflexe, record); break;
    case KF_ICRC: dead_key_accent(FR_I, circonflexe, record); break;
    case KF_OCRC: dead_key_accent(FR_O, circonflexe, record); break;
    case KF_UCRC: dead_key_accent(FR_U, circonflexe, record); break;
    case KF_ETRM: dead_key_accent(FR_E, trema, record); break;
    case KF_ITRM: dead_key_accent(FR_I, trema, record); break;
    case KF_UTRM: dead_key_accent(FR_U, trema, record); break;
    }
}

// ##########################
// # ONE SHOT MOUSE BUTTONS #
// ##########################

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

// #################
// # QMK FUNCTIONS #
// #################

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool override = false;

    #ifdef FRENCH
    dead_key_accents(keycode, record);
    override |= uppercase_accents(keycode, record);
    override |= french_caps_word_fix(keycode, record);
    #endif

    special_layers_clear(keycode, record);
    override |= nav_layer_lock(keycode, record);
    override |= oneshot_mouse_buttons(keycode, record);
    update_oneshots(keycode, record);

    return !override;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    clear_mouse_layer(keycode, record);
}

void oneshot_layer_changed_user(uint8_t layer) {
    cancel_one_shot_hold(layer);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYM, NAV, NUM);
}
