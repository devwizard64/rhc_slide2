CODE_OBJ := \
	$(BUILD)/src/main.o \
	$(BUILD)/src/graphics.o \
	$(BUILD)/src/audio.o \
	$(BUILD)/src/game.o \
	$(BUILD)/src/collision.o $(BUILD)/src/collision.data.o \
	$(BUILD)/src/player.o $(BUILD)/src/player.data.o \
	$(BUILD)/src/physics.o $(BUILD)/src/physics.data.o \
	$(BUILD)/src/pldemo.o $(BUILD)/src/pldemo.data.o \
	$(BUILD)/src/plhang.o $(BUILD)/src/plhang.data.o \
	$(BUILD)/src/plwait.o $(BUILD)/src/plwait.data.o \
	$(BUILD)/src/plmove.o $(BUILD)/src/plmove.data.o \
	$(BUILD)/src/pljump.o $(BUILD)/src/pljump.data.o \
	$(BUILD)/src/plswim.o $(BUILD)/src/plswim.data.o \
	$(BUILD)/src/plhold.o $(BUILD)/src/plhold.data.o \
	$(BUILD)/src/callback.o \
	$(BUILD)/src/memory.o \
	$(BUILD)/src/save.o \
	$(BUILD)/src/scene.o \
	$(BUILD)/src/draw.o \
	$(BUILD)/src/time.o \
	$(BUILD)/src/slidec.o \
	$(BUILD)/src/camera.o $(BUILD)/src/camera.data.o \
	$(BUILD)/src/course.o \
	$(BUILD)/src/object.o \
	$(BUILD)/src/objlib.o $(BUILD)/src/objlib.data.o \
	$(BUILD)/src/object_a.o $(BUILD)/src/object_a.data.o \
	$(BUILD)/src/ride.o \
	$(BUILD)/src/hitcheck.o \
	$(BUILD)/src/objlist.o \
	$(BUILD)/src/objsound.o \
	$(BUILD)/src/debug.o \
	$(BUILD)/src/wipe.o \
	$(BUILD)/src/shadow.o \
	$(BUILD)/src/water.o \
	$(BUILD)/src/objshape.o \
	$(BUILD)/src/wave.o \
	$(BUILD)/src/dprint.o \
	$(BUILD)/src/message.o \
	$(BUILD)/src/lava.o \
	$(BUILD)/src/tag.o \
	$(BUILD)/src/hud.o \
	$(BUILD)/src/object_b.o $(BUILD)/src/object_b.data.o \
	$(BUILD)/src/object_c.o $(BUILD)/src/object_c.data.o \
	$(BUILD)/src/contcheck.o \
	$(BUILD)/src/meta.o \
	$(BUILD)/src/sprite.o \
	$(BUILD)/src/video.o \
	$(BUILD)/src/ext.o \
	$(BUILD)/src/aes.o \
	$(BUILD)/src/PL.o \
	$(BUILD)/src/math.o \
	$(BUILD)/src/mathtbl.o \
	$(BUILD)/src/shape.o \
	$(BUILD)/src/shplang.o \
	$(BUILD)/src/prglang.o \
	$(BUILD)/src/bgcheck.o \
	$(BUILD)/src/bgload.o \
	$(BUILD)/src/objlang.o \
	$(BUILD)/src/title.o \
	$(BUILD)/src/titlebg.o \
	$(BUILD)/src/io/cicscramble.o \
	$(BUILD)/src/io/contreaddol.o

EXEC_OBJ := \
	$(BUILD)/src/exec.o

AUDIO_OBJ := \
	$(BUILD)/src/audio/driver.o $(BUILD)/src/audio/driver.data.o \
	$(BUILD)/src/audio/memory.o $(BUILD)/src/audio/memory.data.o \
	$(BUILD)/src/audio/system.o \
	$(BUILD)/src/audio/voice.o $(BUILD)/src/audio/voice.data.o \
	$(BUILD)/src/audio/effect.o $(BUILD)/src/audio/effect.data.o \
	$(BUILD)/src/audio/sequence.o $(BUILD)/src/audio/sequence.data.o \
	$(BUILD)/src/audio/game.o $(BUILD)/src/audio/game.data.o \
	$(BUILD)/src/audio/data.o

IDO_C :=

IDO_S :=

OBJ := \
	$(BUILD)/libultra/src/PR/rspboot.o \
	$(BUILD)/libultra/src/PR/gspFast3D.fifo.o \
	$(BUILD)/libultra/src/PR/aspMain.o \
	$(BUILD)/code.o

DATA := \
	$(BUILD)/data/cimg.o \
	$(BUILD)/data/zimg.o \
	$(BUILD)/data/timg.o \
	$(BUILD)/data/buffer.o \
	$(BUILD)/data/fifo.o \
	$(BUILD)/src/obj_a.o \
	$(BUILD)/src/obj_player.o \
	$(BUILD)/src/obj_b.o \
	$(BUILD)/src/obj_c.o \
	$(BUILD)/src/obj_camera.o \
	$(BUILD)/src/obj_meta.o \
	$(BUILD)/data/main.o \
	$(BUILD)/data/game.o \
	$(BUILD)/data/anime.o \
	$(BUILD)/data/dolphin.o

SZP := \
	$(BUILD)/data/gfx.szp.o

SHAPE_SZP := \
	$(BUILD)/shape/player/gfx.szp.o \
	$(BUILD)/shape/1i/gfx.szp.o \
	$(BUILD)/shape/2b/gfx.szp.o \
	$(BUILD)/shape/3common/gfx.szp.o \
	$(BUILD)/shape/global/gfx.szp.o

SHAPE_DATA := \
	$(BUILD)/shape/player/shp.o \
	$(BUILD)/shape/1i/shp.o \
	$(BUILD)/shape/2b/shp.o \
	$(BUILD)/shape/3common/shp.o \
	$(BUILD)/shape/global/shp.o

TEXTURE_SZP := \
	$(BUILD)/data/texture/i.szp.o

STAGE_SZP := \
	$(BUILD)/stage/contcheck/gfx.szp.o \
	$(BUILD)/stage/title/logo.szp.o \
	$(BUILD)/stage/stage1/gfx.szp.o \
	$(BUILD)/stage/pss/gfx.szp.o

STAGE_DATA := \
	$(BUILD)/stage/contcheck/prg.o $(BUILD)/stage/contcheck/shp.o \
	$(BUILD)/stage/title/prg.o $(BUILD)/stage/title/shp.o \
	$(BUILD)/stage/stage1/prg.o $(BUILD)/stage/stage1/shp.o \
	$(BUILD)/stage/ending/prg.o $(BUILD)/stage/ending/shp.o \
	$(BUILD)/stage/pss/prg.o $(BUILD)/stage/pss/shp.o

VID := \
	$(BUILD)/data/video/cirno.vid.o

AUDIO_DATA := \
	$(BUILD)/src/audio/heap.o \
	$(BUILD)/src/audio/work.o \
	$(BUILD)/audio/ctl.o \
	$(BUILD)/audio/tbl.o \
	$(BUILD)/audio/seq.o \
	$(BUILD)/audio/bnk.o

AUDIO_INS := audio/se.ins audio/music.ins audio/stm.ins
AUDIO_SEQ := \
	audio/se/se.seq \
	audio/music/slider.seq \
	audio/music/fanfare.seq \
	audio/music/solution.seq \
	audio/stm/stereo.seq \
	audio/stm/stereo.seq

LIBULTRA_OBJ := \
	$(BUILD)/libultra/src/io/piread.o \
	$(BUILD)/libultra/src/io/piwrite.o \
	$(BUILD)/libultra/src/io/pirawwrite.o
ifeq ($(TARGET),E0)
	LIBULTRA_OBJ += $(BUILD)/libultra/src/os/parameters.o
