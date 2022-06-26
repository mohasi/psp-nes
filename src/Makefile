PSP_EBOOT_TITLE = PSP NES
PSP_EBOOT_DISC_ID = ULES00001
OBJS = main.o nes.o callback.o
LIBS =

CFLAGS = -Wall -Wextra -Wno-unused-parameter -O3
CXXFLAGS = $(CFLAGS) -std=c++14 -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_ICON = ../res/ICON0.PNG
PSP_EBOOT_UNKPNG = ../res/PIC0.PNG
PSP_EBOOT_PIC1 = ../res/PIC1.PNG

include ../master.mak