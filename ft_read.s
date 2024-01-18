global _ft_read

; ssize_t read(int fd, const void* buf, size_t count)
; read to a file descriptor
; rdi =>fd
; rsi => buf
; rdx => count
; syscall => rax: 1 | rdi: fd | rsi: buf | rdx: count

_ft_read:
	mov rax, 0; sys_read ID
	syscall
	jc _error;

	ret

_error:
	mov rax, -1
	ret