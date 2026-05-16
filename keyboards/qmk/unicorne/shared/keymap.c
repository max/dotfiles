#include QMK_KEYBOARD_H
#include "raw_hid.h"
#include "transactions.h"

#include <string.h>

enum layers {
  BASE,
  LOWER,
  RAISE,
  ADJUST,
};

enum oled_protocol {
  OLED_MAGIC_0 = 'U',
  OLED_MAGIC_1 = 'O',
  OLED_PROTO_VERSION = 1,
  OLED_RAW_REPORT_SIZE = 32,
  OLED_CMD_FRAME = 1,
  OLED_CMD_CLEAR = 2,
  OLED_CMD_STOCK = 3,
  OLED_PACKET_PAYLOAD_SIZE = 24,
};

static uint8_t host_oled_frame[OLED_MATRIX_SIZE];
static bool host_oled_enabled = false;
static bool host_oled_dirty = false;

static bool should_render_host_oled(void) {
  return !is_keyboard_left();
}

static void process_oled_packet(const uint8_t *data, uint8_t length) {
  if (length != OLED_RAW_REPORT_SIZE || data[0] != OLED_MAGIC_0 || data[1] != OLED_MAGIC_1 || data[2] != OLED_PROTO_VERSION) {
    return;
  }

  const uint8_t command = data[3];

  if (command == OLED_CMD_CLEAR) {
    memset(host_oled_frame, 0, sizeof(host_oled_frame));
    host_oled_enabled = true;
    host_oled_dirty = true;
    return;
  }

  if (command == OLED_CMD_STOCK) {
    host_oled_enabled = false;
    host_oled_dirty = true;
    return;
  }

  if (command != OLED_CMD_FRAME) {
    return;
  }

  const uint16_t offset = (uint16_t)data[4] | ((uint16_t)data[5] << 8);
  uint8_t size = data[6];

  if (offset >= sizeof(host_oled_frame)) {
    return;
  }

  if (size > OLED_PACKET_PAYLOAD_SIZE) {
    size = OLED_PACKET_PAYLOAD_SIZE;
  }

  if (offset + size > sizeof(host_oled_frame)) {
    size = sizeof(host_oled_frame) - offset;
  }

  memcpy(&host_oled_frame[offset], &data[8], size);
  host_oled_enabled = true;
  host_oled_dirty = true;
}

/*
 * BASE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc |  Q |  W |  E |  R |  T |                    |  Y |  U |  I |  O |  P | Bsp |
 * | Tab |CtlA|AltS|GuiD|SftF|  G |                    |  H |SftJ|GuiK|AltL|Ctl;|  '  |
 * | F13 |  Z |  X |  C |  V |  B |                    |  N |  M |  , |  . |  / |     |
 * `--------------------------'                    `---------------------------'
 *                  |     | Lower | Spc |        | Ent | Raise |     |
 *                  `--------------------'        `-------------------'
 *
 * LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `  |  1 |  2 |  3 |  4 |  5 |                    |  6 |  7 |  8 |  9 |  0 |  -  |
 * |     |  ! |  @ |  # |  $ |  % |                    |  ^ |  & |  * |  ( |  ) |  \  |
 * |     |    |    |    |    |    |                    |    |  [ |  ] |  { |  } |  =  |
 * `--------------------------'                    `---------------------------'
 *                  |     |      | Spc |        | Ent |Adjust|     |
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
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
    KC_ESC,          KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,                                      KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,               KC_BSPC,
    KC_TAB,          MT(MOD_LCTL, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LGUI, KC_D), MT(MOD_LSFT, KC_F), KC_G,                                  KC_H,              MT(MOD_RSFT, KC_J), MT(MOD_RGUI, KC_K), MT(MOD_RALT, KC_L), MT(MOD_RCTL, KC_SCLN), KC_QUOT,
    KC_F13,          KC_Z,              KC_X,              KC_C,              KC_V,              KC_B,                                      KC_N,              KC_M,              KC_COMM,           KC_DOT,            KC_SLSH,            KC_NO,
                                                            KC_NO,             MO(LOWER),         KC_SPC,                                    KC_ENT,            MO(RAISE),         KC_NO
  ),

  [LOWER] = LAYOUT_split_3x6_3(
    KC_GRV,          KC_1,              KC_2,              KC_3,              KC_4,              KC_5,                                      KC_6,              KC_7,              KC_8,              KC_9,              KC_0,               KC_MINS,
    KC_NO,           KC_EXLM,           KC_AT,             KC_HASH,           KC_DLR,            KC_PERC,                                   KC_CIRC,           KC_AMPR,           KC_ASTR,           KC_LPRN,           KC_RPRN,            KC_BSLS,
    KC_NO,           KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,                                     KC_NO,             KC_LBRC,           KC_RBRC,           KC_LCBR,           KC_RCBR,            KC_EQL,
                                                            KC_NO,             KC_NO,             KC_SPC,                                    KC_ENT,            MO(ADJUST),        KC_NO
  ),

  [RAISE] = LAYOUT_split_3x6_3(
    KC_TAB,          KC_EXLM,           KC_AT,             KC_HASH,           KC_DLR,            KC_PERC,                                   KC_CIRC,           KC_TRNS,           KC_UP,             KC_TRNS,           KC_RPRN,            KC_BSPC,
    KC_LCTL,         KC_MINS,           KC_EQL,            KC_LBRC,           KC_RBRC,           KC_PERC,                                   KC_TRNS,           KC_LEFT,           KC_DOWN,           KC_RGHT,           KC_BSLS,            KC_GRV,
    KC_NO,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,                                   KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_PIPE,            KC_TILD,
                                                            KC_LGUI,           MO(ADJUST),        KC_SPC,                                    KC_ENT,            KC_TRNS,           KC_RALT
  ),

  [ADJUST] = LAYOUT_split_3x6_3(
    QK_BOOT,         KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,                                     KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,              KC_NO,
    KC_NO,           KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,                                     KC_MRWD,           KC_VOLD,           KC_VOLU,           KC_MFFD,           KC_NO,              KC_NO,
    KC_NO,           KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,                                     KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,              KC_NO,
                                                            KC_NO,             KC_NO,             KC_SPC,                                    KC_ENT,            KC_NO,             KC_NO
  )
};

void raw_hid_receive(uint8_t *data, uint8_t length) {
  if (should_render_host_oled()) {
    process_oled_packet(data, length);
  }

  if (is_keyboard_master()) {
    transaction_rpc_send(UNICORNE_OLED_SYNC, length, data);
  }
}

void unicorne_oled_sync_slave_handler(uint8_t in_buflen, const void *in_data, uint8_t out_buflen, void *out_data) {
  if (should_render_host_oled()) {
    process_oled_packet((const uint8_t *)in_data, in_buflen);
  }
}

void keyboard_post_init_user(void) {
  transaction_register_rpc(UNICORNE_OLED_SYNC, unicorne_oled_sync_slave_handler);
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
  if (should_render_host_oled() && host_oled_enabled) {
    oled_write_raw((const char *)host_oled_frame, sizeof(host_oled_frame));
    if (host_oled_dirty) {
      oled_render_dirty(true);
      host_oled_dirty = false;
    }
    return false;
  }

  return true;
}
#endif
