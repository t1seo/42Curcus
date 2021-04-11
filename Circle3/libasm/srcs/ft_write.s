section .text
	global _ft_write
	extern ___error

_ft_write:
	mov rax, 0x2000004
	syscall
	jc _err
	ret

_err:
	push rax ; 현재 rax에는 errno 저장
	call ___error ; rax에는 error 포인터 주소
	pop rdx ; pop을 해서 rdx에는 errno 저장되어있는 상태
	mov [rax], rdx ; *rax = rdx      rax 주소, rdx errno
	mov rax, -1 ; 리턴값으로 -1
	ret ; rax 리턴
