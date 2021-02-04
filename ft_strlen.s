
global _ft_strlen
section .text
_ft_strlen:
	xor	rcx, rcx
_strlen_next:
	cmp	[rdi], byte 0
	je	_strlen_null
	inc	rcx
	inc	rdi
	jmp	_strlen_next 

_strlen_null:
	mov	rax, rcx
	ret