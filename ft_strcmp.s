global ft_strcmp

; int strcmp(const char* s1, const char* s2)
; compare two strings
; rdi => s1
; rsi => s2

ft_strcmp:
	mov rax, 0; init rax as counter
	jmp _loop

_loop:
	mov bl, [rdi + rax]; get s1 last value
	mov cl, [rsi + rax]; get s2 last value

	cmp bl, 0;
	je _end

	cmp cl, 0
	je _end

	cmp bl, cl
	jne _end

	inc rax
	jmp _loop

_end:
	movzx rax, bl; extension de signe obligatoire pour bl
	movzx r8, cl
	sub rax, r8; sub s1[i] - s2[i]
	ret