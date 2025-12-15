#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  HSV_169_255_255,
  ST_MACRO_0,
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    CW_TOGG,        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    KC_ESCAPE,      KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_QUOTE,       
    KC_F18,         KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       LALT(LSFT(KC_INSERT)),
                                                    KC_NO,          KC_TAB,                                         KC_BSPC,        KC_NO
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_SLASH,       KC_7,           KC_8,           KC_9,           KC_MINUS,       KC_F12,         
    KC_TRANSPARENT, KC_GRAVE,       KC_LBRC,        KC_LCBR,        KC_LPRN,        KC_AMPR,                                        KC_ASTR,        KC_4,           KC_5,           KC_6,           KC_EQUAL,       ST_MACRO_0,     
    KC_NO,          KC_UNDS,        KC_RBRC,        KC_RCBR,        KC_RPRN,        KC_CIRC,                                        KC_PLUS,        KC_1,           KC_2,           KC_3,           KC_DOT,         KC_ENTER,       
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_DELETE,      KC_0
  ),
  [2] = LAYOUT_voyager(
    RGB_MODE_FORWARD,KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    TOGGLE_LAYER_COLOR,KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  RGB_SLD,                                        KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         KC_MS_BTN5,     KC_F12,         
    RGB_TOG,        KC_LEFT_GUI,    KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_LEFT_SHIFT,  KC_TRANSPARENT,                                 KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_MS_BTN4,     KC_F2,          
    KC_NO,          RGB_VAD,        RGB_VAI,        KC_TRANSPARENT, KC_TRANSPARENT, HSV_169_255_255,                                KC_F16,         LALT(KC_1),     KC_INSERT,      LALT(KC_F1),    KC_F17,         LSFT(KC_F2),    
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_GRAVE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TAB,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_TRANSPARENT, 
    KC_LEFT_SHIFT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_SHIFT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_SPACE
  ),
};


const uint16_t PROGMEM combo0[] = { KC_BSLS, KC_QUOTE, KC_F11, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, TG(3)),
};



extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [1] = { {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219} },

    [2] = { {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245} },

    [3] = { {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
    switch (biton32(layer_state)) {
      case 1:
        set_layer_color(1);
        break;
      case 2:
        set_layer_color(2);
        break;
      case 3:
        set_layer_color(3);
        break;
     default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}





bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX: 
    // Mouse keys with modifiers work inconsistently across operating systems, this makes sure that modifiers are always
    // applied to the mouse key that was pressed.
    if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
    if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_EQUAL)SS_DELAY(100)  SS_LSFT(SS_TAP(X_DOT)));
    }
    break;

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_169_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(169,255,255);
      }
      return false;
  }
  return true;
}
