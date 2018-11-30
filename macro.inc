    %define pc r15    ; Program Counter (ptr to ptr to impl)
    %define xt r14    ; eXecution Token (ptr to impl)

    %define cellsize 8    ; bytes

    %define _last_word 0


    ;; data stack operations
    %define dstack rsp

    %define dpop pop

    %define dpush push

    %macro dfetch 1
    mov %1, qword [dstack]
    %endmacro

    %macro dpost 1
    mov qword [dstack], %1
    %endmacro

    ;; return stack operations
    %define rstack r13

    %macro rpop 1
    mov %1, qword [rstack]
    add rstack, cellsize
    %endmacro

    %macro rpush 1
    sub rstack, cellsize
    mov qword [rstack], %1
    %endmacro

    %macro rfetch 1
    mov %1, qword [rstack]
    %endmacro

    %macro rpost 1
    mov qword [rstack], %1
    %endmacro

    ;; macro for creating word header
    %macro _word_header 3
w_%2:
    dq _last_word
    %define _last_word w_%2
    db %1, 0    ; name (null-terminated)
    db %3       ; flag
    %endmacro

    ;; macro for define a native word (primary)
    %macro native 3
    section .data
    _word_header %1, %2, %3
xt_%2:
    dq i_%2

    section .text
i_%2:
    %endmacro

    %macro native 2
    native %1, %2, 0
    %endmacro

    ;; macro for define a compound word
    %macro colon 3
    section .data
    _word_header %1, %2, %3
xt_%2:
    dq i_docol
    %endmacro

    %macro colon 2
    colon %1, %2, 0
    %endmacro
