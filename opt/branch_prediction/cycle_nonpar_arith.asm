looper:
    mov rax, [rsi]
    xor rax, 0x1                ; depends on the previous inst.
    add [rdi], rax              ; depends on the previous inst.
    add rsi, 8
    add rdi, 8
    dec rcx
    jnz looper
