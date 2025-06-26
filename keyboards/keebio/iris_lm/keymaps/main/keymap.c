#include QMK_KEYBOARD_H
#include "print.h"

#define ESC_FUN LT(3, KC_ESC)
#define BSC_NAV LT(1, KC_BSPC)
#define DEL_SYM LT(2, KC_DEL)
#define TAB_SYM LT(2, KC_TAB)
#define WRD_PRV A(KC_LEFT)
#define WRD_NXT A(KC_RGHT)
#define ALT_ENT A(KC_ENT)
#define HRM_A LCTL_T(KC_A)
#define HRM_S LALT_T(KC_S)
#define HRM_D LGUI_T(KC_D)
#define HRM_F LSFT_T(KC_F)
#define HRM_G LCAG_T(KC_G)
#define HRM_H LCAG_T(KC_H)
#define HRM_J RSFT_T(KC_J)
#define HRM_K RGUI_T(KC_K)
#define HRM_L RALT_T(KC_L)
#define HRM_SCL RCTL_T(KC_SCLN)
#define MOD_CAG LCAG(KC_NO)
#define GO_BACK G(KC_LBRC)
#define GO_FWD G(KC_RBRC)
#define KC_COPY LGUI(KC_C)
#define KC_CUT  LGUI(KC_X)
#define KC_PSTE LGUI(KC_V)
#define KC_UNDO  LGUI(KC_Z)
#define KC_REDO  LGUI(KC_Y)
#define Z_BTTN LT(4, KC_Z) // Button layer
#define SL_BTTN LT(4, KC_SLSH) // Button layer
#define KC_LOCK G(C(KC_Q))
#define KC_RAYC LCAG(KC_E)

enum sym_keycodes {
    SS_GRV = SAFE_RANGE,
    SS_LT, SS_GT, SS_MINS, SS_PIPE, SS_CIRC, SS_LCBR, SS_RCBR, SS_DLR,
    SS_EXLM, SS_ASTR, SS_SLSH, SS_EQL, SS_AMPR, SS_HASH, SS_LPRN, SS_RPRN, SS_SCLN, SS_DQUO, 
    SS_TILD, SS_PLUS, SS_LBRC, SS_RBRC, SS_PERC, SS_AT, SS_COLN, SS_COMM, SS_DOT, SS_QUOT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( // alphas
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
        KC_RAYC, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC,
        KC_GRV , HRM_A  , HRM_S  , HRM_D  , HRM_F  , HRM_G  ,                     HRM_H  , HRM_J  , HRM_K  , HRM_L  , HRM_SCL, KC_QUOT,
        KC_LBRC, Z_BTTN , KC_X   , KC_C   , KC_V   , KC_B   , CW_TOGG,   KC_LSFT, KC_N   , KC_M   , KC_COMM, KC_DOT , SL_BTTN, KC_RBRC,
                                            ESC_FUN, TAB_SYM, KC_SPC ,   KC_ENT , BSC_NAV, DEL_SYM
    ),
    [1] = LAYOUT( // navigation
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,                     KC_HOME, WRD_PRV, KC_UP  , WRD_NXT, KC_PGUP, XXXXXXX,
        XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, MOD_CAG,                     KC_END , KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, GO_BACK, XXXXXXX, GO_FWD , XXXXXXX, XXXXXXX,
                                            XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [2] = LAYOUT( // symbols
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, SS_GRV , SS_LT  , SS_GT  , SS_MINS, SS_PIPE,                     SS_CIRC, SS_LCBR, SS_RCBR, SS_DLR , XXXXXXX, XXXXXXX,
        XXXXXXX, SS_EXLM, SS_ASTR, SS_SLSH, SS_EQL , SS_AMPR,                     SS_HASH, SS_LPRN, SS_RPRN, SS_SCLN, SS_DQUO, XXXXXXX,
        XXXXXXX, SS_TILD, SS_PLUS, SS_LBRC, SS_RBRC, SS_PERC, XXXXXXX,   XXXXXXX, SS_AT  , SS_COLN, SS_COMM, SS_DOT , SS_QUOT, XXXXXXX,
                                            XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, MO(5)  , XXXXXXX
    ),
    [3] = LAYOUT( // function
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_F12 , KC_F7  , KC_F8  , KC_F9  , KC_F12 , XXXXXXX,
        XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, MOD_CAG,                     KC_F11 , KC_F4  , KC_F5  , KC_F6  , KC_F11 , XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, KC_F10 , KC_F1  , KC_F2  , KC_F3  , KC_F10 , XXXXXXX,
                                            XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [4] = LAYOUT( // button
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LOCK,                     KC_LOCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_UNDO, KC_CUT , KC_COPY, KC_PSTE, KC_REDO,                     KC_REDO, KC_PSTE, KC_COPY, KC_CUT , KC_UNDO, XXXXXXX,
        XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, MOD_CAG,                     MOD_CAG, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, XXXXXXX,
        XXXXXXX, KC_UNDO, KC_CUT , KC_COPY, KC_PSTE, KC_REDO, XXXXXXX,   XXXXXXX, KC_REDO, KC_PSTE, KC_COPY, KC_CUT , KC_UNDO, XXXXXXX,
                                            XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [5] = LAYOUT( // light
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
                SEND_STRING(":");
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
                SEND_STRING("\"");
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
