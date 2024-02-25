global ft_strdup
extern ft_strcpy
extern ft_strlen
extern malloc
; char* strdup(const char* s)
; duplicate a string

; rdi => s

; info malloc =>	Bytes to malloc go into the rdi register.
;					Returned pointer to memory region in the rax register.
;					WRT (With Respect To) ..plt (Procedure Linkage Table), for call procedure outside of library.

ft_strdup:
	call ft_strlen; rdi => s | ret rax: len
	add rax, 1; add 1 for '\0' to len

	push rdi; string is preserved into the stack

	mov rdi, rax; put len into rdi, malloc take rdi as arg
	call malloc WRT ..plt
	pop rsi; get the string ptr back from the stack, will be used as strcpy src arg

	mov rdi, rax; use ptr of allocated mem as dest for strcpy

	call ft_strcpy; rdi => dest, rsi => src | ret rax: ptr
	ret