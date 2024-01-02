# QMK firmware

This my firmware config for the very cool [Sweep keyboard](https://github.com/davidphilipbarr/Sweep), a split custom keyboard with 34 keys. It makes extensive use of layers to fit all keys.

## Features

- A custom layout optimized for French and English, [Erglace](https://github.com/Lysquid/Erglace)
- One shot mods, taken from the awesome keymap of [Callum](https://github.com/qmk/qmk_firmware/tree/user-keymaps-still-present/users/callum)
- A one shot layer for French accents and useful unicode characters, inspired by [QWERTY Lafayette](https://qwerty-lafayette.org/)
- A mouse layer for easy navigation

## Layers

### `DEF` Default layer

```
┏━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┓ ┏━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┓
┃  Y  │*SPC │  O  │  F  │  K  ┃ ┃  B  │  P  │  L  │  C  │  W  ┃
┠─────┼─────┼─────┼─────┼─────┨ ┠─────┼─────┼─────┼─────┼─────┨
┃  I  │  A  │  E  │  U  │ , ? ┃ ┃  G  │  T  │  N  │  S  │  R  ┃
┠─────┼─────┼─────┼─────┼─────┨ ┠─────┼─────┼─────┼─────┼─────┨
┃  J  │ . ! │ - _ │  H  │  Z  ┃ ┃  Q  │  D  │  M  │  V  │  X  ┃
┗━━━━━┷━━━━━┷━━━━━╅─────┼─────┨ ┠─────┼─────╆━━━━━┷━━━━━┷━━━━━┛
                  ┃ NAV │space┃ ┃shift│ SYM ┃
                  ┗━━━━━┷━━━━━┛ ┗━━━━━┷━━━━━┛
```

### `SYM` Symbols layer

```
┏━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┓ ┏━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┓
┃  %  │  +  │  [  │  ]  │  #  ┃ ┃  ^  │  :  │  "  │  '  │  $  ┃
┠─────┼─────┼─────┼─────┼─────┨ ┠─────┼─────┼─────┼─────┼─────┨
┃  {  │  (  │  )  │  }  │  /  ┃ ┃  =  │ctrl │shift│super│ alt ┃
┠─────┼─────┼─────┼─────┼─────┨ ┠─────┼─────┼─────┼─────┼─────┨
┃  ~  │  \  │  <  │  >  │  |  ┃ ┃  &  │  ;  │  *  │  `  │  @  ┃
┗━━━━━┷━━━━━┷━━━━━╅─────┼─────┨ ┠─────┼─────╆━━━━━┷━━━━━┷━━━━━┛
                  ┃ NAV │space┃ ┃shift│[SYM]┃
                  ┗━━━━━┷━━━━━┛ ┗━━━━━┷━━━━━┛
```

### `NAV` Navigation layer

```
┏━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┓ ┏━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┓
┃mplay│ MOS │vol- │vol+ │mute ┃ ┃home │bkspc│  ↑  │ del │ end ┃
┠─────┼─────┼─────┼─────┼─────┨ ┠─────┼─────┼─────┼─────┼─────┨
┃ alt │super│shift│ctrl │ esc ┃ ┃ tab │  ←  │  ↓  │  →  │enter┃
┠─────┼─────┼─────┼─────┼─────┨ ┠─────┼─────┼─────┼─────┼─────┨
┃ctl+a│ cut │copy │paste│undo ┃ ┃ ins │pgup │pgdwn│menu │pscrn┃
┗━━━━━┷━━━━━┷━━━━━╅─────┼─────┨ ┠─────┼─────╆━━━━━┷━━━━━┷━━━━━┛
                  ┃[NAV]│space┃ ┃shift│ SYM ┃
                  ┗━━━━━┷━━━━━┛ ┗━━━━━┷━━━━━┛
```

### `NUM` Numbers layer

```
┏━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┓ ┏━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┓
┃ F6  │ F7  │  F8 │  F9 │ F10 ┃ ┃ F12 │  7  │  8  │  9  │  ,  ┃
┠─────┼─────┼─────┼─────┼─────┨ ┠─────┼─────┼─────┼─────┼─────┨
┃ alt │super│shift│ctrl │ esc ┃ ┃space│  4  │  5  │  6  │  0  ┃
┠─────┼─────┼─────┼─────┼─────┨ ┠─────┼─────┼─────┼─────┼─────┨
┃ F1  │ F2  │ F3  │ F4  │ F5  ┃ ┃ F11 │  1  │  2  │  3  │  .  ┃
┗━━━━━┷━━━━━┷━━━━━╅─────┼─────┨ ┠─────┼─────╆━━━━━┷━━━━━┷━━━━━┛
                  ┃[NAV]│space┃ ┃shift│[SYM]┃
                  ┗━━━━━┷━━━━━┛ ┗━━━━━┷━━━━━┛
```

### `*SPC` One shot special characters layer

```
┏━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┓ ┏━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┓
┃  ï  │ DEF │  ô  │  è  │  ù  ┃ ┃  «  │  »  │  ©  │  ç  │  ™  ┃
┠─────┼─────┼─────┼─────┼─────┨ ┠─────┼─────┼─────┼─────┼─────┨
┃  î  │  ²  │  ê  │  é  │  û  ┃ ┃  €  │  â  │  à  │  æ  │  œ  ┃
┠─────┼─────┼─────┼─────┼─────┨ ┠─────┼─────┼─────┼─────┼─────┨
┃  •  │  ·  │  ¿  │  ë  │  ü  ┃ ┃  ←  │  →  │  μ  │  °  │  ×  ┃
┗━━━━━┷━━━━━┷━━━━━╅─────┼─────┨ ┠─────┼─────╆━━━━━┷━━━━━┷━━━━━┛
                  ┃ NAV │  '  ┃ ┃shift│ SYM ┃
                  ┗━━━━━┷━━━━━┛ ┗━━━━━┷━━━━━┛
```

### `MOS` Mouse layer

```
┏━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┓ ┏━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┓
┃     │     │     │     │erglc┃ ┃azrty│whl l│  ↑  │whl r│     ┃
┠─────┼─────┼─────┼─────┼─────┨ ┠─────┼─────┼─────┼─────┼─────┨
┃     │r clk│m clk│l clk│     ┃ ┃     │  ←  │  ↓  │  →  │     ┃
┠─────┼─────┼─────┼─────┼─────┨ ┠─────┼─────┼─────┼─────┼─────┨
┃ alt │super│shift│ctrl │rboot┃ ┃boot │whl d│whl u│     │     ┃
┗━━━━━┷━━━━━┷━━━━━╅─────┼─────┨ ┠─────┼─────╆━━━━━┷━━━━━┷━━━━━┛
                  ┃ NAV │slow2┃ ┃slow1│ SYM ┃
                  ┗━━━━━┷━━━━━┛ ┗━━━━━┷━━━━━┛