endif
LIBULTRA_OBJ += \
	$(BUILD)/libultra/src/io/vitbl.o \
	$(BUILD)/libultra/src/os/settime.o \
	$(BUILD)/libultra/src/os/maptlb.o \
	$(BUILD)/libultra/src/os/unmaptlball.o \
	$(BUILD)/libultra/src/rmon/sprintf.o \
	$(BUILD)/libultra/src/os/createmesgqueue.o \
	$(BUILD)/libultra/src/os/seteventmesg.o \
	$(BUILD)/libultra/src/io/visetevent.o \
	$(BUILD)/libultra/src/os/createthread.o \
	$(BUILD)/libultra/src/os/recvmesg.o \
	$(BUILD)/libultra/src/io/sptask.o \
	$(BUILD)/libultra/src/io/sptaskyield.o \
	$(BUILD)/libultra/src/os/sendmesg.o \
	$(BUILD)/libultra/src/io/sptaskyielded.o \
	$(BUILD)/libultra/src/os/startthread.o \
	$(BUILD)/libultra/src/os/writebackdcacheall.o \
	$(BUILD)/libultra/src/io/vimgr.o \
	$(BUILD)/libultra/src/io/visetmode.o \
	$(BUILD)/libultra/src/io/viblack.o \
	$(BUILD)/libultra/src/io/visetspecial.o \
	$(BUILD)/libultra/src/io/pimgr.o \
	$(BUILD)/libultra/src/os/setthreadpri.o \
	$(BUILD)/libultra/src/os/initialize.o \
	$(BUILD)/libultra/src/io/viswapbuf.o \
	$(BUILD)/libultra/src/gu/sqrtf.o \
	$(BUILD)/libultra/src/io/contreaddata.o \
	$(BUILD)/libultra/src/io/controller.o \
	$(BUILD)/libultra/src/io/conteepprobe.o \
	$(BUILD)/libultra/src/libc/ll.o \
	$(BUILD)/libultra/src/os/invaldcache.o \
	$(BUILD)/libultra/src/io/pidma.o \
	$(BUILD)/libultra/src/libc/bzero.o \
	$(BUILD)/libultra/src/os/invalicache.o \
	$(BUILD)/libultra/src/io/conteeplongread.o \
	$(BUILD)/libultra/src/io/conteeplongwrite.o \
	$(BUILD)/libultra/src/libc/bcopy.o \
	$(BUILD)/libultra/src/gu/ortho.o \
	$(BUILD)/libultra/src/gu/perspective.o \
	$(BUILD)/libultra/src/os/gettime.o \
	$(BUILD)/libultra/src/libc/llcvt.o \
	$(BUILD)/libultra/src/gu/cosf.o \
	$(BUILD)/libultra/src/gu/sinf.o \
	$(BUILD)/libultra/src/gu/translate.o \
	$(BUILD)/libultra/src/gu/rotate.o \
	$(BUILD)/libultra/src/gu/scale.o \
	$(BUILD)/libultra/src/io/aisetfreq.o \
	$(BUILD)/libultra/src/audio/bnkf.o \
	$(BUILD)/libultra/src/os/writebackdcache.o \
	$(BUILD)/libultra/src/io/aigetlen.o \
	$(BUILD)/libultra/src/io/aisetnextbuf.o \
	$(BUILD)/libultra/src/os/timerintr.o \
	$(BUILD)/libultra/src/rmon/xprintf.o \
	$(BUILD)/libultra/src/libc/string.o \
	$(BUILD)/libultra/src/os/thread.o \
	$(BUILD)/libultra/src/os/interrupt.o \
	$(BUILD)/libultra/src/io/vi.o \
	$(BUILD)/libultra/src/os/exceptasm.o \
	$(BUILD)/libultra/src/gu/libm_vals.o \
	$(BUILD)/libultra/src/os/virtualtophysical.o \
	$(BUILD)/libultra/src/io/spsetstat.o \
	$(BUILD)/libultra/src/io/spsetpc.o \
	$(BUILD)/libultra/src/io/sprawdma.o \
	$(BUILD)/libultra/src/io/sp.o \
	$(BUILD)/libultra/src/io/spgetstat.o \
	$(BUILD)/libultra/src/os/getthreadpri.o \
	$(BUILD)/libultra/src/io/vigetcurrcontext.o \
	$(BUILD)/libultra/src/io/viswapcontext.o \
	$(BUILD)/libultra/src/os/getcount.o \
	$(BUILD)/libultra/src/io/piacs.o \
	$(BUILD)/libultra/src/io/pirawdma.o \
	$(BUILD)/libultra/src/io/devmgr.o \
	$(BUILD)/libultra/src/os/setsr.o \
	$(BUILD)/libultra/src/os/getsr.o \
	$(BUILD)/libultra/src/os/setfpccsr.o \
	$(BUILD)/libultra/src/io/sirawread.o \
	$(BUILD)/libultra/src/io/sirawwrite.o \
	$(BUILD)/libultra/src/os/maptlbrdb.o \
	$(BUILD)/libultra/src/io/pirawread.o
ifeq ($(TARGET),J0)
	LIBULTRA_OBJ += $(BUILD)/libultra/src/os/parameters.o
endif
LIBULTRA_OBJ += \
	$(BUILD)/libultra/src/io/siacs.o \
	$(BUILD)/libultra/src/io/sirawdma.o \
	$(BUILD)/libultra/src/os/settimer.o \
	$(BUILD)/libultra/src/io/conteepwrite.o \
	$(BUILD)/libultra/src/os/jammesg.o \
	$(BUILD)/libultra/src/io/pigetcmdq.o \
	$(BUILD)/libultra/src/io/conteepread.o \
	$(BUILD)/libultra/src/gu/mtxutil.o \
	$(BUILD)/libultra/src/gu/normalize.o \
	$(BUILD)/libultra/src/io/ai.o \
	$(BUILD)/libultra/src/os/setcompare.o \
	$(BUILD)/libultra/src/rmon/xlitob.o \
	$(BUILD)/libultra/src/rmon/xldtob.o \
	$(BUILD)/libultra/src/vimodentsclan1.o \
	$(BUILD)/libultra/src/vimodepallan1.o \
	$(BUILD)/libultra/src/os/kdebugserver.o \
	$(BUILD)/libultra/src/os/syncputchars.o \
	$(BUILD)/libultra/src/os/setintmask.o \
	$(BUILD)/libultra/src/os/destroythread.o \
	$(BUILD)/libultra/src/os/probetlb.o \
	$(BUILD)/libultra/src/io/si.o \
	$(BUILD)/libultra/src/libc/ldiv.o \
	$(BUILD)/libultra/src/os/getcause.o \
	$(BUILD)/libultra/src/os/atomic.o

LIBULTRA_CO3 := \
	$(BUILD)/libultra/src/gu/ortho.o \
	$(BUILD)/libultra/src/gu/perspective.o \
	$(BUILD)/libultra/src/gu/cosf.o \
	$(BUILD)/libultra/src/gu/sinf.o \
	$(BUILD)/libultra/src/gu/translate.o \
	$(BUILD)/libultra/src/gu/rotate.o \
	$(BUILD)/libultra/src/gu/scale.o \
	$(BUILD)/libultra/src/audio/bnkf.o \
	$(BUILD)/libultra/src/libc/string.o \
	$(BUILD)/libultra/src/gu/mtxutil.o \
	$(BUILD)/libultra/src/gu/normalize.o \
	$(BUILD)/libultra/src/libc/ldiv.o

LIBULTRA_CMIPS3 := \
	$(BUILD)/libultra/src/libc/ll.o \
	$(BUILD)/libultra/src/libc/llcvt.o

LIBULTRA_SMIPS3 := \
	$(BUILD)/libultra/src/os/exceptasm.o

################################################################################
# Player

