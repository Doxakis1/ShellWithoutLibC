global d_signal

d_signal:
	mov eax, 48
	mov ebx, [esp+8]
	int 0x80
	ret
