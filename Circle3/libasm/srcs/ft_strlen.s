section .text
	global _ft_strlen

_ft_strlen:
	mov rax, 0
	jmp count

count:
	cmp BYTE [rdi + rax], 0
	je exit	; if str[i] == 0 jmp exit
	inc rax ; else rax++
	jmp count ; loop

exit:
	ret ; return rax value
