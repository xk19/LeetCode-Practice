#include"SeqList.h"

void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
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

void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}
void SeqListPushBack(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPopBack(SL* ps)
{
	assert(ps->size > 0);
	ps->size--;
}

void SeqListPushFront(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SL* ps)
{
	assert(ps->size > 0);
	int begin = 1;
	while(begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++ begin;
	}
	ps->size--;
}

int SeqListFind(SL* ps, SLDataType x)
{
	for(int i = 0; i<ps->size; i++)
	{
		if (ps->a[i] == x) return i;
	}
	return -1;
}
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	int end = ps->size;
	SeqListCheckCapacity(ps);
	assert(pos <= ps->size);
	while (end - pos + 1 > 0)
	{
		ps->a[end] = ps->a[end - 1];
		--end;
	}
	ps->a[pos - 1] = x;
	ps->size++;
}
void SeqListErase(SL* ps, int pos)
{
	int start = pos - 1;
	assert(ps->size > 0);
	while (start + 1< ps->size)
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	ps->size--;
}
