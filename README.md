# QMK firmware

This my firmware config for the very cool [Sweep keyboard](https://github.com/davidphilipbarr/Sweep), a split custom keyboard with 34 keys. It makes extensive use of layers to fit all keys.

## Features

- Custom layout optimized for French and English, [Erglace](https://github.com/Lysquid/Erglace)
- A layer for all symbols
- A layer for navigation keys, like the arrow keys
- A tri layer for numbers and function keys
- One shot modifiers, taken from the awesome keymap of [Callum](https://github.com/qmk/qmk_firmware/tree/user-keymaps-still-present/users/callum)
- One shot layer for French accents and useful Unicode characters, inspired by [QWERTY Lafayette](https://qwerty-lafayette.org/)
- A layer to emulate a mouse
- Compiled for QWERTY or AZERTY depending on a flag in the config

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
┃ctl+a│ cut │copy │paste│undo ┃ ┃capsw│pgup │pgdwn│menu │pscrn┃
┗━━━━━┷━━━━━┷━━━━━╅─────┼─────┨ ┠─────┼─────╆━━━━━┷━━━━━┷━━━━━┛
                  ┃[NAV]│space┃ ┃shift│ SYM ┃
                  ┗━━━━━┷━━━━━┛ ┗━━━━━┷━━━━━┛
```

### `NUM` Numbers layer

```
┏━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┓ ┏━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┓
┃ F6  │ F7  │ F8  │ F9  │ F10 ┃ ┃ F12 │  7  │  8  │  9  │  ,  ┃
┠─────┼─────┼─────┼─────┼─────┨ ┠─────┼─────┼─────┼─────┼─────┨
┃ alt │super│shift│ctrl │space┃ ┃zoom │  4  │  5  │  6  │  0  ┃
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
┃     │r osc│m osc│l osc│erglc┃ ┃azrty│whl l│  ↑  │whl r│     ┃
┠─────┼─────┼─────┼─────┼─────┨ ┠─────┼─────┼─────┼─────┼─────┨
┃m bck│r clk│m clk│l clk│m fwd┃ ┃     │  ←  │  ↓  │  →  │     ┃
┠─────┼─────┼─────┼─────┼─────┨ ┠─────┼─────┼─────┼─────┼─────┨
┃ alt │super│shift│ctrl │rboot┃ ┃boot │whl d│whl u│     │     ┃
┗━━━━━┷━━━━━┷━━━━━╅─────┼─────┨ ┠─────┼─────╆━━━━━┷━━━━━┷━━━━━┛
                  ┃ NAV │slow2┃ ┃slow1│ SYM ┃
                  ┗━━━━━┷━━━━━┛ ┗━━━━━┷━━━━━┛
```

## Special behaviors

### Modifiers

- The one shot modifiers are on the `NAV` and `SYM` layers. When a mod is tapped, it is queued and will be applied to the next key (for exemple a letter on the default layer).
- Pressing `NAV` or `SYM` again cancels any queued modifier.
- To do the same shortcut multiple times, the modifier can be held. It stays active even if the layer changes.
- `capsw` is QMK [caps word](https://docs.qmk.fm/#/feature_caps_word): it enables caps lock for one word only, useful to write constants.
- Accented letters from the one shot layer can be made uppercase with `shift`.

### Key overrides

- `super`+`undo` does `redo`
- `alt`+`paste` does `alt`+`tab`, to be able to do this useful shortcut with one hand while the other is on the mouse.
- Similarly, `ctrl`+`ctrl+a` does `ctrl`+`tab`
- `super`+`vol+` plays the next song, and `super`+`vol-` the previous one.
- `alt`+`vol+` increases the brightness, and `super`+`vol` decreases it.
- `zoom` zooms in, `ctrl`+`zoom` zooms out, and `super`+`zoom` resets the zoom.
- `pgup` and `pgdwn` are inverted when used with `ctrl`, `super`, or `alt` because it feels more natural to me.

### Navigation lock

- Because it is used very often, the `NAV` layer can be locked by pressing `shift` with the thumb when on the layer.
- Alternatively, `shift` and then `NAV` does the same (if shift was not used to make a letter uppercase).
- Any layer key unlocks the layer, except for `SYM` if a modifier is active, to be able to navigate with `super`+`<number>` on a window manager.
- Holding `shift` or pressing `capsw` also disables the layer.

### Mouse layer

- `osc` buttons stand for 'one shot click'. The mouse layer is disabled after the button is clicked, unlike the other buttons.
- `slow` buttons make the cursor speed slower for more precision.
- A tap on `NAV` or `SYM` exits the mouse layer.
- `erglc` stands for Erglace, my keyboard layout, and `azrty` for AZERTY. Those keys changes the layout (including the one shot special characters layer, see the [keymap definition](keyboards/ferris/keymaps/lysquid/keymap.c)).
