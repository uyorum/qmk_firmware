#include QMK_KEYBOARD_H

#define BASE 0
#define EMACS 1
#define META1 2
#define TENKEY 3
#define META2 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*  Base
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | ESC  | Tab  |   Q  |   W  |   E  |   R  |  T   |   |  Y   |   U  |   I  |   O  |   P  |   @  | Bksp |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | 半/全| LCtrl|   A  |   S  |   D  |   F  |  G   |   |  H   |   J  |   K  |   L  |   ;  |   :  | Enter|
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Meta2| LSft |   Z  |   X  |   C  |   V  |  B   |   |  N   |   M  |   ,  |   .  |   /  |   _  |  UP  |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |TenKey| LGUI | LAlt |   \  | LCtrl|Space |Emacs |   | Meta1| RSft |   -  |   ^  | LEFT | RIGHT| DOWN |
   * `------------------------------------------------'   `------------------------------------------------'
   */

	[BASE] = LAYOUT( \
		KC_ESC,       KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,      KC_Y,      KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC, KC_BSPC, \
		KC_GRV,       KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,      KC_H,      KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT, \
		MO(META2), KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,      KC_N,      KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RO,   KC_UP, \
		TG(TENKEY),    KC_LGUI, KC_LALT, KC_JYEN, KC_LCTL, KC_SPC, MO(EMACS), MO(META1), KC_RSFT, KC_MINS, KC_EQL, KC_LEFT, KC_RGHT, KC_DOWN \
		),

  [EMACS] = LAYOUT( \
	  KC_NO, KC_NO, KC_NO,   KC_CUT,  KC_END, KC_NO,   KC_NO,   KC_PSTE, KC_NO,  KC_TAB, KC_NO, KC_UP,   KC_NO,  KC_DEL, \
		KC_NO, KC_NO, KC_HOME, KC_FIND, KC_DEL, KC_RGHT, KC_ESC,  KC_BSPC, KC_ENT, KC_NO,  KC_NO, KC_NO,   KC_NO,  KC_NO, \
		KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,  KC_PGDN, KC_LEFT, KC_DOWN, KC_ENT, KC_NO,  KC_NO, KC_UNDO, KC_NO,  KC_NO, \
		KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_TRNS, KC_KANA, KC_NO,  KC_NO,  KC_NO, KC_NO,   KC_NO,  KC_NO \
	  ),

  /* Meta 1
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |      |   1  |   2  |   3  |   4  |   5  |  (   |   |  )   |   6  |   7  |   8  |   9  |   0  |A PSCR|
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * |      |   !  |   "  |   #  |   $  |   %  |  [   |   |  ]   |   &  |   '  |   ( |    )  |      | PSCR |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  {   |   |  }   |  F6  |  F7  |  F8  |  F9  | F10  |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |  F11 |  F12 |      | LCtrl|      | Kata |   | Meta1|      |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */

	[META1] = LAYOUT( \
	  KC_NO, KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       LSFT(KC_8),    LSFT(KC_9),    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,   LALT(KC_PSCR), \
		KC_NO, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), KC_RBRC,       KC_NUHS,       LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), KC_NO,  KC_PSCR, \
		KC_NO, KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      LSFT(KC_RBRC), LSFT(KC_NUHS), KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10, KC_NO, \
		KC_NO, KC_F11,     KC_F12,     KC_NO,      KC_LCTL,    KC_NO,      LSFT(KC_KANA),       KC_TRNS,       KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,  KC_NO \
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
	  TO(0),   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P7, KC_P8, KC_P9,   KC_PMNS, KC_PSLS, KC_BSPC, \
		KC_GRV,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P4, KC_P5, KC_P6,   KC_PPLS, KC_PAST, KC_ENT, \
		KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P1, KC_P2, KC_P3,   KC_PCMM, KC_NO,   KC_NO, \
		KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P0, 00,    KC_PDOT, KC_PEQL, KC_NO,   KC_NO \
		),

  /* Meta 2
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | Base | VOL+ | Prev | Play | Next |      |      |   |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * |      | VOL- |      |      |      |      |      |   |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Meta2| Mute |      |      |      |      |      |   |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      |      |      |   .  |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */

	[META2] = LAYOUT( \
	  TO(0),   KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
		KC_NO,   KC_VOLD, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
		KC_TRNS, KC_MUTE, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
		KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO \
		)
};

