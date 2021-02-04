global _ft_strlen
_ft_strlen:
	xor	rcx, rcx
.loop:
	cmp	[rdi], byte 0
	je	.return
	inc	rcx
	inc	rdi
	jmp	.loop 
.return:
	mov	rax, rcx
	ret