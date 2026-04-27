#include QMK_KEYBOARD_H

enum layers {
  BASE,
  LOWER,
  RAISE,
  ADJUST,
};

/*
 * BASE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc |  Q |  W |  E |  R |  T |                    |  Y |  U |  I |  O |  P | Bsp |
 * | Tab |CtlA|AltS|GuiD|SftF|  G |                    |  H |SftJ|GuiK|AltL|Ctl;|  '  |
 * | F13 |  Z |  X |  C |  V |  B |                    |  N |  M |  , |  . |  / |     |
 * `--------------------------'                    `---------------------------'
 *                  | Gui | Lower | Spc |        | Ent | Raise | Alt |
 *                  `--------------------'        `-------------------'
 *
 * LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `  |  1 |  2 |  3 |  4 |  5 |                    |  6 |  7 |  8 |  9 |  0 |  -  |
 * |     |  - |  = |  [ |  ] |  5 |                    |    |    |  + |  * |    |     |
 * |     |    |    |    |    |    |                    |    |    |  [ |  ] |  = |     |
 * `--------------------------'                    `---------------------------'
 *                  | Gui |      | Spc |        | Ent |Adjust| Alt |
 *                  `--------------------'        `-------------------'
 *
 * RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Tab |  ! |  @ |  # |  $ |  % |                    |  ^ |    | Up |    |  ) | Bsp |
 * | Ctl |  - |  = |  [ |  ] |  % |                    |    | Lft| Dn | Rgt|  \ |  `  |
 * |     |    |    |    |    |    |                    |    |    |    |    |  | |  ~  |
 * `--------------------------'                    `---------------------------'
 *                  | Gui |Adjust| Spc |        | Ent |      | Alt |
 *                  `--------------------'        `-------------------'
 *
 * Notes:
 * - Shift+Lower on the top row yields ~ ! @ # $ % ^ & * ( ) _
 * - Lower+, and Lower+. yield [ and ], with Shift+Lower on those keys yielding { and }
 * - Raise+I/J/K/L yields Up/Left/Down/Right
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
    KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T,                                      KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    KC_TAB, MT(MOD_LCTL, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LGUI, KC_D), MT(MOD_LSFT, KC_F), KC_G,
                                                                            KC_H, MT(MOD_RSFT, KC_J), MT(MOD_RGUI, KC_K), MT(MOD_RALT, KC_L), MT(MOD_RCTL, KC_SCLN), KC_QUOT,
    KC_F13, KC_Z, KC_X, KC_C, KC_V, KC_B,                                      KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
                               KC_LGUI, MO(LOWER), KC_SPC,             KC_ENT, MO(RAISE), KC_RALT
  ),

  [LOWER] = LAYOUT_split_3x6_3(
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,                                      KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
    KC_TRNS, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_5,                          KC_TRNS, KC_TRNS, KC_PLUS, KC_ASTR, KC_TRNS, KC_NO,
    KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                        KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_EQL, KC_TRNS,
                                 KC_LGUI, KC_TRNS, KC_SPC,             KC_ENT, MO(ADJUST), KC_RALT
  ),

  [RAISE] = LAYOUT_split_3x6_3(
    KC_TAB, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                          KC_CIRC, KC_TRNS, KC_UP, KC_TRNS, KC_RPRN, KC_BSPC,
    KC_LCTL, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_PERC,                       KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSLS, KC_GRV,
    KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PIPE, KC_TILD,
                                 KC_LGUI, MO(ADJUST), KC_SPC,          KC_ENT, KC_TRNS, KC_RALT
  ),

  [ADJUST] = LAYOUT_split_3x6_3(
    KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSPC,
    QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                 KC_LGUI, KC_TRNS, KC_SPC,             KC_ENT, KC_TRNS, KC_RALT
  )
};
