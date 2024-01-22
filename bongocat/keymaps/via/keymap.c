#include QMK_KEYBOARD_H

enum custom_layer {
    _BASE,     // default layer
    _FN1,      // first function layer
    _FN2,      // second function layer
    _FN3,      // third function layer
    _FN4,      // fourth function layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        OSL(1),			// switch to layer 1 (_FN1) for one keypress
        QK_AREP,		// repeat alt of last key pressed
        QK_REP			// repeat last key pressed
    ),
    [_FN1] = LAYOUT(
        OSL(2),			// switch to layer 2 (_FN2) for one keypress
        C(KC_G),		// ctrl+G (for current use in lightroom)
        C(KC_H)			// ctrl+G (for current use in lightroom)
    ),
    [_FN2] = LAYOUT(
        OSL(3),			// switch to layer 3 (_FN3) for one keypress
        KC_MFFD,		// fast forward (alt repeat will rewind)
		C(KC_Z)			// undo (alt repeat will redo CTRL+Y)
    ),
    [_FN3] = LAYOUT(
        OSL(4),			// switch to layer 4 (_FN4) for one keypress
        RGB_MOD,		// change animation mode forward (alt repeat will go back)
        RGB_HUI			// change hue forward (alt repeat will go back)
    ),
    [_FN4] = LAYOUT(
        RGB_TOG,			// toggle switch key lights on and off
        QK_CLEAR_EEPROM,	// reset board back to defaults
        QK_BOOT				// put board into boot mode for flashing
    )
};

// Default Layer
const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 2, HSV_GREEN}
);
// MO(_FN1)
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 2, HSV_PURPLE}
);
// MO(_FN2)
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 2, HSV_CHARTREUSE}
);
// MO(_FN3)
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 2, HSV_GOLDENROD}
);
// MO(_FN4)
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 2, 0,255,255}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer0_layer,
    my_layer1_layer,
    my_layer2_layer,
    my_layer3_layer,
    my_layer4_layer
);

void keyboard_post_init_user(void) {
	// set effects to only be for 3 switches and not backlights
	rgblight_set_effect_range(0,3);

    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _FN1));
    rgblight_set_layer_state(2, layer_state_cmp(state, _FN2));
    rgblight_set_layer_state(3, layer_state_cmp(state, _FN3));
    rgblight_set_layer_state(4, layer_state_cmp(state, _FN4));
    return state;
}


// How long (in milliseconds) to wait between animation steps for each of the "Cycling rainbow" animations
const uint8_t RGBLED_RAINBOW_MOOD_INTERVALS[] PROGMEM = {10, 60, 200};

// How long (in milliseconds) to wait between animation steps for each of the "Swirling rainbow" animations
const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {10, 60, 200};

// How long (in milliseconds) to wait between animation steps for each of the "Knight" animations
const uint8_t RGBLED_KNIGHT_INTERVALS[] PROGMEM = {80, 120, 170};

// How long (in milliseconds) to wait between animation steps for each of the "Twinkle" animations
const uint8_t RGBLED_TWINKLE_INTERVALS[] PROGMEM = {5, 10, 20};

// // These control which hues are selected for each of the "Static gradient" modes
// const uint8_t RGBLED_GRADIENT_RANGES[] PROGMEM = {255, 170, 127, 85, 64};

// Use the get_alt_repeat_key_keycode_user() callback to define the "alternate" for additional keys or override the default definitions. 
uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
// define alt key for forward/backword animation cycling and for hue
	switch (keycode) {
		case RGB_MOD: return RGB_RMOD;	// change light animation mode backward on alt for forward mode key
		case RGB_RMOD: return RGB_MOD;	// change light animation mode forward on alt for backward mode key
		case RGB_HUI: return RGB_HUD;	// change light hue backward on alt for forward hue key
		case RGB_HUD: return RGB_HUI;	// change light hue forward on alt for backward hue key
		case C(KC_Z): return C(KC_Y);	// set redo for alt of undo
	}
    return KC_TRNS;  // Defer to default definitions.
}
