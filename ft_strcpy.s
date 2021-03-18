section .text
	global _ft_strcpy
_ft_strcpy:
	xor rcx, rcx
	jmp .loop

.loop:
	mov al, byte[rsi + rcx]
	mov byte[rdi + rcx], al
	cmp al, 0
	je .return
	inc rcx
	jmp .loop	

.return:
	mov rax, rdi
	ret