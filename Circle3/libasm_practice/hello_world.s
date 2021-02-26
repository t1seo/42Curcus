section .data   ; data section
    msg db "hello world", 0x0A ; message and new line charactor

section .text   ; text section
    global  _main   ; can be approch from global

_main : ; main function
    mov rax, 0x2000004 ; syscall write() function number of MAC OS
    ; below are parameter
    mov rdi, 1
    mov rsi, msg
    mov rdx, 12
    syscall ; call
    mov rax, 0x2000001 ; syscall exit() function number of MAC OS
    ; below are parameter
    mov rdi, 0
    syscall ; call
