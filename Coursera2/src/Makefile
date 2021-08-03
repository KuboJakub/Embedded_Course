#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile for native and crosscompilation for MSP432 platform.
# Automatic vars:
# 		$@ - use the same name as is the name of the target
# 		$< - first prerequsit
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
# 		<FILE>.i - generates preprocessed output of C-code
# 		<FILE>.asm - generates assembly output of C-code
# 		<FILE>.o - generates object files for C-code, no linking
# 		compile-all - compiles all objects, DO NOT LINK them
# 		build - compiles all objecst and link them into one executable
# 		clean - removes all outputs from make target executions
#
# Platform Overrides:
# 		PLATFORM - supported platforms for native and crosscompilation (HOST,MSP432)
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

# Architectures Specific Flags (just for ARM)
LINKER_FILE = msp432p401r.lds #linking file - describes physical mem layout
CPU = -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16
ARCH = -march=armv7e-m -mthumb
SPECS = --specs=nosys.specs


CFLAGS = -O0 -std=c99 -Wall -Werror -g
ifeq ($(PLATFORM),HOST)
    CC = gcc                           #native compiler
    CPPFLAGs = 
else
    CC = arm-none-eabi-gcc             #cross-compiler
    LDFLAGS = -Wl,-T $(LINKER_FILE)
    CFLAGS += $(CPU) $(ARCH) $(SPEC)
    CPPFLAGs =
endif


# pattern to create preprocessed file *.i for any *.c file
%.i : %.c
	$(CC) -E -D$(PLATFORM) $(CFLAGS) $(INCLUDES) $< -o $@


# pattern to create assambly *.s/*.asm from object file by using 'objdump'
%.asm : %.o
	objdump -S $<

# pattern to create object file *.o for any *.c file
%.o : %.c
        $(CC) -c -D$(PLATFORM) $< $(INCLUDES) $(CFLAGS) -o $@

# Compiles all files to objects but does not link them
OBJS = $(SOURCES:.c=.o)
.PHONY:compile-all
compile-all : $(OBJS)




.PHONY:clean
clean:
	rm -f *.o *.asm *.i
	






main.out: main.c
	gcc -D$(PLATFORM) $(INCLUDES) main.c memory.c -o main.out
