PROJ_NAME = stm32f103c8
CC = arm-none-eabi-gcc

SRC = mainop.c
INC = mainop.h

SRC += systick.c
INC += systick.h

SRC += rcc.c
INC += rcc.h

SRC += gpio.c
INC += gpio.h

STARTUP = Startup_STM32F103C8.s
LD_SCRIPT = STM32F103C8TX_FLASH.ld
MAP_FILE = stm32f103c8.map
ELF_FILE = $(PROJ_NAME).elf
BIN_FILE = $(PROJ_NAME).bin
HEX_FILE = $(PROJ_NAME).hex
OBJCOPY = arm-none-eabi-objcopy

CFLAGS = -mcpu=cortex-m3
CFLAGS += --specs=nosys.specs
CFLAGS += -T"STM32F103C8TX_FLASH.ld"
CFLAGS += -Wl,-Map="${MAP_FILE}"
CFLAGS += -Wl,--gc-sections -static
CFLAGS += --specs=nano.specs -mfloat-abi=soft
CFLAGS += -mthumb 
CFLAGS += -Wl,--start-group -lc -lm -Wl,--end-group
CFLAGS += -g
#CFLAGS += --save-temps

sample.elf: ${INC} ${SRC} ${STARTUP}
	${CC} ${CFLAGS} ${SRC} ${STARTUP} -o  ${ELF_FILE}
	$(OBJCOPY) -O ihex $(ELF_FILE) $(HEX_FILE)
	$(OBJCOPY) -O binary $(PROJ_NAME).elf $(BIN_FILE)

.PHONY:clean

clean:
	rm ${ELF_FILE} ${BIN_FILE} ${HEX_FILE}

