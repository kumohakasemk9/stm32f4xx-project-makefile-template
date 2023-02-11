stm32f4xx-project-makefile-template
=====
STM32F4XX project files. CMSIS and stm32f4xx.h needed.  

This is template project for STM32F4XX, won't include CMSIS ant stm32f4xx.h.   
You have to download it too.  
Desined for load-in-RAM.  

CMSIS can be found in https://developer.arm.com/tools-and-software/embedded/cmsis.  
stm32f4xx.h can be found in https://www.keil.com/dd/chip/6103.htm.  
Or you can extract STM32F4 firmware package from ST, it includes both.  

Usage
=====
You have to adjust flash.ld's start address of RAM, according to  
your program location.. (Ex: 0x08000000 for ROM, depends.)  
Then you have to correct CMSIS path in makefile, stm32f4xx.h's path too.   
And you can modify main.c and then make (generates elf file and srec file) , enjoy!  

License
====
https://creativecommons.org/licenses/by/2.5/

Please consider supporting me using kofi.com https://ko-fi.com/kumohakase
