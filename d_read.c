#include "DoxShell.h"

size_t d_read(int fd, char *dst, size_t size)
{
	REGISTER(int, sysnum, "rax", 0);
	REGISTER(int, filed, "rdi", fd);
	REGISTER(char *, dest, "rsi", dst);
	REGISTER(size_t, read_size, "rdx", size);
	SYS_CALL
	return sysnum;
}
