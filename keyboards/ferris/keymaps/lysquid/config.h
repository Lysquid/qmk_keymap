#pragma once

// Fixes obscure bug where both sides don't communicate
#define SPLIT_USB_DETECT

// BUG: Must be flashed on each side individually
#define DEBOUNCE 50

// Fixes the problem where I have to replug the keyboard on boot
// BUG: Breaks symetry, you can only flash on one side with this option
#define WAIT_FOR_USB

#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX

#define CAPS_WORD_IDLE_TIMEOUT 0

#define MOUSEKEY_DELAY 10
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MOVE_DELTA 5
#define MOUSEKEY_MAX_SPEED 3
#define MOUSEKEY_TIME_TO_MAX 30

#define MOUSEKEY_WHEEL_DELAY 10
#define MOUSEKEY_WHEEL_INTERVAL 80
#define MOUSEKEY_WHEEL_MAX_SPEED 8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40

// French AZERTY layout compatibility
#define FRENCH
