global ft_write

; ssize_t write(int fd, const void* buf, size_t count)
; write to a file descriptor
; rdi => fd
; rsi => buf
; rdx => count
; syscall => rax: 1 | rdi: fd | rsi: buf | rdx: count

ft_write:
	mov rax, 1; sys_write ID
	syscall; call sys_write
	jc _error; fail sys_write => CF = 1 

	ret

_error:
	mov rax, -1; write return -1 on error
	ret