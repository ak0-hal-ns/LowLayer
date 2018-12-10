    extern _GLOBAL_OFFSET_TABLE_

    global sofun:function

    extern msg

    section .text
sofun:
    mov rax, 1
    mov rdi, 1
    mov rsi, [rel msg wrt ..got]
    mov rdx, 19
    syscall
    ret

