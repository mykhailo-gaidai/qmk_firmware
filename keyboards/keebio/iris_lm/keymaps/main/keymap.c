#include QMK_KEYBOARD_H

// Tap Dance keycodes
enum td_keycodes {
    ALT_OSL4
};

// Define a type containing as many tapdance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD
} td_state_t;

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Declare your tapdance functions:

// Function to determine the current tapdance state
td_state_t cur_dance(tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void alt_osl4_finished(tap_dance_state_t *state, void *user_data);
void alt_osl4_reset(tap_dance_state_t *state, void *user_data);


#define MOD_CAG LCAG(KC_NO)
#define GO_BACK G(KC_LBRC)
#define GO_FWD G(KC_RBRC)
#define CTL_GRV LCTL_T(KC_GRV)
#define A_LEFT  A(KC_LEFT)
#define A_RIGHT A(KC_RGHT)
#define OS_LOCK C(G(KC_Q))
#define RAYCAST C(G(KC_S))
#define HR_CLCK LCAG(KC_SPC)
#define HR_FIND LCAG(KC_F)
#define BS_SYM  LT(2, KC_BSPC)
#define ALT_FUN TD(ALT_OSL4)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( // alphas
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC,
        CTL_GRV, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , MO(3)  ,   MO(2)  , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                                            ALT_FUN, KC_LGUI, KC_SPC ,   KC_ENT , MO(1)  , BS_SYM
    ),
    [1] = LAYOUT( // navigation
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_VOLU, KC_VOLD, KC_MUTE, XXXXXXX, OS_LOCK,
        XXXXXXX, XXXXXXX, KC_F7  , KC_F8  , KC_F9  , KC_F11 ,                     KC_HOME, A_LEFT , KC_UP  , A_RIGHT, KC_PGUP, XXXXXXX,
        _______, XXXXXXX, KC_F4  , KC_F5  , KC_F6  , KC_F12 ,                     KC_END , KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,
        _______, XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F10 , MO(4)  ,   _______, HR_CLCK, GO_BACK, RAYCAST, GO_FWD , XXXXXXX, _______,
                                            _______, _______, _______,   _______, _______, KC_DEL
    ),
    [2] = LAYOUT( // symbols
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_GRV , KC_LT  , KC_GT  , KC_MINS, KC_PIPE,                     KC_CIRC, KC_LCBR, KC_RCBR, KC_DLR , XXXXXXX, XXXXXXX,
        _______, KC_EXLM, KC_ASTR, KC_SLSH, KC_EQL , KC_AMPR,                     KC_HASH, KC_LPRN, KC_RPRN, XXXXXXX, KC_COLN, KC_DQUO,
        _______, KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC, _______,   _______, KC_AT  , KC_UNDS, _______, _______, KC_QUES, _______,
                                            _______, _______, _______,   _______, _______, _______
    ),
    [3] = LAYOUT( // numbers
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_P7  , KC_P8  , KC_P9  , KC_PPLS, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_P4  , KC_P5  , KC_P6  , KC_PPLS, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,   _______, XXXXXXX, KC_P1  , KC_P2  , KC_P3  , KC_PDOT, XXXXXXX,
                                            _______, _______, _______,   _______, KC_P0  , _______
    ),
    [4] = LAYOUT( // functions
        XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11 ,                     KC_F12 , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11 , _______,   _______, KC_F12, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            _______, _______, _______,   _______, _______, _______
    )
};

// Determine the tapdance state to return
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    else if (state->count == 2) {
        if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
      }
    else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
}

// Handle the possible states for each tapdance keycode you define:

void alt_osl4_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: set_oneshot_layer(4, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED); break;
        case TD_SINGLE_HOLD: register_code(KC_LALT); break;
        case TD_DOUBLE_TAP: set_oneshot_layer(4, ONESHOT_START); set_oneshot_layer(4, ONESHOT_PRESSED); break;
        case TD_DOUBLE_HOLD: register_code(KC_LALT); layer_on(4); break;
        default:
            break;
    }
}

void alt_osl4_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: unregister_code(KC_LALT); break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_HOLD: layer_off(4); unregister_code(KC_LALT); break;
        default:
            break;
    }
}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
tap_dance_action_t tap_dance_actions[] = {
    [ALT_OSL4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_osl4_finished, alt_osl4_reset)
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
      case KC_TRNS:
      case KC_NO:
        /* Always cancel one-shot layer when another key gets pressed */
        if (record->event.pressed && is_oneshot_layer_active())
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        return true;
    //   case RESET:
    //     /* Don't allow reset from oneshot layer state */
    //     if (record->event.pressed && is_oneshot_layer_active()){
    //       clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
    //       return false;
    //     }
    //     return true;
      default:
        return true;
    }
    return true;
  }
