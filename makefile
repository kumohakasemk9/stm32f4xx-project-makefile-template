CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m4 -g3 -mfpu=fpv4-sp-d16 -I /home/owner/harddisk_home/programs/STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/ST/STM32F4xx/Include -I /home/owner/harddisk_home/programs/CMSIS_5-5.7.0/CMSIS/Core/Include
OBJS = main.o start.o

all: $(OBJS)
	$(CC) $^ -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -nostartfiles -T flash.ld -o output.elf
	arm-none-eabi-objcopy -O srec output.elf output.srec
	arm-none-eabi-objdump -hdS output.elf > build_report
	arm-none-eabi-objdump -h output.elf

clean:
	rm -f build_report output.elf output.srec $(OBJS)
