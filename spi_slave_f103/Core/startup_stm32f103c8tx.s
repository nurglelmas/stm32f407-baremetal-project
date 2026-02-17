.syntax unified
.cpu cortex-m3
.thumb

.global Reset_Handler
.extern main

/* Vector table */
.section .isr_vector,"a",%progbits
.type g_pfnVectors, %object
g_pfnVectors:
    .word _estack          /* Stack pointer */
    .word Reset_Handler    /* Reset handler */
    .word 0                /* NMI */
    .word 0                /* HardFault */
    .word 0
    .word 0
    .word 0
    .word 0
    .word 0
    .word 0
    .word 0
    .word 0
    .word 0
    .word 0
    .word 0
    .word 0

/* Reset Handler */
.section .text.Reset_Handler
Reset_Handler:
    bl main
    b .

