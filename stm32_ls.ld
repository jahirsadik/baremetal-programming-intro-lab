ENTRY(Reset_Handler)
MEMORY
{
    FLASH(rx): ORIGIN = 0x08000000, LENGTH = 512K
    SRAM(rwx): ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS
{
    .text :
    {
        *(.isr_vector)
        *(.text)
        *(.rodata)
        . = ALIGN(4);
        _eotext = .;
    } > FLASH

    .data :
    {
        _sodata = .;
        *(.data)
        . = ALIGN(4);
        _eodata = .;
    } > SRAM AT > FLASH

    .bss :
    {
        _sobss = .;
        *(.bss)
        *(COMMON)
        . = ALIGN(4);
        _eobss = .;
    } > SRAM
}