section .text
	global _ft_strdup
	extern _ft_strlen
	extern _ft_strcpy
	extern malloc

_ft_strdup:
	call _ft_strlen
	push rdi
	mov rdi, rax
	call malloc wrt ..plt
	cmp rax, 0
	je .error
	mov rdi, rax
	pop rsi
	call _ft_strcpy
	ret

.error:
	mov rax, -1
	ret