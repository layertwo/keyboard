#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

#define _BASE 0
#define _LMOD 1
#define _RMOD 2
#define _FMOD 3

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE] = LAYOUT( \
  KC_GESC,   KC_1,   KC_2,   KC_3,     KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,     KC_9,     KC_0,     KC_BSPC, \
  KC_TAB,    KC_Q,   KC_W,   KC_E,     KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_BSLS, \
  KC_CAPS,   KC_A,   KC_S,   KC_D,     KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT, \
  KC_LSFT,   KC_Z,   KC_X,   KC_C,     KC_V,    KC_B, LT(2,KC_LBRC), LT(1,KC_RBRC), KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, \
                             KC_LCTL,  KC_LALT, KC_LGUI, KC_SPC,            KC_ENT, KC_DEL,  KC_MINS, KC_EQL \
),
 [_LMOD] = LAYOUT( \
  KC_NO,     KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO, \
  KC_NO,     KC_NO,  KC_NO,  KC_HOME,  KC_PGUP, KC_NO,                              KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO, \
  KC_NO,     KC_NO,  KC_NO,  KC_END,   KC_PGDN, KC_NO,                              KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO, \
  KC_NO,     KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,        KC_NO,  KC_NO,        KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO, \
                             KC_NO,    KC_NO,   KC_NO,    KC_NO,           KC_NO,   KC_NO,   KC_NO,   KC_NO \
), //TODO m_ent
 [_RMOD] = LAYOUT( \
  KC_NO,     KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_NO, \
  KC_NO,     KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_MRWD,  KC_MFFD,  KC_MPLY,  KC_NO, \
  KC_NO,     KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,                              KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT,  KC_NO,    KC_NO, \
  KC_NO,     KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,        KC_NO,  KC_NO,        KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO, \
                             KC_NO,    KC_NO,   KC_NO,    KC_NO,           KC_NO,   KC_NO,   KC_NO,   KC_NO \
),
 [_FMOD] = LAYOUT( \
  KC_F1,     KC_F2,  KC_F3,  KC_F4,    KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,   KC_F12,
  KC_NO,     KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_NO,     KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,                              KC_NO,   KC_NO,   RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,
  KC_NO,     KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,        KC_NO,  KC_NO,        KC_NO,   KC_NO,   RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,
                             KC_NO,    KC_NO,   KC_NO,    KC_NO,           KC_NO,   KC_NO,   KC_NO,   KC_NO \
)
};

int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
void set_timelog(void);
 const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
     set_timelog();
#endif
  }

  return true;
}
