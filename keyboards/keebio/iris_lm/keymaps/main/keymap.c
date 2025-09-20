#include QMK_KEYBOARD_H

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( // alphas
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC,
        CTL_GRV, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , MO(3)  ,   MO(2)  , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                                            KC_LALT, KC_LGUI, KC_SPC ,   KC_ENT , MO(1)  , BS_SYM
    ),
    [1] = LAYOUT( // navigation
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_VOLU, KC_VOLD, KC_MUTE, XXXXXXX, OS_LOCK,
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
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11 , XXXXXXX,   XXXXXXX, KC_F12 , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                            _______, _______, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
    )
};

enum combo_events {
    BOTH_BRACKETS,
    BOTH_PARENS,
    BOTH_BRACES,
    BOTH_ANGLES,
    BOTH_DQUO,
    BOTH_QUOT,
    BOTH_GRV
};

// wide
const uint16_t PROGMEM combo_wr[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM combo_xv[] = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM combo_uo[] = {KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM combo_mdot[] = {KC_M, KC_DOT, COMBO_END};
// horizontal
const uint16_t PROGMEM combo_we[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_er[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_sd[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_df[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_fg[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM combo_xc[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_cv[] = {KC_C, KC_V, COMBO_END};
// vertical
const uint16_t PROGMEM combo_ws[] = {KC_W, KC_S, COMBO_END};
const uint16_t PROGMEM combo_ed[] = {KC_E, KC_D, COMBO_END};
const uint16_t PROGMEM combo_tg[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM combo_rf[] = {KC_R, KC_F, COMBO_END};
const uint16_t PROGMEM combo_sx[] = {KC_S, KC_X, COMBO_END};
const uint16_t PROGMEM combo_dc[] = {KC_D, KC_C, COMBO_END};
const uint16_t PROGMEM combo_fv[] = {KC_F, KC_V, COMBO_END};
// diagonal
const uint16_t PROGMEM combo_rd[] = {KC_R, KC_D, COMBO_END};
const uint16_t PROGMEM combo_fc[] = {KC_F, KC_C, COMBO_END};
// right - horizontal
const uint16_t PROGMEM combo_ui[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_io[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_hj[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM combo_jk[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_kl[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_mcomma[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM combo_commadot[] = {KC_COMMA, KC_DOT, COMBO_END};
// right - vertical
const uint16_t PROGMEM combo_yh[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM combo_uj[] = {KC_U, KC_J, COMBO_END};
const uint16_t PROGMEM combo_ik[] = {KC_I, KC_K, COMBO_END};
const uint16_t PROGMEM combo_ol[] = {KC_O, KC_L, COMBO_END};
const uint16_t PROGMEM combo_jm[] = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM combo_kcomma[] = {KC_K, KC_COMMA, COMBO_END};
// right - diagonal
const uint16_t PROGMEM combo_ij[] = {KC_I, KC_J, COMBO_END};
const uint16_t PROGMEM combo_km[] = {KC_K, KC_M, COMBO_END};

combo_t key_combos[] = {
    [BOTH_BRACKETS] = COMBO_ACTION(combo_wr),
    [BOTH_BRACES] = COMBO_ACTION(combo_xv),
    [BOTH_PARENS] = COMBO_ACTION(combo_uo),
    [BOTH_ANGLES] = COMBO_ACTION(combo_mdot),
    [BOTH_DQUO] = COMBO_ACTION(combo_jm),
    [BOTH_QUOT] = COMBO_ACTION(combo_kcomma),
    [BOTH_GRV] = COMBO_ACTION(combo_sx),
    COMBO(combo_we, KC_LBRC),
    COMBO(combo_er, KC_RBRC),
    COMBO(combo_sd, KC_MINS),
    COMBO(combo_df, KC_EQL),
    COMBO(combo_fg, KC_PLUS),
    COMBO(combo_xc, KC_LCBR),
    COMBO(combo_cv, KC_RCBR),
    COMBO(combo_ws, KC_AT),
    COMBO(combo_ed, KC_HASH),
    COMBO(combo_rf, KC_DLR),
    COMBO(combo_tg, KC_PERC),
    COMBO(combo_dc, KC_GRV),
    COMBO(combo_fv, KC_TILD),
    COMBO(combo_rd, KC_EXLM),
    COMBO(combo_fc, KC_UNDS),
    COMBO(combo_ui, KC_LPRN),
    COMBO(combo_io, KC_RPRN),
    COMBO(combo_hj, KC_PIPE),
    COMBO(combo_jk, KC_DQUO),
    COMBO(combo_kl, KC_QUOT),
    COMBO(combo_mcomma, KC_LT),
    COMBO(combo_commadot, KC_GT),
    COMBO(combo_yh, KC_CIRC),
    COMBO(combo_uj, KC_AMPR),
    COMBO(combo_ik, KC_ASTR),
    COMBO(combo_ol, KC_BSLS),
    COMBO(combo_ij, KC_QUES),
    COMBO(combo_km, KC_SCLN)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case BOTH_BRACKETS: if (pressed)  SEND_STRING("[]" SS_TAP(X_LEFT)); break;
    case BOTH_BRACES: if (pressed)  SEND_STRING("{}" SS_TAP(X_LEFT)); break;
    case BOTH_PARENS: if (pressed)  SEND_STRING("()" SS_TAP(X_LEFT)); break;
    case BOTH_ANGLES: if (pressed)  SEND_STRING("<>" SS_TAP(X_LEFT)); break;
    case BOTH_DQUO: if (pressed)  SEND_STRING("\"\"" SS_TAP(X_LEFT)); break;
    case BOTH_QUOT: if (pressed)  SEND_STRING("''" SS_TAP(X_LEFT)); break;
    case BOTH_GRV: if (pressed)  SEND_STRING("``" SS_TAP(X_LEFT)); break;
      break;
  }
}
