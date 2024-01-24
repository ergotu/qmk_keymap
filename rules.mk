# Disable unused features
#LEADER_ENABLE = no
#COMMAND_ENABLE = no
#TERMINAL_ENABLE = no
#KEY_LOCK_ENABLE = no
#SLEEP_LED_ENABLE = no
#VELOCIKEY_ENABLE = no
MAGIC_ENABLE = no
CONSOLE_ENABLE = no
UNICODE_ENABLE = no
SPACE_CADET_ENABLE = no

# Common features
COMBO_ENABLE = no
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
BOOTMAGIC_ENABLE = yes
CAPS_WORD_ENABLE = yes

VPATH += $(USER_PATH)/oled $(USER_PATH)/features
SRC += ergotu.c achordion.c

ifeq ($(strip $(MCU)), atmega32u4)
	LTO_ENABLE = yes
	TOP_SYMBOLS = yes
	BOOTLOADER = atmel-dfu
else
	SWAP_HANDS_ENABLE = yes
	DEBOUNCE_TYPE = asym_eager_defer_pk
#	EEPROM_DRIVER = transient
endif

ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), splitkb/elora/rev1))
	SWAP_HANDS_ENABLE = no

	VIA_ENABLE = yes
	VIAL_ENABLE = yes
	ENCODER_MAP_ENABLE = no
endif

# Split boards
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), splitkb/aurora/lily58/rev1 splitkb/aurora/corne/rev1))
	# OPT_DEFS += -DAUTOCORRECT
	# SRC += autocorrect.c
endif

# RGB boards
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), splitkb/aurora/corne/rev1))
	RGB_MATRIX_ENABLE = yes
endif

# OLED
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), splitkb/aurora/lily58/rev1))
	OLED_ENABLE = yes
	WPM_ENABLE = yes
	ifneq ($(strip $(OLED)),)
		OPT_DEFS += -D${OLED}
		SRC += oled-icons.c oled-luna.c
	else
		SRC += oled-icons.c oled.c
	endif
endif

# Encoders
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), splitkb/aurora/lily58/rev1))
	ENCODERS_ENABLE = yes
endif

# Cirque Trackpad
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), splitkb/aurora/lily58/rev1))
	POINTING_DEVICE_ENABLE = yes
	POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c
endif