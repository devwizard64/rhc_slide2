#include <sm64/segment.h>

#ifdef NEWSPEC
#define MAXADDR(x) maxaddr x
#else
#define MAXADDR(x)
#endif

beginseg
	name    "code"
	flags   OBJECT BOOT
	address ADDRESS_CODE
	MAXADDR(ADDRESS_CIMG)
	entry   entry
	stack   entry_stack + BOOT_STACK_SIZE
	include "$(BUILD)/code.o"
	include "$(BUILD)/libultra/src/PR/rspboot.o"
	include "$(BUILD)/libultra/src/PR/gspFast3D.fifo.o"
	include "$(BUILD)/libultra/src/PR/aspMain.o"
endseg

beginseg
	name    "cimg"
	flags   OBJECT
	address ADDRESS_CIMG
	MAXADDR(0x80400000)
	include "$(BUILD)/data/cimg.o"
endseg

beginseg
	name    "zimg"
	flags   OBJECT
	address ADDRESS_ZIMG
	MAXADDR(ADDRESS_MEM_START)
	include "$(BUILD)/data/zimg.o"
endseg

beginseg
	name    "timg"
	flags   OBJECT
	address ADDRESS_TIMG
	MAXADDR(ADDRESS_BUFFER)
	include "$(BUILD)/data/timg.o"
endseg

beginseg
	name    "buffer"
	flags   OBJECT
	address ADDRESS_BUFFER
	MAXADDR(ADDRESS_FIFO)
	include "$(BUILD)/src/audio/heap.o"
	include "$(BUILD)/data/buffer.o"
	include "$(BUILD)/src/audio/work.o"
endseg

beginseg
	name    "fifo"
	flags   OBJECT
	address ADDRESS_FIFO
	MAXADDR(ADDRESS_CODE)
	include "$(BUILD)/data/fifo.o"
endseg

beginseg
	name    "Main"
	flags   OBJECT
	address ADDRESS_MAIN
	include "$(BUILD)/data/main.o"
endseg

beginseg
	name    "Gfx"
	flags   OBJECT
	number  SEG_GFX
	include "$(BUILD)/data/gfx.szp.o"
endseg

beginseg
	name    "PlayerGfx"
	flags   OBJECT
	number  SEG_PLAYER_GFX
	include "$(BUILD)/shape/player/gfx.szp.o"
endseg

beginseg
	name    "PlayerShp"
	flags   OBJECT
	address ADDRESS_PLAYER_SHP
	include "$(BUILD)/shape/player/shp.o"
endseg

beginseg
	name    "Shape1IGfx"
	flags   OBJECT
	number  SEG_SHAPE1_GFX
	include "$(BUILD)/shape/1i/gfx.szp.o"
endseg

beginseg
	name    "Shape1IShp"
	flags   OBJECT
	address ADDRESS_SHAPE1_SHP
	include "$(BUILD)/shape/1i/shp.o"
endseg

beginseg
	name    "Shape2BGfx"
	flags   OBJECT
	number  SEG_SHAPE2_GFX
	include "$(BUILD)/shape/2b/gfx.szp.o"
endseg

beginseg
	name    "Shape2BShp"
	flags   OBJECT
	address ADDRESS_SHAPE2_SHP
	include "$(BUILD)/shape/2b/shp.o"
endseg

beginseg
	name    "CommonGfx"
	flags   OBJECT
	number  SEG_SHAPE3_GFX
	include "$(BUILD)/shape/3common/gfx.szp.o"
endseg

beginseg
	name    "CommonShp"
	flags   OBJECT
	address ADDRESS_SHAPE3_SHP
	include "$(BUILD)/shape/3common/shp.o"
endseg

beginseg
	name    "GlobalGfx"
	flags   OBJECT
	number  SEG_GLOBAL_GFX
	include "$(BUILD)/shape/global/gfx.szp.o"
endseg

