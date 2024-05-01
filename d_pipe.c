#include "DoxShell.h"

int d_pipe(int *p)
{
	REGISTER(int, sysnum, "rax", 22)
	REGISTER(int *, files, "rdi", p)
	SYS_CALL
	return sysnum;	
}
