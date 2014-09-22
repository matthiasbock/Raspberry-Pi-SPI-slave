.section .init
	
.global _start

_start:
   mov sp, #0x8000
   bl main
   b _start

@ wait routine is simpler in assembly
@ wait_ms & wait_us depend on this as well as SPI_SLAVE
@ do not change unless you retest those functions
.globl wait
wait:
    sub r0, #1
    cmp r0, #0
    bne wait
    bx lr
