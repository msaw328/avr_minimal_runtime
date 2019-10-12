.PHONY := dir all clear
.DEFAULT_GOAL = all

# build directories
DIRS := build obj obj/rt obj/cc

# AVR toolchain
CC := avr-gcc
AS := avr-as
LD := avr-ld

# flags
# atmega8a is avr4 according to https://www.microchip.com/webdoc/AVRLibcReferenceManual/using_tools_1using_avr_gcc_mach_opt.html
CC_FLAGS := -std=c99 -I./include -c -Wall -Werror -mmcu=atmega8 -Os -nostartfiles
AS_FLAGS := -mmcu=avr4
LD_FLAGS := -T script.ld

# source files for assembly and C
CC_SRC_FILES := src/main.c
AS_SRC_FILES := rt/runtime.s rt/vectors.s

# object files
CC_OBJ_FILES := $(CC_SRC_FILES:src/%.c=obj/cc/%.o)
AS_OBJ_FILES := $(AS_SRC_FILES:rt/%.s=obj/rt/%.o)

# ~~~~~object files and linking
obj/cc/%.o: src/%.c ;
	$(CC) $(CC_FLAGS) $^ -o $@

# have to cd to src and then preface target/sources with ../ otherwise it breaks includes in assembly files
obj/rt/%.o: rt/%.s ;
	cd rt && $(AS) $(AS_FLAGS) ../$^ -o ../$@

build/firmware.elf: $(AS_OBJ_FILES) $(CC_OBJ_FILES);
	$(LD) $(LD_FLAGS) $^ -o $@

# ~~~~~phony targets - utility
dir:
	mkdir -p $(DIRS)

clear:
	rm -rf $(DIRS)

all: dir build/firmware.elf
