// in rules.mk set the following: RGB_MATRIX_CUSTOM_USER = yes

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

// RGB_MATRIX_EFFECT(MY_SOLID)
RGB_MATRIX_EFFECT(MY_PENDULUM)


// RGB_MATRIX_EFFECT(STAR_LIGHT)
// RGB_MATRIX_EFFECT(DUAL_SAT_STAR_LIGHT)
// RGB_MATRIX_EFFECT(DUAL_HUE_STAR_LIGHT)


RGB_MATRIX_EFFECT(MY_NEW_CROSS)
RGB_MATRIX_EFFECT(MY_NEW_SPLASH)
RGB_MATRIX_EFFECT(MY_NEW_NEXUS)
RGB_MATRIX_EFFECT(MY_KEY_REACTIVE)
RGB_MATRIX_EFFECT(ONLINE_NEW_SPLASH)


#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS


// bool MY_SOLID(effect_params_t* params) {
    // LED_MATRIX_USE_LIMITS(led_min, led_max);

    // uint8_t val = led_matrix_eeconfig.val;
    // for (uint8_t i = led_min; i < led_max; i++) {
        // LED_MATRIX_TEST_LED_FLAGS();
        // led_matrix_set_value(i+2, val);
    // }
    // return led_matrix_check_finished_leds(led_max);
// }


// Change huedelta to adjust range of hue change. 0-255.
// Looks better with a low value and slow speed for subtle change.
// Hue Pendulum - color changes in a wave to the right before reversing direction
static HSV MY_HUE_PENDULUM_math(HSV hsv, uint8_t i, uint8_t time) {
    uint8_t huedelta = 70;
    hsv.h            = hsv.h + scale8(abs8(sin8(time) + (g_led_config.point[i].x) - 128), huedelta);
    return hsv;
}

bool MY_PENDULUM(effect_params_t* params) {
    return effect_runner_i(params, &MY_HUE_PENDULUM_math);
}


// //Starlight/Twinkle effects by @bactaholic
// //-------------------STAR LIGHT -----------------------------------------//
// static void star_light_set_color(int i, effect_params_t* params) {
    // if (!HAS_ANY_FLAGS(g_led_config.flags[i], params->flags)) return;
        // HSV hsv = rgb_matrix_config.hsv;
        // uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
        // hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
        // RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        // rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
// }

// bool STAR_LIGHT(effect_params_t* params) {
    // if (!params->init) {
        // if (scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 5)) % 5 == 0) {
            // star_light_set_color(rand() % DRIVER_LED_TOTAL, params);
        // }
        // return false;
    // }

    // RGB_MATRIX_USE_LIMITS(led_min, led_max);
    // for (int i = led_min; i < led_max; i++) {
        // star_light_set_color(i, params);
    // }
    // return rgb_matrix_check_finished_leds(led_max);
// }

// //-------------------DUAL SAT STAR LIGHT -------------------------------------//
// static void dual_sat_star_light_set_color(int i, effect_params_t* params) {
    // if (!HAS_ANY_FLAGS(g_led_config.flags[i], params->flags)) return;
        // HSV hsv = rgb_matrix_config.hsv;
        // uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
        // hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
        // hsv.s = hsv.s + (rand() % (30 + 1 - -30) + -30);
        // RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        // rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
// }

// bool DUAL_SAT_STAR_LIGHT(effect_params_t* params) {
    // if (!params->init) {
        // if (scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 5)) % 5 == 0) {
            // dual_sat_star_light_set_color(rand() % DRIVER_LED_TOTAL, params);
        // }
        // return false;
    // }

    // RGB_MATRIX_USE_LIMITS(led_min, led_max);
    // for (int i = led_min; i < led_max; i++) {
        // dual_sat_star_light_set_color(i, params);
    // }
    // return rgb_matrix_check_finished_leds(led_max);
// }

// //-------------------DUAL HUE STAR LIGHT -------------------------------------//
// static void dual_hue_star_light_set_color(int i, effect_params_t* params) {
    // if (!HAS_ANY_FLAGS(g_led_config.flags[i], params->flags)) return;
        // HSV hsv = rgb_matrix_config.hsv;
        // uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
        // hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
        // hsv.h = hsv.h + (rand() % (30 + 1 - -30) + -30);
        // RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        // rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
// }

