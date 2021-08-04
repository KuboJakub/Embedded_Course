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
LINKER_FILE = ../msp432p401r.lds #linking file - describes physical mem layout
CPU = -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16
ARCH = -march=armv7e-m -mthumb
SPECS = --specs=nosys.specs

# Compilation flags depending from choosen platform
CFLAGS = -O0 -std=c99 -Wall -g
ifeq ($(PLATFORM),HOST)
    CC = gcc                           #native compiler
else
    CC = arm-none-eabi-gcc             #cross-compiler
    LDFLAGS = -Wl,-T $(LINKER_FILE) -Wl,-Map=Linking_map.map # use linker file + print linking map
    CFLAGS += $(CPU) $(ARCH) $(SPECS)
endif


# Pattern to create preprocessed file *.i for any *.c file
%.i : %.c
	$(CC) -E -D$(PLATFORM) $(CFLAGS) $(INCLUDES) $< -o $@



# Pattern to create assambly *.s/*.asm - ways:
#                    from object file by using 'objdump' for HOST
#                    from *.c code for MSP432 platform
ifeq ($(PLATFORM),HOST)
    DODIS = objdump -S main.o
else
    DODIS = $(CC) -S -D$(PLATFORM) $(CFLAGS) $(INCLUDES) $< -o $@
endif
%.asm : %.o main.out
	$(DODIS)


# Pattern to create object file *.o for any *.c file
%.o : %.c
	$(CC) -c -D$(PLATFORM) $(INCLUDES) $(CFLAGS) $< -o $@


# Creates executable for main program
main.out : main.c $(OBJS)
	$(CC) -D$(PLATFORM) $(CFLAGS) $(INCLUDES) $(SOURCES) main.c $(LDFLAGS) -o main.out



# Compiles all files to objects but does not link them
OBJS = $(SOURCES:.c=.o)       # create names of new files
.PHONY:compile-all
compile-all : $(OBJS)         # thanks to dependency generate %.o files


# Compiles and link final executable dependent on platform
.PHONY:build
build : main.out



# Deletes all compiled files
.PHONY:clean
clean:
	rm -f *.o *.asm *.i *.out *.map
	
