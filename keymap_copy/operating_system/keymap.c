#include QMK_KEYBOARD_H

#define _BASE 0
#define _FN1 1
#define _FN2 2
#define _FN3 3
#define _OSL1 4

enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  SCHEDULESTATUS,
  JIRAQUOTE,
  JIRACODE,
  SCREENSHOT,
  LOCALHOST,
  ALL_ENTITIES
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SCREENSHOT:
      if (record->event.pressed) { // Create a screenshot using windows 10 snipping tool
        register_code(KC_LGUI);
        register_code(KC_LSFT);
        tap_code(KC_S);
        clear_keyboard();
      }
      break;
    case QMKBEST:
      if (record->event.pressed) {
        SEND_STRING("QMK is the best thing ever!");
      }
      break;
    case SCHEDULESTATUS:
      if (record->event.pressed) {
        SEND_STRING("scheduleStatus:LIV");
      }
      break;
    case JIRAQUOTE:
      if (record->event.pressed) {
        SEND_STRING("{quote}\n\n{quote}"); // selects all and copies
      }
      break;
    case JIRACODE:
      if (record->event.pressed) {
        SEND_STRING("{code}\n\n{code}");
      }
      break;
    case LOCALHOST:
      if (record->event.pressed) {
        SEND_STRING("localhost:8079/");
      }
      break;
    case ALL_ENTITIES:
      if (record->event.pressed) {
        SEND_STRING("*:*");
      }
      break;
  }
  return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT( /* Qwerty */
    KC_ESC,            KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,    KC_BSPC,
    KC_TAB,            KC_A,     KC_S,    KC_D,    KC_F,    KC_G,     KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_UP,   RSFT_T(KC_SLSH),
    KC_LCTL,           MO(_FN3), KC_LALT,                   MO(_FN1), KC_SPC,           MO(_FN2), KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  [_FN1] = LAYOUT( /* Numbers and navigation */
    KC_TRANSPARENT, KC_LPRN,        KC_RPRN,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_7,          KC_8,          KC_9,           KC_0,           KC_TRANSPARENT, KC_TRANSPARENT,
    MO(_FN3),       KC_LBRC,        KC_RBRC,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_4,          KC_5,          KC_6,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LT,          KC_GT,          KC_COMM,        KC_TRANSPARENT, KC_QUOT,        KC_1,          KC_2,          KC_3,           KC_TRANSPARENT, KC_PGUP,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_P0,                                        KC_TRANSPARENT, KC_HOME,        KC_PGDN,        KC_END
  ),

  [_FN2] = LAYOUT( /* Symbols */
    KC_GRV,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_DEL,
    KC_TRANSPARENT, KC_TRANSPARENT, SCHEDULESTATUS, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MINS,        KC_EQL,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, OSL(_OSL1),     KC_TRANSPARENT, KC_BSLS,        KC_SLSH,        KC_TRANSPARENT, KC_EXLM,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_FN3] = LAYOUT( /* F keys */
    KC_LGUI,        JIRAQUOTE,      KC_LGUI,        KC_TRANSPARENT, RESET,          KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,
    KC_TRANSPARENT, KC_TRANSPARENT, SCHEDULESTATUS, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F4,          KC_F5,          KC_F6,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, SCREENSHOT,     JIRACODE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_MUTE,        KC_VOLU,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_VOLD,        KC_TRANSPARENT
  ),

  [_OSL1] = LAYOUT(
    TO(_BASE), KC_NO,        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO,
    KC_NO,     ALL_ENTITIES, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LOCALHOST, KC_NO, KC_NO,
    KC_NO,     KC_NO,        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO,
    KC_NO,     KC_NO,        KC_NO,               KC_NO, KC_NO,        KC_NO, KC_NO,     KC_NO, KC_NO
  )
};
