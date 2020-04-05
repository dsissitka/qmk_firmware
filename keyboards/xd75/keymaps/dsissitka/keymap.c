#include "xd75.h"

LEADER_EXTERNS();

enum xd75_keycodes {
    DEFAULT = SAFE_RANGE,
    GAMING
};

enum xd75_layers {
    _DEFAULT,
    _GAMING,
    _NAV,
    _SYMBOL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = {
        { _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_MPRV,  KC_MPLY, KC_MNXT,     KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    _______ },
        { KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   _______,  _______, _______,     KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC },
        { KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   _______,  _______, _______,     KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT  },
        { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   _______,  _______, _______,     KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT },
        { KC_LEAD, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, KC_SPC, MO(_NAV), GAMING,  MO(_SYMBOL), KC_SPC, KC_RGUI, KC_RSFT, KC_RCTL, KC_RALT, KC_LEAD }
    },

    [_GAMING] = {
        { _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______ },
        { _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______ },
        { _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______ },
        { _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______ },
        { _______, _______, _______, _______, _______, _______, KC_LCTRL, DEFAULT, _______, _______, _______, _______, _______, _______, _______ }
    },

    [_NAV] = {
        { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,  RESET,   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  _______ },
        { _______, KC_F11,  KC_F12,  _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,  _______, _______ },
        { _______, _______, _______, _______, _______, _______, _______,  _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_DEL,  _______ },
        { _______, _______, _______, _______, _______, _______, _______,  _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_INS,  _______ },
        { _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,  _______, _______ }
    },

    [_SYMBOL] = {
        { _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______ },
        { _______, KC_HASH, KC_GRV,  KC_LBRC, KC_AMPR, _______, _______,  _______, _______, _______, KC_DLR,  KC_RBRC, KC_PLUS, KC_TILD, _______ },
        { _______, KC_UNDS, KC_LCBR, KC_QUOT, KC_LPRN, _______, _______,  _______, _______, _______, KC_RPRN, KC_EQL,  KC_RCBR, KC_ASTR, _______ },
        { _______, KC_PIPE, KC_PERC, KC_BSLS, KC_MINS, _______, _______,  _______, _______, _______, KC_DQT,  KC_AT,   KC_CIRC, KC_EXLM, _______ },
        { _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______ }
    }
};

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // (S)creenshot -> (D)esktop
        SEQ_TWO_KEYS(KC_S, KC_D) {
            // Print Screen
            tap_code(KC_PSCREEN);
        }

        // (S)creenshot -> (D)esktop -> Save it in a (f)ile.
        SEQ_THREE_KEYS(KC_S, KC_D, KC_F) {
            // Windows + Print Screen
            register_code(KC_LWIN);
            tap_code(KC_PSCREEN);
            unregister_code(KC_LWIN);
        }

        // (S)creenshot -> (S)election
        SEQ_TWO_KEYS(KC_S, KC_S) {
            // Windows + Shift + S
            register_code(KC_LWIN);
            register_code(KC_LSHIFT);
            tap_code(KC_S);
            unregister_code(KC_LSHIFT);
            unregister_code(KC_LWIN);
        }

        // (S)creenshot -> (W)indow
        SEQ_TWO_KEYS(KC_S, KC_W) {
            // Alt + Print Screen
            register_code(KC_LALT);
            tap_code(KC_PSCREEN);
            unregister_code(KC_LALT);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DEFAULT:
            if (record->event.pressed) {
                layer_off(_GAMING);
                rgblight_disable_noeeprom();
            }

            return false;

        case GAMING:
            if (record->event.pressed) {
                layer_on(_GAMING);
                rgblight_enable_noeeprom();
            }

            return false;

        default:
            return true;
    }
}
