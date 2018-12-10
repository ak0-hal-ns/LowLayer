    extern _GLOBAL_OFFSET_TABLE_

    extern printf
    global unwind

    section .rodata
format:
    db "%x", 10, 0

    section .text
unwind:
    push rbx
    mov rbx, rbp
.loop:
    test rbx, rbx
    jz .end
    mov rdi, format
    mov rsi, rbx
    call printf wrt ..plt
    mov rbx, [rbx]
    jmp .loop
.end:
    pop rbx
    ret
