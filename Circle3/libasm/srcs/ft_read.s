section .text
	global _ft_read
	extern ___error

_ft_read:
	mov rax, 0x2000003 ; read
	syscall
	jc _err
	ret

_err:
	push rax
	call ___error
	pop rdx
	mov [rax], rdx ; save error num to errno
	mov rax, -1
	ret

