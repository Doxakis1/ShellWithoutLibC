#include "DoxShell.h"

void d_execve(const char *cmd, const char **args, const char **envs)
{
	REGISTER(int, sysnum, "rax", 59)
	REGISTER(const char *, execmd, "rdi", cmd)
	REGISTER(const char **,	execargs, "rsi", args)
	REGISTER(const char **,	execenvs, "rdx", envs)
	SYS_CALL
	return ;
}	
