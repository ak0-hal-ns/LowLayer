symbols.asm
```assembly
    global _start
    extern somewhere

    section .data
datavar1:
    dq 1488
datavar2:
    dq 42

    section .bss
bssvar1:
    resq 4*1024*1024
bssvar2:
    resq 1

    section .text
    mov rax, datavar1
    mov rax, bssvar1
    mov rax, bssvar2
    mov rax, datavar2
_start:
    jmp _start
    ret
textlabel:
    dq 0
```

executable.asm
```assembly
    global somewhere
    global func

    section .data
somewhere:
    dq 999
private:
    dq 666

    section .text
func:
    mov rax, somewhere
    ret
```

compile and link
```
$ nasm -felf64 -o symbols.o symbols.asm
$ nasm -felf64 -o executable.o executable.asm
$ ld -o main executable.o symbols.o
```
reverse assemble
```
$ objdump -D -Mintel symbol.o
$ objdump -r symbols.o
$ objdump -D -Mintel executable.o
$ objdump -r executable.o
```

reverse assemble of symbols.asm
```assembly
    section .data
datavar1:                       ; 0x0000000000000000
    dq 0x5d0
datavar2:                       ; 0x0000000000000008
    dq 0x2a


    section .bss
bssvar1:
    resq 0x2000000              ; 0x0000000000000000
bssvar2:
    resq 1                      ; 0x0000000002000000


    section .text
                                ; 0x0000000000000000
    mov rax, 0x0    ; datavar1
    mov rax, 0x0    ; bssvar1
    mov rax, 0x0    ; bssvar2
    mov rax, 0x0    ; datavar2
_start:                         ; 0x0000000000000028
    jmp _start
    ret
textlabel:                      ; 0x000000000000002b
    dq 0

;;; relocate .text
    ;; offset    value
    ;; 0x02      .data
    ;; 0x0c      .bss
    ;; 0x16      .bss  +0x2000000
    ;; 0x20      .data +0x0000008
```

reverse assemble of executable.asm
```assembly
    section .data
somewhere:                      ; 0x0000000000000000
    dq 0x3e7
private:                        ; 0x0000000000000008
    dq 0x29a


    section .text
func:                           ; 0x0000000000000000
    mov rax, 0x0    ; somewhere
    ret

;;; relocate .text
    ;; offset    value
    ;; 0x02      .data
```
