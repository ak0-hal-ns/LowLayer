    ;; init
    native "init", init
    mov pc, prog_stub
    jmp next

    
    ;; exit
    native "exit", exit
    mov rax, 60
    xor rdi, rdi
    syscall
