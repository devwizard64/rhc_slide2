.bss

.globl __imp_GetModuleHandleA; __imp_GetModuleHandleA: .space 8
.globl __imp_GetProcAddress; __imp_GetProcAddress: .space 8
.globl __imp_VirtualProtect; __imp_VirtualProtect: .space 8

.include "build/intel/proclist.s"

.globl execbase; execbase: .space 8
.globl execinfo; execinfo: .space 4
.globl execdata; execdata: .space 4
.globl execflag; execflag: .space 4
.globl execstat; execstat: .space 4

.globl strp; strp: .space 8
.globl hWnd; hWnd: .space 8
.globl argv; argv: .space 16

.globl __aes_bss; __aes_bss:

.globl sbox; sbox: .space 256
.globl rsbox; rsbox: .space 256
.globl Rcon; Rcon: .space 16
.globl aeswork; aeswork: .space 256

.globl execbuff; execbuff:
