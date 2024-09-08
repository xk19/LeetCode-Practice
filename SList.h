#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

void SListPrint(SLTNode* phead);
SLTNode* CreateSListNode(SLTDataType x);

void SListPushBack(SLTNode** phead, SLTDataType x);
void SListPopBack(SLTNode** phead);
void SListPushFront(SLTNode** phead, SLTDataType x);
void SListPopFront(SLTNode** phead);

SLTNode* SListFind(SLTNode* phead, SLTDataType x);
void SListInsert(SLTNode** phead, SLTNode* pos, SLTDataType x);
void SListInsertAfter(SLTNode** phead, SLTNode* pos, SLTDataType x);
void SListErase(SLTNode** phead, SLTNode* pos);
void SListDestroy(SLTNode** phead);