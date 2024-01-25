
extern ft_strcmp
extern ft_strcpy
extern ft_read
extern ft_write
extern ft_strlen
global _start

section .data
	string		db "b", 0
	string2		db "a", 0

section .text

_start:
	mov rax, 0
	mov rdi, string
	mov rsi, string2
	call ft_strcmp

_exit:
	mov rax, 60
	mov rdi, 0
	syscall