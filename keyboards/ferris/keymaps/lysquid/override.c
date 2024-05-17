#include "azerty.h"
#include "quantum_keycodes.h"
#include "override.h"
#include "keymap.h"

#define DEF_MASK (1 << DEF | 1 << DEF2)
#define NAV_MASK (1 << NAV)
#define SYM_MASK (1 << SYM)
#define NUM_MASK (1 << NUM)

// Layout symbols
const key_override_t def_comma_override         = ko_make_with_layers(MOD_MASK_SHIFT, KF_COMM, KF_QUES, DEF_MASK);
const key_override_t def_dot_override           = ko_make_with_layers(MOD_MASK_SHIFT, KF_DOT,  KF_EXLM, DEF_MASK);
const key_override_t def_minus_override         = ko_make_with_layers(MOD_MASK_SHIFT, KF_MINS, KF_UNDS, DEF_MASK);

// Media keys
const key_override_t media_next_override        = ko_make_mod_only_with_layers(MOD_MASK_SHIFT, KC_VOLU, KC_MEDIA_NEXT_TRACK, NAV_MASK);
const key_override_t media_previous_override    = ko_make_mod_only_with_layers(MOD_MASK_SHIFT, KC_VOLD, KC_MEDIA_PREV_TRACK, NAV_MASK);
const key_override_t mute_override              = ko_make_mod_only_with_layers(MOD_MASK_SHIFT, KC_MPLY, KC_MUTE,             NAV_MASK);
// Browser
const key_override_t browser_forward_override   = ko_make_mod_only_with_layers(MOD_MASK_GUI,   KC_VOLU, KC_WWW_FORWARD,      NAV_MASK);
const key_override_t browser_backward_override  = ko_make_mod_only_with_layers(MOD_MASK_GUI,   KC_VOLD, KC_WWW_BACK,         NAV_MASK);
const key_override_t browser_refresh_override   = ko_make_mod_only_with_layers(MOD_MASK_GUI,   KC_MPLY, KC_WWW_REFRESH,      NAV_MASK);
// Brightness
const key_override_t brightness_up_override     = ko_make_mod_only_with_layers(MOD_MASK_SG,    KC_VOLU, KC_BRIGHTNESS_UP,    NAV_MASK);
const key_override_t brightness_down_override   = ko_make_mod_only_with_layers(MOD_MASK_SG,    KC_VOLD, KC_BRIGHTNESS_DOWN,  NAV_MASK);
// Power
const key_override_t system_power_override      = ko_make_mod_only_with_layers(MOD_MASK_CTRL,  KC_VOLU, KC_SYSTEM_POWER,     NAV_MASK);
const key_override_t system_sleep_override      = ko_make_mod_only_with_layers(MOD_MASK_CTRL,  KC_VOLD, KC_SYSTEM_SLEEP,     NAV_MASK);

// NAV combinations
const key_override_t close_override             = ko_make_mod_only_with_layers(MOD_MASK_CTRL, KF_REDO, KF_CLOSE,   NAV_MASK);
const key_override_t copy_override              = ko_make_mod_only_with_layers(MOD_MASK_CTRL, KF_COPY, S(KF_COPY), NAV_MASK);
const key_override_t save_override              = ko_make_mod_only_with_layers(MOD_MASK_CTRL, KF_CUT,  KF_SAVE,    NAV_MASK);
// Browser
const key_override_t browser_next_override      = ko_make_mod_only_with_layers(MOD_MASK_GUI,  KF_UNDO, KF_BROWSER_NEXT, NAV_MASK);
const key_override_t browser_previous_override  = ko_make_mod_only_with_layers(MOD_MASK_GUI,  KF_REDO, KF_BROWSER_PREV, NAV_MASK);
// Alt+Tab like behavior
const key_override_t alt_shift_tab_override     = ko_make_with_layers(MOD_MASK_ALT,  KF_REDO, LSA(KC_TAB), NAV_MASK);
const key_override_t alt_tab_override           = ko_make_with_layers(MOD_MASK_ALT,  KF_UNDO, A(KC_TAB),   NAV_MASK);
const key_override_t alt_shift_esc_override     = ko_make_with_layers(MOD_MASK_ALT,  KC_VOLU, LSA(KC_ESC), NAV_MASK);
const key_override_t alt_esc_override           = ko_make_with_layers(MOD_MASK_ALT,  KC_VOLD, A(KC_ESC),   NAV_MASK);
const key_override_t ctrl_tab_override          = ko_make_with_layers(MOD_MASK_CTRL, KC_ESC,  C(KC_TAB),   NAV_MASK);
// Invert page up and page when used with no mod
const key_override_t page_up_override           = ko_make_no_suppressed_mods_with_options(MOD_MASK_CAG, KC_PGUP, KC_PGDN, ko_option_one_mod);
const key_override_t page_down_override         = ko_make_no_suppressed_mods_with_options(MOD_MASK_CAG, KC_PGDN, KC_PGUP, ko_option_one_mod);

