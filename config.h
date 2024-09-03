#pragma once

// Common QMK settings
#define USB_SUSPEND_WAKEUP_DELAY 2000
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1500U
// Space saving options
#define LAYER_STATE_16BIT
#define NO_ACTION_ONESHOT
// Tap-hold settings
#define TAPPING_TERM 230
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define QUICK_TAP_TERM TAPPING_TERM - 100

#ifdef SPLIT_KEYBOARD
#   define EE_HANDS
#	define SPLIT_WATCHDOG_ENABLE
#	ifdef CONVERT_TO_ELITE_PI
#		define USB_VBUS_PIN 19U
#	else
#		define SPLIT_USB_DETECT
#	endif
#   ifdef POINTING_DEVICE_ENABLE
#       undef SPLIT_OLED_ENABLE
#       define SPLIT_POINTING_ENABLE
#       define POINTING_DEVICE_RIGHT
#       define CIRQUE_PINNACLE_CURVED_OVERLAY
#       define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_2X
#       define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_ABSOLUTE_MODE
#       define CIRQUE_PINNACLE_TAP_ENABLE
#       define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
#       define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#		define SPLIT_MODS_ENABLE
#		define SPLIT_LED_STATE_ENABLE
#		define SPLIT_LAYER_STATE_ENABLE
#	endif
#endif

#ifdef COMBO_ENABLE
#   define COMBO_TERM 25
#   define EXTRA_SHORT_COMBOS
#   define COMBO_SHOULD_TRIGGER
#   define COMBO_ONLY_FROM_LAYER 0
#endif

#ifdef MOUSEKEY_ENABLE
#   define MOUSEKEY_OVERLAP_RESET
#   define MOUSEKEY_OVERLAP_INTERVAL   64
#   define MOUSEKEY_DELAY               0 // Delay between pressing a key and cursor movement
#   define MOUSEKEY_INTERVAL           16 // Time between cursor movements in milliseconds
#   if defined (MK_KINETIC_SPEED)
#       define MOUSEKEY_MOVE_DELTA     25
#       define MOUSEKEY_INITIAL_SPEED 200
#       define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS 4
#   else // Default accelerated
#       define MOUSEKEY_MAX_SPEED      10
#       define MOUSEKEY_MOVE_DELTA     10 // Step size for acceleration
#       define MOUSEKEY_TIME_TO_MAX    80
#   endif
#   define MOUSEKEY_WHEEL_DELAY        16
#   define MOUSEKEY_WHEEL_INTERVAL     30
#   define MOUSEKEY_WHEEL_MAX_SPEED    10
#   define MOUSEKEY_WHEEL_TIME_TO_MAX  95
#endif

#ifdef OLED_ENABLE
#   define OLED_TIMEOUT 10000
#   define OLED_BRIGHTNESS 180
#   undef OLED_FONT_H
#   define OLED_FONT_H "oled_font.c"
#endif

#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_KEYPRESSES
#   define ENABLE_RGB_MATRIX_CANDY_TAP
#   define ENABLE_RGB_MATRIX_CANDY_RAIN
#   define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CUSTOM_CANDY_TAP
#   define DEF_MODE RGB_MATRIX_DEFAULT_MODE
#   define CMK_MODE RGB_MATRIX_CUSTOM_CANDY_RAIN
#endif

// Layout macros
#ifndef __ASSEMBLER__
#   include "layout.h"
#endif