MARIO_DEP := \
	shape/player/mario/h_waist.h \
	shape/player/mario/h_waist.blue.h \
	shape/player/mario/h_uarmL.h \
	shape/player/mario/h_uarmL.red.h \
	shape/player/mario/h_larmL.h \
	shape/player/mario/h_larmL.red.h \
	shape/player/mario/h_fistL.h \
	shape/player/mario/h_fistL.white.h \
	shape/player/mario/h_uarmR.h \
	shape/player/mario/h_uarmR.red.h \
	shape/player/mario/h_larmR.h \
	shape/player/mario/h_larmR.red.h \
	shape/player/mario/h_fistR.h \
	shape/player/mario/h_fistR.white.h \
	shape/player/mario/h_thighL.h \
	shape/player/mario/h_thighL.blue.h \
	shape/player/mario/h_shinL.h \
	shape/player/mario/h_shinL.blue.h \
	shape/player/mario/h_shoeL.h \
	shape/player/mario/h_shoeL.shoe.h \
	shape/player/mario/h_thighR.h \
	shape/player/mario/h_thighR.blue.h \
	shape/player/mario/h_shinR.h \
	shape/player/mario/h_shinR.blue.h \
	shape/player/mario/h_shoeR.h \
	shape/player/mario/h_shoeR.shoe.h \
	shape/player/mario/h_torso.h \
	shape/player/mario/h_torso.button.h \
	shape/player/mario/h_torso.red.h \
	shape/player/mario/h_torso.blue.h \
	shape/player/mario/h_cap.h \
	shape/player/mario/h_cap.logo.h \
	shape/player/mario/h_cap.eyes.h \
	shape/player/mario/h_cap.sideburn.h \
	shape/player/mario/h_cap.moustache.h \
	shape/player/mario/h_cap.red.h \
	shape/player/mario/h_cap.skin.h \
	shape/player/mario/h_cap.hair.h \
	shape/player/mario/h_hair.h \
	shape/player/mario/h_hair.eyes.h \
	shape/player/mario/h_hair.sideburn.h \
	shape/player/mario/h_hair.moustache.h \
	shape/player/mario/h_hair.skin.h \
	shape/player/mario/h_hair.hair.h \
	shape/player/mario/h_hair.001.h \
	shape/player/mario/h_hair.001.skin.h \
	shape/player/mario/m_waist.h \
	shape/player/mario/m_waist.blue.h \
	shape/player/mario/m_uarmL.h \
	shape/player/mario/m_uarmL.red.h \
	shape/player/mario/m_larmL.h \
	shape/player/mario/m_larmL.red.h \
	shape/player/mario/m_fistL.h \
	shape/player/mario/m_fistL.white.h \
	shape/player/mario/m_uarmR.h \
	shape/player/mario/m_uarmR.red.h \
	shape/player/mario/m_larmR.h \
	shape/player/mario/m_larmR.red.h \
	shape/player/mario/m_fistR.h \
	shape/player/mario/m_fistR.white.h \
	shape/player/mario/m_thighL.h \
	shape/player/mario/m_thighL.blue.h \
	shape/player/mario/m_shinL.h \
	shape/player/mario/m_shinL.blue.h \
	shape/player/mario/m_shoeL.h \
	shape/player/mario/m_shoeL.shoe.h \
	shape/player/mario/m_thighR.h \
	shape/player/mario/m_thighR.blue.h \
	shape/player/mario/m_shinR.h \
	shape/player/mario/m_shinR.blue.h \
	shape/player/mario/m_shoeR.h \
	shape/player/mario/m_shoeR.shoe.h \
	shape/player/mario/m_torso.h \
	shape/player/mario/m_torso.button.h \
	shape/player/mario/m_torso.red.h \
	shape/player/mario/m_torso.blue.h \
	shape/player/mario/l_waist.h \
	shape/player/mario/l_waist.blue.h \
	shape/player/mario/l_uarmL.h \
	shape/player/mario/l_uarmL.red.h \
	shape/player/mario/l_larmL.h \
	shape/player/mario/l_larmL.red.h \
	shape/player/mario/l_fistL.h \
	shape/player/mario/l_fistL.white.h \
	shape/player/mario/l_uarmR.h \
	shape/player/mario/l_uarmR.red.h \
	shape/player/mario/l_larmR.h \
	shape/player/mario/l_larmR.red.h \
	shape/player/mario/l_fistR.h \
	shape/player/mario/l_fistR.white.h \
	shape/player/mario/l_thighL.h \
	shape/player/mario/l_thighL.blue.h \
	shape/player/mario/l_shinL.h \
	shape/player/mario/l_shinL.blue.h \
	shape/player/mario/l_shoeL.h \
	shape/player/mario/l_shoeL.shoe.h \
	shape/player/mario/l_thighR.h \
	shape/player/mario/l_thighR.blue.h \
	shape/player/mario/l_shinR.h \
	shape/player/mario/l_shinR.blue.h \
	shape/player/mario/l_shoeR.h \
	shape/player/mario/l_shoeR.shoe.h \
	shape/player/mario/l_torso.h \
	shape/player/mario/l_torso.button.h \
	shape/player/mario/l_torso.blue.h \
	shape/player/mario/l_torso.red.h \
	shape/player/mario/l_cap.h \
	shape/player/mario/l_cap.logo.h \
	shape/player/mario/l_cap.eyes.h \
	shape/player/mario/l_cap.moustache.h \
	shape/player/mario/l_cap.red.h \
	shape/player/mario/l_cap.skin.h \
	shape/player/mario/l_cap.hair.h \
	shape/player/mario/l_hair.h \
	shape/player/mario/l_hair.eyes.h \
	shape/player/mario/l_hair.moustache.h \
	shape/player/mario/l_hair.skin.h \
	shape/player/mario/l_hair.hair.h \
	shape/player/mario/handL.h \
	shape/player/mario/handL.white.h \
	shape/player/mario/handR.h \
	shape/player/mario/handR.white.h \
	shape/player/mario/capR.h \
	shape/player/mario/capR.logo.h \
	shape/player/mario/capR.white.h \
	shape/player/mario/capR.red.h \
	shape/player/mario/capR.hair.h \
	shape/player/mario/wingsR.h \
	shape/player/mario/wingsR.wing_l.h \
	shape/player/mario/wingsR.wing_r.h \
	shape/player/mario/peaceR.h \
	shape/player/mario/peaceR.white.h \
	shape/player/mario/cap.h \
	shape/player/mario/cap.logo.h \
	shape/player/mario/cap.red.h \
	shape/player/mario/cap.hair.h \
	shape/player/mario/wings.h \
	shape/player/mario/wings.wing_l.h \
	shape/player/mario/wings.wing_r.h \
	shape/player/mario/wing.h \
	shape/player/mario/wing.wing_l.h \
	shape/player/mario/wing.wing_r.h

################################################################################
# Shape2B

CHEST_DEP := \
	shape/2b/chest/box.h \
	shape/2b/chest/box.keyhole.h \
	shape/2b/chest/box.latch.h \
	shape/2b/chest/box.inside.h \
	shape/2b/chest/box.outside.h \
	shape/2b/chest/lid.h \
	shape/2b/chest/lid.inside.h \
	shape/2b/chest/lid.latch.h \
	shape/2b/chest/lid.outside.h

################################################################################
# Common

BLUECOINSW_DEP := \
	shape/3common/bluecoinsw/bluecoinsw.h \
	shape/3common/bluecoinsw/bluecoinsw.side.h \
	shape/3common/bluecoinsw/bluecoinsw.top.h

AMP_DEP := \
	shape/3common/amp/arc.h \
	shape/3common/amp/arc.arc.h \
	shape/3common/amp/eyes.h \
	shape/3common/amp/eyes.eyes.h \
	shape/3common/amp/mouth.h \
	shape/3common/amp/mouth.mouth.h \
	shape/3common/amp/body.h \
	shape/3common/amp/body.body.h \
	shape/3common/amp/arcA_old.h \
	shape/3common/amp/arcA_old.arc_old.h \
	shape/3common/amp/arcB_old.h \
	shape/3common/amp/arcB_old.arc_old.h \
	shape/3common/amp/arcC_old.h \
	shape/3common/amp/arcC_old.arc_old.h \
	shape/3common/amp/arcD_old.h \
	shape/3common/amp/arcD_old.arc_old.h \
	shape/3common/amp/body_old.h \
	shape/3common/amp/body_old.shade_old.h \
	shape/3common/amp/mouth_old.h \
	shape/3common/amp/mouth_old.shade_old.h \
	shape/3common/amp/anger_old.h \
	shape/3common/amp/anger_old.shade_old.h \
	shape/3common/amp/eyes_old.h \
	shape/3common/amp/eyes_old.shade_old.h

CANNONLID_DEP := \
	shape/3common/cannonlid/cannonlid.h \
	shape/3common/cannonlid/cannonlid.lid.h

CANNON_DEP := \
	shape/3common/cannon/cannon.h \
	shape/3common/cannon/cannon.side.h \
	shape/3common/cannon/cannon.shade.h

CANNONBARREL_DEP := \
	shape/3common/cannonbarrel/cannonbarrel.h \
	shape/3common/cannonbarrel/cannonbarrel.rim.h \
	shape/3common/cannonbarrel/cannonbarrel.shade.h

CHUCKYA_DEP := \
	shape/3common/chuckya/body.h \
	shape/3common/chuckya/body.purple_l.h \
	shape/3common/chuckya/body.purple_r.h \
	shape/3common/chuckya/armL.h \
	shape/3common/chuckya/armL.purple_l.h \
	shape/3common/chuckya/armL.purple_r.h \
	shape/3common/chuckya/armR.h \
	shape/3common/chuckya/armR.purple_l.h \
	shape/3common/chuckya/armR.purple_r.h \
	shape/3common/chuckya/handL.h \
	shape/3common/chuckya/handL.red.h \
	shape/3common/chuckya/handR.h \
	shape/3common/chuckya/handR.red.h \
	shape/3common/chuckya/antenna_end.h \
	shape/3common/chuckya/antenna_end.red.h \
	shape/3common/chuckya/eyes.h \
	shape/3common/chuckya/eyes.eyes.h \
	shape/3common/chuckya/base.h \
	shape/3common/chuckya/base.base.h \
	shape/3common/chuckya/antenna.h \
	shape/3common/chuckya/antenna.antenna.h \
	shape/3common/chuckya/back.h \
	shape/3common/chuckya/back.back.h

