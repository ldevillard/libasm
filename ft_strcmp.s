global _ft_strcmp
_ft_strcmp:
.compare:
	cmp byte [rdi], 0
	je .return
	cmp byte [rsi], 0
	je .return
	mov dl, byte [rsi]
	cmp byte [rdi], dl
	jne .return
	jmp .increment
.increment:
	inc rdi
	inc rsi
	jmp .compare
.return:
	movzx rax, byte [rdi]
	movzx rdx, byte [rsi]
	sub rax, rdx
	ret
