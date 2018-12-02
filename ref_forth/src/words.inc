    ;; init
    native "init", init
    mov rstack, rstack_base
    cmp qword [dstack_base], 0
    je .default
    mov rsp, [dstack_base]    ; custom dstack base
    jmp .start
.default:
    mov [dstack_base], rsp
.start:
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

    ;; jump to location
    ;; location is an offset relative to the arg end
    native "branch", branch
    add pc, [pc]
    add pc, cellsize
    jmp next

    ;; jump to location if ToS(d) = 0
    ;; location is an offset relative to the arg end
    native "branch0", branch0
    dfetch rax
    test rax, rax
    jnz .skip
    add pc, [pc]
.skip:
    add pc, cellsize
    jmp next

    ;; Pushs a value immediately following this XT
    native "lit", lit
    dpush qword [pc]
    add pc, cellsize    ; skip the value pushed
    jmp next

    ;; interpreter
    colon "interpreter", interpreter
.start:
    dq xt_inbuf
    dq xt_word
    branch0 .end_of_input
    dq xt_drop    ; discard len of word
    dq xt_inbuf
    dq xt_find
    branch0 .number
    dq xt_wh2xt
    dq xt_execute
    branch .start
.number:
    dq xt_drop
    dq xt_inbuf
    dq xt_number
    branch0 .no_word
    dq xt_drop    ; discard len of int parsed
    branch .start
.no_word:
    dq xt_drop    ; discard len of int parsed
    dq xt_drop    ; discard int itself parsed
    dq xt_inbuf
    dq xt_prints
    dq xt_lit, msg_err_find
    dq xt_prints
    branch .start
.end_of_input:
    dq xt_drop    ; discard len-of-word
    dq xt_decol

    ;; Shows stack contents. Does NOT pop elements.
    native ".S", show_stack
    mov rcx, rsp
.loop:
    cmp rcx, [dstack_base]
    jae next
    mov rdi, [rcx]
    push rcx
    call print_int
    call print_newline
    pop rcx
    add rcx, 8
    jmp .loop

    ;; Pops and prints top of data stack
    native ".", dot
    dpop rdi
    call print_int
    call print_newline
    jmp next

    ;; (str -- num len)
    native "number", number
    dpop rdi
    call parse_int
    dpush rax
    dpush rdx
    jmp next

    ;; (addr --)
    ;; Prints a null-terminated string
    native "prints", prints
    pop rdi
    call print_string
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
    dpost 0
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

    ;; exit
    native "exit", exit
    mov rax, 60
    xor rdi, rdi
    syscall

    ;; test for interpreter loop
    native "hello", hello
    mov rdi, msg_test
    call print_string
    jmp next
