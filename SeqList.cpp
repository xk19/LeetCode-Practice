#include "SeqList.h"

// 顺序表源文件

void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
}

void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

void SeqListPushBack(SL* ps, SLDataType x)
{
	SeqListInsert(ps, ps->size, x);
	/*SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;*/
}

void SeqListPopBack(SL* ps)
{
	SeqLiatErase(ps, ps->size - 1);
	/*assert(ps->size > 0);
	ps->size--;*/
}

void SeqListPushFront(SL* ps, SLDataType x)
{
	SeqListInsert(ps, 0, x);
	/*SeqListCheckCapacity(ps);
	int end = ps->size;
	while (end)
	{
		ps->a[end] = ps->a[end - 1];
		end--;
	}
	ps->a[0] = x;
	ps->size++;*/
}

void SeqListPopFront(SL* ps)
{
	SeqLiatErase(ps, 0);
	/*assert(ps->size > 0);
	int start = 1;
	while (start < ps->size)
	{
		ps->a[start - 1] = ps->a[start];
		start++;
	}
	ps->size--;*/
}

int SeqListFind(SL* ps, SLDataType x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	SeqListCheckCapacity(ps);
	assert(pos >= 0 && pos <= ps->size);
	int end = ps->size;
	while (end >= pos)
	{
		ps->a[end] = ps->a[end-1];
		end--;
	}
	ps ->a[pos] = x;
	ps->size++;
}

void SeqLiatErase(SL* ps, int pos)
{
	assert(pos >= 0 && pos < ps->size);
	int start = pos;
	while(start < ps->size - 1)
	{
		ps->a[start] = ps->a[start+1];
		start++;
	}
	ps->size--;
}