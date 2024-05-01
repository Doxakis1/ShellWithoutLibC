#include "DoxShell.h"


size_t d_strlen(const char *str)
{
	if (!str)
		return 0;
	size_t l = 0;
	while (str[l])
		l++;
	return l;
}

void d_bzero(void *ptr, size_t size)
{
	size_t i;
	while (i < size)
	{
		((char *)ptr)[i++] = 0;
	}
	return ;
}
