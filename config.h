#pragma once

// Common QMK settings
#define TAP_CODE_DELAY 5
#define TAP_HOLD_CAPS_DELAY 25
#define GRAVE_ESC_SHIFT_OVERRIDE
#define USB_SUSPEND_WAKEUP_DELAY 2000
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

// Space saving options
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_MUSIC_MODE
//#define LAYER_STATE_8BIT
//#define NO_ACTION_ONESHOT

// Tap-hold settings
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 220
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM 110
#define QUICK_TAP_TERM_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define IS_COMMAND() (get_mods() == MOD_MASK_CTRL)

#ifdef COMBO_ENABLE
#	define COMBO_TERM 30
#	define COMBO_ONLY_FROM_LAYER 0
#endif

#ifdef SPLIT_KEYBOARD
#	define SPLIT_WATCHDOG_ENABLE
#	ifdef CONVERT_TO_ELITE_PI
#		define USB_VBUS_PIN 19U
#	else
#		define SPLIT_USB_DETECT
#	endif
#	ifdef OLED_ENABLE
#		define SPLIT_OLED_ENABLE
#		define SPLIT_MODS_ENABLE
#		define SPLIT_LED_STATE_ENABLE
#		define SPLIT_LAYER_STATE_ENABLE
#	elif RGB_MATRIX_ENABLE
#		define SPLIT_MODS_ENABLE
#		define SPLIT_LED_STATE_ENABLE
#		define SPLIT_LAYER_STATE_ENABLE
#	endif
#endif

#ifdef MOUSEKEY_ENABLE
#	define MOUSEKEY_DELAY 0			// Delay between pressing a key and cursor movement
#	define MOUSEKEY_INTERVAL 15		// Time between cursor movements in milliseconds
#	define MOUSEKEY_MOVE_DELTA 10	// Step size for acceleration
#	define MOUSEKEY_MAX_SPEED 9
#	define MOUSEKEY_TIME_TO_MAX 90
#	define MOUSEKEY_WHEEL_DELAY 16
#	define MOUSEKEY_WHEEL_INTERVAL 30
#	define MOUSEKEY_WHEEL_MAX_SPEED 10
#	define MOUSEKEY_WHEEL_TIME_TO_MAX 95
#endif

#ifdef OLED_ENABLE
#	define OLED_TIMEOUT 10000
#	define OLED_BRIGHTNESS 180
#	undef  OLED_FONT_H
#	define OLED_FONT_H "oled/oledfont.c"
#endif

// Layout macros
#ifndef __ASSEMBLER__
#	include "layout.h"
#endif