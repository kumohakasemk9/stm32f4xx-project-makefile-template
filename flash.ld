/*
Copyright (C) 2022 kumohakase (license: https://creativecommons.org/licenses/by/2.5/)
STM32F4xx section address definition file (ldscript)
Please consider supporting me using kofi.com https://ko-fi.com/kumohakase
*/

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
