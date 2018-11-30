    global string_length
    global print_newline
    global print_char
    global print_string
    global print_uint
    global print_int
    global parse_int
    global parse_uint
    global string_equals
    global read_char
    global read_word
    global string_copy


    section .text

string_length:
    xor rax, rax
.loop:
    cmp byte [rdi + rax], 0
    je .end
    inc rax
    jmp .loop
.end:
    ret

print_newline:
    mov rdi, 0x0a    ; char-code of newline
print_char:
    push rdi             ; store into buffer
    mov rdi, rsp         ; point to buffer
    call print_string
    pop rdi              ; restore the stack
    ret

print_string:
    push rdi
    call string_length
    pop rsi         ; point to buffer
    mov rdx, rax    ; count bytes
    mov rax, 1      ; 'write' system call
    mov rdi, 1      ; stdout
    syscall
    ret

print_uint:
    mov rax, rdi
    mov rdi, rsp         ; pointer to buffer
    push 0               ; 8 bytes in 64-bit mode
    sub rsp, 16          ; buffer size is 24 bytes
    dec rdi              ; buffer ends with null byte
    mov r8, 10           ; divisor
.loop:
    xor rdx, rdx
    div r8
    or dl, 0x30          ; add 0x30, faster
    dec rdi
    mov [rdi], dl
    test rax, rax
    jnz .loop
    call print_string
    add rsp, 24          ; restore the stack
    ret

print_int:
    test rdi, rdi
    jns print_uint       ; jmp if SF = 0
    push rdi
    mov rdi, '-'
    call print_char
    pop rdi
    neg rdi              ; rdi *= (-1)
    jmp print_uint

parse_int:
    ;; returns rax: number, rdx: length
    mov al, byte [rdi]
    cmp al, '-'
    je .signed
    jmp parse_uint
.signed:
    inc rdi
    call parse_uint
    neg rax
    test rdx, rdx
    jz .error
    inc rdx
    ret
.error:
    xor rax, rax
    ret

parse_uint:
    ;; returns rax: number, rdx, length
    mov r8, 10       ; multiplier
    xor rax, rax
    xor rcx, rcx
.loop:
    movzx r9, byte [rdi + rcx]    ; zero-extended move
    cmp r9b, '0'
    jb .end
    cmp r9b, '9'
    ja .end
    xor rdx, rdx
    mul r8           ; rdx:rax <- rax * r8
    and r9b, 0x0f    ; 0 <= r9b <= 9
    add rax, r9
    inc rcx
    jmp .loop
.end:
    mov rdx, rcx
    ret

string_equals:
    mov al, byte [rdi]
    cmp al, byte [rsi]
    jne .no
    inc rdi
    inc rsi
    test al, al
    jnz string_equals
    mov rax, 1
    ret
.no:
    xor rax, rax
    ret

read_char:
    push 0          ; create buffer (8 bytes in 64-bit mode)
    xor rax, rax    ; 'read' system call
    xor rdi, rdi    ; stdin
    mov rsi, rsp    ; buffer address
    mov rdx, 1      ; count bytes
    syscall
    pop rax
    ret

read_word:
    ;; returns rax: buffer, rdx: length
    push r14      ; callee-saved
    xor r14, r14
.A:
    ;; strip leading whitespaces
    push rdi
    call read_char
    pop rdi
    cmp al, ' '   ; space
    je .A
    cmp al, 10    ; newline
    je .A
    cmp al, 13    ; carriage return
    je .A
    cmp al, 9     ; horizontal tab
    je .A
    test al, al
    jz .C
.B:
    mov byte [rdi + r14], al
    inc r14
    push rdi
    call read_char
    pop rdi
    cmp al, ' '   ; space
    je .C
    cmp al, 10    ; newline
    je .C
    cmp al, 13    ; carriage return
    je .C
    cmp al, 9     ; horizontal tab
    je .C
    test al, al
    jz .C
    cmp r14, 254    ; maxlen of buffer
    je .C
    jmp .B
.C:
    mov byte [rdi + r14], 0
    mov rax, rdi
    mov rdx, r14
    pop r14       ; restore the stack
    ret

string_copy:
    mov dl, byte [rdi]
    mov byte [rsi], dl
    inc rdi
    inc rsi
    test dl, dl
    jnz string_copy
    ret

