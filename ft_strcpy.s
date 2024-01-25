global ft_strcpy

; char* strcpy(char* dest, const char* src);
; copy a string
; rdi => dest
; rsi => src

ft_strcpy:
	mov rax, 0; init rax as counter
	jmp _loop

_loop:
	cmp BYTE [rsi + rax], 0; check if current src ptr value is '\0'
	je _end; end of src

	mov bl, [rsi + rax]; put character to copy into bl (8 bits)
	mov [rdi + rax], bl; copy src value to dest

	inc rax
	jmp _loop

_end:
	mov bl, 0; copy '\0' aswell
	mov [rdi + rax], bl

	mov rax, rdi; rax is ret; rdi is dest
	ret