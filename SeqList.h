#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int
SLDataType;

// ¾²Ì¬Ë³Ðò±í
typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;
}SL;

void SeqListInit(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);
void SeqListPrint(SL* ps);