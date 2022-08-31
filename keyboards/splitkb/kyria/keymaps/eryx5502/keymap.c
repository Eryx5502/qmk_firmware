/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include "keymap_spanish.h"

enum layers {
    _QWERTY = 0,
    _LOL,
    _NUM,
    _SYM,
    _NAV,
    _SNAP,
    _ADJUST,
};

enum custom_keycodes {
    APPS = SAFE_RANGE,
};

// Aliases for readability
#define QWERTY DF(_QWERTY)
#define LOL DF(_LOL)

#define SYM MO(_SYM)
#define NAV MO(_NAV)
#define NUM MO(_NUM)
#define SNAP MO(_SNAP)
#define ADJUST MO(_ADJUST)

#define SFT_BSPC MT(MOD_LSFT, KC_BSPC)
#define SFT_ENT MT(MOD_LSFT, KC_ENT)

#define CLOSE LALT(KC_F4)
#define RUNNER LALT(KC_SPC)
// #define APPS RALT(KC_TAB)
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define SEARCH LCTL(KC_F)
#define C_RGHT LCTL(KC_RGHT)
#define C_LEFT LCTL(KC_LEFT)

// Note: LAlt/Enter (SFT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                             ,---------------------------------------.
 * |  Esc  |   Q  |   W  |   E  |   R  |   T  |                             |   Y  |   U  |   I  |   O  |   P  |  Bs |
 * |-------+------+------+------+------+------|                             |------+------+------+------+------+-----|
 * |  Tab  |   A  |S/ALT |D/WIN |F/CTRL|   G  |                             |   H  |J/CTRL|K/WIN |L/ALT |   Ñ  |  ´  |
 * |-------+------+------+------+------+------+------------.  ,-------------+------+------+------+------+------+-----|
 * | Runner|   Z  |   X  |   C  |   V  |   B  |     |      |  |      |      |   N  |   M  | ,  < | . >  | /  ? | LOL |
 * `---------------------+------+------+------| SPC | ENTR |  | RSFT | SPC  +------+------+------+-------------------'
 *                       | DESKS|  NAV |  NUM |     |  /   |  |      |      |  SYM | SNAP |  Vol |
 *                       | ENC1 |      |      |     | SFT  |  |      |      |      |      | ENC2 |
 *                       `---------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
     KC_ESC, KC_Q ,    KC_W   ,    KC_E   ,    KC_R   ,   KC_T ,                                          KC_Y ,    KC_U   ,    KC_I   ,     KC_O  ,  KC_P , KC_BSPC,
     KC_TAB, KC_A ,ALT_T(KC_S),GUI_T(KC_D),CTL_T(KC_F),   KC_G ,                                          KC_H ,CTL_T(KC_J),GUI_T(KC_K),ALT_T(KC_L),ES_NTIL, ES_ACUT,
     RUNNER, KC_Z ,    KC_X   ,    KC_C   ,   KC_V    ,   KC_B , XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_N ,    KC_M   ,   KC_COMM  ,   KC_DOT  ,ES_MINS,   LOL  ,
                                   APPS   ,   NAV     ,   NUM  ,  KC_SPC, SFT_ENT,     KC_RSFT,  KC_SPC, SYM  ,    SNAP   ,   KC_MUTE
    ),

