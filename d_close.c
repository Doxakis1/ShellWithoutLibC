#include "DoxShell.h"

size_t d_close(int fd)
{
	REGISTER(int, sysnum, "rax", 3)
	REGISTER(size_t, filed, "rdi", fd);
	SYS_CALL
	return sysnum;
}
