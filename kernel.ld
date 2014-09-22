/*
* define the program entry point.
*/
ENTRY(_start)

/*
* start memory at 0x8000, stack and ATAGS go before
*/
MEMORY {
  ram : ORIGIN = 0x8000, LENGTH = 0x10000
}

SECTIONS {
  /*
  * init contains the bootloader code
  */
  .init : { *(.init) } > ram

  /*
  * all text goes next
  */
  .text : { *(.text) } > ram

  /*
  * followed by bss
  */
  .bss : { *(.bss) } > ram

  /*
  * and last data
  */
  .data : { *(.data) } > ram

  /*
  * anything else gets discarded
  */
  /DISCARD/ : {
    *(*)
  }
}