/*
 * Base Layer: LoL
 *
 * ,-------------------------------------------.                              ,---------------------------------------.
 * |  Esc  |   1  |   2  |   3  |   4  |   P  |                              |      |      |      |      |      |     |
 * |-------+------+------+------+------+------|                              |------+------+------+------+------+-----|
 * |  Tab  |   Q  |   W  |   E  |   R  |   T  |                              |      |      |      |      |      |     |
 * |-------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+-----|
 * |   Z   |   A  |   S  |   D  |   F  |   B  |      |      |  |      |      |      |      |      |      |      |ALPHA|
 * `---------------------+------+------+------|      | ENTR |  | RSFT | SPC  +------+------+------+-------------------'
 *                       |  Vol | LALT | LCTL | SPC  |  /   |  |      |      |  SYM | LGUI | APPS |
 *                       | ENC1 |      |      |      | SFT  |  |      |      |      |      | ENC2 |
 *                       `----------------------------------'  `----------------------------------'
 */
    [_LOL] = LAYOUT(
     KC_ESC , KC_1 ,  KC_2   ,  KC_3  ,   KC_4 ,   KC_P ,                                           KC_Y ,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
     KC_TAB , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                           KC_H ,   KC_J ,  KC_K ,   KC_L ,ES_NTIL, ES_ACUT,
      KC_Z  , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_B , XXXXXXX  , XXXXXXX,     XXXXXXX, XXXXXXX, KC_N ,   KC_M ,KC_COMM, KC_DOT ,ES_MINS,  QWERTY,
                               KC_MUTE, KC_LALT, KC_LCTL,  KC_SPC  , SFT_ENT,     KC_RSFT,  KC_SPC, SYM  , KC_LGUI,  APPS
    ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    º   |  ·   |  "   |  €   |  $   |  %   |                              |   &  |  {   |  }   |   #  |  /   |   \    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  @   |  '   |  <   |  >   |  ^   |                              |   =  |  (   |  )   |   !  |  ?   |   ~    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  ¬   |   -  |  +   |  *   |  `   |      |      |  |      |      |   |  |  [   |  ]   |  ¡   |  ¿   |   ¨    |
 * `----------------------+------+------+------+------|------|  |------|------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
      KC_GRV , ES_BULT, ES_DQUO, ES_EURO,  ES_DLR, ES_PERC,                                     ES_AMPR, ES_LCBR, ES_RCBR, ES_HASH, ES_SLSH, ES_BSLS,
      _______,   ES_AT, ES_QUOT, ES_LABK, ES_RABK, ES_CIRC,                                      ES_EQL, ES_LPRN, ES_RPRN, ES_EXLM, ES_QUES, ES_TILD,
      _______,  ES_NOT, ES_MINS, ES_PLUS, ES_ASTR,  ES_GRV, _______, _______, _______, _______, ES_PIPE, ES_LBRC, ES_RBRC, ES_IEXL, ES_IQUE, ES_DIAE,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, CLOSE
    ),

/*
 * Function Layer: NUM keys
 *
 * ,-------------------------------------------.                              ,--------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |      |                              |   /  |  7  |  8  |  9  |  -  |       |
 * |--------+------+------+------+------+------|                              |------+-----+-----+-----+-----+-------|
 * |        |  F5  |F6/ALT|F7/WIN|F8/CTR|      |                              |   *  |4/ALT|5/WIN|6/CTR|  +  |   ,   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+-----+-----+-----+-----+-------|
 * |        |  F9  |  F10 |  F11 |  F12 |      |      |      |  |      |      |   =  |  1  |  2  |  3  |  .  | ENTER |
 * `----------------------+------+------+------+------|------|  |------|------+------+-----+-----+-------------------'
 *                        |      |      |      |      |      |  |      |      |   0  |     |     |
 *                        |      |      |      |      |      |  |      |      |      |     |     |
 *                        `----------------------------------'  `--------------------------------'
 */
    [_NUM] = LAYOUT(
      _______,  KC_F1 ,    KC_F2   ,    KC_F3   ,    KC_F4   , _______,                                     ES_SLSH,    ES_7   ,     ES_8  ,     ES_9  , ES_MINS, _______,
      _______,  KC_F5 ,ALT_T(KC_F6),WIN_T(KC_F7),CTL_T(KC_F8), _______,                                     ES_ASTR,ALT_T(ES_4),WIN_T(ES_5),CTL_T(ES_6), ES_PLUS, ES_COMM,
      _______,  KC_F9 ,    KC_F10  ,    KC_F11  ,    KC_F12  , _______, _______, _______, _______, _______,  ES_EQL,    ES_1   ,     ES_2  ,     ES_3  ,  ES_DOT, KC_PENT,
                                         _______,     _______, _______, _______, _______, _______, _______,    ES_0,    _______,    _______
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      | IMPR |      |                              |  C_← | PgDn | PgUp |  C_→  | INICIO| DEL  |
 * |--------+------+------+------+------+------|                              |------+------+------+-------+-------+------|
 * | ADJUST |      | LALT | LWIN | LCTL |      |                              |  ←   |   ↓  |   ↑  |   →   |  FIN  | INS  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+-------+-------+------|
 * |        |      |  CUT | COPY | PASTE|SEARCH|      |      |  |      |      |      |      |      |       |       |      |
 * `----------------------+------+------+------+------|------|  |------|------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      | Music|
 *                        |      |      |      |      |      |  |      |      |      |      | ENC2 |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, KC_PSCR, _______,                                      C_LEFT, KC_PGDN, KC_PGUP,  C_RGHT, KC_HOME,  KC_DEL,
       ADJUST, _______, KC_LALT, KC_LGUI, KC_LCTL, _______,                                     KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_END,  KC_INS,
      _______, _______,   CUT  ,   COPY ,  PASTE ,  SEARCH, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY
    ),

/*
 * Snap layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | Exp ←|Exp ↓ |Exp ↑ |Exp → |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |Conf 1|Conf 2|Conf 3|Conf 4|      |                              |  ←   |   ↓  |   ↑  |   →  | Conf.|        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+      |      |  |      |      +------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SNAP] = LAYOUT(
      _______,   _______,   _______,   _______,   _______,   _______,                                        LCAG(KC_LEFT),LCAG(KC_DOWN),LCAG(KC_UP),LCAG(KC_RGHT),     _______, _______,
      _______,LCAG(KC_0),LCAG(KC_1),LCAG(KC_2),LCAG(KC_3),LCAG(KC_4),                                           G(KC_LEFT),   G(KC_DOWN),   G(KC_UP),   G(KC_RGHT),LSG(ES_NTIL), _______,
      _______,   G(KC_1),   G(KC_2),   G(KC_3),   G(KC_4),   G(KC_5), _______, _______,     _______, _______,      _______,      _______,     _______,      _______,     _______, _______,
                                       _______,   _______,   _______, _______, _______,     _______, _______,      _______,      _______,     KC_MPLY
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |QWERTY|      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------|------|  |------+------|------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                    _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______, QWERTY , _______,                                    RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
      _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+      |      |  |      |      +------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

bool is_alt_tab_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case APPS:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
          tap_code(KC_TAB);
        } else {
          is_alt_tab_active = false;
          unregister_code(KC_LALT);
        }
      }
      break;
  }
  return true;
}

void tab_encoder(bool clockwise) {
  if (clockwise) {
    tap_code(KC_TAB);
  } else {
    tap_code16(S(KC_TAB));
  }
}

void change_desk_encoder(bool clockwise) {
  if (clockwise) {
    tap_code16(LCTL(LGUI(KC_RGHT)));
  } else {
    tap_code16(LCTL(LGUI(KC_LEFT)));
  }
}

void volume_encoder(bool clockwise) {
  if (clockwise) {
    tap_code(KC_VOLU);
  } else {
    tap_code(KC_VOLD);
  }
}

void music_encoder(bool clockwise) {
  if (clockwise) {
    tap_code(KC_MNXT);
  } else {
    tap_code(KC_MPRV);
  }
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  switch (get_highest_layer(layer_state|default_layer_state)) {
    case _QWERTY:
      if (index == 0) {
        if (is_alt_tab_active) {
          tab_encoder(clockwise);
        } else {
          change_desk_encoder(clockwise);
        }
      } else if (index == 1) {
          volume_encoder(clockwise);
      }
      break;
    case _LOL:
      if (index == 0) {
        volume_encoder(clockwise);
      } else if (index == 1) {
        tab_encoder(clockwise);
      }
      break;
    case _NAV:
    case _SNAP:
      if (index == 0) {
        register_code(KC_LCTL);
        tab_encoder(clockwise);
        unregister_code(KC_LCTL);
      } else if (index == 1) {
        music_encoder(clockwise);
      }
      break;
  }
  return false;
}
#endif

/* DELETE THIS LINE TO UNCOMMENT (1/2)
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _DVORAK:
                oled_write_P(PSTR("Dvorak\n"), false);
                break;
            case _COLEMAK_DH:KC_MUTE
                oled_write_P(PSTR("Colemak-DH\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Sym\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}
#endif
DELETE THIS LINE TO UNCOMMENT (2/2) */
