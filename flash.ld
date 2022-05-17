MEMORY {
	RAM (wx) : ORIGIN = 0x20002000, LENGTH = 64K
}

SECTIONS {
	__stack = ORIGIN(RAM) + LENGTH(RAM);
	.text : {
		*(.vects);
		*(.text*);
		*(.rodata*);
	} >RAM
	.data : {
		*(.data);
		*(.data.*);
	} >RAM
	.bss : {
		*(.bss);
		*(.bss.*);
		*(COMMON);
	} >RAM
}
