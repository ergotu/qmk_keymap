#include "ergotu.h"
#include "features/achordion.h"

#if (defined TAPPING_TERM_PER_KEY || defined PERMISSIVE_HOLD_PER_KEY)
static uint_fast16_t tap_timer = 0;
#endif


#ifdef TAPPING_TERM_PER_KEY
// Scale tapping term to short key press interval to avoid false trigger.
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
	return IS_HOME_ROW() && IS_TYPING() ? IS_TYPING_TERM : TAPPING_TERM;
}
#endif


#ifdef QUICK_TAP_TERM_PER_KEY
// Reduce quick tap term for thumb keys
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
	return IS_THUMB_ROW() ? QUICK_TAP_TERM / 2 : QUICK_TAP_TERM;
}
#endif


#ifdef PERMISSIVE_HOLD_PER_KEY
// Select Shift mod tap immediately when another key is pressed and released.
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
	return MODTAP_BIT(keycode) & MOD_MASK_SHIFT && !IS_TYPING() ? true : false;
}
#endif


#ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
// Select hold immediately with another key for layer tap 1 and higher.
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
	return IS_LAYER_TAP(keycode) ? true : false;
}
#endif

// Send custom hold keycode for mod tap.
static inline bool process_tap_hold(uint16_t hold_keycode, keyrecord_t *record) {
	if (!record->tap.count) {
		tap_code16(hold_keycode);
		return false;
	}
	return true;
}

void matrix_scan_user(void) {
  achordion_task();
}

bool process_record_user(uint16_t const keycode, keyrecord_t *record) {
	if (!process_achordion(keycode, record)) { return false; }
	if (record->event.pressed) {
	#if (defined TAPPING_TERM_PER_KEY || defined PERMISSIVE_HOLD_PER_KEY)
		tap_timer = timer_read();
	#endif

	#ifdef AUTOCORRECT
		extern bool process_autocorrect(uint16_t keycode, keyrecord_t* record);
		if (!process_autocorrect(keycode, record)) {
			return false;
		}
	#endif

	#ifdef CAPS_UNLOCK
		extern bool process_caps_unlock(uint16_t keycode, keyrecord_t *record);
		if (!process_caps_unlock(keycode, record)) {
			return false;
		}
	#endif
	
		// Clipboard shortcuts.
		switch(keycode) {
			case TH_SLSH: return process_tap_hold(Z_UND, record);
			case TH_DOT:  return process_tap_hold(Z_CUT, record);
			case TH_COMM: return process_tap_hold(Z_CPY, record);
			case TH_M:    return process_tap_hold(Z_PST, record);
		}
	}
	return true;
}

#ifdef ENCODER_MAP_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  return false;
}

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = {
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    },
    [1] = {
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    },
    [2] = {
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    },
    [3] = {
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    },
    [4] = {
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    },
    [5] = {
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    },
    [6] = {
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    }
};
#endif