#include "DoxShell.h"

int d_open(const char *name, int f, int m)
{
	REGISTER(int, sysnum, "rax", 2)
	REGISTER(const char *, filename, "rdi", name)
	REGISTER(int, of, "rsi", f)
	REGISTER(int, om, "rdx", m)
	SYS_CALL
	return sysnum;	
}