PURPLESW_DEP := \
	shape/3common/purplesw/purplesw.h \
	shape/3common/purplesw/purplesw.side.h \
	shape/3common/purplesw/purplesw.top.h

LIFT_DEP := \
	shape/3common/lift/lift.h \
	shape/3common/lift/lift.side.h \
	shape/3common/lift/lift.face.h

HEART_DEP := \
	shape/3common/heart/heart.h \
	shape/3common/heart/heart.heart.h

FLYGUY_DEP := \
	shape/3common/flyguy/footR.h \
	shape/3common/flyguy/footR.foot.h \
	shape/3common/flyguy/footL.h \
	shape/3common/flyguy/footL.foot.h \
	shape/3common/flyguy/shaft.h \
	shape/3common/flyguy/shaft.shaft.h \
	shape/3common/flyguy/propeller.h \
	shape/3common/flyguy/propeller.propeller.h \
	shape/3common/flyguy/body.h \
	shape/3common/flyguy/body.face.h \
	shape/3common/flyguy/body.cloth_black.h \
	shape/3common/flyguy/body.cloth_red.h \
	shape/3common/flyguy/body.black.h

BLOCK_DEP := \
	shape/3common/block/block.h \
	shape/3common/block/block.block.h

ITEMBOX_DEP := \
	shape/3common/itembox/32x64.h \
	shape/3common/itembox/32x64.32x64_face.h \
	shape/3common/itembox/32x64.32x64_side.h \
	shape/3common/itembox/64x32.h \
	shape/3common/itembox/64x32.64x32_face.h \
	shape/3common/itembox/64x32.64x32_side.h

GOOMBA_DEP := \
	shape/3common/goomba/head.h \
	shape/3common/goomba/head.head.h \
	shape/3common/goomba/body.h \
	shape/3common/goomba/body.body.h \
	shape/3common/goomba/footL.h \
	shape/3common/goomba/footL.footL.h \
	shape/3common/goomba/footR.h \
	shape/3common/goomba/footR.footR.h \
	shape/3common/goomba/head_old.h \
	shape/3common/goomba/head_old.head_old.h \
	shape/3common/goomba/body_old.h \
	shape/3common/goomba/body_old.body_old.h

BOBOMB_DEP := \
	shape/3common/bobomb/eyes.h \
	shape/3common/bobomb/eyes.eyes.h \
	shape/3common/bobomb/footR.h \
	shape/3common/bobomb/footR.foot.h \
	shape/3common/bobomb/footL.h \
	shape/3common/bobomb/footL.foot.h \
	shape/3common/bobomb/cap.h \
	shape/3common/bobomb/cap.cap.h

PUSHBLOCK_DEP := \
	shape/3common/pushblock/pushblock.h \
	shape/3common/pushblock/pushblock.pushblock.h

DOTBOX_DEP := \
	shape/3common/dotbox/box.h \
	shape/3common/dotbox/box.box.h \
	shape/3common/dotbox/dot.h \
	shape/3common/dotbox/dot.dot.h \
	shape/3common/dotbox/mark.h \
	shape/3common/dotbox/mark.mark.h

TESTLIFT_DEP := \
	shape/3common/testlift/testlift.h \
	shape/3common/testlift/testlift.shade.h

SHELL_OLD_DEP := \
	shape/3common/shell/shell_old.h \
	shape/3common/shell/shell_old.top.h \
	shape/3common/shell/shell_old.bottom.h \
	shape/3common/shell/shell_old.side.h

SHELL_DEP := \
	shape/3common/shell/shell.h \
	shape/3common/shell/shell.top.h \
	shape/3common/shell/shell.bottom.h \
	shape/3common/shell/shell.front.h \
	shape/3common/shell/shell.white.h

################################################################################
# Global

BUTTERFLY_DEP := \
	shape/global/butterfly/l.h \
	shape/global/butterfly/l.wing.h \
	shape/global/butterfly/r.h \
	shape/global/butterfly/r.wing.h

PIPE_DEP := \
	shape/global/pipe/side.h \
	shape/global/pipe/side.side.h \
	shape/global/pipe/end.h \
	shape/global/pipe/end.top.h \
	shape/global/pipe/end.bottom.h

DOOR_DEP := \
	shape/global/door/ah.h \
	shape/global/door/ah.a_side.h \
	shape/global/door/ah.a_face.h \
	shape/global/door/ahf.h \
	shape/global/door/ahf.knob.h \
	shape/global/door/ahb.h \
	shape/global/door/ahb.knob.h \
	shape/global/door/al.h \
	shape/global/door/al.a_face.h \
	shape/global/door/h.h \
	shape/global/door/h.knob.h \
	shape/global/door/h.b_side.h \
	shape/global/door/h.b_face.h \
	shape/global/door/l.h \
	shape/global/door/l.b_face.h \
	shape/global/door/l.knob.h

DOORKEY_DEP := \
	shape/global/doorkey/key.h \
	shape/global/doorkey/key.key.h

FISH_DEP := \
	shape/global/fish/body.h \
	shape/global/fish/body.fish.h \
	shape/global/fish/tail.h \
	shape/global/fish/tail.fish.h

CAP_DEP := \
	shape/global/cap/cap.h \
	shape/global/cap/cap.logo.h \
	shape/global/cap/cap.red.h \
	shape/global/cap/cap.hair.h \
	shape/global/cap/wing.h \
	shape/global/cap/wing.wing_l.h \
	shape/global/cap/wing.wing_r.h

POWERSTAR_DEP := \
	shape/global/powerstar/star.h \
	shape/global/powerstar/star.star.h \
	shape/global/powerstar/eyes.h \
	shape/global/powerstar/eyes.eye.h

SHADESTAR_DEP := \
	shape/global/shadestar/star.h \
	shape/global/shadestar/star.star.h

SIGNPOST_DEP := \
	shape/global/signpost/post.h \
	shape/global/signpost/post.wood.h \
	shape/global/signpost/sign.h \
	shape/global/signpost/sign.wood.h \
	shape/global/signpost/sign.face.h

TREE_DEP := \
	shape/global/tree/a.h \
	shape/global/tree/a.a_l.h \
	shape/global/tree/a.a_r.h \
	shape/global/tree/b.h \
	shape/global/tree/b.b.h \
	shape/global/tree/c.h \
	shape/global/tree/c.c.h \
	shape/global/tree/d.h \
	shape/global/tree/d.b.h \
	shape/global/tree/e.h \
	shape/global/tree/e.e.h

################################################################################
# Title

LOGO_DEP := \
	stage/title/logo.h \
	stage/title/logo.marble.h \
	stage/title/logo.wood.h \
	stage/title/logo.shade.h \
	stage/title/symbol.h \
	stage/title/symbol.copyright.h \
	stage/title/symbol.trademark.h

################################################################################
# Stage1

RAINBOWROAD_DEP := \
	stage/stage1/rainbowroad/banner.h \
	stage/stage1/rainbowroad/banner.banner_ah.h \
	stage/stage1/rainbowroad/banner.banner_al.h \
	stage/stage1/rainbowroad/banner.banner_bh.h \
	stage/stage1/rainbowroad/banner.banner_bl.h \
	stage/stage1/rainbowroad/banner.banner_ch.h \
	stage/stage1/rainbowroad/banner.banner_cl.h \
	stage/stage1/rainbowroad/banner.banner_dh.h \
	stage/stage1/rainbowroad/banner.banner_dl.h \
	stage/stage1/rainbowroad/banner.ba_cable.h \
	stage/stage1/rainbowroad/banner.ba_pole.h \
	stage/stage1/rainbowroad/character.h \
	stage/stage1/rainbowroad/character.ch_donkey_h.h \
	stage/stage1/rainbowroad/character.ch_donkey_l.h \
	stage/stage1/rainbowroad/character.ch_kinoko_h.h \
	stage/stage1/rainbowroad/character.ch_kinoko_l.h \
	stage/stage1/rainbowroad/character.ch_kinopio_h.h \
	stage/stage1/rainbowroad/character.ch_kinopio_l.h \
	stage/stage1/rainbowroad/character.ch_kuppa_h.h \
	stage/stage1/rainbowroad/character.ch_kuppa_l.h \
	stage/stage1/rainbowroad/character.ch_luizi_h.h \
	stage/stage1/rainbowroad/character.ch_luizi_l.h \
	stage/stage1/rainbowroad/character.ch_mario_h.h \
	stage/stage1/rainbowroad/character.ch_mario_l.h \
	stage/stage1/rainbowroad/character.ch_peach_h.h \
	stage/stage1/rainbowroad/character.ch_peach_l.h \
	stage/stage1/rainbowroad/character.ch_teresa_h.h \
	stage/stage1/rainbowroad/character.ch_teresa_l.h \
	stage/stage1/rainbowroad/character.ch_wario_h.h \
	stage/stage1/rainbowroad/character.ch_wario_l.h \
	stage/stage1/rainbowroad/character.ch_yossy_h.h \
	stage/stage1/rainbowroad/character.ch_yossy_l.h \
	stage/stage1/rainbowroad/track.h \
	stage/stage1/rainbowroad/track.tr_checker.h \
	stage/stage1/rainbowroad/track.tr_hosi.h \
	stage/stage1/rainbowroad/track.tr_rainbow.h \
	stage/stage1/rainbowroad/hosi.h \
	stage/stage1/rainbowroad/hosi.hosi_body.h \
	stage/stage1/rainbowroad/hosi.hosi_face.h

