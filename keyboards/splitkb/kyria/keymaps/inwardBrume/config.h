#pragma once

// Fixes obscure bug where both sides don't communicate
// #define SPLIT_USB_DETECT

// BUG: Must be flashed on each side individually
// #define DEBOUNCE 50

// Fixes the problem where I have to replug the keyboard on boot
// BUG: Breaks symetry, you can only flash on one side with this option
// #define WAIT_FOR_USB

#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX

#define CAPS_WORD_IDLE_TIMEOUT 0

#define MOUSEKEY_DELAY 10
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MOVE_DELTA 7
#define MOUSEKEY_MAX_SPEED 3
#define MOUSEKEY_TIME_TO_MAX 30

#define MOUSEKEY_WHEEL_DELAY 10
#define MOUSEKEY_WHEEL_INTERVAL 80
#define MOUSEKEY_WHEEL_DELTA 1
#define MOUSEKEY_WHEEL_MAX_SPEED 10
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40

// French AZERTY layout compatibility
#define FRENCH

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_RGB_TEST
#    define RGBLIGHT_EFFECT_ALTERNATING
#    define RGBLIGHT_EFFECT_TWINKLE
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#    ifndef RGBLIGHT_LIMIT_VAL
#    	define RGBLIGHT_LIMIT_VAL 150
#    endif
#endif
