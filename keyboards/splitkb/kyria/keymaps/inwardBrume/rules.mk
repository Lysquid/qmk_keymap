LTO_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
CAPS_WORD_ENABLE = yes
UNICODE_COMMON = yes
UNICODE_ENABLE = no
UNICODEMAP_ENABLE = yes
DEBOUNCE_TYPE = sym_eager_pk

# Kyria
OLED_ENABLE = yes
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
RGB_MATRIX_ENABLE = no     # Disable keyboard RGB matrix, as it is enabled by default on rev3
RGBLIGHT_ENABLE = no       # Enable keyboard RGB underglow
CONVERT_TO = liatris

SRC += process.c
SRC += features/caps_word.c
SRC += features/french.c
SRC += features/key_tri_layer.c
SRC += features/layer_clear.c
SRC += features/macros.c
SRC += features/mouse.c
SRC += features/nav_lock.c
SRC += features/oneshots.c
SRC += features/overrides.c
SRC += features/remove_mods.c
SRC += features/swappers.c
