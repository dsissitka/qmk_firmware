#include QMK_KEYBOARD_H

enum layer_names {
    _NORMAL,
    _GAMING,
    _SYMBOL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_NORMAL] = LAYOUT_ortho_5x15(
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_MPRV,     KC_MPLY,     KC_MNXT,     KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   XXXXXXX,     KC_PSCR,     XXXXXXX,     KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   XXXXXXX,     XXXXXXX,     XXXXXXX,     KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   XXXXXXX,     XXXXXXX,     XXXXXXX,     KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        XXXXXXX, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, KC_SPC, MO(_SYMBOL), TG(_GAMING), MO(_SYMBOL), KC_SPC, KC_RGUI, KC_RSFT, KC_RCTL, KC_RALT, XXXXXXX
    ),

    [_GAMING] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_LCTL, TG(_GAMING), _______, _______, _______, _______, _______, _______, _______
    ),

    [_SYMBOL] = LAYOUT_ortho_5x15(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  QK_BOOT,
        _______, KC_F11,  KC_F12,  KC_MINS, KC_PLUS, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_DEL,
        _______, KC_QUOT, KC_DQT,  KC_TILD, KC_EQL,  _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PIPE, _______,
        _______, _______, _______, KC_GRV,  KC_UNDS, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BSLS, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
     if (IS_LAYER_ON_STATE(state, _GAMING)) {
        rgblight_enable_noeeprom();
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_sethsv_noeeprom(HSV_RED);
     } else {
        rgblight_disable_noeeprom();
     }

     return state;
}
