#pragma once

#define ko_make_disable_shifted_ver(trigger_key) \
    ko_make_mod_only_with_layers(MOD_MASK_SHIFT, trigger_key, trigger_key, ~0)

#define ko_make_mod_only_with_layers(trigger_mods, trigger_key, replacement_key, layers) \
    ko_make_with_layers_and_negmods(trigger_mods, trigger_key, replacement_key, layers, (unsigned char) (~(trigger_mods)))

#define ko_make_no_suppressed_mods_with_options(trigger_mods_, trigger_key, replacement_key, options_) \
    ((const key_override_t){                                                                \
        .trigger_mods                           = (trigger_mods_),                          \
        .layers                                 = ~0,                                       \
        .suppressed_mods                        = 0,                                        \
        .options                                = (options_),                               \
        .negative_mod_mask                      = 0,                                        \
        .custom_action                          = NULL,                                     \
        .context                                = NULL,                                     \
        .trigger                                = (trigger_key),                            \
        .replacement                            = (replacement_key),                        \
        .enabled                                = NULL                                      \
    })
