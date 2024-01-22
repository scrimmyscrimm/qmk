/* 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* key matrix size */
// #define MATRIX_ROWS 1
// #define MATRIX_COLS 3

/*
 * Keyboard Matrix Assignments
 */
#define MATRIX_ROW_PINS { A6 }				//pin on MCU that starts the 'row' for the switches (the non-diode side)
#define MATRIX_COL_PINS { A3, A4, A5 }		//pin on MCU for each switch on this board that is the diode side
#define DIODE_DIRECTION ROW2COL				//direction diodes are with the pins

#define WS2812_DI_PIN B8				//pin for all the lights (all lights are connected in a string --- starts with left switch light
#define RGBLED_NUM 5					//how many leds we have

#define DYNAMIC_KEYMAP_LAYER_COUNT 5	//set number of layers allowed

//specify lighting changes and defaults
#define RGBLIGHT_LAYERS										//enables per layer lighting which is set up in keymap.c
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF 					//allows layer lights to stay on even if RGB is toggled off with RGB_TOG
#define RGBLIGHT_HUE_STEP 2									//steps to increment hue by
#define RGBLIGHT_SAT_STEP 8									//steps to increment saturation by
#define RGBLIGHT_VAL_STEP 8									//steps to increment brightness by
#define RGBLIGHT_LIMIT_VAL 255 								//sets max brightness level
#define RGBLIGHT_SLEEP  									//enables lights to turn off when comp goes to sleep
#define RGBLIGHT_DEFAULT_HUE 184							//default hue when reset (cleared the EEPROM)
#define RGBLIGHT_DEFAULT_SAT 255							//default saturation when reset (cleared the EEPROM)
#define RGBLIGHT_DEFAULT_VAL 150							//default brightness when reset (cleared the EEPROM)
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT	//sets default to static light upon rest (clearing the EEPROM)
#define RGBLIGHT_DEFAULT_ON TRUE							//sets default to lights on when rest (clearing the EEPROM)

//animations to chose from
// #define RGBLIGHT_ANIMATIONS							 //Enable all additional animation modes. (deprecated)
// #define RGBLIGHT_EFFECT_ALTERNATING					 //Enable alternating animation mode.
// #define RGBLIGHT_EFFECT_BREATHING					 //Enable breathing animation mode.
// #define RGBLIGHT_EFFECT_CHRISTMAS					 //Enable christmas animation mode.
#define RGBLIGHT_EFFECT_KNIGHT						 //Enable knight animation mode.
#define RGBLIGHT_EFFECT_RAINBOW_MOOD				 //Enable rainbow mood animation mode.
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL				 //Enable rainbow swirl animation mode.
// #define RGBLIGHT_EFFECT_RGB_TEST					 //Enable RGB test animation mode.
// #define RGBLIGHT_EFFECT_SNAKE						 //Enable snake animation mode.
// #define RGBLIGHT_EFFECT_STATIC_GRADIENT				 //Enable static gradient mode.
#define RGBLIGHT_EFFECT_TWINKLE						 //Enable twinkle animation mode.

//controls to customize animations if needed
// #define RGBLIGHT_EFFECT_BREATHE_CENTER			// Not defined 		If defined, used to calculate the curve for the breathing animation. Valid values are 1.0 to 2.7
// #define RGBLIGHT_EFFECT_BREATHE_MAX 				// 255 				The maximum brightness for the breathing mode. Valid values are 1 to 255
// #define RGBLIGHT_EFFECT_CHRISTMAS_INTERVAL 		// 40 				How long (in milliseconds) to wait between animation steps for the “Christmas” animation
// #define RGBLIGHT_EFFECT_CHRISTMAS_STEP 			// 2 				The number of LEDs to group the red/green colors by for the “Christmas” animation
#define RGBLIGHT_EFFECT_KNIGHT_LED_NUM 3			// RGBLED_NUM 		The number of LEDs to have the “Knight” animation travel
#define RGBLIGHT_EFFECT_KNIGHT_LENGTH 3				// 3 				The number of LEDs to light up for the “Knight” animation
// #define RGBLIGHT_EFFECT_KNIGHT_OFFSET 			// 0 				The number of LEDs to start the “Knight” animation from the start of the strip by
#define RGBLIGHT_RAINBOW_SWIRL_RANGE 30			// 255 				Range adjustment for the rainbow swirl effect to get different swirls
// #define RGBLIGHT_EFFECT_SNAKE_LENGTH 			// 4 				The number of LEDs to light up for the “Snake” animation
#define RGBLIGHT_EFFECT_TWINKLE_LIFE 300			// 200 				Adjusts how quickly each LED brightens and dims when twinkling (in animation steps)
#define RGBLIGHT_EFFECT_TWINKLE_PROBABILITY 1/40	// 1/127 			Adjusts how likely each LED is to twinkle (on each animation step)


// remove alternate repeat key to reduce firmware
// #define NO_ALT_REPEAT_KEY