################################################################################
# PSS

CHASER_DEP := \
	stage/pss/wega.rgba16.h \
	stage/pss/osaka.rgba16.h

MINISLIDER_DEP := \
	stage/pss/minislider/0.h \
	stage/pss/minislider/0.i21_shade.h \
	stage/pss/minislider/0.i21_light.h \
	stage/pss/minislider/0.0_light.h \
	stage/pss/minislider/0.i0_light.h \
	stage/pss/minislider/0.i10_light.h \
	stage/pss/minislider/0.i2_light.h \
	stage/pss/minislider/1.h \
	stage/pss/minislider/1.i21.h \
	stage/pss/minislider/1.i0.h \
	stage/pss/minislider/1.i12.h \
	stage/pss/minislider/2.h \
	stage/pss/minislider/2.i13.h \
	stage/pss/minislider/3.h \
	stage/pss/minislider/3.i12.h \
	stage/pss/minislider/4.h \
	stage/pss/minislider/4.1.h \
	stage/pss/minislider/5.h \
	stage/pss/minislider/5.i12.h \
	stage/pss/minislider/5.0.h \
	stage/pss/minislider/5.i10.h \
	stage/pss/minislider/6.h \
	stage/pss/minislider/6.2.h

################################################################################

GFX_DEP := \
	data/gfx/glbfont/0.rgba16.h \
	data/gfx/glbfont/1.rgba16.h \
	data/gfx/glbfont/2.rgba16.h \
	data/gfx/glbfont/3.rgba16.h \
	data/gfx/glbfont/4.rgba16.h \
	data/gfx/glbfont/5.rgba16.h \
	data/gfx/glbfont/6.rgba16.h \
	data/gfx/glbfont/7.rgba16.h \
	data/gfx/glbfont/8.rgba16.h \
	data/gfx/glbfont/9.rgba16.h \
	data/gfx/glbfont/a.rgba16.h \
	data/gfx/glbfont/b.rgba16.h \
	data/gfx/glbfont/c.rgba16.h \
	data/gfx/glbfont/d.rgba16.h \
	data/gfx/glbfont/e.rgba16.h \
	data/gfx/glbfont/f.rgba16.h \
	data/gfx/glbfont/g.rgba16.h \
	data/gfx/glbfont/h.rgba16.h \
	data/gfx/glbfont/i.rgba16.h \
	data/gfx/glbfont/k.rgba16.h \
	data/gfx/glbfont/l.rgba16.h \
	data/gfx/glbfont/m.rgba16.h \
	data/gfx/glbfont/n.rgba16.h \
	data/gfx/glbfont/o.rgba16.h \
	data/gfx/glbfont/p.rgba16.h \
	data/gfx/glbfont/r.rgba16.h \
	data/gfx/glbfont/s.rgba16.h \
	data/gfx/glbfont/t.rgba16.h \
	data/gfx/glbfont/u.rgba16.h \
	data/gfx/glbfont/w.rgba16.h \
	data/gfx/glbfont/y.rgba16.h \
	data/gfx/glbfont/squote.rgba16.h \
	data/gfx/glbfont/dquote.rgba16.h \
	data/gfx/glbfont/multiply.rgba16.h \
	data/gfx/glbfont/coin.rgba16.h \
	data/gfx/glbfont/mario.rgba16.h \
	data/gfx/glbfont/star.rgba16.h \
	data/gfx/staff/3.rgba16.h \
	data/gfx/staff/4.rgba16.h \
	data/gfx/staff/6.rgba16.h \
	data/gfx/staff/a.rgba16.h \
	data/gfx/staff/b.rgba16.h \
	data/gfx/staff/c.rgba16.h \
	data/gfx/staff/d.rgba16.h \
	data/gfx/staff/e.rgba16.h \
	data/gfx/staff/f.rgba16.h \
	data/gfx/staff/g.rgba16.h \
	data/gfx/staff/h.rgba16.h \
	data/gfx/staff/i.rgba16.h \
	data/gfx/staff/j.rgba16.h \
	data/gfx/staff/k.rgba16.h \
	data/gfx/staff/l.rgba16.h \
	data/gfx/staff/m.rgba16.h \
	data/gfx/staff/n.rgba16.h \
	data/gfx/staff/o.rgba16.h \
	data/gfx/staff/p.rgba16.h \
	data/gfx/staff/q.rgba16.h \
	data/gfx/staff/r.rgba16.h \
	data/gfx/staff/s.rgba16.h \
	data/gfx/staff/t.rgba16.h \
	data/gfx/staff/u.rgba16.h \
	data/gfx/staff/v.rgba16.h \
	data/gfx/staff/w.rgba16.h \
	data/gfx/staff/x.rgba16.h \
	data/gfx/staff/y.rgba16.h \
	data/gfx/staff/z.rgba16.h \
	data/gfx/staff/period.rgba16.h \
	data/gfx/lgfont/0.ia4.h \
	data/gfx/lgfont/1.ia4.h \
	data/gfx/lgfont/2.ia4.h \
	data/gfx/lgfont/3.ia4.h \
	data/gfx/lgfont/4.ia4.h \
	data/gfx/lgfont/5.ia4.h \
	data/gfx/lgfont/6.ia4.h \
	data/gfx/lgfont/7.ia4.h \
	data/gfx/lgfont/8.ia4.h \
	data/gfx/lgfont/9.ia4.h \
	data/gfx/lgfont/u_a.ia4.h \
	data/gfx/lgfont/u_b.ia4.h \
	data/gfx/lgfont/u_c.ia4.h \
	data/gfx/lgfont/u_d.ia4.h \
	data/gfx/lgfont/u_e.ia4.h \
	data/gfx/lgfont/u_f.ia4.h \
	data/gfx/lgfont/u_g.ia4.h \
	data/gfx/lgfont/u_h.ia4.h \
	data/gfx/lgfont/u_i.ia4.h \
	data/gfx/lgfont/u_j.ia4.h \
	data/gfx/lgfont/u_k.ia4.h \
	data/gfx/lgfont/u_l.ia4.h \
	data/gfx/lgfont/u_m.ia4.h \
	data/gfx/lgfont/u_n.ia4.h \
	data/gfx/lgfont/u_o.ia4.h \
	data/gfx/lgfont/u_p.ia4.h \
	data/gfx/lgfont/u_q.ia4.h \
	data/gfx/lgfont/u_r.ia4.h \
	data/gfx/lgfont/u_s.ia4.h \
	data/gfx/lgfont/u_t.ia4.h \
	data/gfx/lgfont/u_u.ia4.h \
	data/gfx/lgfont/u_v.ia4.h \
	data/gfx/lgfont/u_w.ia4.h \
	data/gfx/lgfont/u_x.ia4.h \
	data/gfx/lgfont/u_y.ia4.h \
	data/gfx/lgfont/u_z.ia4.h \
	data/gfx/lgfont/l_a.ia4.h \
	data/gfx/lgfont/l_b.ia4.h \
	data/gfx/lgfont/l_c.ia4.h \
	data/gfx/lgfont/l_d.ia4.h \
	data/gfx/lgfont/l_e.ia4.h \
	data/gfx/lgfont/l_f.ia4.h \
	data/gfx/lgfont/l_g.ia4.h \
	data/gfx/lgfont/l_h.ia4.h \
	data/gfx/lgfont/l_i.ia4.h \
	data/gfx/lgfont/l_j.ia4.h \
	data/gfx/lgfont/l_k.ia4.h \
	data/gfx/lgfont/l_l.ia4.h \
	data/gfx/lgfont/l_m.ia4.h \
	data/gfx/lgfont/l_n.ia4.h \
	data/gfx/lgfont/l_o.ia4.h \
	data/gfx/lgfont/l_p.ia4.h \
	data/gfx/lgfont/l_q.ia4.h \
	data/gfx/lgfont/l_r.ia4.h \
	data/gfx/lgfont/l_s.ia4.h \
	data/gfx/lgfont/l_t.ia4.h \
	data/gfx/lgfont/l_u.ia4.h \
	data/gfx/lgfont/l_v.ia4.h \
	data/gfx/lgfont/l_w.ia4.h \
	data/gfx/lgfont/l_x.ia4.h \
	data/gfx/lgfont/l_y.ia4.h \
	data/gfx/lgfont/l_z.ia4.h \
	data/gfx/lgfont/arrow.ia4.h \
	data/gfx/lgfont/exclaim.ia4.h \
	data/gfx/lgfont/coin.ia4.h \
	data/gfx/lgfont/multiply.ia4.h \
	data/gfx/lgfont/paren_l.ia4.h \
	data/gfx/lgfont/paren_rl.ia4.h \
	data/gfx/lgfont/paren_r.ia4.h \
	data/gfx/lgfont/tilde.ia4.h \
	data/gfx/lgfont/period.ia4.h \
	data/gfx/lgfont/percent.ia4.h \
	data/gfx/lgfont/bullet.ia4.h \
	data/gfx/lgfont/comma.ia4.h \
	data/gfx/lgfont/apostrophe.ia4.h \
	data/gfx/lgfont/question.ia4.h \
	data/gfx/lgfont/star.ia4.h \
	data/gfx/lgfont/star_outline.ia4.h \
	data/gfx/lgfont/quote_l.ia4.h \
	data/gfx/lgfont/quote_r.ia4.h \
	data/gfx/lgfont/colon.ia4.h \
	data/gfx/lgfont/hyphen.ia4.h \
	data/gfx/lgfont/ampersand.ia4.h \
	data/gfx/lgfont/button_a.ia4.h \
	data/gfx/lgfont/button_b.ia4.h \
	data/gfx/lgfont/button_c.ia4.h \
	data/gfx/lgfont/button_z.ia4.h \
	data/gfx/lgfont/button_r.ia4.h \
	data/gfx/lgfont/button_cu.ia4.h \
	data/gfx/lgfont/button_cd.ia4.h \
	data/gfx/lgfont/button_cl.ia4.h \
	data/gfx/lgfont/button_cr.ia4.h \
	data/gfx/camera/camera.rgba16.h \
	data/gfx/camera/lakitu.rgba16.h \
	data/gfx/camera/cross.rgba16.h \
	data/gfx/camera/up.rgba16.h \
	data/gfx/camera/down.rgba16.h \
	data/gfx/message.ja_jp.h data/gfx/message.en_us.h \
	data/gfx/course.ja_jp.h data/gfx/course.en_us.h \
	data/gfx/shadow/circle.ia8.h \
	data/gfx/shadow/square.ia8.h \
	data/gfx/wipe/star.ia8.h \
	data/gfx/wipe/circle.ia8.h \
	data/gfx/wipe/mario.ia8.h \
	data/gfx/wipe/bowser.ia8.h \
	data/gfx/water/0.rgba16.h \
	data/gfx/water/1.rgba16.h \
	data/gfx/water/2.rgba16.h \
	data/gfx/water/mist.ia16.h \
	data/gfx/water/lava.rgba16.h \
	data/gfx/minimap/arrow.ia8.h

