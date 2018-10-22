#include QMK_KEYBOARD_H

// Helpful defines
#define _______ KC_TRNS


enum custom_keycodes {
    MACRO_ENT_L_DEF = SAFE_RANGE, // enter macro and return to layer 0
    TD_RCTL_LOCK = 0 // tap dance macro
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case MACRO_ENT_L_DEF:
                SEND_STRING(SS_TAP(X_ENTER));
                layer_off(1);
                layer_on(0);
                return false;

        }
    }
    return true;
 };


qk_tap_dance_action_t tap_dance_actions[] = {

    // right control if held or tap once, lock macOS if double tap */
    [TD_RCTL_LOCK] = ACTION_TAP_DANCE_DOUBLE(KC_RCTL, LCTL(LCMD(KC_Q)))

};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // default QWERTY layer
    [0] = LAYOUT_60_ansi_split_bs_rshift(KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_J,
                                         KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
                                         KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_NO, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
                                         KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, LT(2, KC_MPLY),
                                         KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_RGUI, TO(1), KC_RALT, TD(TD_RCTL_LOCK)),

    // navigation layer
    [1] = LAYOUT_60_ansi_split_bs_rshift(TO(0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSPC, KC_DOWN,
                                         KC_NO, TO(0), KC_NO, KC_HOME, KC_PGUP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                         KC_NO, KC_NO, KC_NO, KC_NO, KC_END, KC_PGDN, KC_NO, KC_LEFT, KC_NO, KC_UP, KC_RGHT, KC_NO, KC_NO, MACRO_ENT_L_DEF,
                                         KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                         KC_NO, KC_NO, KC_NO, KC_SPC, KC_NO, TO(0), KC_NO, KC_NO),

    // system control layer
    [2] = LAYOUT_60_ansi_split_bs_rshift(KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, KC_NO,
                                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_MNXT, KC_NO,
                                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, BL_BRTG, KC_NO,
                                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, BL_DEC, BL_INC, BL_TOGG, KC_NO, KC_NO,
                                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};
