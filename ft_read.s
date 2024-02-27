global ft_read
extern __errno_location

; ssize_t read(int fd, const void* buf, size_t count)
; read to a file descriptor
; rdi =>fd
; rsi => buf
; rdx => count
; syscall => rax: 1 | rdi: fd | rsi: buf | rdx: count

ft_read:
	mov rax, 0; sys_read ID
	syscall
	cmp rax, 0
	jl _error;

	ret

_error:
	neg rax;
	mov rdi, rax;
	call __errno_location WRT ..plt
	mov [rax], rdi;
	mov rax, -1;
	ret