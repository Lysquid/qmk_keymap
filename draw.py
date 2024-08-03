# Stolen from Callum:
# https://github.com/callum-oakley/keymap

from contextlib import redirect_stdout

KEY_W = 55
KEY_H = 45
KEY_RX = 6
KEY_RY = 6
INNER_PAD_W = 2
INNER_PAD_H = 2
OUTER_PAD_W = KEY_W / 2
OUTER_PAD_H = KEY_H / 2
LINE_SPACING = 18

STYLE = """
    svg {
        font-family: SFMono-Regular,Consolas,Liberation Mono,Menlo,monospace;
        font-size: 14px;
        font-kerning: normal;
        text-rendering: optimizeLegibility;
        fill: #24292e;
    }

    rect {
        fill: #f6f8fa;
    }

    .held {
        fill: #fbb;
    }
"""

STYLE_FULL = """
    svg {
        background-color: #1f1f1f;
        margin: auto;
    }
"""


def held(key):
    return {"key": key, "class": "held"}


KEYMAP = [
    {
        "left": [
            ["B", "M", "P", "O", "W"],
            ["A", "U", "I", "E", "? ,"],
            ["_ -", "Y", "X", "! .", "K"],
        ],
        "right": [
            ["Z", "V", "D", "L", "J"],
            ["C", "T", "S", "R", "N"],
            ["SPEC", "Q", "G", "H", "F"],
        ],
        "thumbs": {"left": ["NAV", "space"], "right": ["bksp", "SYM"],},
    },
    {
        "left": [
            ["%", "+", "[", "]", "#"],
            ["{", "(", ")", "}", "/"],
            ["~", "\\", "&lt;", "&gt;", "&amp;"],
        ],
        "right": [
            ["^", ":", "\"", "'", "$"],
            ["=", "ctrl", "shift", "super", "alt"],
            ["|", ";", "*", "`", "@"],
        ],
        "thumbs": {"left": ["NAV", "space"], "right": ["bksp", held("SYM")],},
    },
    {
        "left": [
            ["alt grave", "alt esc", "alt tab", "undo", "redo"],
            ["alt", "super", "shift", "ctrl", "esc"],
            ["selct all", "cut", "copy", "paste", "prnt scrn"],
        ],
        "right": [
            ["home", "caps word", "up", "del", "end"],
            ["tab", "left", "down", "right", "enter"],
            ["half scrol", "page up", "page down", "menu", "MOUS"],
        ],
        "thumbs": {"left": [held("NAV"), "space"], "right": ["ctrl bksp", "SYM"],},
    },
    {
        "left": [
            ["F6", "F7", "F8", "F9", "F10"],
            ["alt", "super", "shift", "ctrl", "space"],
            ["F1", "F2", "F3", "F4", "F5"],
        ],
        "right": [
            ["F12", "7", "8", "9", ","],
            ["tab", "4", "5", "6", "0"],
            ["F11", "1", "2", "3", "."],
        ],
        "thumbs": {
            "left": [held("NAV"), "space"],
            "right": ["bksp", held("SYM")],
        },
    },
    {
        "left": [
            ["â", "û", "î", "ô", "œ"],
            ["à", "ù", "é", "è", "ê"],
            ["-", "¿", "_", "·", "æ"],
        ],
        "right": [
            ["←", "→", "“", "”", "°"],
            ["ç", "€", "«", "»", "ñ"],
            [held("SPEC"), "•", "µ", "≠", "×"],
        ],
        "thumbs": {"left": ["NAV", "'"], "right": ["bksp", "SYM"],},
    },
    {
        "optional": True,
        "left": [
            ["", "right onesht", "middle onesht", "left onesht", "bright up"],
            ["", "right click", "middle click", "left click", "bright down"],
            ["alt", "super", "shift", "ctrl", "reboot"],
        ],
        "right": [
            ["bépo", "wheel left", "mouse up", "wheel right", ""],
            ["erglce", "mouse left", "mouse down", "mouse right", ""],
            ["boot", "wheel up", "wheel down", "", held("MOUS")],
        ],
        "thumbs": {
            "left": ["NAV", "slow mouse"],
            "right": ["bksp", "SYM"],
        },
    },
    {
        "optional": True,
        "left": [
            ["", "play pause", "vol down", "vol up", "mute"],
            [held("alt"), "super", "shift", "ctrl", ""],
            ["", "", "media prev", "media next", ""],
        ],
        "right": [
            ["", "", "", "", ""],
            ["", "", "", "", ""],
            ["", "", "", "", ""],
        ],
        "thumbs": {"left": [held("NAV"), ""], "right": ["", ""],},
    },
    {
        "optional": True,
        "left": [
            ["", "", "tab prev", "tab next", "refrsh"],
            ["alt", held("super"), "shift", "ctrl", ""],
            ["", "", "brswr back", "brswr frwrd", ""],
        ],
        "right": [
            ["", "", "", "", ""],
            ["", "", "", "", ""],
            ["", "", "", "", ""],
        ],
        "thumbs": {"left": [held("NAV"), ""], "right": ["", "SYM"],},
    },
    {
        "optional": True,
        "left": [
            ["", "save", "close tab", "", ""],
            ["alt", "super", "shift", held("ctrl"), ""],
            ["del", "close app", "term copy", "power off", ""],
        ],
        "right": [
            ["", "", "", "", ""],
            ["", "", "", "", ""],
            ["", "", "", "", ""],
        ],
        "thumbs": {"left": [held("NAV"), ""], "right": ["", "SYM"],},
    },
    {
        "optional": True,
        "left": [
            ["", "zoom2 reset", "zoom2 in", "zoom2 out", ""],
            ["", "zoom reset", "zoom in", "zoom out", ""],
            ["", "", "", "", ""],
        ],
        "right": [
            ["", "", "", "", ""],
            ["", "ctrl", held("shift"), "super", "alt"],
            ["", "", "", "", ""],
        ],
        "thumbs": {"left": ["NAV", ""], "right": ["", held("SYM")],},
    },
    {
        "optional": True,
        "left": [
            ["", "", "", "", ""],
            ["alt", "super", held("shift"), "ctrl", ""],
            ["", "", "", "", ""],
        ],
        "right": [
            ["", "wrksp mv1", "wrksp mv2", "wrksp mv3", "wrksp mv4"],
            ["", "wrksp go1", "wrksp go2", "wrksp go3", "wrksp go4"],
            ["", "wrksp go&lt;", "wrksp go&gt;", " wrksp mv&lt;", "wrksp mv&gt;"],
        ],
        "thumbs": {"left": [held("NAV"), ""], "right": ["", held("SYM")],},
    },
]

