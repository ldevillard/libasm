extern ___error
global _ft_write
_ft_write:
.write:
    mov rax, 0x2000004
    syscall
    jc .error
    ret
.error:
    mov rcx, rax
    push rcx
    call ___error
    pop rcx
    mov [rax], rcx
    mov rax, -1
    ret