TARGET ?= E0

BUILD := build/$(TARGET)

CC := gcc
CFLAGS := -O2 -Wall -Wextra -Wpedantic

U64_PREFIX  := mips-linux-gnu-
U64_CC      := $(U64_PREFIX)gcc
U64_LD      := $(U64_PREFIX)ld
U64_AR      := $(U64_PREFIX)ar
U64_OBJCOPY := $(U64_PREFIX)objcopy
U64_ARCH    := -mabi=32 -march=vr4300 -mfix4300
U64_OPT     := -Os
U64_WARN    := -Wall -Wextra -Werror=implicit-function-declaration
U64_CPPFLAGS = -Ilibultra/include -Iinclude -I. -I$(BUILD) -D_ULTRA64
U64_CFLAGS = $(U64_ARCH) -mno-abicalls -fno-PIC -mno-check-zero-division -fno-builtin -ffast-math -ftrapping-math -fno-associative-math -fsingle-precision-constant -G 0 $(U64_OPT) $(U64_WARN)
U64_ASFLAGS = $(U64_ARCH) -mno-abicalls -fno-PIC -G 0 $(U64_OPT)
U64_ARMIPSFLAGS = -strequ BUILD $(BUILD)

IDO_CC      := $(IDO)/bin/cc
IDO_ARCH    := -mips2
IDO_OPT     :=
IDO_WARN    := -fullwarn -prototypes
IDO_CFLAGS = $(IDO_ARCH) -non_shared -Wab,-r4300_mul -signed -Xcpluscomm -G 0 $(IDO_OPT) $(IDO_WARN)
IDO_ASFLAGS = $(IDO_ARCH) -non_shared -Wab,-r4300_mul -Xcpluscomm -G 0 $(IDO_OPT)

LIBULTRA_ARCH   := -mips2
LIBULTRA_OPT    :=
LIBULTRA_WARN   := -fullwarn -prototypes
LIBULTRA_CPPFLAGS = -Ilibultra/include -Ilibultra/src/include -D_ULTRA64
LIBULTRA_CFLAGS = $(LIBULTRA_ARCH) -non_shared -Wab,-r4300_mul -G 0 $(LIBULTRA_OPT) $(LIBULTRA_WARN)
LIBULTRA_ASFLAGS = $(LIBULTRA_ARCH) -non_shared -G 0 $(LIBULTRA_OPT)
LIBULTRA_ARMIPSFLAGS = -strequ BUILD $(BUILD)

APP := app

ifeq ($(TARGET),J0)
	ICODE := NSMJ
	VERSION := 0
	REVISION := 199606
	U64_CPPFLAGS += -DJAPANESE
endif
ifeq ($(TARGET),E0)
	ICODE := NSME
	VERSION := 0
	REVISION := 199609
	U64_CPPFLAGS += -DENGLISH -DNEWVOICE
endif
ifeq ($(TARGET),G0)
	ICODE := NSMG
	VERSION := 0
	REVISION := 199610
	U64_CPPFLAGS += -DENGLISH -DNEWVOICE -DGATEWAY
endif
ifeq ($(TARGET),DD)
	ICODE := DSMJ
	VERSION := 0
	REVISION := 199611
	U64_CPPFLAGS += -DJAPANESE -DDISK
endif
ifeq ($(TARGET),P0)
	ICODE := NSMP
	VERSION := 0
	REVISION := 199703
	U64_CPPFLAGS += -DMULTILANG -DNEWVOICE
endif
ifeq ($(TARGET),J3)
	ICODE := NSMJ
	VERSION := 3
	REVISION := 199707
	U64_CPPFLAGS += -DJAPANESE -DNEWVOICE -DMOTOR
endif
ifeq ($(TARGET),C3)
	ICODE := NSMC
	VERSION := 3
	REVISION := 200311
	U64_CPPFLAGS += -DCHINESE -DNEWVOICE -DMOTOR