PLAYER_DEP := \
	shape/player/mario/metal.rgba16.h \
	shape/player/mario/button.rgba16.h \
	shape/player/mario/logo.rgba16.h \
	shape/player/mario/sideburn.rgba16.h \
	shape/player/mario/moustache.rgba16.h \
	shape/player/mario/eyes_open.rgba16.h \
	shape/player/mario/eyes_half.rgba16.h \
	shape/player/mario/eyes_closed.rgba16.h \
	shape/player/mario/eyes_left.rgba16.h \
	shape/player/mario/eyes_right.rgba16.h \
	shape/player/mario/eyes_up.rgba16.h \
	shape/player/mario/eyes_down.rgba16.h \
	shape/player/mario/eyes_dead.rgba16.h \
	shape/player/mario/wing_l.rgba16.h \
	shape/player/mario/wing_r.rgba16.h \
	shape/player/mario/metal_wing_l.rgba16.h \
	shape/player/mario/metal_wing_r.rgba16.h \
	$(MARIO_DEP) \
	shape/player/bubble/a.rgba16.h \
	shape/player/bubble/b.rgba16.h \
	shape/player/dust/0.ia16.h \
	shape/player/dust/1.ia16.h \
	shape/player/dust/2.ia16.h \
	shape/player/dust/3.ia16.h \
	shape/player/dust/4.ia16.h \
	shape/player/dust/5.ia16.h \
	shape/player/dust/6.ia16.h \
	shape/player/smoke/smoke.ia16.h \
	shape/player/wave/0.ia16.h \
	shape/player/wave/1.ia16.h \
	shape/player/wave/2.ia16.h \
	shape/player/wave/3.ia16.h \
	shape/player/wave/4.ia16.h \
	shape/player/wave/5.ia16.h \
	shape/player/ripple/0.ia16.h \
	shape/player/ripple/1.ia16.h \
	shape/player/ripple/2.ia16.h \
	shape/player/ripple/3.ia16.h \
	shape/player/sparkle/0.rgba16.h \
	shape/player/sparkle/1.rgba16.h \
	shape/player/sparkle/2.rgba16.h \
	shape/player/sparkle/3.rgba16.h \
	shape/player/sparkle/4.rgba16.h \
	shape/player/sparkle/5.rgba16.h \
	shape/player/splash/0.rgba16.h \
	shape/player/splash/1.rgba16.h \
	shape/player/splash/2.rgba16.h \
	shape/player/splash/3.rgba16.h \
	shape/player/splash/4.rgba16.h \
	shape/player/splash/5.rgba16.h \
	shape/player/splash/6.rgba16.h \
	shape/player/splash/7.rgba16.h \
	shape/player/droplet/droplet.rgba16.h \
	shape/player/glow/0.ia16.h \
	shape/player/glow/1.ia16.h \
	shape/player/glow/2.ia16.h \
	shape/player/glow/3.ia16.h \
	shape/player/glow/4.ia16.h

SHAPE_1I_DEP :=

SHAPE_2B_DEP := \
	shape/2b/chest/keyhole.rgba16.h \
	shape/2b/chest/inside.rgba16.h \
	shape/2b/chest/latch.rgba16.h \
	shape/2b/chest/outside.rgba16.h \
	$(CHEST_DEP)

COMMON_DEP := \
	shape/3common/bluecoinsw/side.rgba16.h \
	shape/3common/bluecoinsw/top.rgba16.h \
	$(BLUECOINSW_DEP) \
	shape/3common/bluecoinsw/map.h \
	shape/3common/amp/arc.rgba16.h \
	shape/3common/amp/eyes.rgba16.h \
	shape/3common/amp/body.rgba16.h \
	shape/3common/amp/mouth.rgba16.h \
	$(AMP_DEP) \
	shape/3common/cannonlid/lid.rgba16.h \
	$(CANNONLID_DEP) \
	shape/3common/cannonlid/map.h \
	shape/3common/cannon/side.rgba16.h \
	$(CANNON_DEP) \
	shape/3common/cannonbarrel/rim.rgba16.h \
	$(CANNONBARREL_DEP) \
	shape/3common/chuckya/eyes.rgba16.h \
	shape/3common/chuckya/purple.rgba16.h \
	shape/3common/chuckya/red.rgba16.h \
	shape/3common/chuckya/purple_l.rgba16.h \
	shape/3common/chuckya/purple_r.rgba16.h \
	$(CHUCKYA_DEP) \
	shape/3common/purplesw/side.rgba16.h \
	shape/3common/purplesw/top.rgba16.h \
	$(PURPLESW_DEP) \
	shape/3common/purplesw/map.h \
	shape/3common/lift/side.rgba16.h \
	shape/3common/lift/face.rgba16.h \
	$(LIFT_DEP) \
	shape/3common/lift/map.h \
	shape/3common/heart/heart.rgba16.h \
	$(HEART_DEP) \
	shape/3common/flyguy/cloth.rgba16.h \
	shape/3common/flyguy/face.rgba16.h \
	shape/3common/flyguy/propeller.ia16.h \
	$(FLYGUY_DEP) \
	shape/3common/block/0.rgba16.h \
	shape/3common/block/1.rgba16.h \
	$(BLOCK_DEP) \
	shape/3common/block/map.h \
	shape/3common/itembox/face_b.rgba16.h \
	shape/3common/itembox/side_b.rgba16.h \
	shape/3common/itembox/face_g.rgba16.h \
	shape/3common/itembox/side_g.rgba16.h \
	shape/3common/itembox/face_r.rgba16.h \
	shape/3common/itembox/side_r.rgba16.h \
	shape/3common/itembox/face_y.rgba16.h \
	shape/3common/itembox/side_y.rgba16.h \
	$(ITEMBOX_DEP) \
	shape/3common/goomba/body.rgba16.h \
	shape/3common/goomba/head_open.rgba16.h \
	shape/3common/goomba/head_closed.rgba16.h \
	$(GOOMBA_DEP) \
	shape/3common/bobomb/black_l.rgba16.h \
	shape/3common/bobomb/black_r.rgba16.h \
	shape/3common/bobomb/red_l.rgba16.h \
	shape/3common/bobomb/red_r.rgba16.h \
	shape/3common/bobomb/eyes_open.rgba16.h \
	shape/3common/bobomb/eyes_closed.rgba16.h \
	$(BOBOMB_DEP) \
	shape/3common/pushblock/pushblock.rgba16.h \
	$(PUSHBLOCK_DEP) \
	shape/3common/pushblock/map.h \
	shape/3common/dotbox/dot.rgba16.h \
	shape/3common/dotbox/mark.rgba16.h \
	$(DOTBOX_DEP) \
	shape/3common/dotbox/map.h \
	$(TESTLIFT_DEP) \
	shape/3common/testlift/map.h \
	$(SHELL_OLD_DEP) \
	shape/3common/shell/bottom.rgba16.h \
	shape/3common/shell/top.rgba16.h \
	$(SHELL_DEP)

