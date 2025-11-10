#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  CKC_BEGIN = ML_SAFE_RANGE, // no longer required since sm_td 5.0
  CKC_JK,
  RGB_SLD,
  HSV_169_255_255,
  ST_MACRO_0,
};
#include "sm_td.h" // must be included exactly after custom_keycodes

#define SMTD_LTcw(virt_kc, tap_kc, layer_idx) case virt_kc: { \
  switch (action) { \
    case SMTD_ACTION_TOUCH: \
      break; \
    case SMTD_ACTION_TAP: \
      caps_word_off(); \
      tap_code16(tap_kc); \
    break; \
    case SMTD_ACTION_HOLD: \
      if (tap_count < 1) { \
        LAYER_PUSH(layer_idx); \
      } else { \
        register_code16(tap_kc); \
      } \
    break; \
    case SMTD_ACTION_RELEASE: \
      if (tap_count < 1) { \
        LAYER_RESTORE(); \
      } \
      unregister_code16(tap_kc); \
    break; \
  } \
  break; }

#define MOD_BIT_MEH MOD_BIT(KC_LEFT_SHIFT) | MOD_BIT(KC_LEFT_ALT) | MOD_BIT(KC_LEFT_CTRL)
smtd_resolution on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
  switch(keycode){
    SMTD_MT(KC_A, KC_LEFT_GUI, 1)
    SMTD_MT(KC_S, KC_LEFT_ALT, 1)
    SMTD_MT(KC_D, KC_LEFT_CTRL, 1)
    SMTD_MT(KC_F, KC_LEFT_SHIFT, 1)
    SMTD_MT(KC_G, MOD_BIT_MEH, 1)
    SMTD_MT(KC_H, MOD_BIT_MEH, 1)
    SMTD_MT(KC_J, KC_RIGHT_SHIFT, 1)
    SMTD_MT(KC_K, KC_RIGHT_CTRL, 1)
    SMTD_MT(KC_L, KC_LEFT_ALT, 1)
    SMTD_MT(KC_SCLN, KC_LEFT_GUI, 1)
    SMTD_LTcw(KC_ENTER, 1)
    SMTD_LTcw(KC_SPACE, 2)
    case CKC_JK:
      switch(action){
        case SMTD_ACTION_TAP:
          tap_code16(KC_RIGHT_ALT);
          break;
        case SMTD_ACTION_TOUCH:
        case SMTD_ACTION_HOLD:
        case SMTD_ACTION_RELEASE:
          // don't do anything
          break;
      }
      return;
  }
  return SMTD_RESOLUTION_UNHANDLED;
}

uint32_t get_smtd_timeout(uint16_t keycode, smtd_timeout timeout) {
  uint32_t default_timeout = get_smtd_timeout_default(timeout);
  uint32_t really_dangerous_extend = 150;
  uint32_t dangerous_extend = 50;
  switch (keycode) {
    case KC_L:
    case KC_S:
      switch(timeout) {
        case SMTD_TIMEOUT_TAP:
          return default_timeout + really_dangerous_extend;
        case SMTD_TIMEOUT_RELEASE:
          return default_timeout - (really_dangerous_extend >> 3);
        default:
          break;
      }

    case KC_SCLN:
    case KC_A:
      switch(timeout) {
        case SMTD_TIMEOUT_TAP:
          return default_timeout + dangerous_extend;
        case SMTD_TIMEOUT_RELEASE:
          return default_timeout - (dangerous_extend >> 3);
        default:
          break;
      }
  }

  return default_timeout;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LALT_T(KC_S):
        case LALT_T(KC_L):
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}

#ifdef qmk_alt
#define CH_S LALT_T(KC_S)
#define CH_L LALT_T(KC_L)
#else
#define CH_S KC_S
#define CH_L KC_L
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    CW_TOGG,        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    KC_ESCAPE,      KC_A,           CH_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           CH_L,           KC_SCLN,        KC_QUOTE,
    OSL(1),         KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       LSA(KC_INSERT),
                                                    KC_RET,         KC_TAB,                                         KC_BSPC,        KC_SPC
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
    RGB_TOG,        KC_LEFT_GUI,    KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_LEFT_SHIFT,  KC_MEH,                                         KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_MS_BTN4,     KC_F2,          
    KC_NO,          RGB_VAD,        RGB_VAI,        KC_TRANSPARENT, KC_TRANSPARENT, HSV_169_255_255,                                KC_BSPC,        LALT(KC_1),     KC_INSERT,      LALT(KC_F1),    KC_DELETE,      LSFT(KC_F2),    
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
const uint16_t PROGMEM combo_ui[] = { KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_jk[] = { KC_J, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO_ACTION(combo0),
    COMBO_ACTION(combo_ui),
    COMBO_ACTION(combo_jk),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case 0:
      if (pressed) {
        layer_invert(3);
      }
      break;
    case 1:
      if (pressed) {
        tap_code16(KC_RIGHT_ALT);
      }
      break;
    case 2:
      keyrecord_t record = {.event = MAKE_KEYEVENT(0, 0, pressed)};
      process_smtd(CKC_JK, &record);
      break;
  }
}

bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
  return true;
}

extern rgb_config_t rgb_matrix_config;

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
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
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
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_smtd(keycode, record)) {
    return false;
  }

  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_EQUAL) SS_DELAY(100) SS_LSFT(SS_TAP(X_DOT)));
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



