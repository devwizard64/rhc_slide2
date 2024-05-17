SECTIONS
{
	.text 0x200000000 : { *(.text.init) *(.text) }
	.rdata : { *(.rdata) }
	.data : { *(.data) }
	.bss : { *(.bss) }
	/DISCARD/ : { *(*) }
}