KEYSPACE_W = KEY_W + 2 * INNER_PAD_W
KEYSPACE_H = KEY_H + 2 * INNER_PAD_H
HAND_W = 5 * KEYSPACE_W
HAND_H = 4 * KEYSPACE_H
LAYER_W = 2 * HAND_W + OUTER_PAD_W
LAYER_H = HAND_H
BOARD_W = LAYER_W + 2 * OUTER_PAD_W


def print_key(x, y, key):
    key_class = ""
    if type(key) is dict:
        key_class = key["class"]
        key = key["key"]
    print(
        f'<rect rx="{KEY_RX}" ry="{KEY_RY}" x="{x + INNER_PAD_W}" y="{y + INNER_PAD_H}" width="{KEY_W}" height="{KEY_H}" class="{key_class}" />'
    )
    words = key.split()
    y += (KEYSPACE_H - (len(words) - 1) * LINE_SPACING) / 2
    for word in key.split():
        print(
            f'<text text-anchor="middle" dominant-baseline="middle" x="{x + KEYSPACE_W / 2}" y="{y}">{word}</text>'
        )
        y += LINE_SPACING


def print_row(x, y, row):
    for key in row:
        print_key(x, y, key)
        x += KEYSPACE_W


def print_block(x, y, block):
    for row in block:
        print_row(x, y, row)
        y += KEYSPACE_H


def print_layer(x, y, layer, full):
    if "optional" in layer and not full:
        return
    print_block(x, y, layer["left"])
    print_block(
        x + HAND_W + OUTER_PAD_W, y, layer["right"],
    )
    print_row(
        x + 3 * KEYSPACE_W, y + 3 * KEYSPACE_H, layer["thumbs"]["left"],
    )
    print_row(
        x + HAND_W + OUTER_PAD_W, y + 3 * KEYSPACE_H, layer["thumbs"]["right"],
    )


def print_board(x, y, keymap, full):
    x += OUTER_PAD_W
    for layer in keymap:
        y += OUTER_PAD_H
        print_layer(x, y, layer, full)
        y += LAYER_H


def print_svg(keymap, full):
    N_LAYER = len(keymap) if full else sum(not "optional" in layer for layer in keymap)
    BOARD_H = N_LAYER * (LAYER_H + OUTER_PAD_H) + OUTER_PAD_H
    print(
        f'<svg width="{BOARD_W}" height="{BOARD_H}" viewBox="0 0 {BOARD_W} {BOARD_H}" xmlns="http://www.w3.org/2000/svg">'
    )
    print(f"<style>{STYLE_FULL if full else ''}{STYLE}</style>")
    print_board(0, 0, keymap, full)
    print("</svg>")


def main():
    with open("keymap.svg", "w") as file:
        with redirect_stdout(file):
            print_svg(KEYMAP, False)

    with open("keymap_full.svg", "w") as file:
        with redirect_stdout(file):
            print_svg(KEYMAP, True)


if __name__ == "__main__":
    main()
