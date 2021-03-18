global ft_putstr

section .text
ft_putstr:
	push rsi
	push rcx
	xor rcx, rcx
	mov rsi, rdi
	mov rdi, 1
	mov rdx, 1
	mov rax, 1

.loop:
	cmp byte[rsi], 0
	je 	.return
	syscall
	inc rsi
	inc rcx
	jmp .loop

.return:
	mov rax, rcx
	pop rcx
	pop rsi
	ret 
