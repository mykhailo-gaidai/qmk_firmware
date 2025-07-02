#include QMK_KEYBOARD_H
#include "print.h"

#define BSC_NAV LT(1, KC_BSPC)
#define DEL_SYM LT(2, KC_DEL)
#define WRD_PRV A(KC_LEFT)
#define WRD_NXT A(KC_RGHT)
#define ALT_ENT A(KC_ENT)
#define MOD_CAG LCAG(KC_NO)
#define GO_BACK G(KC_LBRC)
#define GO_FWD G(KC_RBRC)
#define KC_LOCK G(C(KC_Q))
#define KC_RAYC LCAG(KC_E)
#define ZM_IN   G(KC_EQUAL)
#define ZM_OUT  G(KC_MINUS)
#define ZM_RST  G(KC_0)
#define RCT_GRV LCTL_T(KC_GRV)
#define SEL_INC A(KC_UP)
#define SEL_DEC A(KC_DOWN)


enum sym_keycodes {
    SS_GRV = SAFE_RANGE,
    SS_LT, SS_GT, SS_MINS, SS_PIPE, SS_CIRC, SS_LCBR, SS_RCBR, SS_DLR,
    SS_EXLM, SS_ASTR, SS_SLSH, SS_EQL, SS_AMPR, SS_HASH, SS_LPRN, SS_RPRN, SS_SCLN, SS_DQUO, 
    SS_TILD, SS_PLUS, SS_LBRC, SS_RBRC, SS_PERC, SS_AT, SS_COLN, SS_COMM, SS_DOT, SS_QUOT, SS_UNDS
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( // alphas
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC,
        RCT_GRV, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , MOD_CAG,   KC_HYPR, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                                            KC_LALT, KC_LGUI, KC_SPC ,   KC_ENT , BSC_NAV, DEL_SYM
    ),
    [1] = LAYOUT( // navigation
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,                     SEL_INC, KC_HOME, KC_UP  , KC_END , KC_PGUP, ZM_IN,
        _______, KC_F11 , KC_MUTE, KC_VOLD, KC_VOLU, KC_F12 ,                     SEL_DEC, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, ZM_OUT,
        _______, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, GO_BACK, XXXXXXX, GO_FWD , XXXXXXX, ZM_RST,
                                            _______, _______, XXXXXXX,   XXXXXXX, XXXXXXX, MO(3)
    ),
    [2] = LAYOUT( // symbols
        KC_GRV , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, SS_GRV , SS_LT  , SS_GT  , SS_MINS, SS_PIPE,                     SS_CIRC, SS_LCBR, SS_RCBR, SS_DLR , XXXXXXX, XXXXXXX,
        XXXXXXX, SS_EXLM, SS_ASTR, SS_SLSH, SS_EQL , SS_AMPR,                     SS_HASH, SS_LPRN, SS_RPRN, SS_SCLN, SS_DQUO, XXXXXXX,
        XXXXXXX, SS_TILD, SS_PLUS, SS_LBRC, SS_RBRC, SS_PERC, XXXXXXX,   XXXXXXX, SS_AT  , SS_COLN, SS_COMM, SS_DOT , SS_QUOT, XXXXXXX,
                                            XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, MO(3)  , XXXXXXX
    ),
    [3] = LAYOUT( // light
        RM_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UG_TOGG,
        XXXXXXX, RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU,                     UG_SPDU, UG_VALU, UG_SATU, UG_HUEU, UG_NEXT, XXXXXXX,
        XXXXXXX, RM_PREV, RM_HUED, RM_SATD, RM_VALD, RM_SPDD,                     XXXXXXX, UG_VALD, UG_SATD, UG_HUED, UG_PREV, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
    )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SS_GRV:
            if (record->event.pressed) {
                SEND_STRING("`");
            }
            return false;
        case SS_LT:
            if (record->event.pressed) {
                SEND_STRING("<");
            }
            return false;
        case SS_GT:
            if (record->event.pressed) {
                SEND_STRING(">");
            }
            return false;
        case SS_MINS:
            if (record->event.pressed) {
                SEND_STRING("-");
            }
            return false;
        case SS_PIPE:
            if (record->event.pressed) {
                SEND_STRING("|");
            }
            return false;
        case SS_CIRC:
            if (record->event.pressed) {
                SEND_STRING("^");
            }
            return false;
        case SS_LCBR:
            if (record->event.pressed) {
                SEND_STRING("{");
            }
            return false;
        case SS_RCBR:
            if (record->event.pressed) {
                SEND_STRING("}");
            }
            return false;
        case SS_DLR:
            if (record->event.pressed) {
                SEND_STRING("$");
            }
            return false;
        case SS_EXLM:
            if (record->event.pressed) {
                SEND_STRING("!");
            }
            return false;
        case SS_ASTR:
            if (record->event.pressed) {
                SEND_STRING("*");
            }
            return false;
        case SS_SLSH:
            if (record->event.pressed) {
                SEND_STRING("/");
            }
            return false;
        case SS_EQL:
            if (record->event.pressed) {
                SEND_STRING("=");
            }
            return false;
        case SS_AMPR:
            if (record->event.pressed) {
                SEND_STRING("&");
            }
            return false;
        case SS_HASH:
            if (record->event.pressed) {
                SEND_STRING("#");
            }
            return false;
        case SS_LPRN:
            if (record->event.pressed) {
                SEND_STRING("(");
            }
            return false;
        case SS_RPRN:
            if (record->event.pressed) {
                SEND_STRING(")");
            }
            return false;
        case SS_SCLN:
            if (record->event.pressed) {
                SEND_STRING(";");
            }
            return false;
        case SS_DQUO:
            if (record->event.pressed) {
                SEND_STRING("\"");
            }
            return false;
        case SS_TILD:
            if (record->event.pressed) {
                SEND_STRING("~");
            }
            return false;
        case SS_PLUS:
            if (record->event.pressed) {
                SEND_STRING("+");
            }
            return false;
        case SS_LBRC:
            if (record->event.pressed) {
                SEND_STRING("[");
            }
            return false;
        case SS_RBRC:
            if (record->event.pressed) {
                SEND_STRING("]");
            }
            return false;
        case SS_PERC:
            if (record->event.pressed) {
                SEND_STRING("%");
            }
            return false;
        case SS_AT:
            if (record->event.pressed) {
                SEND_STRING("@");
            }
            return false;
        case SS_COLN:
            if (record->event.pressed) {
                SEND_STRING(":");
            }
            return false;
        case SS_COMM:
            if (record->event.pressed) {
                SEND_STRING(",");
            }
            return false;
        case SS_DOT:
            if (record->event.pressed) {
                SEND_STRING(".");
            }
            return false;
        case SS_QUOT:
            if (record->event.pressed) {
                SEND_STRING("'");
            }
            return false;
        case SS_UNDS:
            if (record->event.pressed) {
                SEND_STRING("_");
            }
            return false;
    }
    return true;
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   // If console is enabled, it will print the matrix position and status of each key pressed
// #ifdef CONSOLE_ENABLE
//     uprintf("KL: kc: %s, pressed: %u, int: %u, count: %u\n", get_keycode_string(keycode), record->event.pressed,  record->tap.interrupted, record->tap.count);
// #endif
//   return true;
// }

// layer_state_t layer_state_set_user(layer_state_t state) {
//     int layer = get_highest_layer(state);
// #ifdef CONSOLE_ENABLE
//     uprintf("Layer changed to %d\n", layer);
// #endif
//   return state;
// }