GLOBAL_DEP := \
	shape/global/puff/puff.ia16.h \
	shape/global/explosion/0.rgba16.h \
	shape/global/explosion/1.rgba16.h \
	shape/global/explosion/2.rgba16.h \
	shape/global/explosion/3.rgba16.h \
	shape/global/explosion/4.rgba16.h \
	shape/global/explosion/5.rgba16.h \
	shape/global/explosion/6.rgba16.h \
	shape/global/butterfly/wing.rgba16.h \
	$(BUTTERFLY_DEP) \
	shape/global/coin/0.ia16.h \
	shape/global/coin/1.ia16.h \
	shape/global/coin/2.ia16.h \
	shape/global/coin/3.ia16.h \
	shape/global/pipe/side.rgba16.h \
	shape/global/pipe/top.rgba16.h \
	$(PIPE_DEP) \
	shape/global/pipe/map.h \
	shape/global/door/a_face.rgba16.h \
	shape/global/door/a_side.rgba16.h \
	shape/global/door/b_face.rgba16.h \
	shape/global/door/b_side.rgba16.h \
	shape/global/door/d_face.rgba16.h \
	shape/global/door/d_side.rgba16.h \
	shape/global/door/e_face.rgba16.h \
	shape/global/door/e_side.rgba16.h \
	shape/global/door/f_face.rgba16.h \
	shape/global/door/f_side.rgba16.h \
	shape/global/door/star.rgba16.h \
	shape/global/door/star1.rgba16.h \
	shape/global/door/star3.rgba16.h \
	shape/global/door/keyhole.rgba16.h \
	$(DOOR_DEP) \
	$(DOORKEY_DEP) \
	shape/global/flame/0.ia16.h \
	shape/global/flame/1.ia16.h \
	shape/global/flame/2.ia16.h \
	shape/global/flame/3.ia16.h \
	shape/global/flame/4.ia16.h \
	shape/global/flame/5.ia16.h \
	shape/global/flame/6.ia16.h \
	shape/global/flame/7.ia16.h \
	shape/global/fish/fish.rgba16.h \
	$(FISH_DEP) \
	shape/global/stone/stone.rgba16.h \
	shape/global/leaf/leaf.rgba16.h \
	shape/global/map/door.h \
	shape/global/map/13002018.h \
	shape/global/cap/metal.rgba16.h \
	shape/global/cap/logo.rgba16.h \
	shape/global/cap/wing_l.rgba16.h \
	shape/global/cap/wing_r.rgba16.h \
	shape/global/cap/metal_wing_l.rgba16.h \
	shape/global/cap/metal_wing_r.rgba16.h \
	$(CAP_DEP) \
	shape/global/meter/0_l.rgba16.h \
	shape/global/meter/0_r.rgba16.h \
	shape/global/meter/8.rgba16.h \
	shape/global/meter/7.rgba16.h \
	shape/global/meter/6.rgba16.h \
	shape/global/meter/5.rgba16.h \
	shape/global/meter/4.rgba16.h \
	shape/global/meter/3.rgba16.h \
	shape/global/meter/2.rgba16.h \
	shape/global/meter/1.rgba16.h \
	shape/global/1up/1up.rgba16.h \
	shape/global/powerstar/star.rgba16.h \
	shape/global/powerstar/eye.rgba16.h \
	$(POWERSTAR_DEP) \
	shape/global/sand/sand.rgba16.h \
	shape/global/shard/cork.rgba16.h \
	$(SHADESTAR_DEP) \
	shape/global/snow/snow.rgba16.h \
	shape/global/signpost/wood.rgba16.h \
	shape/global/signpost/face.rgba16.h \
	$(SIGNPOST_DEP) \
	shape/global/signpost/map.h \
	shape/global/tree/a_l.rgba16.h \
	shape/global/tree/a_r.rgba16.h \
	shape/global/tree/b.rgba16.h \
	shape/global/tree/c.rgba16.h \
	shape/global/tree/e.rgba16.h \
	$(TREE_DEP)

CONTCHECK_DEP := \
	stage/contcheck/banner.i4.h \
	stage/contcheck/error.i4.h \
	stage/contcheck/pad.rgba16.h \
	stage/contcheck/stick.rgba16.h \
	stage/contcheck/substick.rgba16.h \
	stage/contcheck/triggerLeft.rgba16.h \
	stage/contcheck/triggerRight.rgba16.h

TITLE_LOGO_DEP := \
	stage/title/wood.rgba16.h \
	stage/title/marble.rgba16.h \
	stage/title/subtitle.i4.h \
	stage/title/trademark.rgba16.h \
	$(LOGO_DEP)

TEXTURE_I_DEP := \
	data/texture/i0.rgba16.h \
	data/texture/i2.rgba16.h \
	data/texture/i10.rgba16.h \
	data/texture/i12.rgba16.h \
	data/texture/i13.rgba16.h \
	data/texture/i21.rgba16.h

STAGE1_DEP := \
	stage/stage1/banner_ah.rgba16.h \
	stage/stage1/banner_al.rgba16.h \
	stage/stage1/banner_bh.rgba16.h \
	stage/stage1/banner_bl.rgba16.h \
	stage/stage1/banner_ch.rgba16.h \
	stage/stage1/banner_cl.rgba16.h \
	stage/stage1/banner_dh.rgba16.h \
	stage/stage1/banner_dl.rgba16.h \
	stage/stage1/ba_cable.rgba16.h \
	stage/stage1/ba_pole.rgba16.h \
	stage/stage1/ch_donkey_h.rgba16.h \
	stage/stage1/ch_donkey_l.rgba16.h \
	stage/stage1/ch_kinoko_h.rgba16.h \
	stage/stage1/ch_kinoko_l.rgba16.h \
	stage/stage1/ch_kinopio_h.rgba16.h \
	stage/stage1/ch_kinopio_l.rgba16.h \
	stage/stage1/ch_kuppa_h.rgba16.h \
	stage/stage1/ch_kuppa_l.rgba16.h \
	stage/stage1/ch_luizi_h.rgba16.h \
	stage/stage1/ch_luizi_l.rgba16.h \
	stage/stage1/ch_mario_h.rgba16.h \
	stage/stage1/ch_mario_l.rgba16.h \
	stage/stage1/ch_peach_h.rgba16.h \
	stage/stage1/ch_peach_l.rgba16.h \
	stage/stage1/ch_teresa_h.rgba16.h \
	stage/stage1/ch_teresa_l.rgba16.h \
	stage/stage1/ch_wario_h.rgba16.h \
	stage/stage1/ch_wario_l.rgba16.h \
	stage/stage1/ch_yossy_h.rgba16.h \
	stage/stage1/ch_yossy_l.rgba16.h \
	stage/stage1/hosi_face.rgba16.h \
	stage/stage1/tr_checker.rgba16.h \
	stage/stage1/tr_hosi.i8.h \
	stage/stage1/tr_rainbow.rgba16.h \
	$(RAINBOWROAD_DEP) \
	stage/stage1/rainbowroad/map.h

