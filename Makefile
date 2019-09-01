.PHONY := dir all clear
.DEFAULT_GOAL = all

SRC_FILES := src/main.s src/runtime.s src/vectors.s
OBJ_FILES := $(SRC_FILES:src/%.s=obj/%.o)

AS := avr-as # use the avr toolchain
LD := avr-ld

# atmega8a is avr4 according to https://www.microchip.com/webdoc/AVRLibcReferenceManual/using_tools_1using_avr_gcc_mach_opt.html
AS_FLAGS := -mmcu=avr4
LD_FLAGS := -T script.ld

# have to cd to src and then preface target/sources with ../ otherwise it breaks includes in assembly files
obj/%.o: src/%.s ;
	cd src && $(AS) $(AS_FLAGS) ../$^ -o ../$@

dir:
	mkdir -p build obj

build/firmware.elf: $(OBJ_FILES) ;
	$(LD) $(LD_FLAGS) $^ -o $@

all: dir build/firmware.elf

clear: ;
	rm obj bin -rf
