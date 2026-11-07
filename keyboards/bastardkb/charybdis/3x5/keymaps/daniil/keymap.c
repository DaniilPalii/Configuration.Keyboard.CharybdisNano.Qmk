#include QMK_KEYBOARD_H
#include "bk_pointing_device.h"
#include "bk_pointing_modes.h"

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_FUNCTION,
    LAYER_NAVIGATION,
    LAYER_MEDIA,
    LAYER_POINTER,
    LAYER_NUMERAL,
    LAYER_SYMBOLS,
    LAYER_FUNCTIONS,
};

enum {
    TD_DRAGSCROLL_CLICK = 5,
};

enum charybdis_combos {
    COMBO_BACKSPACE,
    COMBO_DELETE,
    COMBO_ESCAPE_LEFT,
    COMBO_SPACE_LEFT,
    COMBO_TAB_LEFT,
    COMBO_TAB_RIGHT,
    COMBO_ESCAPE_RIGHT,
    COMBO_ENTER_RIGHT,
    COMBO_SYMBOL_1,
    COMBO_SYMBOL_2,
    COMBO_ENTER_NUMERAL,
    COMBO_BACKSPACE_NUMERAL,
    COMBO_MOUSE_LEFT,
    COMBO_MOUSE_RIGHT,
    COMBO_MOUSE_MIDDLE,
    COMBO_SYSTEM_WAKE,
};

#define HOME_ROW_ALT_T(KC) LALT_T(KC)
#define HOME_ROW_SHIFT_T(KC) LSFT_T(KC)
#define HOME_ROW_CTRL_T(KC) LCTL_T(KC)
#define HOME_ROW_GUI_T(KC) LGUI_T(KC)

// clang-format off
#define LAYOUT_LAYER_BASE \
    KC_LALT, KC_Q,    KC_W,    KC_E,    KC_R,       KC_0,    KC_6,    KC_7,    KC_8,    KC_9, \
    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,       KC_5,    KC_1,    KC_2,    KC_3,    KC_4, \
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,       KC_T, KC_SPC, KC_TAB, MS_BTN2, SNIPING, \
                            TD(TD_DRAGSCROLL_CLICK), MS_BTN1, KC_ENT, LT(LAYER_FUNCTIONS, KC_B), LT(LAYER_FUNCTION, KC_ESC)

#define LAYOUT_LAYER_FUNCTION \
    LT(LAYER_NAVIGATION, KC_Q), KC_W, LT(LAYER_FUNCTIONS, KC_E), KC_R, KC_T,       KC_Y, KC_U, LT(LAYER_FUNCTIONS, KC_I), KC_O, LT(LAYER_NUMERAL, KC_P), \
    LT(LAYER_SYMBOLS, KC_A), HOME_ROW_ALT_T(KC_S), HOME_ROW_SHIFT_T(KC_D), HOME_ROW_CTRL_T(KC_F), KC_G,       KC_H, HOME_ROW_CTRL_T(KC_J), HOME_ROW_SHIFT_T(KC_K), HOME_ROW_ALT_T(KC_L), LT(LAYER_SYMBOLS, KC_SCLN), \
    HOME_ROW_GUI_T(KC_Z), LT(LAYER_MEDIA, KC_X), LT(LAYER_NUMERAL, KC_C), RALT_T(KC_V), KC_B,       KC_N, RALT_T(KC_M), LT(LAYER_NUMERAL, KC_COMM), LT(LAYER_MEDIA, KC_DOT), HOME_ROW_GUI_T(KC_SLSH), \
                            MO(LAYER_NUMERAL), MS_BTN1, LSFT_T(MS_BTN2), LT(LAYER_FUNCTIONS, KC_ENT), LT(LAYER_NAVIGATION, KC_SPC)

#define LAYOUT_LAYER_NAVIGATION \
    KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PGUP,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_NO, MS_BTN4, KC_SPC, MS_BTN5, KC_NO,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define LAYOUT_LAYER_MEDIA \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO, KC_MNXT, KC_VOLU, KC_BRIU, KC_SYSTEM_POWER, \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       DF(1), KC_MPLY, KC_VOLD, KC_BRID, KC_NO, \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       DF(0), KC_MPRV, KC_MUTE, KC_NO, KC_NO, \
                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO

