extern ___error
extern _malloc
extern _ft_strlen
extern _ft_strcpy
global _ft_strdup
_ft_strdup: 
.dup:
    push rdi
    call _ft_strlen
    inc rax
    mov rdi, rax
    call _malloc
    cmp rax, 0
    je .error
    mov rdi, rax
    pop rsi
    call _ft_strcpy
    ret
.error:
    mov rdi, rax
    push rdi
    call ___error
    pop rdi
    mov [rax], rdi
    mov rax, 0
    ret