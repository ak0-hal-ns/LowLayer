    global _start

    %include "util.inc"
    %include "macro.inc"
    %include "words.inc"


    section .bss

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

prog_stub:
.loop:
    dq xt_inbuf
    dq xt_word
    dq xt_drop
    dq xt_inbuf
    dq xt_find
    dq xt_branch_end
    dq xt_wh2xt
    dq xt_execute
    dq xt_loop
.end:
    dq xt_exit


    section .text

next:
    mov xt, [pc]
    add pc, cellsize
    jmp [xt]

_start:
    jmp i_init
