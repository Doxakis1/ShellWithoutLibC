#include "DoxShell.h"

void d_signal(int sig, void *handler)
{
	REGISTER(int, signal, "rdi", sig)
	REGISTER(void *, hand, "rsi", handler)
	asm("call signal");
	return ;
}
