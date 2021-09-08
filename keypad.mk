# Shell PATH
KEYPADPATH = ./keypad

# RT Shell files.
KEYPADSRC = $(KEYPADPATH)/keypad.c

KEYPADINC = $(KEYPADPATH)

# Shared variables
ALLCSRC += $(KEYPADSRC)
ALLINC  += $(KEYPADINC)