    extern _GLOBAL_OFFSET_TABLE_

    global sofun:function       ; dynamically accessed by other files

    section .rodata
msg:
    db "SO function called", 10
.end:
    db 0

    section .text
sofun:
    mov rax, 1
    mov rdi, 1
    lea rsi, [rel msg]          ; rip relative
    mov rdx, msg.end - msg
    syscall
    ret

