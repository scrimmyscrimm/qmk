#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        TO(1),
        KC_1,
        QK_BOOT
    ),
    [1] = LAYOUT(
        TO(2),
        KC_NO,
        KC_NO
    ),
    [2] = LAYOUT(
        TO(3),
        KC_NO,
        KC_NO
    ),
    [3] = LAYOUT(
        TO(0),
        KC_NO,
        KC_NO
    )
};
