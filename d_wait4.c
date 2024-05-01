#include "DoxShell.h"


int d_wait(int pid, int *status, int options)
{	
	REGISTER(int, sysnum, "rax", 61)
	REGISTER(int, childpid, "rdi", pid)
	REGISTER(int *, stat, "rsi", status)
	REGISTER(int, opts, "rdx", options)
	REGISTER(void *, rusage, "r10", (void *)0)
	SYS_CALL
	return sysnum;
}
