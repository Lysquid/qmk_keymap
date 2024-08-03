#pragma once

#include "action.h"



// FRENCH

// Handle all dead key accents
void dead_key_accents(uint16_t keycode, keyrecord_t *record);



// KEY TRI LAYER

// Update all key tri layers.
// They are tri layers which get triggered by a layer and a key
// (instead of 2 layers)
void update_key_tri_layers(uint16_t keycode, keyrecord_t *record);



// LAYER CLEAR

// Disable hold for specials one shot layer
void cancel_one_shot_hold(uint8_t layer);

// Clear up higher layers when NAV, SYM or shift are pressed
void special_layers_clear(uint16_t keycode, keyrecord_t *record);

// Clear mouse layer after switching layout
void clear_mouse_layer(uint16_t keycode, keyrecord_t *record);



// MACROS

// Key that scrolls half a page up or down
void half_scroll(uint16_t keycode, keyrecord_t *record);



// MOUSE

// One shot mouse buttons that disable mouse layer after being pressed
bool oneshot_mouse_buttons(uint16_t keycode, keyrecord_t *record);



// NAV LOCK

// Lock the NAV layer with MO(NAV) + shift
bool nav_layer_lock(uint16_t keycode, keyrecord_t *record);

// If the NAV key is held too long without using the nav lock, block further keypress
bool nav_time_block(uint16_t keycode, keyrecord_t *record);



// ONE SHOT MODS

// Update all one shot mods
void update_oneshots(uint16_t keycode, keyrecord_t *record);

// Instantly trigger Gui key when Gui+Ctrl one shot mods are pressed on NAV layer
void instant_gui(uint16_t keycode, keyrecord_t *record);



// OVERRIDES

// Override keys with unicode character (not possible with QMK key override)
bool overrides_with_unicode(uint16_t keycode, keyrecord_t *record);



// REMOVE MODS

// Remove and save mods incompatibles with certains keys on certain layers.
// It should be placed near the end of the process function.
void save_incompatible_mods(uint16_t keycode, keyrecord_t *record);


// Restore the incompatible mods after the key has been pressed without it
void restore_incompatible_mods(void);



// SWAPPERS

// Update all swappers, providing Alt+Tab like behavior with one key
void update_swappers(uint16_t keycode, keyrecord_t *record);
