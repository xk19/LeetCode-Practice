#include "List.h"

LTNode* ListInit()
{
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

LTNode* BuyListNode(LTDataType x)
{
	LTNode* newNode = (LTNode*)malloc(sizeof(LTNode));
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	return newNode;
}

void ListPrint(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	ListInsert(phead, phead, x);
}

void ListPoPBack(LTNode* phead)
{
	assert(phead);

	ListErase(phead, phead->prev);
}

void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);

	ListInsert(phead, phead->next, x);
}

void ListPopFront(LTNode* phead)
{
	assert(phead);

	ListErase(phead, phead->next);
}

void ListInsert(LTNode* phead, LTNode* pos, LTDataType x)
{
	LTNode* newNode = BuyListNode(x);
	LTNode* posPrev = pos->prev;

	newNode->next = pos;
	pos->prev = newNode;
	posPrev->next = newNode;
	newNode->prev = posPrev;
}

void ListErase(LTNode* phead, LTNode* pos)
{
	assert(pos);
	assert(pos != phead);

	LTNode* posPrev = pos->prev;
	LTNode* posNext = pos->next;
	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
}

LTNode* ListFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x) return cur;
		cur = cur->next;
	}
	return NULL;
}

void ListDestroy(LTNode* phead)
{
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* curNext = cur->next;
		free(cur);
		cur = curNext;
	}
	free(phead);
}