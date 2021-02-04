;int	ft_strcmp(char *s1, char *s2)
;{
;	int i;
;
;	i = 0;
;	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
;	{
;		i++;
;	}
;	return (s1[i] - s2[i]);
;}
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
	movzx rax, byte [rdi] ;Right in notebook the meaning of movzx
	movzx rdx, byte [rsi]
	sub rax, rdx
	ret