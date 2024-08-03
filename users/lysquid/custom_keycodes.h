#pragma once

#include QMK_KEYBOARD_H
#include "azerty_keycodes.h"


// Shortucts
#define KF_COPY             C(KF_C)
#define KF_CUT              C(KF_X)
#define KF_PASTE            C(KF_V)
#define KF_SELECT_ALL       C(KF_A)
#define KF_UNDO             C(KF_Z)
#define KF_REDO             C(KF_Y)
#define KF_SAVE             C(KF_S)
#define KF_CLOSE_TAB        C(KF_W)
#define KF_CLOSE_APP        A(KC_F4)
#define KF_TERM_COPY        S(KF_COPY)
#define KF_TERM_PASTE       S(KF_PASTE)

#define KF_PSTE KF_PASTE
#define KF_SLCT KF_SELECT_ALL
#define KF_CL_T KF_CLOSE_TAB
#define KF_CL_A KF_CLOSE_APP
#define KF_TCPY KF_TERM_COPY
#define KF_TPST KF_TERM_PASTE


// Zoom
#ifdef FRENCH
#define KF_ZOOM_IN          C(FR_EQL)
#else
#define KF_ZOOM_IN          C(KC_PLUS)
#endif
#define KF_ZOOM_OUT         C(KF_MINS)
#define KF_ZOOM_RESET       C(KF_0)
#define KF_KP_ZOOM_IN       C(KC_KP_PLUS)
#define KF_KP_ZOOM_OUT      C(KC_KP_MINUS)
#define KF_KP_ZOOM_RESET    C(KC_KP_0)

#define ZM_IN_1  KF_ZOOM_IN
#define ZM_OU_1 KF_ZOOM_OUT
#define ZM_RS_1 KF_ZOOM_RESET
#define ZM_IN_2  KF_KP_ZOOM_IN
#define ZM_OU_2 KF_KP_ZOOM_OUT
#define ZM_RS_2 KF_KP_ZOOM_RESET


// Browser
#define KF_WWW_NEXT         C(KC_PGDN)
#define KF_WWW_PREV         C(KC_PGUP)

#define KF_WNXT KF_WWW_NEXT
#define KF_WPRV KF_WWW_PREV


// Workspaces
#define KF_WKSP_GO_1        G(KC_F1)
#define KF_WKSP_GO_2        G(KC_F2)
#define KF_WKSP_GO_3        G(KC_F3)
#define KF_WKSP_GO_4        G(KC_F4)
#define KF_WKSP_GO_PREV     G(KC_PGUP)
#define KF_WKSP_GO_NEXT     G(KC_PGDN)
#define KF_WKSP_MOVE_1      SGUI(KC_F1)
#define KF_WKSP_MOVE_2      SGUI(KC_F2)
#define KF_WKSP_MOVE_3      SGUI(KC_F3)
#define KF_WKSP_MOVE_4      SGUI(KC_F4)
#define KF_WKSP_MOVE_PREV   SGUI(KC_PGUP)
#define KF_WKSP_MOVE_NEXT   SGUI(KC_PGDN)

#define WP_GO_1 KF_WKSP_GO_1
#define WP_GO_2 KF_WKSP_GO_2
#define WP_GO_3 KF_WKSP_GO_3
#define WP_GO_4 KF_WKSP_GO_4
#define WP_GO_P KF_WKSP_GO_PREV
#define WP_GO_N KF_WKSP_GO_NEXT
#define WP_MV_1 KF_WKSP_MOVE_1
#define WP_MV_2 KF_WKSP_MOVE_2
#define WP_MV_3 KF_WKSP_MOVE_3
#define WP_MV_4 KF_WKSP_MOVE_4
#define WP_MV_P KF_WKSP_MOVE_PREV
#define WP_MV_N KF_WKSP_MOVE_NEXT