// Zoom
const key_override_t zoom_in_override           = ko_make_with_layers_and_negmods(MOD_MASK_GUI, KF_RBRC, KF_ZOOM_IN,    SYM_MASK, MOD_MASK_CTRL);
const key_override_t zoom_out_override          = ko_make_with_layers_and_negmods(MOD_MASK_GUI, KF_LBRC, KF_ZOOM_OUT,   SYM_MASK, MOD_MASK_CTRL);
const key_override_t zoom_reset_override        = ko_make_with_layers_and_negmods(MOD_MASK_GUI, KF_PLUS, KF_ZOOM_RESET, SYM_MASK, MOD_MASK_CTRL);
// Keypad variants because some apps don't recognize Azerty
const key_override_t zoom_in_kp_override        = ko_make_with_layers(MOD_MASK_SG,  KF_RBRC, KF_KP_ZOOM_IN,    SYM_MASK);
const key_override_t zoom_out_kp_override       = ko_make_with_layers(MOD_MASK_SG,  KF_LBRC, KF_KP_ZOOM_OUT,   SYM_MASK);
const key_override_t zoom_reset_kp_override     = ko_make_with_layers(MOD_MASK_SG,  KF_PLUS, KF_KP_ZOOM_RESET, SYM_MASK);
// One hand
const key_override_t zoom_reset_override2       = ko_make_with_layers_and_negmods(MOD_MASK_GUI, KF_PSTE, KF_ZOOM_RESET, NAV_MASK, MOD_MASK_ALT);
const key_override_t zoom_reset_kp_override2    = ko_make_with_layers(MOD_MASK_AG, KF_PSTE, KF_KP_ZOOM_RESET, NAV_MASK);

// Disable shifted variants
const key_override_t lbrc_override  = ko_make_disable_shifted_ver(KF_LBRC);
const key_override_t rbrc_override  = ko_make_disable_shifted_ver(KF_RBRC);
const key_override_t lprn_override  = ko_make_disable_shifted_ver(KF_LPRN);
const key_override_t rprn_override  = ko_make_disable_shifted_ver(KF_RPRN);
const key_override_t lcbr_override  = ko_make_disable_shifted_ver(KF_LCBR);
const key_override_t rcbr_override  = ko_make_disable_shifted_ver(KF_RCBR);
const key_override_t labk_override  = ko_make_disable_shifted_ver(KF_LABK);
const key_override_t rabk_override  = ko_make_disable_shifted_ver(KF_RABK);
const key_override_t tilde_override = ko_make_disable_shifted_ver(KF_TILD);
const key_override_t hash_override  = ko_make_disable_shifted_ver(KF_HASH);
const key_override_t circ_override  = ko_make_disable_shifted_ver(KF_CIRC);
const key_override_t dot_override   = ko_make_disable_shifted_ver(KF_DOT);
const key_override_t comm_override  = ko_make_disable_shifted_ver(KF_COMM);
const key_override_t coln_override  = ko_make_disable_shifted_ver(KF_COLN);
const key_override_t mins_override  = ko_make_disable_shifted_ver(KF_MINS);
const key_override_t scln_override  = ko_make_disable_shifted_ver(KF_SCLN);
const key_override_t dquo_override  = ko_make_disable_shifted_ver(KF_DQUO);
const key_override_t quot_override  = ko_make_disable_shifted_ver(KF_QUOT);
const key_override_t dlr_override   = ko_make_disable_shifted_ver(KF_DLR);
const key_override_t perc_override  = ko_make_disable_shifted_ver(KF_PERC);
const key_override_t bsls_override  = ko_make_disable_shifted_ver(KF_BSLS);
const key_override_t ampr_override  = ko_make_disable_shifted_ver(KF_AMPR);
const key_override_t pipe_override  = ko_make_disable_shifted_ver(KF_PIPE);
const key_override_t grv_override   = ko_make_disable_shifted_ver(KF_GRV);
const key_override_t at_override    = ko_make_disable_shifted_ver(KF_AT);
const key_override_t under_unds     = ko_make_disable_shifted_ver(KF_UNDS);
#ifdef FRENCH
// Keypad variants to fix some shortcuts
const key_override_t slsh_override  = ko_make_basic(MOD_MASK_SHIFT, FR_SLSH, KC_KP_SLASH);
const key_override_t astr_override  = ko_make_basic(MOD_MASK_SHIFT, FR_ASTR, KC_KP_ASTERISK);
const key_override_t plus_override  = ko_make_basic(MOD_MASK_SHIFT, FR_PLUS, KC_KP_PLUS);
const key_override_t equal_override = ko_make_basic(MOD_MASK_SHIFT, FR_EQL,  KC_KP_EQUAL);
#else
const key_override_t slsh_override  = ko_make_disable_shifted_ver(KC_SLSH);
const key_override_t astr_override  = ko_make_disable_shifted_ver(KC_ASTR);
const key_override_t plus_override  = ko_make_disable_shifted_ver(KC_PLUS);
const key_override_t equal_override = ko_make_disable_shifted_ver(KC_EQL);
#endif

