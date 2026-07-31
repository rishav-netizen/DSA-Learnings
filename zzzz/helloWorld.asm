section .data
    message db "Hello, World!", 10
    message_len equ $ - message

section .text
    global _main
    extern _printf

_main:
    lea rdi, [rel message]
    xor eax, eax
    call _printf

    xor eax, eax
    ret

