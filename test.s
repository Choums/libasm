extern ft_strcmp
extern ft_strcpy
extern ft_read
extern ft_write
extern ft_strlen

global _start

section .data
	string		db "salut", 0
	string_len	equ $-string
section .text

_start:
	mov rax, 0
	mov rdi, string
	mov rsi, string_len
	call ft_strdup

_exit:
	mov rax, 60
	mov rdi, 0
	syscall