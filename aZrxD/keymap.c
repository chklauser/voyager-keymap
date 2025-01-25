#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

bool process_snakebab_word(uint16_t keycode, keyrecord_t *record);

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_38_255_255,
  HSV_0_0_255,
  HSV_169_255_255,
  SNAKE,
  KEBAB,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    CW_TOGG,        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    KC_ESCAPE,      MT(MOD_LGUI, KC_A),MT(MOD_LALT, KC_S),MT(MOD_LCTL, KC_D),MT(MOD_LSFT, KC_F),MEH_T(KC_G),                                    MEH_T(KC_H),    MT(MOD_RSFT, KC_J),MT(MOD_RCTL, KC_K),MT(MOD_LALT, KC_L),MT(MOD_LGUI, KC_SCLN),KC_QUOTE,
    SNAKE,          KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KEBAB,
                                                    LT(3,KC_ENTER), KC_TAB,                                         KC_BSPC,        LT(4,KC_SPACE)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, LT(4,KC_F13)
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, LT(4,KC_MINUS)
  ),
  [3] = LAYOUT_voyager(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_SLASH,       KC_7,           KC_8,           KC_9,           KC_MINUS,       KC_F12,         
    KC_TRANSPARENT, KC_GRAVE,       KC_LBRC,        KC_LCBR,        KC_LPRN,        KC_AMPR,                                        KC_ASTR,        KC_4,           KC_5,           KC_6,           KC_EQUAL,       KC_DQUO,        
    KC_NO,          KC_UNDS,        KC_RBRC,        KC_RCBR,        KC_RPRN,        KC_CIRC,                                        KC_PLUS,        KC_1,           KC_2,           KC_3,           KC_DOT,         KC_ENTER,       
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_DELETE,      KC_0
  ),
  [4] = LAYOUT_voyager(
    RGB_MODE_FORWARD,KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    TOGGLE_LAYER_COLOR,KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  KC_TRANSPARENT,                                 KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         KC_MS_BTN5,     KC_F12,         
    RGB_TOG,        KC_LEFT_GUI,    KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_LEFT_SHIFT,  RGB_SLD,                                        KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_MS_BTN4,     KC_F2,          
    KC_NO,          RGB_VAD,        RGB_VAI,        HSV_38_255_255, HSV_0_0_255,    HSV_169_255_255,                                KC_BSPC,        LALT(KC_1),     KC_INSERT,      LALT(KC_F1),    KC_DELETE,      LSFT(KC_F2),    
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_voyager(
    KC_GRAVE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TAB,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_TRANSPARENT, 
    KC_LEFT_SHIFT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_SHIFT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_SPACE
  ),
};

const uint16_t PROGMEM combo0[] = { KC_7, KC_8, COMBO_END};
const uint16_t PROGMEM combo1[] = { MT(MOD_RSFT, KC_J), MT(MOD_RCTL, KC_K), COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_MINUS, KC_BSLS, KC_QUOTE, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_RIGHT_ALT),
    COMBO(combo1, KC_RIGHT_ALT),
    COMBO(combo2, TG(5)),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LGUI, KC_A):
            return TAPPING_TERM + 50;
        case MT(MOD_LSFT, KC_F):
            return TAPPING_TERM -50;
        case MT(MOD_RSFT, KC_J):
            return TAPPING_TERM -50;
        case MT(MOD_LGUI, KC_SCLN):
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [1] = { {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186}, {96,198,186} },

    [2] = { {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104}, {24,159,104} },

    [3] = { {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219}, {139,238,219} },

    [4] = { {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245} },

    [5] = { {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191}, {215,113,191} },

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
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_38_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(38,255,255);
      }
      return false;
    case HSV_0_0_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,0,255);
      }
      return false;
    case HSV_169_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(169,255,255);
      }
      return false;
    // CUSTOMIZATIONS
      case LT(4,KC_F13):
        if(record->tap.count){
            if(record->event.pressed){
              SEND_STRING("_");
            }
            return false;
        }
    default:
      if (!process_snakebab_word(keycode, record)) {
        return false;
      }
    // END CUSTOMIZATIONS
  }
  return true;
}




bool get_combo_must_tap(uint16_t combo_index, combo_t* combo) {
    switch (combo_index) {
        case 1:
            // Return true to indicate that this combo must be pure taps
                return true;
        default:
            return false;
    }
}

static uint16_t snakebab_timer;

#define SNAKE_LAYER 1
#define KEBAB_LAYER 2
bool process_snakebab_word(uint16_t keycode, keyrecord_t *record) {
    // From here on, we only take action on press events.
    if (!record->event.pressed) {
        return true;
    }

    snakebab_timer = timer_read();
    if(keycode == SNAKE){
        layer_invert(SNAKE_LAYER);
        layer_off(KEBAB_LAYER);
        return false;
    }
    if(keycode == KEBAB){
        layer_invert(KEBAB_LAYER);
        layer_off(SNAKE_LAYER);
        return false;
    }

    if(keycode == CW_TOGG) {
      return true;
    }

    const uint8_t mods = get_mods() | get_oneshot_mods();
    if (!(mods & ~(MOD_MASK_SHIFT | MOD_BIT(KC_RALT)))) {
        if(
            keycode == MT(MOD_LGUI, KC_A)
            || keycode == MT(MOD_LALT, KC_S)
            || keycode == MT(MOD_LCTL, KC_D)
            || keycode == MT(MOD_LSFT, KC_F)
            || keycode == MT(MOD_RSFT, KC_J)
            || keycode == MT(MOD_RCTL, KC_K)
            || keycode == MT(MOD_LALT, KC_L)
              || keycode == LT(4,KC_MINUS)
              || keycode == LT(4,KC_F13)
          || keycode == ALL_T(KC_G)
          || keycode == ALL_T(KC_H)
          ){
          return true;
        }

        switch (keycode) {
            // Ignore MO, TO, TG, TT, and OSL layer switch keys.
            case QK_MOMENTARY ... QK_MOMENTARY_MAX:
            case QK_TO ... QK_TO_MAX:
            case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
            case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
            case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
            case QK_TRI_LAYER_LOWER ... QK_TRI_LAYER_UPPER:
            // Ignore AltGr.
            case KC_RALT:
            case OSM(MOD_RALT):
                return true;
            // Keycodes that continue snakebab Word
            case KC_A ... KC_Z:
            case KC_MINS:
            case KC_1 ... KC_0:
            case KC_BSPC:
            case KC_DEL:
            case KC_UNDS:
                return true;
            default:
                layer_off(SNAKE_LAYER);
                layer_off(KEBAB_LAYER);
                return true;
        }
    } else {
        layer_off(SNAKE_LAYER);
        layer_off(KEBAB_LAYER);
        return true;
    }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case SNAKE:
  		case KEBAB:
            return true;
        default:
            return false;  // Deactivate Caps Word.
    }
}

void matrix_scan_user() {
    if (timer_elapsed(snakebab_timer) > CAPS_WORD_IDLE_TIMEOUT) {
        layer_off(SNAKE_LAYER);
        layer_off(KEBAB_LAYER);
    }
}
