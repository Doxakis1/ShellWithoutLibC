#include "DoxShell.h"


int errnum;

void myhandler(int sig)
{
	d_write(1, "Here\n", 5);
	return ;
}

void sigstophandler(int sig)
{
	return ;
}

int main(int ac, char **av, char **envs)
{
	d_signal(SIGINT, (void *)myhandler);
	d_signal(SIGQUIT, (void *)sigstophandler);
	while (1)
	{

	}
	return 0;
}
