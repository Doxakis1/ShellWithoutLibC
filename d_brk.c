#include "DoxShell.h"


void *d_brk(unsigned long end)
{
	REGISTER(unsigned long, sysnum, "rax", 12);
	REGISTER(unsigned long, brk_end, "rsi", end)
	SYS_CALL
	return (void *)sysnum;
}
