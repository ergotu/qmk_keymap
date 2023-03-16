ENCODER_ENABLE = yes

VPATH += $(USER_PATH)/oled 
SRC += ergotu.c

# OLED
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), splitkb/aurora/lily58/rev1))
	OLED_ENABLE = yes
	ifneq ($(strip $(OLED)),)
		OPT_DEFS += -D${OLED}
		SRC += oled-icons.c oled-luna.c
	else
		SRC += oled-icons.c oled-bongocat.c
	endif
endif