impl1:
    push rbp
    mov rbp, rsp
    sub rsp, 0x20
    mov [rbp-0x18], rdi         ; unused argument _
    mov [rbp-0x4], 0x0          ; n = 0
    jmp .cond
.loop:
    lea rdi, [rip+0x2007da]  # 201060 <m>
    call pthread_mutex_lock
    mov rax, [rip+0x200796]  # 201028 <value>    ; rax = value
    add rax, 0x1                                 ; rax = rax + 1
    mov [rip+0x20078b], rax  # 201028 <value>    ; value = rax
    lea rdi, [rip+0x2007bc]  # 201060 <m>
    call pthread_mutex_unlock
    add [rbp-0x4], 0x1                           ; n = n + 1
.cond:
    cmp [rbp-0x4], 0x98967f     ; n <= 9999999
    jle .loop
    mov eax, 0x0                ; return NULL
    leave
    ret
