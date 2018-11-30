    ;; init
    native "init", init
    mov rstack, rstack_start
    mov pc, prog_stub
    jmp next

    ;; implementation of any colon word
    native "docol", docol
    rpush pc
    add xt, cellsize
    mov pc, xt
    jmp next

    ;; return back from colon word
    native "decol", decol
    rpop pc
    jmp next

    ;; interpreter
    colon "interpreter", interpreter
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
    dq xt_decol

    ;; loop
    native "loop", loop
    ;; mov pc, prog_stub.loop
    mov pc, xt_interpreter.loop
    jmp next

    ;; jump to exit if top of data stack is 0
    native "branch_end", branch_end
    dfetch rax
    test rax, rax
    jz .end
    jmp next
.end:
    ;; mov pc, prog_stub.end
    mov pc, xt_interpreter.end
    jmp next

    ;; ( -- addr_to_input_buffer)
    native "inbuf", inbuf
    dpush input_buf
    jmp next

    ;; (addr -- len)
    ;; read a word from stdin to buffer pointed by addr
    native "word", word
    dpop rdi
    call read_word
    dpush rdx
    jmp next

    ;; (hoge -- )
    native "drop", drop
    dpop rdi
    jmp next

    ;; (addr_to_str -- addr_to_word_hdr)
    native "find", find
    mov rsi, [last_word]
.loop:
    dfetch rdi
    dpush rsi
    add rsi, cellsize    ; skip ptr to next word
    call string_equals
    dpop rsi
    test rax, rax
    jnz .found
    mov rsi, [rsi]       ; go to next word
    test rsi, rsi
    jnz .loop
.not_found:
    dpop rdi
    call print_string
    mov rdi, msg_err_find
    call print_string
    dpush 0
    jmp next
.found:
    dpost rsi
    jmp next

    ;; (addr_to_word_hdr -- addr_to_xt)
    native "wh2xt", wh2xt
    dpop rsi
    add rsi, cellsize    ; skip ptr to next word
.loop:
    mov al, [rsi]
    test al, al
    jz .end
    inc rsi
    jmp .loop
.end:
    add rsi, 2    ; skip terminating null byte and flag
    dpush rsi
    jmp next

    ;; (xt -- )
    ;; Execute word on Top of data stack
    native "execute", execute
    pop xt
    jmp [xt]

    ;; test for interpreter loop
    native "hello", hello
    mov rdi, msg_test
    call print_string
    jmp next
    
    ;; exit
    native "exit", exit
    mov rax, 60
    xor rdi, rdi
    syscall

