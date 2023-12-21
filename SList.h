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
SLTNode* CreatListNode(SLTNode* newnode);

void SListPushBack(SLTNode** phead, SLTDataType x);
void SListPushFront(SLTNode** phead, SLTDataType x);
void SListPoPBack(SLTNode** phead);
void SListPoPFront(SLTNode** phead);

SLTNode SListFind(SLTNode* phead);
void SListInsert(SLTNode** phead, SLTNode pos, SLTDataType x);
void SListErase(SLTNode** phead, SLTNode pos);
void SListDestory(SLTNode** phead);