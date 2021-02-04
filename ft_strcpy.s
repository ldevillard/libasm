global _ft_strcpy
_ft_strcpy:
	mov rax, rdi
.copy:
	cmp byte [rsi], 0
	je  .finished
	mov dl, byte [rsi]
	mov byte [rdi], dl
	inc rsi
	inc rdi
	jmp .copy

.finished:
	mov byte [rdi], 0
	ret
