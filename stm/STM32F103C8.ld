/* Scatter file or linker script for STM32F103C8 */

ENTRY(Reset_Handler)

_end_stack = ORIGIN(SRAM) + LENGTH(SRAM);
_seg_start_data = ORIGIN(SRAM);

MEMORY
{
    /*memory information is available in STM datasheet*/
    FLASH_ROM (RX) : ORIGIN = 0x08000000, LENGTH = 64K
    SRAM      (RWX): ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
    . = ORIGIN(FLASH_ROM);
    .isr :  
    {
        . = ALIGN(4);
        KEEP(*(.isr*))
        . = ALIGN(4);
    }>FLASH_ROM


    .text :
    {
        . = ALIGN(4);
        _start_text = .;
        *(.text)
        *(.text*)
        . = ALIGN(4);
        _end_text = .;
    }>FLASH_ROM

    /*process initialization code*/
    .init :
    {
        . = ALIGN(4);
        *(.init)
        *(.init*)
        . = ALIGN(4);
    }>FLASH_ROM

    /*process termination code*/
    .fini :
    {
        . = ALIGN(4);
        *(.fini)
        *(.fini*)
        . = ALIGN(4);
    }>FLASH_ROM


    .rodata :
    {
        . = ALIGN(4);
        _start_rodata = .;
        KEEP(*(.rodata))
        KEEP(*(.rodata*))
        . = ALIGN(4);
        _end_rodata = .;
    }>FLASH_ROM

    _seg_start_data = LOADADDR(.data); 

    .data :
    {
        . = ALIGN(4);
        _start_data = .;
        KEEP(*(.data))
        KEEP(*(.data*))
        . = ALIGN(4);
        _end_data = .;
    } >SRAM AT> FLASH_ROM
    
        . = ALIGN(4);
    .bss :
    {
        _start_bss = .;
        KEEP(*(.bss))
        KEEP(*(.bss*))
        . = ALIGN(4);
        _end_bss = .;        
    }>SRAM
}

