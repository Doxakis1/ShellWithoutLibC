#include "DoxShell.h"


int d_fork(void)
{
	REGISTER(int, sysnum, "rax", 57)
	SYS_CALL
	return sysnum;
}
