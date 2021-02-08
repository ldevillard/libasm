extern ___error
global _ft_read
_ft_read:
.write:
    mov rax, 0x2000003
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