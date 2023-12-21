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

SLTNode* CreatListNode(SLTDataType x)
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
	SLTNode* newnode = CreatListNode(x);
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
	SLTNode* newnode = CreatListNode(x);
	newnode->next = *phead;

	*phead = newnode;
}

void SListPoPBack(SLTNode** phead)
{
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
	assert(*phead != NULL);
	SLTNode* next = (*phead)->next;
	free(*phead);
	*phead = next;
}


SLTNode SListFind(SLTNode* phead);
void SListInsert(SLTNode** phead, SLTNode pos, SLTDataType x);
void SListErase(SLTNode** phead, SLTNode pos);
void SListDestory(SLTNode** phead);
