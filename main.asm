    global _start

    %include "macro.inc"
    %include "words.inc"


    section .bss

input_buf:
    resb 1024


    section .data

last_word:
    dq _last_word

prog_stub:
    dq xt_exit


    section .text

next:
    mov xt, [pc]
    add pc, 8
    jmp [xt]

_start:
    jmp i_init
