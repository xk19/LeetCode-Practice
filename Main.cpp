#include"SeqList.h"

void TestSeqList1()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);

	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPrint(&s1);

	SeqListDestory(&s1);
}

void TestSeqList2()
{
	SL s1;
	int FindData;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPrint(&s1);

	SeqListPushFront(&s1, 10);
	SeqListPushFront(&s1, 20);
	SeqListPushFront(&s1, 30);
	SeqListPrint(&s1);

	SeqListErase(&s1, 6);
	SeqListPrint(&s1);

	SeqListDestory(&s1);
}

int main()
{
	TestSeqList2();
	return 0;
}