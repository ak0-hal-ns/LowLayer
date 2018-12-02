    global _start

    %include "src/util.inc"
    %include "src/macro.inc"
    %include "src/words.inc"


    section .bss

    resq 1023
rstack_base:
    resq 1
input_buf:
    resb 1024


    section .rodata
msg_err_find:
    db ":no such word in the dictionary.", 10, 0
msg_test:
    db "Hello, world!", 10, 0


    section .data

last_word:
    dq _last_word

dstack_base:
    dq 0

prog_stub:
    dq xt_interpreter
    dq xt_exit


    section .text

next:
    mov xt, [pc]
    add pc, cellsize
    jmp [xt]

_start:
    jmp i_init
