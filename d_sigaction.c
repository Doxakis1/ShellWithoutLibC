#include "DoxShell.h"


void d_sigaction(int s, s_sigaction *n, s_sigaction *o)
{
	REGISTER(int, sysnum, "rax", 13)
	REGISTER(int, sig, "rdi", s)
	REGISTER(s_sigaction *, new, "rsi", n)
	REGISTER(s_sigaction *, old, "rdx", o)
	REGISTER(int, sigsetsize, "r10", 0)
	SYS_CALL
	return ;
}
