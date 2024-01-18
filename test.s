BITS 64

extern _ft_read
extern _ft_write
extern _ft_strlen
global _start

section .data
	string		db "salut", 10, 0
	string_len	equ $-string

section .text

_start:
	mov rdi, 1
	mov rsi, string
	mov rdx, string_len
	call _ft_write
	mov rcx, rax

_exit:
	mov rax, 60
	mov rdi, 0
	syscall