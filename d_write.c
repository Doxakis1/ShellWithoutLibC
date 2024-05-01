#include "DoxShell.h"

size_t d_write(int fd, const char *buf, size_t size)
{
	register size_t sysnum asm("rax") = 1;
	register int filed asm("rdi") = fd;
	register const char *buffer asm("rsi") = buf;
	register size_t write_size asm("rdx") = size;
	asm("syscall");
	return (sysnum);
}
