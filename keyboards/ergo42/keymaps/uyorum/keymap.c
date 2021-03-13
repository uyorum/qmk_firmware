#include QMK_KEYBOARD_H
#include "keymap_jp.h"
#include "secret.h"

#define BASE 0
#define META1 1
#define META2 2
#define META3 3
#define TENKEY 4

enum custom_keycodes {
    ZEROZERO = SAFE_RANGE,
    PASS1,
    PASS2,
    PASS3,
    PASS4,
    PASS5,
    PASS6,
    PASS7,
    PASS8,
    ALT_TAB,
};

// Alt Tab
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

// Definitions of Macro
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case ZEROZERO:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_P0) SS_TAP(X_P0));
      }
      break;
    case PASS1:
      if (record->event.pressed) {
        SEND_STRING(PASSWORD1);
      }
      break;
    case PASS2:
      if (record->event.pressed) {
        SEND_STRING(PASSWORD2);
      }
      break;
    case PASS3:
      if (record->event.pressed) {
        SEND_STRING(PASSWORD3);
      }
      break;
    case PASS4:
      if (record->event.pressed) {
        SEND_STRING(PASSWORD4);
      }
      break;
    case PASS5:
      if (record->event.pressed) {
        SEND_STRING(PASSWORD5);
      }
      break;
    case PASS6:
      if (record->event.pressed) {
        SEND_STRING(PASSWORD6);
      }
      break;
    case PASS7:
      if (record->event.pressed) {
        SEND_STRING(PASSWORD7);
      }
      break;
    case PASS8:
      if (record->event.pressed) {
        SEND_STRING(PASSWORD8);
      }
      break;
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*  Base
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | ESC  | Tab  |   Q  |   W  |   E  |   R  |  T   |   |  Y   |   U  |   I  |   O  |   P  |   @  | Bksp |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | 半/全| LCtrl|   A  |   S  |   D  |   F  |  G   |   |  H   |   J  |   K  |   L  |   ;  |   :  | Enter|
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Meta3| LSft |   Z  |   X  |   C  |   V  |  B   |   |  N   |   M  |   ,  |   .  |   /  |   _  |  UP  |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |TenKey| LGUI |AltTab| LAlt |   \  |CtlSpc| Meta1|   | Meta2|SftSpc|   -  |   ^  | LEFT | RIGHT| DOWN |
   * `------------------------------------------------'   `------------------------------------------------'
   */

	[BASE] = LAYOUT( \
		KC_ESC,     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,          KC_T,              KC_Y,              KC_U,           KC_I,    KC_O,   KC_P,    KC_LBRC, KC_BSPC, \
		KC_GRV,     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,          KC_G,              KC_H,              KC_J,           KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT, \
		MO(META3),  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,          KC_B,              KC_N,              KC_M,           KC_COMM, KC_DOT, KC_SLSH, KC_RO,   KC_UP, \
		TG(TENKEY), KC_LGUI, ALT_TAB, KC_LALT, KC_JYEN, CTL_T(KC_SPC), LT(META1, KC_F19), LT(META2, KC_F20), RSFT_T(KC_SPC), KC_MINS, KC_EQL, KC_LEFT, KC_RGHT, KC_DOWN \
		),

  /* Meta 1
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  (   |   |  )   |  F6  |  F7  |  F8  |  F9  | F10  |  Del |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * |      | F11  | F12  | F13  | F14  | F15  |  [   |   |  ]   |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |  {   |   |  }   |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      |      | LCtrl| Meta1|   |      |      |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  
  [META1] = LAYOUT( \
	  KC_NO, KC_F1,  KC_F2,   KC_F3,  KC_F4,  KC_F5,   LSFT(KC_8), LSFT(KC_9), KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_DEL, \
		KC_NO, KC_F11, KC_F12,  KC_F13, KC_F14, KC_F15,  KC_RBRC,    KC_NUHS,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, \
		KC_NO, KC_NO,  KC_NO,   KC_NO,  KC_NO,  KC_NO,   KC_NO,      KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, \
		KC_NO, KC_NO,  KC_NO,   KC_NO,  KC_NO,  KC_LCTL, KC_TRNS,    KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO \
	  ),

  /* Meta 2
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |      |   1  |   2  |   3  |   4  |   5  |  (   |   |  )   |   6  |   7  |   8  |   9  |   0  |A PSCR|
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * |      |   !  |   "  |   #  |   $  |   %  |  [   |   |  ]   |   &  |   '  |   (  |   )  |      | PSCR |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |  {   |   |  }   |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      |      | LCtrl|      |   | Meta2|      |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */

	[META2] = LAYOUT( \
	  KC_NO, KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       LSFT(KC_8),    LSFT(KC_9),    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,  LALT(KC_PSCR), \
		KC_NO, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), KC_RBRC,       KC_NUHS,       LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), KC_NO, KC_PSCR, \
		KC_NO, KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      LSFT(KC_RBRC), LSFT(KC_NUHS), KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO, KC_NO, \
		KC_NO, KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_LCTL,    KC_NO,         KC_TRNS,       KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO, KC_NO \
		),

  /* Meta 3
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | Base | VOL+ | Prev | Play | Next |      |      |   | Pass1| Pass5|      |      |      |      | Sleep|
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * |      | VOL- |      |      |      |      |      |   | Pass2| Pass6|      |      |      |      |      |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Meta2| Mute |      |      |      |      |      |   | Pass3| Pass7|      |      |      |      |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   | Pass4| Pass8|      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */

	[META3] = LAYOUT( \
	  TO(0),   KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO, KC_NO, PASS1, PASS5, KC_NO, KC_NO, KC_NO, KC_NO, KC_SLEP, \
		KC_NO,   KC_VOLD, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, PASS2, PASS6, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
		KC_TRNS, KC_MUTE, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, PASS3, PASS7, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
		KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, PASS4, PASS8, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO \
		),

  /* Ten key
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | Base |      |      |      |      |      |      |   |      |   7  |   8  |   9  |   -  |   /  | Bksp |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | 半/全|      |      |      |      |      |      |   |      |   4  |   5  |   6  |   +  |   *  | Enter|
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      |   1  |   2  |   3  |   ,  |      |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |TenKey|      |      |      |      |      |      |   |      |   0  |  00  |   .  |   =  |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */

	[TENKEY] = LAYOUT( \
	  TO(0),   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P7, KC_P8,    KC_P9,   KC_PMNS, KC_PSLS, KC_BSPC, \
		KC_GRV,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P4, KC_P5,    KC_P6,   KC_PPLS, KC_PAST, KC_ENT, \
		KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P1, KC_P2,    KC_P3,   KC_PCMM, KC_NO,   KC_NO, \
		KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P0, ZEROZERO, KC_PDOT, KC_PEQL, KC_NO,   KC_NO \
		)
};

