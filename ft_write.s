global ft_write
extern __errno_location

; ssize_t write(int fd, const void* buf, size_t count)
; write to a file descriptor
; rdi => fd
; rsi => buf
; rdx => count
; syscall => rax: 1 | rdi: fd | rsi: buf | rdx: count

ft_write:
	mov rax, 1; sys_write ID
	syscall; call sys_write
	cmp rax, 0; syscall = 0 => error
	jl _error; jump if fail sys_write flag

	ret

_error:
	neg rax;
	mov rdi, rax;
	call __errno_location WRT ..plt
	mov [rax], rdi;
	mov rax, -1;
	ret