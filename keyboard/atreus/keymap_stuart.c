#include "keymap_common.h"

/* This layout implements dvorak fully in the firmware. It will work
   on machines where the OS is set to use QWERTY, but not if the OS is
   already set for dvorak. For that use case, see keymap_multidvorak.c. */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: mostly letters */
  KEYMAP(KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y,  KC_F, KC_G, KC_C, KC_R, KC_L, \
         KC_A, KC_O, KC_E, KC_U, KC_I,          KC_D, KC_H, KC_T, KC_N, KC_S, \
         KC_SCLN, KC_Q, KC_J, KC_K, KC_X,       KC_B, KC_M, KC_W, KC_V, KC_Z, \
         KC_ESC, KC_TAB, KC_LGUI, KC_LSFT, KC_BSPC, KC_LALT, KC_LCTL, KC_SPC, KC_FN0, KC_MINS, KC_SLSH, KC_ENT),
  /* 1: punctuation and numbers */
  KEYMAP(KC_1, KC_2, KC_3, KC_4, KC_5,            KC_6, KC_7, KC_8, KC_9, KC_0, \
         KC_EQUAL, KC_NO, KC_DOT, KC_NO, KC_HOME, KC_PGUP, KC_NO, KC_UP, KC_LBRACKET, KC_RBRACKET, \
         KC_GRAVE, KC_NO, KC_NO, KC_NO, KC_END,   KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_BSLASH, \
         KC_FN1, KC_TAB, KC_LGUI, KC_LSFT, KC_DEL, KC_LALT, KC_LCTL, KC_SPC, KC_FN0, KC_MINS, KC_SLSH, KC_ENTER),
  /* 2: function keys */
  KEYMAP(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,   KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, \
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_F11, \
         KC_NO, KC_NO, KC_NO, KC_NO, KC_FN3,  KC_NO, KC_NO, KC_NO, KC_NO, KC_F12, \
         KC_FN2, KC_TAB, KC_LGUI, KC_LSFT, KC_BSPC, KC_LALT, KC_LCTL, KC_SPC, KC_FN2, KC_NO, KC_NO, KC_ENTER)
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
  [1] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [2] = ACTION_LAYER_OFF(2, 1),  // switch back to layer 0
  [3] = ACTION_FUNCTION(BOOTLOADER)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
