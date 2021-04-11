section .text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy

_ft_strdup:
	push rdi ; src를 임시저장
	call _ft_strlen
	inc rax ; len + 1
	mov rdi, rax ; rdi에 len + 1 할당
	call _malloc ; len + 1 만큼 동적할당을 해준다
	cmp rax, 0 ; 동적할당 실패 리턴값(rax)가 0이면 exit
	je exit
	mov rdi, rax ; rdi가 strcpy의 dest인자가 된다
	pop rsi ; 스택에 임시 저장한 것을 pop해서 rsi 저장
	call _ft_strcpy ; rdi: dest(동적할당), rsi: src
	ret ; rax 리턴

exit:
	ret
