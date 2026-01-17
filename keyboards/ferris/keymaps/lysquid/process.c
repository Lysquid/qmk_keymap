#include "keymap.h"
#include "features.h"

#include "../../../../users/lysquid/french.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool continue_processing = true;

    clear_special_layers(keycode, record);
    continue_processing &= nav_layer_lock(keycode, record);
    continue_processing &= oneshot_mouse_buttons(keycode, record);
    continue_processing &= overrides_with_unicode(keycode, record);
    continue_processing &= windows_alt_codes(keycode, record);
    continue_processing &= update_swappers(keycode, record);
    update_oneshots(keycode, record);
    half_scroll(keycode, record);
    instant_gui(keycode, record);
    persistent_default_layer(keycode, record);

    #ifdef AZERTY
    dead_key_accents(keycode, record);
    continue_processing &= french_caps_word_fix(keycode, record);
    process_uppercase_dk_accents(keycode, record);
    #endif

    save_incompatible_mods(keycode, record);
    return continue_processing;
}


void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    restore_incompatible_mods();
    update_key_tri_layers(keycode, record);
    clear_mouse_layer(keycode, record);
    #ifdef AZERTY
    post_process_uppercase_dk_accents(keycode, record);
    #endif
}


void oneshot_layer_changed_user(uint8_t layer) {
    cancel_one_shot_hold(layer);
}


layer_state_t layer_state_set_user(layer_state_t state) {
    if (nav_lock_allows_tri_layer(state)) {
        return update_tri_layer_state(state, SYM, NAV, NUM);
    } else {
        return state;
   }
}

