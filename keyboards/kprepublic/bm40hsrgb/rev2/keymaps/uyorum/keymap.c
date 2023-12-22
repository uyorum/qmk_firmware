/* Copyright 2020 tominabox1
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
#include "keymap_japanese.h"

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |  Tab |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   @  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   :  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |   _  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Esc |  GUI |  Alt | Bksp/| F19/ |    Space    | F20/ |Enter/|   -  |   ^  |   \  |
 * |      |      |      | Ctrl | Lower|             | Raise| Shift|      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12_1x2uC(
    KC_TAB,  KC_Q,    KC_W,    KC_E,            KC_R,               KC_T,    KC_Y,               KC_U,           KC_I,    KC_O,    KC_P,    JP_AT,
    KC_LCTL, KC_A,    KC_S,    KC_D,            KC_F,               KC_G,    KC_H,               KC_J,           KC_K,    KC_L,    KC_SCLN, JP_COLN,
    KC_LSFT, KC_Z,    KC_X,    KC_C,            KC_V,               KC_B,    KC_N,               KC_M,           KC_COMM, KC_DOT,  KC_SLSH, JP_BSLS,
    KC_ESC,  KC_LGUI, KC_LALT, LCTL_T(KC_BSPC), LT(_LOWER, KC_F19), KC_SPC,  LT(_RAISE, KC_F20), RSFT_T(KC_ENT), KC_MINS, JP_CIRC, JP_YEN
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | 半/全 |   !  |   "  |   #  |   $  |   %  |   &  |   '  |   =  |   ~  |   |  |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |   [  |   {  |   (  |   )  |   }  |   ]  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |A+PScr| Pg Up|  Up  | Pg Dn|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | XXXX |             |      | PrtSc| Left | Down | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12_1x2uC(
    JP_ZKHK, KC_EXLM, JP_DQUO, KC_HASH, KC_DLR,  KC_PERC, JP_AMPR, JP_QUOT,       JP_EQL,  JP_TILD, JP_PIPE, KC_DEL,
    _______, _______, _______, JP_LBRC, JP_LCBR, JP_LPRN, JP_RPRN, JP_RCBR,       JP_RBRC, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, LALT(KC_PSCR), _______, KC_PGUP, KC_UP,   KC_PGDN,
    _______, _______, _______, _______, _______, _______, _______, KC_PSCR,       KC_LEFT, KC_DOWN, KC_RGHT
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | 半/全 |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |   [  |   {  |   (  |   )  |   }  |   ]  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F11 |  F12 |      |      |             | XXXX | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12_1x2uC(
    JP_ZKHK, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    _______, _______, _______, JP_LBRC, JP_LCBR, JP_LPRN, JP_RPRN, JP_RCBR, JP_RBRC, _______, _______, _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
    _______, KC_F11,  KC_F12,  _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12_1x2uC(
    _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
