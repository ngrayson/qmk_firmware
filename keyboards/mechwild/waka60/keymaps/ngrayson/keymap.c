/* Copyright 2021 Kyle McCreery
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _MAIN,
    _RAISE,
    _LOWER,
};


// Readability keycodes
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)

#define ES_TSK LT(0,KC_1)
#define DOT_PR LT(0,KC_2)
#define COM_PR LT(0,KC_3)
#define TABL LT(0,KC_F1)
#define TABR LT(0,KC_F2)
#define TABCLOSE LT(0,KC_F3)
#define PLS_MIN LT(0,KC_F4)
#define RE_CACHE LT(0,KC_F5)
#define QUIT LT(0,KC_6)
#define MEN_AST LT(0,KC_TAB)
#define FOC_1 LT(0,KC_A)
#define FOC_2 LT(0,KC_S)
#define FOC_3 LT(0,KC_D)
#define FOC_4 LT(0,KC_F)
#define AUD_5 LT(0,KC_H) // 6 on tap, toggle audio source on hold
#define DRK_BANG LT(0,KC_Z)
#define VIS_HASH LT(0,KC_C)
#define TAB_RES LT(0,KC_ESC)
#define KVMONE LT(0,KC_LGUI)
#define KVMTWO LT(0,KC_RGUI)



#define VDLEFT LGUI(LCTL(KC_LEFT))
#define VDRIGHT LGUI(LCTL(KC_RIGHT))
#define SNAPUP LGUI(KC_UP)
#define SNAPLEFT LGUI(KC_LEFT)
#define SNAPDOWN LGUI(KC_DOWN)
#define SNAPRIGHT LGUI(KC_RIGHT)
#define LOCK LGUI(KC_L)
#define MAXIMIZE HYPR(KC_M)
#define AUDIOSRC MEH(KC_G)
#define PIK_WIN LCA(KC_TAB)
#define VDTVIEW LGUI(KC_TAB)
#define SH_TAB LSFT_T(KC_TAB)
#define SH_SLS RSFT_T(KC_SLSH)
#define ZOOMIN RCTL_T(KC_PLUS)
#define ZOOMOUT RCTL_T(KC_MINUS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_MAIN] = LAYOUT(
    ES_TSK,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_ENT,
    SH_TAB,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_MUTE,  KC_N,    KC_M,    COM_PR,  DOT_PR,  KC_UP,   SH_SLS,
    KC_LCTL, KC_LALT, RAISE,   MO(1),   KC_SPC,  KC_SPC, KC_SPC,   KC_SPC,  KC_SPC,  MO(1),   KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_RAISE] = LAYOUT(
    TAB_RES, TABL  ,  TABCLOSE,TABR,     QUIT,    RE_CACHE,         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
    KC_TRNS, VDLEFT,  SNAPUP,  VDRIGHT,  KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT,
    LOWER,   SNAPLEFT,MAXIMIZE,SNAPRIGHT,DRK_BANG,AUD_5,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    PIK_WIN, VDTVIEW, SNAPDOWN,LOCK,     VIS_HASH,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_PGUP, KC_BSLASH,
    KVMONE,  KVMTWO,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END
    ),
    [_LOWER] = LAYOUT(
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
    KC_TRNS, AU_TOG,  RGB_TOG, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, MU_TOG,  RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, MU_MOD,  RGB_RMOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KVMONE:
          if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_TAP(X_SCROLLLOCK) "1" SS_TAP(X_ENTER));
          } else{
          }
          return false;
        case KVMTWO:
          if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_TAP(X_SCROLLLOCK) "2" SS_TAP(X_ENTER));
          } else{
          }
          return false;
        case ES_TSK:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_ESC); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(LCTL(LSFT(KC_ESC))); // Intercept hold function to send Ctrl-V
          }
          return false;
        case DOT_PR:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_DOT); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(KC_RPRN); // Intercept hold function to send Ctrl-V
          }
          return false;
        case COM_PR:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_COMM); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(KC_LPRN); // Intercept hold function to send Ctrl-V
          }
          return false;
        case PLS_MIN:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_EQL); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(KC_MINS); // Intercept hold function to send Ctrl-V
          }
          return false;
        case TAB_RES:
          if (record->tap.count && record->event.pressed) {
              tap_code16(RCTL(RSFT(KC_T))); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(KC_F); // Intercept hold function to send Ctrl-V
          }
          return false;
        case TABL:
          if (record->tap.count && record->event.pressed) {
              tap_code16(RCTL(RSFT(KC_TAB))); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(KC_F1); // Intercept hold function to send Ctrl-V
          }
          return false;
        case TABR:
          if (record->tap.count && record->event.pressed) {
              tap_code16(RCTL(KC_TAB)); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(KC_F2); // Intercept hold function to send Ctrl-V
          }
          return false;
        case TABCLOSE:
          if (record->tap.count && record->event.pressed) {
            tap_code16(RCTL(KC_W)); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(KC_F3); // Intercept hold function to send Ctrl-V
          }
          return false;
        case RE_CACHE:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_F5); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(RCTL(KC_F5)); // Intercept hold function to send Ctrl-V
          }
          return false;
        case QUIT:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_F4); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(RALT(KC_F4)); // Intercept hold function to send Ctrl-V
          }
          return false;
        case MEN_AST:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_ASTR); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(LGUI(KC_X)); // Intercept hold function to send Ctrl-V
          }
          return false;
        case FOC_1:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_1); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(LGUI(KC_1)); // Intercept hold function to send Ctrl-V
          }
          return false;
        case FOC_2:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_2); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(LGUI(KC_2)); // Intercept hold function to send Ctrl-V
          }
          return false;
        case FOC_3:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_3); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(LGUI(KC_3)); // Intercept hold function to send Ctrl-V
          }
          return false;
        case FOC_4:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_4); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(LGUI(KC_4)); // Intercept hold function to send Ctrl-V
          }
          return false;
        case AUD_5:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_5); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(AUDIOSRC); // Intercept hold function to send Ctrl-V
          }
          return false;
        case DRK_BANG:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_EXLM); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(LSFT(LALT(KC_F))); // Intercept hold function to send Ctrl-V
          }
          return false;
        case VIS_HASH:
          if (record->tap.count && record->event.pressed) {
              tap_code16(KC_HASH); // Intercept tap function to send Ctrl-C
          } else if (record->event.pressed) {
              tap_code16(LGUI(LALT(KC_V))); // Intercept hold function to send Ctrl-V
          }
          return false;
    }
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (get_highest_layer(layer_state|default_layer_state) > 0) {
        if (index == 0) { //first encoder
            if (clockwise) {
                tap_code_delay(KC_VOLU, 5);
            } else {
                tap_code_delay(KC_VOLD, 5);
            }
        }
    } else {  /* Layer 0 */
        if (index == 0) { //first encoder
            if (clockwise) {
                tap_code16(LCTL(KC_PLUS));
            } else {
                tap_code16(LCTL(KC_MINUS));
            }
        }
    }
    return false;
}
