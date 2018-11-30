    global _start

    %include "src/util.inc"
    %include "src/macro.inc"
    %include "src/words.inc"


    section .bss

input_buf:
    resb 1024
rstack_end:
    resq 1023
rstack_start:
    resq 1


    section .rodata
msg_err_find:
    db ":no such word in the dictionary.", 10, 0
msg_test:
    db "Hello, world!", 10, 0


    section .data

last_word:
    dq _last_word

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
