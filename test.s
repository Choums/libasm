BITS 64

extern _ft_strlen
global _start

section .data
	s db "salut", 0

section .text

_start:
	mov rdi, s
	call _ft_strlen
	mov rcx, rax

_exit:
	mov rax, 60
	mov rdi, 0
	syscall