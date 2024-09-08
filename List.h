#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;


LTNode* ListInit();
LTNode* BuyListNode(LTNode* phead);
void ListPrint(LTNode* phead);


void ListPushBack(LTNode* phead, LTDataType x);
void ListPoPBack(LTNode* phead);
void ListPushFront(LTNode* phead, LTDataType x);
void ListPopFront(LTNode* phead);

void ListInsert(LTNode* phead, LTNode* pos, LTDataType x);
void ListErase(LTNode* phead, LTNode* pos);
LTNode* ListFind(LTNode* phead, LTDataType x);

void ListDestroy(LTNode* phead);


