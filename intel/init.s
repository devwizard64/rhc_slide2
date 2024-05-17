.intel_syntax

_start:
	sub %rsp,40
	lea %r9d,[%rsp+32]
	mov %r8,0x40
	mov %edx,0x800000
	mov %rcx,[%rip+dram]
	call [%rip+__imp_VirtualProtect]
	add %rsp,40
	ret

.bss

__imp_VirtualProtect: .space 8
dram: .space 8
