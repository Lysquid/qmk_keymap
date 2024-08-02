#include "action.h"
#include "action_util.h"
#include "azerty.h"
#include "keycodes.h"
#include "keymap_french.h"
#include "modifiers.h"
#include "oneshot.h"
#include "swapper.h"
#include "french.h"
#include "keymap.h"
#include "quantum.h"
#include "unicodemap.h"
#include "unicodes.h"

// #################
// # ONE SHOT MODS #
// #################

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode)
    {
    case MO(SYM):
        return IS_LAYER_OFF(NAV);
    case MO(NAV):
        return IS_LAYER_OFF(SYM);
    case KC_MPLY:
    case KC_MNXT:
    case KC_MPRV:
        // Won't work without cancelling the mod on Gnome
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode)
    {
    case MO(SYM):
    case MO(NAV):
    case OSL(SPC):
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

// ############
// # SWAPPERS #
// ############

bool sw_tab_active = false;
bool sw_esc_active = false;
bool sw_grv_active = false;

bool is_swapper_ignored_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
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
    case KC_LEFT:
    case KC_RIGHT:
    case KC_UP:
    case KC_DOWN:
    case SW_TAB:
    case SW_ESC:
    case SW_GRV:
        return true;
    case KC_ESC:
        if (record->event.pressed) {
            return true;
        }
    default:
        return false;
    }
}

// Alt+Tab like behaviors with one key
void update_swappers(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &sw_tab_active, KC_LALT, KC_TAB, SW_TAB, SW_ESC,
        keycode, record
    );
    if (!sw_tab_active) {
        update_swapper(
            &sw_esc_active, KC_LALT, KC_ESC, SW_ESC, SW_GRV,
            keycode, record
        );
    }
    if (!sw_esc_active) {
        update_swapper(
            &sw_grv_active, KC_LALT, KC_GRV, SW_GRV, XXXXXXX,
            keycode, record
        );
    }
}

// #############
// # CAPS WORD #
// #############

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
    case KF_ACRC: dead_key_accent(FR_A, circumflex, record); break;
    case KF_ECRC: dead_key_accent(FR_E, circumflex, record); break;
    case KF_ICRC: dead_key_accent(FR_I, circumflex, record); break;
    case KF_OCRC: dead_key_accent(FR_O, circumflex, record); break;
    case KF_UCRC: dead_key_accent(FR_U, circumflex, record); break;
    case KF_EDIA: dead_key_accent(FR_E, diaeresis, record); break;
    case KF_IDIA: dead_key_accent(FR_I, diaeresis, record); break;
    case KF_UDIA: dead_key_accent(FR_U, diaeresis, record); break;
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

// ###############
// # HALF SCROLL #
// ###############

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

// ##########################
// # OVERRIDES WITH UNICODE #
// ##########################

bool overrides_with_unicode(uint16_t keycode, keyrecord_t *record) {
    if (keycode == KF_QUOT && get_mods() & MOD_MASK_SHIFT && (IS_LAYER_ON(SPC) || IS_LAYER_ON(SPC2))) {
        if (record->event.pressed) {
            register_unicodemap(NNBSP);
        }
        return true;
    }
    return false;
}

// #####################
// # INCOMPATIBLE MODS #
// #####################

uint8_t saved_mods;

void save_incompatible_mods(uint16_t keycode, keyrecord_t *record) {

    if (!record->event.pressed) {
        return;
    }

    bool mod_layer_on =
        IS_LAYER_ON(SYM_SFT) ||
        IS_LAYER_ON(NAV_ALT) ||
        IS_LAYER_ON(NAV_GUI) ||
        IS_LAYER_ON(NAV_CTL) ||
        IS_LAYER_ON(NUM_SFT);

    uint8_t removed_mods = 0;

    switch (keycode)
    {
    case KC_WBAK:
    case KC_WFWD:
    case KC_WREF:
        if (mod_layer_on) {
            removed_mods = MOD_MASK_CSAG;
        }
        break;
    case KF_WPRV:
    case KF_WNXT:
        if (mod_layer_on) {
            removed_mods = MOD_MASK_AG;
        }
        break;
    case KF_CLAP:
        if (mod_layer_on) {
            removed_mods = MOD_MASK_CSG;
        }
        break;
    case KF_GWP1:
    case KF_GWP2:
    case KF_GWP3:
    case KF_GWP4:
    case KF_GWPP:
    case KF_GWPN:
    case ZOM1_IN:
    case ZOM1_OU:
    case ZOM1_RS:
    case ZOM2_IN:
    case ZOM2_OU:
    case ZOM2_RS:
        if (mod_layer_on) {
            removed_mods = MOD_MASK_CSA;
        }
        break;
    case KF_MWP1:
    case KF_MWP2:
    case KF_MWP3:
    case KF_MWP4:
    case KF_MWPP:
    case KF_MWPN:
        if (mod_layer_on) {
            removed_mods = MOD_MASK_CA;
        }
        break;
    case KC_DELETE:
        if (mod_layer_on && record->event.key.row < 3) {
            removed_mods = MOD_MASK_CAG;
        }
        break;
    #ifdef FRENCH
    case KF_RARW:
    case KF_LARW:
    case KF_RAQT:
    case KF_LAQT:
    case KF_MDOT:
    case KF_BDOT:
    case KF_EURO:
    case KF_SUP2:
    case KF_UNDS:
        if (IS_LAYER_ON(SPC) || IS_LAYER_ON(SPC2)) {
            removed_mods = MOD_MASK_SHIFT;
        }
        break;
    #endif
    }

    // Disable shift on symbol layer
    if ((get_mods() & MOD_MASK_SHIFT) == get_mods() && (
        get_highest_layer(layer_state) == SYM ||
        get_highest_layer(layer_state) == SYM_SFT
    )) {
        removed_mods = MOD_MASK_SHIFT;
    }

    saved_mods = get_mods() & removed_mods;
    del_mods(saved_mods);
}

