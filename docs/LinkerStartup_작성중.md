---
title: 링커_링커스크립트_Startup(작업중)  
author: 이우택 (wootaik@gmail.com)  
date: Sep 01 2016  
...

# 링커_링커스크립트_Startup(작업중)

http://www.bravegnu.org/gnu-eprog/linker.html#_symbol_resolution

http://www.bravegnu.org/gnu-eprog/lds.html

http://www.bravegnu.org/gnu-eprog/exc-handle.html

http://www.bravegnu.org/gnu-eprog/c-startup.html

## 실습

```
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(Reset_Handler)

MEMORY
{
	FLASH_1_cached(RX) : ORIGIN = 0x08000000, LENGTH = 0x100000
	FLASH_1_uncached(RX) : ORIGIN = 0x0C000000, LENGTH = 0x100000
	PSRAM_1(!RX) : ORIGIN = 0x10000000, LENGTH = 0x10000
	DSRAM_1_system(!RX) : ORIGIN = 0x20000000, LENGTH = 0x10000
	DSRAM_2_comm(!RX) : ORIGIN = 0x30000000, LENGTH = 0x8000
}

stack_size = DEFINED(stack_size) ? stack_size : 2048;
no_init_size = 64;

SECTIONS
{
  .text :
  {
      sText = .;
          ...(omitted)...
      /* C++ Support */
          ...(omitted)...
      /* .ctors */
          ...(omitted)...
      /* .dtors */
          ...(omitted)...
      *(.rodata .rodata.*)
      . = ALIGN(4);        
  } > FLASH_1_cached AT > FLASH_1_uncached

  /* Exception handling, exidx needs a dedicated section */
  .ARM.extab :
  {
          ...(omitted)...
  } > FLASH_1_cached AT > FLASH_1_uncached
          ...(omitted)...

  /* DSRAM layout (Lowest to highest)*/
  Stack (NOLOAD) :
  {
          ...(omitted)...
  } > PSRAM_1

  .ram_code :
  {
          ...(omitted)...
  } > PSRAM_1 AT > FLASH_1_uncached

  PSRAM_DATA :
  {
          ...(omitted)...
  } > PSRAM_1 AT > FLASH_1_uncached

  PSRAM_BSS (NOLOAD) :
  {       ...(omitted)...
  } > PSRAM_1

  /* Standard DATA and user defined DATA/BSS/CONST sections */
  .data :
  {
          ...(omitted)...
      * (.data);
      * (.data*);
      KEEP(*(.preinit_array))
      KEEP(*(.init_array))
      KEEP(*(.fini_array))
  } > DSRAM_1_system AT > FLASH_1_uncached

  /* BSS section */
  .bss (NOLOAD) :
  {
        ...(omitted)...
      * (.bss);
      * (.bss*);
        ...(omitted)...
  } > DSRAM_1_system
        ...(omitted)...

  .no_init ORIGIN(DSRAM_1_system) + LENGTH(DSRAM_1_system) - no_init_size (NOLOAD) :
  {
          ...(omitted)...
  } > DSRAM_1_system

  DSRAM2_DATA :
  {
      *(DSRAM2_DATA)      
  } > DSRAM_2_comm AT > FLASH_1_uncached

  DSRAM2_BSS (NOLOAD) :
  {
      *(ETH_RAM)
      *(USB_RAM)
      *(DSRAM2_BSS)   
  } > DSRAM_2_comm

}

```


## 요약
