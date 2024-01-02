#include "SList.h"


void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLTNode* CreateListNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		printf("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

void SListPushBack(SLTNode** phead, SLTDataType x)
{
	assert(phead);
	SLTNode* newnode = CreateListNode(x);
	if (*phead == NULL)
	{
		*phead = newnode;
	}
	else
	{
		SLTNode* tail = *phead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListPushFront(SLTNode** phead, SLTDataType x)
{
	assert(phead);
	SLTNode* newnode = CreateListNode(x);
	newnode->next = *phead;

	*phead = newnode;
}

void SListPoPBack(SLTNode** phead)
{
	assert(phead);
	assert(*phead != NULL);
	
	if ((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	else
	{
		SLTNode* tail = *phead;
		while (tail->next->next)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}

void SListPoPFront(SLTNode** phead)
{
	assert(phead);
	assert(*phead != NULL);
	SLTNode* next = (*phead)->next;
	free(*phead);
	*phead = next;
}


SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

void SListInsert(SLTNode** phead, SLTNode* pos, SLTDataType x)
{
	assert(phead);
	assert(pos);
	SLTNode* newnode = CreateListNode(x);
	SLTNode* posprev = *phead;
	if (*phead == pos)
	{
		newnode->next = *phead;
		*phead = newnode;
	}
	else
	{
		while (posprev->next != pos)
		{
			posprev = posprev->next;
		}
		posprev->next = newnode;
		newnode->next = pos;
	}
}

void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = CreateListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListErase(SLTNode** phead, SLTNode* pos)
{
	assert(pos);
	if (*phead == pos)
	{
		*phead = (*phead)->next;
		free(pos);
		pos = NULL;
	}
	else
	{
		SLTNode* cur = *phead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void SListDestory(SLTNode** phead)
{
	assert(phead);
	SLTNode* cur = *phead;
	while (*phead)
	{
		cur = *phead;
		*phead = (*phead)->next;
		free(cur);
	}
	*phead = NULL;
}