// bool DUAL_HUE_STAR_LIGHT(effect_params_t* params) {
    // if (!params->init) {
        // if (scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 5)) % 5 == 0) {
            // dual_hue_star_light_set_color(rand() % DRIVER_LED_TOTAL, params);
        // }
        // return false;
    // }

    // RGB_MATRIX_USE_LIMITS(led_min, led_max);
    // for (int i = led_min; i < led_max; i++) {
        // dual_hue_star_light_set_color(i, params);
    // }
    // return rgb_matrix_check_finished_leds(led_max);
// }



static HSV MY_SOLID_REACTIVE_CROSS_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    uint16_t effect = tick + dist;
    dx              = dx < 0 ? dx * -1 : dx;
    dy              = dy < 0 ? dy * -1 : dy;
    dx              = dx * 16 > 255 ? 255 : dx * 16;
    dy              = dy * 16 > 255 ? 255 : dy * 16;
    effect += dx > dy ? dy : dx;
    if (effect > 255) effect = 255;
    // hsv.h = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 8) >> 4);	// rainbow
    hsv.h += qsub8(130, effect);
    hsv.v = qadd8(hsv.v, 255 - effect);
    return hsv;
}

bool MY_NEW_CROSS(effect_params_t* params) {
    // return effect_runner_reactive_splash(qsub8(g_last_hit_tracker.count, 1), params, &MY_SOLID_REACTIVE_CROSS_math);	// single
    return effect_runner_reactive_splash(0, params, &MY_SOLID_REACTIVE_CROSS_math); // multi
}



static HSV MY_SOLID_SPLASH_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    uint16_t effect = tick - dist;
    if (effect > 255) effect = 255;
    hsv.h += qsub8(130, effect);
    hsv.v = qadd8(hsv.v, 255 - effect);
    return hsv;
}

bool MY_NEW_SPLASH(effect_params_t* params) {
    // return effect_runner_reactive_splash(qsub8(g_last_hit_tracker.count, 1), params, &MY_SOLID_SPLASH_math);	// single
    return effect_runner_reactive_splash(0, params, &MY_SOLID_SPLASH_math); // multi
}



static HSV MY_SOLID_REACTIVE_NEXUS_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    uint16_t effect = tick - dist;
    if (effect > 255) effect = 255;
    if (dist > 72) effect = 255;
    if ((dx > 8 || dx < -8) && (dy > 8 || dy < -8)) effect = 255;
    // hsv.h = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 8) >> 4) + dy / 4;	// rainbow
    // hsv.h = rgb_matrix_config.hsv.h + dy / 4;
    hsv.h += qsub8(130, effect);
    hsv.v = qadd8(hsv.v, 255 - effect);
    return hsv;
}

bool MY_NEW_NEXUS(effect_params_t* params) {
    // return effect_runner_reactive_splash(qsub8(g_last_hit_tracker.count, 1), params, &MY_SOLID_REACTIVE_NEXUS_math);	// single
    return effect_runner_reactive_splash(0, params, &MY_SOLID_REACTIVE_NEXUS_math); // multi
}



static HSV MY_SOLID_REACTIVE_math(HSV hsv, uint16_t offset) {
    // hsv.h = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 8) >> 4);	// rainbow
    hsv.h += qsub8(130, offset); 			// RGB_MATRIX_SOLID_REACTIVE - keep only this line (and/or rainbow if wanted)
    hsv.v = scale8(255 - offset, hsv.v);	// RGB_MATRIX_SOLID_REACTIVE_SIMPLE - keep only this line (and/or rainbow if wanted)
    return hsv;
}

bool MY_KEY_REACTIVE(effect_params_t* params) {
    return effect_runner_reactive(params, &MY_SOLID_REACTIVE_math);
}



#define _MAX(a, b) ((a) > (b) ? (a) : (b))
#define _MIN(a, b) ((a) < (b) ? (a) : (b))
#define _CLAMP(v, min, max) (_MIN(_MAX(v, min), max))

#define _RGBHEX_R(rgb) ((rgb) >> 16)
#define _RGBHEX_G(rgb) (((rgb) >> 8) & 0xFF)
#define _RGBHEX_B(rgb) ((rgb) & 0xFF)