PSS_DEP := \
	stage/pss/0.rgba16.h \
	stage/pss/1.ia16.h \
	stage/pss/2.rgba16.h \
	stage/pss/3.rgba16.h \
	$(CHASER_DEP) \
	$(MINISLIDER_DEP) \
	stage/pss/minislider/map.h

CIRNO_DEP := \
	data/video/cirno/0.rgba16.h \
	data/video/cirno/1.rgba16.h \
	data/video/cirno/2.rgba16.h \
	data/video/cirno/3.rgba16.h \
	data/video/cirno/4.rgba16.h \
	data/video/cirno/5.rgba16.h \
	data/video/cirno/6.rgba16.h \
	data/video/cirno/7.rgba16.h \
	data/video/cirno/8.rgba16.h \
	data/video/cirno/9.rgba16.h \
	data/video/cirno/10.rgba16.h \
	data/video/cirno/11.rgba16.h \
	data/video/cirno/12.rgba16.h \
	data/video/cirno/13.rgba16.h \
	data/video/cirno/14.rgba16.h \
	data/video/cirno/15.rgba16.h \
	data/video/cirno/16.rgba16.h \
	data/video/cirno/17.rgba16.h \
	data/video/cirno/18.rgba16.h \
	data/video/cirno/19.rgba16.h

DEP := \
	src/en_us.h \
	src/caption.en_us.h \
	$(GFX_DEP) \
	$(PLAYER_DEP) \
	$(SHAPE_1I_DEP) \
	$(SHAPE_2B_DEP) \
	$(COMMON_DEP) \
	$(GLOBAL_DEP) \
	$(CONTCHECK_DEP) \
	$(TITLE_LOGO_DEP) \
	$(TEXTURE_I_DEP) \
	$(STAGE1_DEP) \
	$(PSS_DEP) \
	$(CIRNO_DEP)

src/message.c: src/en_us.h src/caption.en_us.h
data/gfx.c: $(GFX_DEP)
shape/player/gfx.c: $(PLAYER_DEP)
shape/1i/gfx.c: $(SHAPE_1I_DEP)
shape/2b/gfx.c: $(SHAPE_2B_DEP)
shape/3common/gfx.c: $(COMMON_DEP)
shape/global/gfx.c: $(GLOBAL_DEP)
stage/contcheck/gfx.c: $(CONTCHECK_DEP)
stage/title/logo.c: $(TITLE_LOGO_DEP)
data/texture/i.c: $(TEXTURE_I_DEP)
stage/stage1/gfx.c: $(STAGE1_DEP)
stage/pss/gfx.c: $(PSS_DEP) $(BUILD)/data/texture/i.szp.h
data/video/cirno.c: $(CIRNO_DEP)

# Player
$(MARIO_DEP)&: shape/player/mario/mario.glb tools/gltf; tools/gltf $<
# Shape2B
$(CHEST_DEP)&: shape/2b/chest/chest.glb tools/gltf; tools/gltf $<
# Common
$(BLUECOINSW_DEP)&: shape/3common/bluecoinsw/bluecoinsw.glb tools/gltf; tools/gltf $<
$(AMP_DEP)&: shape/3common/amp/amp.glb tools/gltf; tools/gltf $<
$(CANNONLID_DEP)&: shape/3common/cannonlid/cannonlid.glb tools/gltf; tools/gltf $<
$(CANNON_DEP)&: shape/3common/cannon/cannon.glb tools/gltf; tools/gltf $<
$(CANNONBARREL_DEP)&: shape/3common/cannonbarrel/cannonbarrel.glb tools/gltf; tools/gltf $<
$(CHUCKYA_DEP)&: shape/3common/chuckya/chuckya.glb tools/gltf; tools/gltf $<
$(PURPLESW_DEP)&: shape/3common/purplesw/purplesw.glb tools/gltf; tools/gltf $<
$(LIFT_DEP)&: shape/3common/lift/lift.glb tools/gltf; tools/gltf $<
$(HEART_DEP)&: shape/3common/heart/heart.glb tools/gltf; tools/gltf $<
$(FLYGUY_DEP)&: shape/3common/flyguy/flyguy.glb tools/gltf; tools/gltf $<
$(BLOCK_DEP)&: shape/3common/block/block.glb tools/gltf; tools/gltf $<
$(ITEMBOX_DEP)&: shape/3common/itembox/itembox.glb tools/gltf; tools/gltf $<
$(GOOMBA_DEP)&: shape/3common/goomba/goomba.glb tools/gltf; tools/gltf $<
$(BOBOMB_DEP)&: shape/3common/bobomb/bobomb.glb tools/gltf; tools/gltf $<
$(PUSHBLOCK_DEP)&: shape/3common/pushblock/pushblock.glb tools/gltf; tools/gltf $<
$(DOTBOX_DEP)&: shape/3common/dotbox/dotbox.glb tools/gltf; tools/gltf $<
$(TESTLIFT_DEP)&: shape/3common/testlift/testlift.glb tools/gltf; tools/gltf $<
$(SHELL_OLD_DEP)&: shape/3common/shell/shell_old.glb tools/gltf; tools/gltf $<
$(SHELL_DEP)&: shape/3common/shell/shell.glb tools/gltf; tools/gltf $<
# Global
$(BUTTERFLY_DEP)&: shape/global/butterfly/butterfly.glb tools/gltf; tools/gltf $<
$(PIPE_DEP)&: shape/global/pipe/pipe.glb tools/gltf; tools/gltf $<
$(DOOR_DEP)&: shape/global/door/door.glb tools/gltf; tools/gltf $<
$(DOORKEY_DEP)&: shape/global/doorkey/doorkey.glb tools/gltf; tools/gltf $<
$(FISH_DEP)&: shape/global/fish/fish.glb tools/gltf; tools/gltf $<
$(CAP_DEP)&: shape/global/cap/cap.glb tools/gltf; tools/gltf $<
$(POWERSTAR_DEP)&: shape/global/powerstar/powerstar.glb tools/gltf; tools/gltf $<
$(SHADESTAR_DEP)&: shape/global/shadestar/shadestar.glb tools/gltf; tools/gltf $<
$(SIGNPOST_DEP)&: shape/global/signpost/signpost.glb tools/gltf; tools/gltf $<
$(TREE_DEP)&: shape/global/tree/tree.glb tools/gltf; tools/gltf $<
# Title
$(LOGO_DEP)&: stage/title/logo.glb tools/gltf; tools/gltf $<
# Stage1
$(RAINBOWROAD_DEP)&: stage/stage1/rainbowroad/rainbowroad.glb tools/gltf; tools/gltf $<
# PSS
$(MINISLIDER_DEP)&: stage/pss/minislider/minislider.glb tools/gltf; tools/gltf $<

# Common
shape/3common/bluecoinsw/map.h: shape/3common/bluecoinsw/bluecoinsw.obj tools/obj; tools/obj $< $@
shape/3common/cannonlid/map.h: shape/3common/cannonlid/cannonlid.obj tools/obj; tools/obj $< $@
shape/3common/purplesw/map.h: shape/3common/purplesw/purplesw.obj tools/obj; tools/obj $< $@
shape/3common/lift/map.h: shape/3common/lift/lift.obj tools/obj; tools/obj $< $@
shape/3common/block/map.h: shape/3common/block/block.obj tools/obj; tools/obj $< $@
shape/3common/pushblock/map.h: shape/3common/pushblock/pushblock.obj tools/obj; tools/obj $< $@
shape/3common/dotbox/map.h: shape/3common/dotbox/dotbox.obj tools/obj; tools/obj $< $@
shape/3common/testlift/map.h: shape/3common/testlift/testlift.obj tools/obj; tools/obj $< $@
# Global
shape/global/pipe/map.h: shape/global/pipe/pipe.obj tools/obj; tools/obj $< $@
shape/global/map/door.h: shape/global/map/door.obj tools/obj; tools/obj $< $@
shape/global/map/13002018.h: shape/global/map/13002018.obj tools/obj; tools/obj $< $@
shape/global/signpost/map.h: shape/global/signpost/signpost.obj tools/obj; tools/obj $< $@
# Stage1
stage/stage1/rainbowroad/map.h: stage/stage1/rainbowroad/rainbowroad.obj tools/obj tools/makeslip
	tools/obj $< $@
	tools/makeslip $@
# PSS
stage/pss/minislider/map.h: stage/pss/minislider/minislider.obj tools/obj; tools/obj $< $@
