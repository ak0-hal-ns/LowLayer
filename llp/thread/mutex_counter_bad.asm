impl1:
    push rbp
    mov rbp, rsp
    mov [rbp-0x18], rdi        ; unused argument _
    mov [rbp-0x4], 0x0         ; n = 0
    jmp .cond
.loop:
    mov rax, [rip+0x2008e6]  # 201018 <value>    ; rax = value
    add rax, 0x1                                 ; rax = rax + 1
    mov [rip+0x2008db], rax  # 201018 <value>    ; value = rax
    add [rbp-0x4], 0x1                           ; n = n + 1
.cond:
    cmp [rbp-0x4], 0x98967f     ; n <= 9999999
    jle .loop
    mov eax, 0x0                ; return NULL
    pop rbp
    ret
