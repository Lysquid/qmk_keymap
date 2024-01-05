# QMK firmware

This my firmware config for the [Sweep keyboard](https://github.com/davidphilipbarr/Sweep), a split custom keyboard with 34 keys. It makes extensive use of layers to fit all keys.

## Features

- Custom layout optimized for French and English, [Erglace](https://github.com/Lysquid/Erglace) (can be switched with AZERTY)
- A layer for all symbols
- A layer for navigation keys, like the arrow keys
- A tri layer for numbers and function keys
- One shot modifiers, taken from the awesome [Callum's keymap](https://github.com/qmk/qmk_firmware/tree/user-keymaps-still-present/users/callum)
- One shot layer for French accents and useful Unicode characters, inspired by [QWERTY Lafayette](https://qwerty-lafayette.org/)
- A layer to emulate a mouse
- Compilation for QWERTY or AZERTY depending on a config flag (by default, the computer must be set to AZERTY)

## Layers

![keymap](keymap.svg)

## Special behaviors

### Modifiers

- The one shot modifiers are on the `NAV` and `SYM` layers. When a mod is tapped, it is queued and will be applied to the next key (for exemple a letter on the base layer).
- Pressing `NAV` or `SYM` again cancels any queued modifier.
- To do the same shortcut multiple times, the modifier can be held. It stays active even if the layer changes.
- `caps word` is QMK [caps word](https://docs.qmk.fm/#/feature_caps_word): it enables caps lock for one word only, useful to write constants.
- Accented letters from the one shot layer can be made uppercase with `shift`.

### Key overrides

#### Alt+Tab

- `alt`+`undo` does `alt`+`tab`, to be able to do this useful shortcut with one hand while the other is on the mouse. It can be combined with `shift`
- `super`+`undo` does `super`+`tab`
- `ctrl`+`esc` does `ctrl`+`tab`

#### Media keys

- `super`+`vol+` plays the next song, `super`+`vol-` the previous one, and `super`+`play` mutes the sound.
- `super`+`shift`+`vol+` increases the brightness, and `super`+`shift`+`vol-` decreases it.
- `ctrl`+`vol+` goes forward in a browser, `ctrl`+`vol-` goes backward, and `ctrl`+`play` does a refresh.
- `alt`+`vol+` zooms in, `alt`+`vol-` zooms out, and `alt`+`play` resets the zoom.

#### Shortcuts

- `ctrl`+`copy` does `ctrl`+`shift`+`c`, to copy in a terminal.
- `ctrl`+`cut` does `ctrl`+`s` to save a file.
- `ctrl`+`redo` closes a browser tab.

#### Others

- `ctrl`+`vol+` shuts down the computer, and `ctrl`+`vol+` puts it to sleep. They are unlikely te be pressed by accident because those keys use the same finger.
- `page up` and `page down` are inverted when used with `ctrl`, `super`, or `alt` because it feels more natural to me.
- Note: `redo` and `undo` are in this order because `undo` is used much more often, so it is better on a stronger and faster finger. Plus, it must be combined with `shift` to do a redo in certain apps.

### Navigation lock

- Because it is used very often, the `NAV` layer can be locked by pressing `shift` with the thumb when on the layer.
- Alternatively, `shift` and then `NAV` does the same (if shift was not used to make a letter uppercase).
- Any layer key unlocks the layer, except for `SYM` if a modifier is active, to be able to navigate with `super`+`<number>` on a window manager.
- Holding `shift` or pressing `caps word` also disables the layer.

### Mouse layer

- `slow mouse` button make the cursor speed slower for more precision.
- `onesht` buttons stand for 'one shot click'. The mouse layer is disabled after the button is clicked, unlike the other buttons.
- A tap on `NAV`, `SYM` or `shift` exits the mouse layer.
- `erglce` stands for Erglace, my keyboard layout. It can be switched with AZERTY (including the one shot special characters layer, see the [keymap definition](keyboards/ferris/keymaps/lysquid/keymap.c)).

## Installation

- Install the [QMK CLI](https://docs.qmk.fm/#/newbs_getting_started?id=set-up-your-environment) (available on Arch repos as `qmk`)
- Download the latest [release](/releases)
- Run `qmk flash ferris_sweep_lysquid.hex`
- Put your keyboard in bootloader mode (with a `boot` key or a reset button)
- If you are flashing your keyboard for the first time, you must flash the two sides separately with the flags `-bl avrdude-split-left` and `-bl avrdude-split-right`
