#include "SList.h"


void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
}

void SListPushBack(SLTNode** phead, SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	newnode->data = x;
	newnode->next = NULL;

	SLTNode* tail = *phead;
	if (*phead == NULL)
	{
		*phead = newnode;
	}
	else
	{
		while (tail != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

