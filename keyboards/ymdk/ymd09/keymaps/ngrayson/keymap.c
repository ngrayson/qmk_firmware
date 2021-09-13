#include QMK_KEYBOARD_H

enum custom_keycodes {
  KVM_ONE,
  KVM_TWO,
  KVM_THREE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(KC_KP_7, KC_UP, KC_KP_9,
               KC_LEFT, KC_DOWN, KC_RIGHT,
               KVM_ONE, KVM_TWO, KVM_THREE),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KVM_ONE:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_TAP(X_SCROLLLOCK) "1");
      } else{
      }
      return false;
      break;
    case KVM_TWO:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_TAP(X_SCROLLLOCK) "2");
      } else{
      }
      return false;
      break;
    case KVM_THREE:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_TAP(X_SCROLLLOCK) "3");
      } else{
      }
      return false;
      break;
    }
  return true;
}

