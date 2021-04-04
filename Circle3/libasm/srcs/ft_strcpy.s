section .text
	global _ft_strcpy

_ft_strcpy:
	mov rax, 0

copy:
	mov cl, BYTE [rsi + rax]
	mov BYTE [rdi + rax], cl
	cmp cl, 0
	je exit
	inc rax
	jmp copy

exit:
	mov rax, rdi
	ret
