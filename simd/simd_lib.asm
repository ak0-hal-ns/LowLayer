    section .text
    global sse

sse:
    movdqa xmm0, [rdi]          ; MOVe Double Qword Aligned
    mulps xmm0, [rsi]           ; MULtiply Packed Single-precision
    addps xmm0, [rsi]           ; Add Packed Single-precision
    movdqa [rdi], xmm0
    ret

    ;; Instruction type (mov, mul, add, etc.)
    ;; P / S  (pack or scalar)
    ;; D / S  (double or single precision)