endif

ifeq ($(TARGET),DD)
	OUTPUT := $(BUILD)/$(APP).ndd
else
	OUTPUT := $(BUILD)/$(APP).z64
endif

TITLE := redire

ifneq ($(filter J0 E0,$(TARGET)),)
	IDO_OPT := -g
else
	IDO_OPT := -O2
endif

U64_CPPFLAGS += -DREVISION=$(REVISION)
LIBULTRA_CPPFLAGS += -DREVISION=$(REVISION)
LIBULTRA_ARMIPSFLAGS += -equ REVISION $(REVISION)

ROMHEADER   := libultra/src/PR/romheader
BOOT        := $(BUILD)/libultra/src/PR/Boot
FONT        := libultra/src/PR/font

TOOLS := \
	tools/fixsym \
	tools/fixabi \
	tools/makerom \
	tools/makedisk \
	tools/nrdc \
	tools/hbheader \
	tools/sbc \
	tools/slienc \
	tools/videnc \
	tools/symext \
	tools/texture \
	tools/swap

.PHONY: default
default: $(OUTPUT)

.PHONY: dist
dist: $(BUILD)/$(APP).bps

include dep.mk

.PHONY: dep
dep: $(DEP)

.PHONY: clean
clean:
	rm -f -r build

.PHONY: clobber
clobber: clean
	rm -f -r build $(TOOLS) tools/__pycache__ tools/*.pyc $(DEP)

$(BUILD)/data/dolphin.o: data/dolphin.dll data/disc.rvz

$(BUILD)/src/%.data.o $(BUILD)/src/audio/data.o $(BUILD)/src/audio/work.o $(BUILD)/data/%.o $(BUILD)/shape/%.o $(BUILD)/stage/%.o: U64_CFLAGS = $(U64_ARCH) -mno-abicalls -fno-PIC -fno-common -fno-zero-initialized-in-bss -fno-toplevel-reorder -G 0 $(U64_WARN)

$(BUILD)/libultra/src/libc/bcopy.o: LIBULTRA_OPT := -O2
$(BUILD)/libultra/src/libc/bzero.o: LIBULTRA_OPT := -O2
$(BUILD)/libultra/src/PR/Boot.o: LIBULTRA_OPT := -O2

$(BUILD)/libultra/src/gu/cosf.o: U64_CFLAGS += -fno-strict-aliasing
$(BUILD)/libultra/src/gu/sinf.o: U64_CFLAGS += -fno-strict-aliasing
$(BUILD)/libultra/src/os/kdebugserver.o: U64_CFLAGS += -fno-strict-aliasing
$(BUILD)/libultra/src/rmon/xldtob.o: U64_CFLAGS += -fno-single-precision-constant
$(BUILD)/libultra/src/rmon/xprintf.o: U64_CFLAGS += -fno-strict-aliasing

$(BUILD)/data/%.o: data/%.bin

$(BUILD)/data/gfx.elf:          ADDRESS := 0x02000000
$(BUILD)/shape/global/%.elf:    ADDRESS := 0x03000000
$(BUILD)/shape/player/%.elf:    ADDRESS := 0x04000000
$(BUILD)/shape/1%.elf:          ADDRESS := 0x05000000
$(BUILD)/shape/2%.elf:          ADDRESS := 0x06000000
$(BUILD)/stage/%.elf:           ADDRESS := 0x07000000
$(BUILD)/shape/3%.elf:          ADDRESS := 0x08000000
$(BUILD)/data/texture/%.elf:    ADDRESS := 0x09000000
$(BUILD)/data/back/%.elf:       ADDRESS := 0x0A000000
$(BUILD)/data/weather/%.elf:    ADDRESS := 0x0B000000
$(BUILD)/data/video/%.elf:      ADDRESS := 0x01000000

$(BUILD)/$(APP).bps: $(OUTPUT)
	flips $(DONOR)/U$(ICODE)0$(VERSION)$(suffix $<) $< $@

build/C3/$(APP).z64: $(BUILD)/$(APP).elf $(ROMHEADER) $(BOOT) $(FONT) tools/makerom
	tools/makerom -r $@ -h $(ROMHEADER) -b $(BOOT) -F $(FONT) -a 14 $<

$(BUILD)/%.z64: $(BUILD)/%.elf $(ROMHEADER) $(BOOT) $(FONT) tools/makerom tools/nrdc tools/hbheader
	tools/makerom -r $@ -h $(ROMHEADER) -b $(BOOT) -F $(FONT) -s 1024 -f 0xff $<
	tools/nrdc -b -t "$(TITLE)" -i $(ICODE) -v $(VERSION) $@
	tools/hbheader -eep4k -p1 gc -p2 gc -p3 gc -p4 gc $@

$(BUILD)/%.ndd: $(BUILD)/%.elf tools/makedisk
	tools/makedisk -R $@ $<

$(BUILD)/$(APP).elf: $(BUILD)/$(APP).ld $(OBJ) $(EXEC_OBJ) $(DATA) $(SZP) $(SHAPE_SZP) $(SHAPE_DATA) $(TEXTURE_SZP) $(STAGE_SZP) $(STAGE_DATA) $(VID) $(AUDIO_DATA)
	$(U64_LD) -N -Map $(@:.elf=.map) -T$(BUILD)/$(APP).ld -o $@

$(BUILD)/$(APP).ld: spec tools/spec
	@mkdir -p $(dir $@)
	BUILD=$(BUILD) tools/spec $(U64_CPPFLAGS) -DNEWSPEC -o $@ $<

$(BUILD)/code.o: $(CODE_OBJ) $(AUDIO_OBJ) $(BUILD)/libultra/libultra_rom.a
	$(U64_LD) -L$(BUILD)/libultra -Llib -Trel.ld -r -o $@ $(CODE_OBJ) $(AUDIO_OBJ) -lultra_rom -lgcc

$(BUILD)/ulib.o: $(ULIB_OBJ)
	$(U64_LD) -Trel.ld -r -o $@ $(ULIB_OBJ)

$(BUILD)/%.szp.s: %.bin tools/slienc
	@mkdir -p $(dir $@)
	tools/slienc $< $(@:.szp.s=.szp) > $@

$(BUILD)/%.szp.h: $(BUILD)/%.elf tools/symext
	tools/symext $< > $@

$(BUILD)/%.szp.s: $(BUILD)/%.elf tools/slienc
	tools/slienc $< $(@:.szp.s=.szp) > $@

$(BUILD)/%.vid.s: $(BUILD)/%.elf tools/videnc
	tools/videnc $< $(@:.vid.s=.vid) > $@

$(BUILD)/%.elf: $(BUILD)/%.o
	$(U64_LD) -Tdata $(ADDRESS) -Telf.ld -o $@ $<

$(BUILD)/%.o: %.asm
	@mkdir -p $(dir $@)
	armips $(U64_ARMIPSFLAGS) -sym $(@:.o=.sym) $<
	$(U64_CC) -I$(BUILD) $(U64_ASFLAGS) -c -o $@ $(<:.asm=.s)

$(BUILD)/%.o: %.c
	@mkdir -p $(dir $@)
	$(U64_CC) $(U64_CPPFLAGS) $(U64_CFLAGS) -MMD -MP -c -o $@ $<

$(BUILD)/src/exec.o: intel/share.s build/intel/proclist.s
$(BUILD)/src/exec.o: build/intel/init.bin build/intel/proc.bin
$(BUILD)/%.o: %.s
	@mkdir -p $(dir $@)
	$(U64_CC) -Iinclude $(U64_ASFLAGS) -c -o $@ $<

$(BUILD)/%.o: %.sx
	@mkdir -p $(dir $@)
	$(U64_CC) $(U64_CPPFLAGS) $(U64_ASFLAGS) -MMD -MP -c -o $@ $<

$(IDO_C): $(BUILD)/%.o: %.c
	@mkdir -p $(dir $@)
	@rm -f $@ $(@:.o=.d)
	$(IDO_CC) -I$(IDO)/include $(U64_CPPFLAGS) $(IDO_CFLAGS) -MDupdate $(@:.o=.d) -c -o $@ $<

$(IDO_S): $(BUILD)/%.o: %.s tools/fixsym
	@mkdir -p $(dir $@)
	@rm -f $@ $(@:.o=.d)
	$(IRIX_CC) -I$(IDO)/include $(U64_CPPFLAGS) $(IDO_ASFLAGS) -MDupdate $(@:.o=.d) -c -o $@ $<
	tools/fixsym $@

$(BUILD)/%.o: $(BUILD)/%.s
	$(U64_CC) $(U64_ASFLAGS) -c -o $@ $<

$(BUILD)/audio/ctl.s $(BUILD)/audio/tbl.s&: $(AUDIO_INS) tools/ic
	@mkdir -p $(dir $@)
	tools/ic $(U64_CPPFLAGS) -ctl $(BUILD)/audio/ctl.s -tbl $(BUILD)/audio/tbl.s $(AUDIO_INS)

$(BUILD)/audio/seq.s: $(AUDIO_SEQ) tools/sbc
	@mkdir -p $(dir $@)
	tools/sbc 3 $(@:.s=.bin) $(AUDIO_SEQ) > $@

$(BUILD)/audio/bnk.s: audio/bnk.txt
	@mkdir -p $(dir $@)
	tools/audiobnk $< > $@

$(BUILD)/%.seq: %.asm
	@mkdir -p $(dir $@)
	armips $(U64_ARMIPSFLAGS) -sym $(@:.seq=.sym) $<

%.h: %.png tools/texture
	tools/texture $(filter %.png,$^) > $@

%.h: %.txt tools/message
	tools/message $< > $@

%.h: %.obj tools/obj
	tools/obj $< $@

%.aifc: %.aiff
	tabledesign -s 1 $< > $(@:.aifc=.table)
	vadpcm_enc -c $(@:.aifc=.table) $< $@

build/intel/%.bin: build/intel/%.exe tools/swap
	objcopy -O binary $< $@
	tools/swap $@ $@

build/intel/init.exe: build/intel/init.o
build/intel/proc.exe: build/intel/proc.o build/intel/main.o build/intel/aes.o
build/intel/%.exe:
	x86_64-w64-mingw32-ld -Tintel.ld -o $@ $^

build/intel/proc.o: intel/share.s build/intel/procinfo.s build/intel/proclist.s
build/intel/%.o: intel/%.s
	@mkdir -p $(dir $@)
	x86_64-w64-mingw32-gcc -mwindows -Os -c -o $@ $<

build/intel/%.o: intel/%.c
	@mkdir -p $(dir $@)
	x86_64-w64-mingw32-gcc -Iinclude -mwindows -mcmodel=small -Os -Wall -Wextra -Wpedantic -c -o $@ $<

build/intel/procinfo.s: tools/makeimp
	@mkdir -p $(dir $@)
	tools/makeimp -i > $@

build/intel/proclist.s: tools/makeimp
	@mkdir -p $(dir $@)
	tools/makeimp -p > $@

build/intel/main.o: intel/osaka.h
intel/osaka.h: intel/osaka.txt tools/makeascii
	tools/makeascii $< > $@

$(BUILD)/libultra/src/PR/gspFast3D.fifo.o: $(wildcard libultra/src/PR/gspFast3D/*)

$(BUILD)/libultra/libultra_rom.a: LIBULTRA_CPPFLAGS += -D_FINALROM
$(BUILD)/libultra/libultra_rom.a: $(LIBULTRA_OBJ)
	$(U64_AR) rc $@ $(LIBULTRA_OBJ)

$(BUILD)/libultra/src/PR/Boot: $(BUILD)/libultra/src/PR/Boot.elf
	$(U64_OBJCOPY) -O binary $< $@

$(BUILD)/libultra/src/PR/Boot.elf: $(BUILD)/libultra/src/PR/Boot.o
	$(U64_LD) -Tlibultra/src/PR/Boot.ld -o $@ $<

$(BUILD)/libultra/%.o: libultra/%.asm
	@mkdir -p $(dir $@)
	armips $(LIBULTRA_ARMIPSFLAGS) -sym $(@:.o=.sym) $<
	$(U64_CC) -I$(BUILD) $(U64_ASFLAGS) -c -o $@ $(<:.asm=.s)

$(BUILD)/libultra/%.o: libultra/%.c
	@mkdir -p $(dir $@)
	$(IDO_CC) -I$(IDO)/include $(LIBULTRA_CPPFLAGS) $(LIBULTRA_CFLAGS) -c -o $@ $<

$(LIBULTRA_CMIPS3): LIBULTRA_ARCH := -32 -mips3
$(LIBULTRA_CMIPS3): $(BUILD)/libultra/%.o: libultra/%.c tools/fixabi
	@mkdir -p $(dir $@)
	$(IDO_CC) -I$(IDO)/include $(LIBULTRA_CPPFLAGS) $(LIBULTRA_CFLAGS) -c -o $@ $<
	tools/fixabi $@

$(LIBULTRA_CO3): LIBULTRA_OPT := -O3
$(LIBULTRA_CO3): $(BUILD)/libultra/%.o: libultra/%.c
	@mkdir -p $(dir $@)
	$(IRIX_CC) -I$(IDO)/include $(LIBULTRA_CPPFLAGS) $(LIBULTRA_CFLAGS) -c -o $@ $<

$(BUILD)/libultra/%.o: libultra/%.s tools/fixsym
	@mkdir -p $(dir $@)
	$(IRIX_CC) -I$(IDO)/include $(LIBULTRA_CPPFLAGS) $(LIBULTRA_ASFLAGS) -c -o $@ $<
	tools/fixsym $@

$(LIBULTRA_SMIPS3): LIBULTRA_ARCH := -32 -mips3
$(LIBULTRA_SMIPS3): $(BUILD)/libultra/%.o: libultra/%.s tools/fixabi tools/fixsym
	@mkdir -p $(dir $@)
	$(IRIX_CC) -I$(IDO)/include $(LIBULTRA_CPPFLAGS) $(LIBULTRA_ASFLAGS) -c -o $@ $<
	tools/fixabi $@
	tools/fixsym $@

$(TOOLS):
tools/%: tools/%.c
	$(CC) $(CFLAGS) -s -o $@ $<

print-%:
	$(info $* = $(flavor $*): [$($*)]) @true

$(SZP:.szp.o=.o):
$(SHAPE_SZP:.szp.o=.o):
$(TEXTURE_SZP:.szp.o=.o):
$(STAGE_SZP:.szp.o=.o):
$(VID:.vid.o=.o):

-include $(CODE_OBJ:.o=.d)
-include $(ULIB_OBJ:.o=.d)
-include $(EXEC_OBJ:.o=.d)
-include $(AUDIO_OBJ:.o=.d)

-include $(DATA:.o=.d)
-include $(SZP:.szp.o=.d)
-include $(SHAPE_SZP:.szp.o=.d)
-include $(SHAPE_DATA:.o=.d)
-include $(TEXTURE_SZP:.szp.o=.d)
-include $(STAGE_SZP:.szp.o=.d)
-include $(STAGE_DATA:.o=.d)
-include $(VID:.vid.o=.d)
-include $(AUDIO_DATA:.o=.d)
