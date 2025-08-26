#include QMK_KEYBOARD_H
#include "print.h"

#define MOD_CAG LCAG(KC_NO)
#define GO_BACK G(KC_LBRC)
#define GO_FWD G(KC_RBRC)

#define OS_LOCK C(G(KC_Q))
#define RAYCAST LCAG(KC_E)
#define HR_CLCK LCAG(KC_SPC)
#define HR_FIND LCAG(KC_F)

#define S_GRV   KC_GRV
#define S_LT    S(KC_COMM)
#define S_GT    S(KC_DOT)
#define S_MINUS KC_MINS
#define S_PIPE  S(KC_BSLS)
#define S_CIRC  S(KC_6)
#define S_LCBR  S(KC_LBRC)
#define S_RCBR  S(KC_RBRC)
#define S_DLR   S(KC_4)
#define S_EXLM  S(KC_1)
#define S_ASTR  S(KC_8)
#define S_SLSH  KC_SLSH
#define S_EQL   KC_EQL
#define S_AMPR  S(KC_7)
#define S_HASH  S(KC_3)
#define S_LPRN  KC_LBRC
#define S_RPRN  S(KC_9)
#define S_SCLN  S(KC_0)
#define S_DQUO  S(KC_QUOT)
#define S_TILD  S(KC_GRV)
#define S_PLUS  S(KC_EQL)
#define S_LBRC  KC_LBRC
#define S_RBRC  KC_RBRC
#define S_PERC  S(KC_5)
#define S_AT    S(KC_2)
#define S_COLN  S(KC_SCLN)
#define S_COMM  KC_COMM
#define S_DOT   KC_DOT
#define S_QUOT  KC_QUOT
#define S_UNDS  S(KC_MINS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( // alphas
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC,
        KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        MO(2)  , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , MOD_CAG,   MO(3)  , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT ,
                                            KC_LALT, KC_LGUI, KC_SPC ,   MO(1)  , KC_BSPC, KC_LSFT
    ),
    // [1] = LAYOUT( // left mod
    //     _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
    //     _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, MOD_CAG,                     _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
    //                                         _______, _______, MO(4  ),   _______, _______, MO(5)
    // ),
    // [2] = LAYOUT( // right mod
    //     _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______,                     MOD_CAG, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, _______,
    //     _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
    //                                         MO(5)  , _______, _______,   _______, _______, _______
    // ),
    [1] = LAYOUT( // navigation
        OS_LOCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OS_LOCK,
        XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,                     XXXXXXX, KC_HOME, KC_UP  , KC_END , KC_PGUP, XXXXXXX,
        XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, MOD_CAG,                     HR_CLCK, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, HR_FIND, GO_BACK, RAYCAST, GO_FWD , XXXXXXX, _______,
                                            _______, _______, MO(3)  ,   _______, _______, _______
    ),
    [2] = LAYOUT( // symbols
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, S_GRV  , S_LT   , S_GT   , S_MINUS, S_PIPE ,                     S_CIRC , S_LCBR , S_RCBR , S_DLR  , XXXXXXX, XXXXXXX,
        XXXXXXX, S_EXLM , S_ASTR , S_SLSH , S_EQL  , S_AMPR ,                     S_HASH , S_LPRN , S_RPRN , S_SCLN , S_COLN , S_DQUO ,
        XXXXXXX, S_TILD , S_PLUS , S_LBRC , S_RBRC , S_PERC , XXXXXXX,   XXXXXXX, S_AT   , S_UNDS , _______, _______, S_QUOT , _______,
                                            _______, _______, _______,   _______, _______, _______
    ),
    [3] = LAYOUT( // numbers
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , XXXXXXX,
        XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_F11 ,                     KC_F12 , KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, XXXXXXX,
        XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , XXXXXXX,   XXXXXXX, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
                                            _______, _______, _______,   _______, _______, _______
    )
};