#define LAYOUT_LAYER_POINTER \
    KC_LALT, DRGSCRL, DRGSCRL, DRGSCRL, KC_NO,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_LSFT, MS_BTN2, MS_BTN3, MS_BTN1, KC_NO,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define LAYOUT_LAYER_NUMERAL \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       S(KC_EQL), KC_1, KC_2, KC_3, S(KC_8), \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_0, KC_4, KC_5, KC_6, KC_EQL, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_MINS, KC_7, KC_8, KC_9, RALT(KC_8), \
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define LAYOUT_LAYER_SYMBOLS \
    KC_LBRC, KC_RBRC, RALT(KC_9), RALT(KC_0), S(KC_6),       KC_GRV, S(KC_1), RALT(KC_7), S(KC_QUOT), KC_QUOT, \
    S(KC_LBRC), S(KC_RBRC), S(KC_9), S(KC_0), S(KC_4),       S(KC_2), RALT(KC_1), RALT(KC_2), RALT(KC_3), RALT(KC_4), \
    S(KC_7), S(KC_BSLS), RALT(KC_8), KC_BSLS, S(KC_3),       S(KC_GRV), S(KC_MINS), KC_MINS, RALT(KC_MINS), RALT(KC_EQL), \
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define LAYOUT_LAYER_FUNCTIONS \
    KC_F5,  KC_F4,  KC_F3,  KC_F2,  KC_F1,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_F10, KC_F9,  KC_F8,  KC_F7,  KC_F6,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_F15, KC_F14, KC_F13, KC_F12, KC_F11,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE]       = LAYOUT_wrapper(LAYOUT_LAYER_BASE),
    [LAYER_FUNCTION]   = LAYOUT_wrapper(LAYOUT_LAYER_FUNCTION),
    [LAYER_NAVIGATION] = LAYOUT_wrapper(LAYOUT_LAYER_NAVIGATION),
    [LAYER_MEDIA]      = LAYOUT_wrapper(LAYOUT_LAYER_MEDIA),
    [LAYER_POINTER]    = LAYOUT_wrapper(LAYOUT_LAYER_POINTER),
    [LAYER_NUMERAL]    = LAYOUT_wrapper(LAYOUT_LAYER_NUMERAL),
    [LAYER_SYMBOLS]    = LAYOUT_wrapper(LAYOUT_LAYER_SYMBOLS),
    [LAYER_FUNCTIONS]  = LAYOUT_wrapper(LAYOUT_LAYER_FUNCTIONS),
};

const uint16_t PROGMEM combo_backspace[]       = {LT(LAYER_NUMERAL, KC_COMM), LT(LAYER_MEDIA, KC_DOT), COMBO_END};
const uint16_t PROGMEM combo_delete[]          = {LT(LAYER_MEDIA, KC_X), LT(LAYER_NUMERAL, KC_C), COMBO_END};
const uint16_t PROGMEM combo_escape_left[]     = {LT(LAYER_MEDIA, KC_DOT), HOME_ROW_GUI_T(KC_SLSH), COMBO_END};
const uint16_t PROGMEM combo_space_left[]      = {LT(LAYER_NUMERAL, KC_C), RALT_T(KC_V), COMBO_END};
const uint16_t PROGMEM combo_tab_left[]        = {LT(LAYER_FUNCTIONS, KC_I), KC_O, COMBO_END};
const uint16_t PROGMEM combo_tab_right[]       = {KC_W, LT(LAYER_FUNCTIONS, KC_E), COMBO_END};
const uint16_t PROGMEM combo_escape_right[]    = {HOME_ROW_GUI_T(KC_Z), LT(LAYER_MEDIA, KC_X), COMBO_END};
const uint16_t PROGMEM combo_enter_right[]     = {RALT_T(KC_M), LT(LAYER_NUMERAL, KC_COMM), COMBO_END};
const uint16_t PROGMEM combo_symbol_1[]        = {KC_4, KC_5, COMBO_END};
const uint16_t PROGMEM combo_symbol_2[]        = {KC_6, KC_5, COMBO_END};
const uint16_t PROGMEM combo_enter_numeral[]   = {KC_8, KC_7, COMBO_END};
const uint16_t PROGMEM combo_backspace_num[]   = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM combo_mouse_left[]      = {RALT_T(KC_M), LT(LAYER_MEDIA, KC_DOT), COMBO_END};
const uint16_t PROGMEM combo_mouse_right[]     = {LT(LAYER_NUMERAL, KC_COMM), HOME_ROW_GUI_T(KC_SLSH), COMBO_END};
const uint16_t PROGMEM combo_mouse_middle[]    = {RALT_T(KC_M), HOME_ROW_GUI_T(KC_SLSH), COMBO_END};
const uint16_t PROGMEM combo_system_wake[]     = {HOME_ROW_CTRL_T(KC_J), LT(LAYER_SYMBOLS, KC_SCLN), COMBO_END};