bool ONLINE_NEW_SPLASH(effect_params_t* params) {
	RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV hsv  = rgb_matrix_config.hsv;
    hsv.s = 255;
    RGB base_rgb = rgb_matrix_hsv_to_rgb(hsv);
    hsv.h += rgb_matrix_config.speed;
    hsv.s = 255;
    hsv.v = 255;
    RGB wave_rgb = rgb_matrix_hsv_to_rgb(hsv);
	
	int wave_width;
	wave_width = rgb_matrix_get_sat();
	if (wave_width < 50) {
		wave_width = 50;
	}
	if (wave_width > 200) {
		wave_width = 200;
	}
	
	for (uint8_t i = led_min; i < led_max; i++) {
		RGB_MATRIX_TEST_LED_FLAGS();
		uint8_t A          = 0;
		uint8_t hit_count  = g_last_hit_tracker.count;
		uint8_t wave_speed = 50;

		/* result = (A * wave_color) + ((1 - A) * base_color) */
		for (uint8_t j = 0; j < hit_count; j++) {
			uint16_t tick             = g_last_hit_tracker.tick[j];
			uint16_t wave_travel_dist = scale16by8(tick, qadd8(wave_speed, 1));  // a * (b/255)
			uint16_t dx               = g_led_config.point[i].x - g_last_hit_tracker.x[j];
			uint16_t dy               = g_led_config.point[i].y - g_last_hit_tracker.y[j];
			uint8_t  key_dist         = sqrt16(dx * dx + dy * dy);
			uint16_t offset           = wave_travel_dist - key_dist;

			bool before_wave = offset > wave_width;
			bool after_wave = wave_travel_dist < key_dist;
			bool inside_wave = !before_wave && !after_wave;

			if (inside_wave) {
				A = qadd8(A, qsub8(
					0xFF, _CLAMP(
						255 * offset / wave_width,
						0, 0xFF
					)
				));
			}
		}

		RGB rgb = {
			.r = scale8(wave_rgb.r, A) + scale8(base_rgb.r, 0xFF - A),
			.g = scale8(wave_rgb.g, A) + scale8(base_rgb.g, 0xFF - A),
			.b = scale8(wave_rgb.b, A) + scale8(base_rgb.b, 0xFF - A),
		};
		rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
	}

	return rgb_matrix_check_finished_leds(led_max);
}

#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED







// // rgb_matrix_mode(RGB_MATRIX_CUSTOM_my_cool_effect);

// // !!! DO NOT ADD #pragma once !!! //

// // Step 1.
// // Declare custom effects using the RGB_MATRIX_EFFECT macro
// // (note the lack of semicolon after the macro!)
// RGB_MATRIX_EFFECT(my_cool_effect)
// // RGB_MATRIX_EFFECT(my_cool_effect2)
// RGB_MATRIX_EFFECT(custom_testing)

// // Step 2.
// // Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
// #ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// // e.g: A simple effect, self-contained within a single method
// static bool my_cool_effect(effect_params_t* params) {
  // RGB_MATRIX_USE_LIMITS(led_min, led_max);
  // for (uint8_t i = led_min; i < led_max; i++) {
    // rgb_matrix_set_color(i, 0xff, 0xff, 0x00);
  // }
  // return rgb_matrix_check_finished_leds(led_max);
// }

// // // e.g: A more complex effect, relying on external methods and state, with
// // // dedicated init and run methods
// // static uint8_t some_global_state;
// // static void my_cool_effect2_complex_init(effect_params_t* params) {
  // // some_global_state = 1;
// // }
// // static bool my_cool_effect2_complex_run(effect_params_t* params) {
  // // RGB_MATRIX_USE_LIMITS(led_min, led_max);
  // // for (uint8_t i = led_min; i < led_max; i++) {
    // // rgb_matrix_set_color(i, 0xff, some_global_state++, 0xff);
  // // }
  // // return rgb_matrix_check_finished_leds(led_max);
// // }
// // static bool my_cool_effect2(effect_params_t* params) {
  // // if (params->init) my_cool_effect2_complex_init(params);
  // // return my_cool_effect2_complex_run(params);
// // }

// static HSV MY_SOLID_REACTIVE_CROSS_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    // uint16_t effect = tick + dist;
    // dx              = dx < 0 ? dx * -1 : dx;
    // dy              = dy < 0 ? dy * -1 : dy;
    // dx              = dx * 16 > 255 ? 255 : dx * 16;
    // dy              = dy * 16 > 255 ? 255 : dy * 16;
    // effect += dx > dy ? dy : dx;
    // if (effect > 255) effect = 255;
    // hsv.h = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 8) >> 4);
    // hsv.v = qadd8(hsv.v, 255 - effect);
    // return hsv;
// }

// bool CUSTOM_TESTING(effect_params_t* params) {
    // return effect_runner_reactive_splash(0, params, &MY_SOLID_REACTIVE_CROSS_math);
// }
// #endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS

