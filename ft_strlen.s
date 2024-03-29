global ft_strlen

; size_t strlen(const char* s)
; rdi => const char* s
; rax => ret len

ft_strlen:
	mov rax, 0; init rax as counter

	jmp _loop;

_loop:
	
	cmp BYTE [rdi + rax], 0; check if current ptr value is '\0'
	je _end
	
	inc rax; incr counter
	jmp _loop; iterate again

_end:
	ret