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
#COMBO_ENABLE = yes
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
BOOTMAGIC_ENABLE = yes

VPATH += $(USER_PATH)/oled
SRC += ergotu.c

ifeq ($(strip $(MCU)), atmega32u4)
	LTO_ENABLE = yes
	TOP_SYMBOLS = yes
	BOOTLOADER = atmel-dfu
else
	SWAP_HANDS_ENABLE = yes
	DEBOUNCE_TYPE = asym_eager_defer_pk
#	EEPROM_DRIVER = transient
endif

# Split boards
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), splitkb/aurora/lily58/rev1 crkbd/rev1))
	# OPT_DEFS += -DAUTOCORRECT
	# SRC += autocorrect.c
endif

# RGB boards
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), ''))
	RGB_MATRIX_ENABLE = yes
	RGB_MATRIX_CUSTOM_USER = yes
	SRC += rgb-matrix.c
endif

# OLED
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), splitkb/aurora/lily58/rev1))
	OLED_ENABLE = yes
	WPM_ENABLE = yes
	ifneq ($(strip $(OLED)),)
		OPT_DEFS += -D${OLED}
		SRC += oled-icons.c oled-luna.c
	else
		SRC += oled-icons.c oled-bongocat.c
	endif
endif

# Encoders
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), splitkb/aurora/lily58/rev1))
	ENCODERS_ENABLE = yes
endif