void restore_incompatible_mods(void) {
    if (saved_mods) {
        add_mods(saved_mods);
        saved_mods = 0;
    }
}

// ######################
// # TRI LAYER WITH KEY #
// ######################

void update_key_tri_layer(
    uint8_t layer,
    uint16_t key,
    uint8_t tri_layer,
    bool* key_down,
    uint16_t keycode,
    keyrecord_t *record,
    uint8_t mod_blacklist
) {
    if (keycode == key) {
        *key_down = record->event.pressed;
    }
    if (IS_LAYER_ON(layer) && *key_down && !(get_mods() & mod_blacklist)) {
        if (IS_LAYER_OFF(tri_layer)) {
            layer_on(tri_layer);
        }
    } else {
        if (IS_LAYER_ON(tri_layer)) {
            layer_off(tri_layer);
        }
    }
}

bool sym_sft_key_down = false;
bool nav_alt_key_down = false;
bool nav_gui_key_down = false;
bool nav_ctl_key_down = false;
bool num_sft_key_down = false;

void update_key_tri_layers(uint16_t keycode, keyrecord_t *record) {
    update_key_tri_layer(SYM, OS_RSFT, SYM_SFT,
        &sym_sft_key_down, keycode, record, MOD_MASK_CAG
    );
    update_key_tri_layer(NAV, OS_LALT, NAV_ALT,
        &num_sft_key_down, keycode, record, 0
    );
    update_key_tri_layer(NAV, OS_LGUI, NAV_GUI,
        &nav_alt_key_down, keycode, record, 0
    );
    update_key_tri_layer(NAV, OS_LCTL, NAV_CTL,
        &nav_gui_key_down, keycode, record, 0
    );
    update_key_tri_layer(NUM, OS_LSFT, NUM_SFT,
        &num_sft_key_down, keycode, record, MOD_MASK_CAG
    );
}

// ###############
// # INSTANT GUI #
// ###############

void instant_gui(uint16_t keycode, keyrecord_t *record) {

    if (os_lgui_state == os_down_unused && os_lctl_state == os_down_unused) {
        unregister_code(KC_LCTL);
        unregister_code(KC_LGUI);
        uint8_t saved_shift = get_mods() & MOD_BIT_LSHIFT;
        del_mods(saved_shift);
        tap_code(KC_LGUI);
        add_mods(saved_shift);
        register_code(KC_LCTL);
        register_code(KC_LGUI);
        os_lgui_state = os_down_used;
        os_lctl_state = os_down_used;
    }
}

// #################
// # QMK FUNCTIONS #
// #################

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool override = false;

    special_layers_clear(keycode, record);
    override |= nav_layer_lock(keycode, record);
    override |= oneshot_mouse_buttons(keycode, record);
    override |= overrides_with_unicode(keycode, record);
    update_oneshots(keycode, record);
    update_swappers(keycode, record);
    half_scroll(keycode, record);
    instant_gui(keycode, record);

    #ifdef FRENCH
    dead_key_accents(keycode, record);
    override |= french_caps_word_fix(keycode, record);
    process_uppercase_dk_accents(keycode, record); // saves shift mods, so must be at the end
    #else
    override |= diaeresis_accent(keycode, record, KF_DIAE);
    #endif

    save_incompatible_mods(keycode, record);
    return !override;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    restore_incompatible_mods();
    update_key_tri_layers(keycode, record);
    clear_mouse_layer(keycode, record);
    #ifdef FRENCH
    post_process_uppercase_dk_accents(keycode, record);
    #endif
}

void oneshot_layer_changed_user(uint8_t layer) {
    cancel_one_shot_hold(layer);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYM, NAV, NUM);
}