beginseg
	name    "GlobalShp"
	flags   OBJECT
	address ADDRESS_GLOBAL_SHP
	include "$(BUILD)/shape/global/shp.o"
endseg

beginseg
	name    "Object"
	flags   OBJECT
	address ADDRESS_OBJECT
	include "$(BUILD)/src/obj_a.o"
	include "$(BUILD)/src/obj_player.o"
	include "$(BUILD)/src/obj_b.o"
	include "$(BUILD)/src/obj_c.o"
	include "$(BUILD)/src/obj_camera.o"
	include "$(BUILD)/src/obj_meta.o"
endseg

beginseg
	name    "ContCheck"
	flags   OBJECT
	address ADDRESS_MENU_DATA
	include "$(BUILD)/stage/contcheck/prg.o"
	include "$(BUILD)/stage/contcheck/shp.o"
endseg

beginseg
	name    "ContCheckGfx"
	flags   OBJECT
	number  SEG_STAGE_GFX
	include "$(BUILD)/stage/contcheck/gfx.szp.o"
endseg

beginseg
	name    "Title"
	flags   OBJECT
	address ADDRESS_MENU_DATA
	include "$(BUILD)/stage/title/prg.o"
	include "$(BUILD)/stage/title/shp.o"
endseg

beginseg
	name    "TitleLogo"
	flags   OBJECT
	number  SEG_STAGE_GFX
	include "$(BUILD)/stage/title/logo.szp.o"
endseg

beginseg
	name    "Game"
	flags   OBJECT
	address ADDRESS_GAME
	include "$(BUILD)/data/game.o"
endseg

beginseg
	name    "TextureI"
	flags   OBJECT
	number  SEG_TEXTURE
	include "$(BUILD)/data/texture/i.szp.o"
endseg

beginseg
	name    "Stage1Gfx"
	flags   OBJECT
	number  SEG_STAGE_GFX
	include "$(BUILD)/stage/stage1/gfx.szp.o"
endseg

beginseg
	name    "Stage1"
	flags   OBJECT
	address ADDRESS_STAGE_DATA
	include "$(BUILD)/stage/stage1/prg.o"
	include "$(BUILD)/stage/stage1/shp.o"
endseg

beginseg
	name    "Ending"
	flags   OBJECT
	address ADDRESS_STAGE_DATA
	include "$(BUILD)/stage/ending/prg.o"
	include "$(BUILD)/stage/ending/shp.o"
endseg

beginseg
	name    "PSSGfx"
	flags   OBJECT
	number  SEG_STAGE_GFX
	include "$(BUILD)/stage/pss/gfx.szp.o"
endseg

beginseg
	name    "PSS"
	flags   OBJECT
	address ADDRESS_STAGE_DATA
	include "$(BUILD)/stage/pss/prg.o"
	include "$(BUILD)/stage/pss/shp.o"
endseg

beginseg
	name    "Anime"
	flags   OBJECT
	address 0
	include "$(BUILD)/data/anime.o"
endseg

beginseg
	name    "cirno_vid"
	flags   OBJECT
	address 0
	include "$(BUILD)/data/video/cirno.vid.o"
endseg

beginseg
	name    "exec"
	flags   OBJECT
	address ADDRESS_EXEC
	include "$(BUILD)/src/exec.o"
endseg

beginseg
	name    "Audioctl"
	flags   OBJECT
	address 0
	include "$(BUILD)/audio/ctl.o"
endseg

beginseg
	name    "Audiotbl"
	flags   OBJECT
	address 0
	include "$(BUILD)/audio/tbl.o"
endseg

beginseg
	name    "Audioseq"
	flags   OBJECT
	address 0
	include "$(BUILD)/audio/seq.o"
endseg

beginseg
	name    "Audiobnk"
	flags   OBJECT
	address 0
	include "$(BUILD)/audio/bnk.o"
endseg

beginseg
	name    "dolphin"
	flags   OBJECT
	address 0
	include "$(BUILD)/data/dolphin.o"
endseg
