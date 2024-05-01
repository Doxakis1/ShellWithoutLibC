#include "DoxShell.h"

void d_exit(int exit_code)
{
	register int sysnum asm("rax") = 60;
	register int arg1 asm("rdi") = exit_code;
	asm("syscall");
	return ;
}
