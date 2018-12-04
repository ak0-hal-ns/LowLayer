    extern _GLOBAL_OFFSET_TABLE_

    global _start

    extern sofun

    global msg:data (msg.end - msg)    ; size required

    section .rodata
msg:
    db "SO function called", 10
.end:
    db 0

    section .text
_start:
    call sofun wrt ..plt

    mov rdi, 0
    mov rax, 60
    syscall
