.set gp=64

.set EXEC_RD,0
.set EXEC_WR,4
.set EXEC_ADDR,8
.set EXEC_BASE,12
.set EXEC_SRAM,16
.set EXEC_BUF,20
.set EXEC_GetModuleHandleA,24
.set EXEC_GetProcAddress,28
.set EXEC_VirtualProtect,32

.set noreorder

.align 4

.globl exec
exec:
	bnezl $0,1f
	nop
1:
	subu $sp,24
	sw $ra,20($sp)
	sw $a0,24($sp)
	sw $a1,28($sp)
	sw $a2,32($sp)
	sw $a3,36($sp)

	mfc0 $t9,$12
	and $t8,$t9,~1
	bnez $a0,1f
	mtc0 $t8,$12

	# init

	sw $a1,execinfo
	move $t0,$a1

	lw $a0,EXEC_WR($t0)
	addu $a0,8
	jal __execmove
	lw $a1,EXEC_RD($t0)

.set noat
	lui $at,0xa400
	ldl $t1,4($at)
	ldr $t1,3($at)
	lw $t8,EXEC_BASE($t0)
	daddu $t1,$t8
	lui $at,%hi(execbase)
	sdl $t1,%lo(execbase+4)($at)
	sdr $t1,%lo(execbase+3)($at)
.set at

	la $a1,__imp_GetModuleHandleA
	jal __execrd
	lw $a0,EXEC_GetModuleHandleA($t0)
	la $a1,__imp_GetProcAddress
	jal __execrd
	lw $a0,EXEC_GetProcAddress($t0)
	la $a1,__imp_VirtualProtect
	jal __execrd
	lw $a0,EXEC_VirtualProtect($t0)

	lw $t2,EXEC_BUF($t0)

	move $a0,$t2
	la $a1,__intel_init
	jal __execdma
	li $a2,0x30-1
	la $a1,__imp_VirtualProtect
	jal __execwr
	addu $a0,$t2,0x30
	la $a1,execbase
	jal __execwr
	addu $a0,$t2,0x38

	jal __exec
	daddu $a0,$t1,$t2

1: # proc

	lw $t0,execinfo
.set noat
	lui $at,%hi(execbase)
	ldl $t1,%lo(execbase+4)($at)
	ldr $t1,%lo(execbase+3)($at)
.set at

	addu $t8,$sp,24
	sw $t8,execdata

	la $a0,__intel_proc-0x80000000
	jal __exec
	daddu $a0,$t1

	lw $v0,execdata

	mtc0 $t9,$12

	lw $ra,20($sp)
	j $ra
	addu $sp,24


# void __exec(u64 addr)
__exec:
	subu $sp,24
	sw $ra,20($sp)
	sdl $a0,28($sp)
	sdr $a0,27($sp)

	lw $a0,EXEC_RD($t0)
	addu $a0,8
	jal __execmove
	addu $a1,$sp,24

	ld $v0,0xa4010000

	lw $ra,20($sp)
	j $ra
	addu $sp,24


# void __execwr(u32 addr, void *dram)
__execwr:
	b __execdma
	li $a2,8-1

# void __execrd(u32 addr, void *dram)
__execrd:
	li $a2,-(8-1)

# void __execdma(u32 addr, void *dram, int len)
__execdma:
	subu $sp,24
	sw $ra,20($sp)
	sw $a1,28($sp)
	sw $a2,32($sp)

	daddu $a1,$a0,$t1

	lw $a0,EXEC_SRAM($t0)
	jal __execstore
	daddu $a0,$t1

	lw $a0,28($sp)
	li $a1,0x08000000
	lw $a2,32($sp)
.set noat
	lui $at,0xa460
	sw $a0,0($at)
	sw $a1,4($at)
	bltzl $a2,1f
	negu $a2
	b 2f
	sw $a2,8($at)
1:
	sw $a2,12($at)
2:
.set at

	lw $ra,20($sp)
	j $ra
	addu $sp,24


# void __execstore(u64 addr, u64 data)
__execstore:
	subu $sp,24
	sw $ra,20($sp)
	sdl $a0,28($sp)
	sdr $a0,27($sp)

	move $t8,$a1

	lw $a0,EXEC_ADDR($t0)
	jal __execmove
	addu $a1,$sp,24

	sd $t8,0xa4000000
	sd $t8,0xa4010000

	lw $ra,20($sp)
	j $ra
	addu $sp,24


# void __execmove(u32 dst, u32 src)
__execmove:
	li $a2,7
.set noat
	lui $at,0xa404
	sw $0,0($at)
	sw $a1,4($at)
	sw $a2,8($at)
	sw $0,0($at)
	sw $a0,4($at)
	j $ra
	sw $a2,12($at)
.set at


.align 4
.globl __intel_init
__intel_init:
	.incbin "build/intel/init.bin"

.align 4
.globl __intel_proc
__intel_proc:
	.incbin "build/intel/proc.bin"

.include "intel/share.s"
