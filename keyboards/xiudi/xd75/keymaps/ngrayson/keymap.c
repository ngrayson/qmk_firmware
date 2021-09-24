/* Copyright 2017 Wunder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Layer shorthand
#define _QW 0
#define _FN 1
// shorthand for keystrokes
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))
#define OSHIFT OSM(MOD_LSFT)
#define OCTL OSM(MOD_LCTL)
#define OWIN OSM(MOD_LGUI)
#define OALT OSM(MOD_LALT)
#define VDLEFT LGUI(LCTL(KC_LEFT))
#define VDRIGHT LGUI(LCTL(KC_RIGHT))
#define SNAPUP LGUI(KC_UP) 
#define SNAPLEFT LGUI(KC_LEFT)
#define SNAPDOWN LGUI(KC_DOWN)
#define SNAPRIGHT LGUI(KC_RIGHT)
#define ALTF4 LALT(KC_F4)
#define REFRESH LCTL(KC_F5)
#define LOCK LGUI(KC_L)
#define MAXIMIZE HYPR(KC_M)
#define AUDIOSRC MEH(KC_G)

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  KVMONE,
  KVMTWO,
  KVMTHREE,
  KVMFOUR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


 [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KVMONE,  KVMTWO,  KVMTHREE,KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_DEL,  KVMFOUR, KC_MINS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,  \
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC, KC_PGUP, KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_HOME, KC_PGDN, KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH, \
    KC_LCTL, KC_LGUI, KC_SPC,  KC_LALT, MO(_FN), KC_SPC,  KC_PAUS, KC_INS,  KC_BSPC, KC_ENT,  MO(_FN), KC_BSLS, KC_LEFT, KC_DOWN, KC_RGHT  \
 ),
 
 [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
    TSKMGR,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
    KC_MPRV, VDLEFT,  SNAPUP,  VDRIGHT, RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_WH_U, KC_MS_BTN1,KC_MS_U,KC_MS_BTN2,_______,_______, \
    KC_VOLD, SNAPLEFT,MAXIMIZE,SNAPRIGHT,RGB_VAD,RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, \
    _______, _______,SNAPDOWN, _______, RGB_RMOD,RGB_MOD, KC_P0,   RESET,   KC_PDOT, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, RGB_TOG, RESET,   _______, _______, _______, _______, _______, _______, _______  \
 ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KVMONE:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_TAP(X_SCROLLLOCK) "1");
      } else{
      }
      return false;
      break;
    case KVMTWO:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_TAP(X_SCROLLLOCK) "2");
      } else{
      }
      return false;
      break;
    case KVMTHREE:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_TAP(X_SCROLLLOCK) "3");
      } else{
      }
      return false;
      break;
    case KVMFOUR:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_TAP(X_SCROLLLOCK) "4");
      } else{
      }
      return false;
      break;
    }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
