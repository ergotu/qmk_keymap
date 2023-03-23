#include QMK_KEYBOARD_H

// Init and rendering calls
oled_rotation_t oled_init_user(oled_rotation_t const rotation) {
	return OLED_ROTATION_270;
}

bool oled_task_user(void) {
	extern void render_mod_status(void);
	if (is_keyboard_master()) {
		render_mod_status();
	};
	return false;
}