combo_t key_combos[] = {
    [COMBO_BACKSPACE]     = COMBO(combo_backspace, KC_BSPC),
    [COMBO_DELETE]        = COMBO(combo_delete, KC_DEL),
    [COMBO_ESCAPE_LEFT]   = COMBO(combo_escape_left, KC_ESC),
    [COMBO_SPACE_LEFT]    = COMBO(combo_space_left, KC_SPC),
    [COMBO_TAB_LEFT]      = COMBO(combo_tab_left, KC_TAB),
    [COMBO_TAB_RIGHT]     = COMBO(combo_tab_right, KC_TAB),
    [COMBO_ESCAPE_RIGHT]  = COMBO(combo_escape_right, KC_ESC),
    [COMBO_ENTER_RIGHT]   = COMBO(combo_enter_right, KC_ENT),
    [COMBO_SYMBOL_1]      = COMBO(combo_symbol_1, RALT(KC_1)),
    [COMBO_SYMBOL_2]      = COMBO(combo_symbol_2, S(KC_5)),
    [COMBO_ENTER_NUMERAL] = COMBO(combo_enter_numeral, KC_ENT),
    [COMBO_BACKSPACE_NUMERAL] = COMBO(combo_backspace_num, KC_BSPC),
    [COMBO_MOUSE_LEFT]    = COMBO(combo_mouse_left, MS_BTN1),
    [COMBO_MOUSE_RIGHT]   = COMBO(combo_mouse_right, MS_BTN2),
    [COMBO_MOUSE_MIDDLE]  = COMBO(combo_mouse_middle, MS_BTN3),
    [COMBO_SYSTEM_WAKE]   = COMBO(combo_system_wake, KC_SYSTEM_WAKE),
};

static bool dragscroll_click_held;

static void dragscroll_click_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count != 1) {
        return;
    }

    if (state->pressed && !state->interrupted) {
        register_code16(DRGSCRL);
        dragscroll_click_held = true;
    } else {
        tap_code16(MS_BTN3);
    }
}

static void dragscroll_click_reset(tap_dance_state_t *state, void *user_data) {
    if (dragscroll_click_held) {
        unregister_code16(DRGSCRL);
        dragscroll_click_held = false;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_DRAGSCROLL_CLICK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dragscroll_click_finished, dragscroll_click_reset),
};

void keyboard_post_init_user(void) {
    static const struct {
        uint8_t mode;
        uint16_t dpi;
    } mode_dpi[] = {
        {MODE_NORMAL, 1400},
        {MODE_SNIPING, 500},
        {MODE_DRAGSCROLL, 700},
        {MODE_CURSOR, 800},
        {MODE_BRIGHTNESS, 500},
        {MODE_ZOOM, 1100},
        {MODE_VOLUME, 500},
        {MODE_TAB_SWITCH, 500},
        {MODE_HISTORY, 500}
    };

    if (bkpd_get_auto_mouse_layer_enabled()) {
        bkpd_set_auto_mouse_layer_enabled(false);
    }
    if (!bkpd_get_auto_precision_on_mouse_layer_enabled()) {
        bkpd_set_auto_precision_on_mouse_layer_enabled(true);
    }

    for (uint8_t i = 0; i < sizeof(mode_dpi) / sizeof(mode_dpi[0]); i++) {
        if (bkpd_mode_get_dpi(mode_dpi[i].mode) != mode_dpi[i].dpi) {
            bkpd_mode_change_dpi(mode_dpi[i].mode, mode_dpi[i].dpi);
        }
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Keep the exported trackball profiles tied to the active typing layer.
    switch (get_highest_layer(state)) {
        case LAYER_NAVIGATION:
            bkpd_mode_set_active(MODE_CURSOR);
            break;
        case LAYER_MEDIA:
            bkpd_mode_set_active(MODE_VOLUME);
            break;
        case LAYER_POINTER:
        case LAYER_SYMBOLS:
            bkpd_mode_set_active(MODE_SNIPING);
            break;
        case LAYER_NUMERAL:
            bkpd_mode_set_active(MODE_DRAGSCROLL);
            break;
        case LAYER_FUNCTIONS:
            bkpd_mode_set_active(MODE_ZOOM);
            break;
        default:
            bkpd_mode_set_active(MODE_NORMAL);
            break;
    }
    return state;
}
// clang-format on
