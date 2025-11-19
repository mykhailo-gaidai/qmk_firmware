#include QMK_KEYBOARD_H

#define MOD_CAG LCAG(KC_NO)
#define GO_BACK G(KC_LBRC)
#define GO_FWD G(KC_RBRC)
#define CTL_GRV LCTL_T(KC_GRV)
#define A_LEFT  A(KC_LEFT)
#define A_RIGHT A(KC_RGHT)
#define OS_LOCK C(G(KC_Q))
#define RAYCAST C(G(KC_S))
#define HR_CLCK S(G(KC_SLSH))
#define HR_FIND S(A(G(KC_SLSH)))
#define BS_SYM  LT(2, KC_BSPC)
#define EMOJI   C(G(KC_SPACE))
#define KC_CAG  C(A(G(KC_NO)))
#define KC_HYPR HYPR(KC_NO)
#define SFT_SPC LSFT_T(KC_SPC)
#define LSYMB_F LT(2, KC_F)
#define RSYMB_J LT(3, KC_J)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( // alphas
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC,
        OS_LCTL, KC_A   , KC_S   , KC_D   , LSYMB_F, KC_G   ,                     KC_H   , RSYMB_J, KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        OS_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_GRV ,   MO(4)  , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RCTL,
                                            OS_RALT, OS_LGUI, SFT_SPC,   KC_ENT , OSL(1) , KC_BSPC
    ),
    [1] = LAYOUT( // navigation
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     HR_FIND, KC_VOLU, KC_VOLD, KC_MUTE, XXXXXXX, OS_LOCK,
        XXXXXXX, XXXXXXX, KC_F7  , KC_F8  , KC_F9  , KC_F11 ,                     KC_HOME, A_LEFT , KC_UP  , A_RIGHT, KC_PGUP, XXXXXXX,
        _______, XXXXXXX, KC_F4  , KC_F5  , KC_F6  , KC_F12 ,                     KC_END , KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,
        _______, XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F10 , KC_CAG ,   KC_HYPR, HR_CLCK, GO_BACK, RAYCAST, GO_FWD , EMOJI  , _______,
                                            _______, _______, _______,   _______, _______, KC_DEL
    ),
    [2] = LAYOUT( // left symbols
        _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                     _______, KC_UNDS, KC_PIPE, KC_QUOT, _______, _______,
        _______, KC_CIRC, KC_ASTR, KC_AMPR, XXXXXXX, _______,                     KC_HASH, KC_TILD, KC_SLSH, KC_DQUO, KC_DLR , _______,
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, KC_MINS, KC_BSLS, KC_GRV , KC_QUES, _______,
                                            _______, _______, _______,   _______, _______, _______
    ),
    [3] = LAYOUT( // right symbols
        _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, _______, KC_COLN, KC_LT  , KC_GT  , KC_SCLN,                     _______, _______, _______, _______, _______, _______,
        _______, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_AT  ,                     _______, XXXXXXX, KC_EQL , KC_PLUS, KC_PERC, _______,
        _______, _______, KC_EXLM, KC_LBRC, KC_RBRC, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,   _______, _______, _______
    ),
    // [2] = LAYOUT( // symbols
    //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //     XXXXXXX, KC_GRV , KC_LT  , KC_GT  , KC_MINS, KC_PIPE,                     KC_CIRC, KC_LCBR, KC_RCBR, KC_DLR , KC_BSLS, XXXXXXX,
    //     _______, KC_EXLM, KC_ASTR, KC_SLSH, KC_EQL , KC_AMPR,                     KC_HASH, KC_LPRN, KC_RPRN, KC_QUOT, KC_COLN, XXXXXXX,
    //     _______, KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC, _______,   _______, KC_AT  , KC_UNDS, _______, _______, KC_QUES, _______,
    //                                         _______, _______, _______,   _______, _______, _______
    // ),
    [4] = LAYOUT( // RGB
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, UG_HUEU, UG_SATU, UG_VALU, UG_NEXT, XXXXXXX,                     XXXXXXX, RM_NEXT, RM_VALU, RM_SATU, RM_HUEU, XXXXXXX,
        XXXXXXX, UG_HUED, UG_SATD, UG_VALD, UG_PREV, XXXXXXX,                     XXXXXXX, RM_PREV, RM_VALD, RM_SATD, RM_HUED, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_ESC:
            if (record->event.pressed) {
                reset_oneshot_layer();
            }
    }
    return true;
}

// bool rgb_matrix_indicators_user(void) {
//     rgb_matrix_set_color_all(RGB_OFF);
//     int8_t os = get_oneshot_mods();

//     if (os & MOD_MASK_CTRL) {
//         rgb_matrix_set_color(15, RGB_RED);
//     } if (os & MOD_MASK_SHIFT) {
//         rgb_matrix_set_color(28, RGB_RED);
//     } if (os & MOD_MASK_ALT) {
//         rgb_matrix_set_color(33, RGB_RED);
//     } if (os & MOD_MASK_GUI) {
//         rgb_matrix_set_color(32, RGB_RED);
//     } if (IS_LAYER_ON(1)) {
//         rgb_matrix_set_color(30, RGB_GREEN);
//     } if (IS_LAYER_ON(2)) {
//         rgb_matrix_set_color_all(RGB_GREEN);
//     } if (IS_LAYER_ON(3)) {
//         rgb_matrix_set_color_all(RGB_BLUE);
//     }

//     return false;
// }
