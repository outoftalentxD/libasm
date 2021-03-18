section .text
	global _ft_strcmp

_ft_strcmp:
.loop:
	mov al, byte[rdi]
	mov bl, byte[rsi]
	cmp al, bl
	je .increment
	jmp .return

.increment:
	cmp al, 0
	je .return
	inc rdi
	inc rsi
	jmp .loop

.return:
	movzx rax, al
	movzx rbx, bl
	sub rax, rbx
	ret