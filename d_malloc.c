#include "DoxShell.h"

static void *start = NULL;
static void *end = NULL;

void *d_malloc(size_t size)
{
	static _Bool first_time = true;
	if (first_time)
	{
		start = d_brk(0);
		end = d_brk((unsigned long)start + HEAP_SIZE);
		if (end <= start)
		{
			errnum = 1;
			return NULL;
		}
		*((mchunk *)start) = (mchunk){HEAP_SIZE - sizeof(mchunk), false,  end};
		first_time = false;
	}
	mchunk *head = (mchunk *)start;
	while ((long long)head < (long long)end && head->isUsed == true && head->size >= size)
	{
		head = head->next;
	}
	if ((long long)head >= (long long)end || head->isUsed == true)
		return NULL;
	head->isUsed  = true;
	mchunk *ptr = head->next;
	if (head->size > size + sizeof(mchunk) * 2)
	{
		head->next = (mchunk *)((long long)head + (long long)(size + sizeof(mchunk)));
		head->next->next = ptr;
		head->next->size = head->size - size - sizeof(mchunk);
		head->next->isUsed = false;
	}
	return (void *)((long long)head + sizeof(mchunk));
}

void d_free(void *ptr)
{
	mchunk *head = (mchunk *)start;
	if (!ptr)
		return ;
	_Bool found = false;
	ptr = ptr - sizeof(mchunk);
	while ((long long)head < (long long)end)
	{
		if (head == (mchunk *)ptr)
		{
			found = true;
		}
		head = head->next;
	}
	if (!found || (long long)head > (long long)end)
	{
		errnum = 32;
		return ;
	}
	((mchunk *)ptr)->isUsed = false;
	head = (mchunk *)start;
	if (head == ptr)
	{
		goto fix_next;
	}
	while (head != (mchunk *)end &&  head->next != ptr)
	{
		head = head->next;
	}
	if (head->isUsed == true)
		goto fix_next;
	head->size += ((mchunk *)ptr)->size + sizeof(mchunk);
	head->next = ((mchunk *)ptr)->next;
	ptr = (void *)head;
fix_next:
	head = (mchunk *)ptr;
	if (head->next < (mchunk *)end || head->next->isUsed == true)
		return ;
	head->size += head->next->size;
	head->next = head->next->next;
	return ;
}