// Numbers
#ifdef FRENCH
// Azerty window manager compatibility
const key_override_t override_1 = ko_make_basic(MOD_MASK_GUI, FR_1, G(FR_AMPR));
const key_override_t override_2 = ko_make_basic(MOD_MASK_GUI, FR_2, G(FR_EACU));
const key_override_t override_3 = ko_make_basic(MOD_MASK_GUI, FR_3, G(FR_DQUO));
const key_override_t override_4 = ko_make_basic(MOD_MASK_GUI, FR_4, G(FR_QUOT));
const key_override_t override_5 = ko_make_basic(MOD_MASK_GUI, FR_5, G(FR_LPRN));
const key_override_t override_6 = ko_make_basic(MOD_MASK_GUI, FR_6, G(FR_MINS));
const key_override_t override_7 = ko_make_basic(MOD_MASK_GUI, FR_7, G(FR_EGRV));
const key_override_t override_8 = ko_make_basic(MOD_MASK_GUI, FR_8, G(FR_UNDS));
const key_override_t override_9 = ko_make_basic(MOD_MASK_GUI, FR_9, G(FR_CCED));
const key_override_t override_0 = ko_make_basic(MOD_MASK_GUI, FR_0, G(FR_AGRV));
#else
const key_override_t override_1 = ko_make_disable_shifted_ver(KC_1);
const key_override_t override_2 = ko_make_disable_shifted_ver(KC_2);
const key_override_t override_3 = ko_make_disable_shifted_ver(KC_3);
const key_override_t override_4 = ko_make_disable_shifted_ver(KC_4);
const key_override_t override_5 = ko_make_disable_shifted_ver(KC_5);
const key_override_t override_6 = ko_make_disable_shifted_ver(KC_6);
const key_override_t override_7 = ko_make_disable_shifted_ver(KC_7);
const key_override_t override_8 = ko_make_disable_shifted_ver(KC_8);
const key_override_t override_9 = ko_make_disable_shifted_ver(KC_9);
const key_override_t override_0 = ko_make_disable_shifted_ver(KC_0);
#endif

// Azerty specials
#ifdef FRENCH
const key_override_t rarw_override  = ko_make_disable_shifted_ver(KF_RARW);
const key_override_t larw_override  = ko_make_disable_shifted_ver(KF_LARW);
const key_override_t raqt_override  = ko_make_disable_shifted_ver(KF_RAQT);
const key_override_t laqt_override  = ko_make_disable_shifted_ver(KF_LAQT);
const key_override_t mdot_override  = ko_make_disable_shifted_ver(KF_MDOT);
const key_override_t bdot_override  = ko_make_disable_shifted_ver(KF_BDOT);
const key_override_t euro_override  = ko_make_disable_shifted_ver(KF_EURO);
const key_override_t sup2_override  = ko_make_disable_shifted_ver(KF_SUP2);
#endif

const key_override_t **key_overrides = (const key_override_t *[]) {
    &def_comma_override,
    &def_dot_override,
    &def_minus_override,
    &media_next_override,
    &media_previous_override,
    &mute_override,
    &browser_forward_override,
    &browser_backward_override,
    &browser_previous_override,
    &brightness_up_override,
    &brightness_down_override,
    &system_sleep_override,
    &system_power_override,
    &zoom_in_kp_override,
    &zoom_out_kp_override,
    &zoom_reset_kp_override,
    &zoom_in_override,
    &zoom_out_override,
    &zoom_reset_override,
    &zoom_reset_override2,
    &zoom_reset_kp_override2,
    &close_override,
    &copy_override,
    &save_override,
    &browser_refresh_override,
    &browser_next_override,
    &alt_shift_tab_override,
    &alt_tab_override,
    &alt_shift_esc_override,
    &alt_esc_override,
    &ctrl_tab_override,
    &page_up_override,
    &page_down_override,
    &lbrc_override,
    &rbrc_override,
    &lprn_override,
    &rprn_override,
    &lcbr_override,
    &rcbr_override,
    &labk_override,
    &rabk_override,
    &tilde_override,
    &hash_override,
    &circ_override,
    &dot_override,
    &comm_override,
    &coln_override,
    &mins_override,
    &scln_override,
    &dquo_override,
    &quot_override,
    &dlr_override,
    &perc_override,
    &bsls_override,
    &ampr_override,
    &pipe_override,
    &grv_override,
    &at_override,
    &under_unds,
    &slsh_override,
    &astr_override,
    &plus_override,
    &equal_override,
    &override_1,
    &override_2,
    &override_3,
    &override_4,
    &override_5,
    &override_6,
    &override_7,
    &override_8,
    &override_9,
    &override_0,
    #ifdef FRENCH
    &rarw_override,
    &larw_override,
    &raqt_override,
    &laqt_override,
    &mdot_override,
    &bdot_override,
    &euro_override,
    &sup2_override,
    #endif
    NULL
};
