#include"SeqList.h"

void TestSeqList()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);

	SeqListPushFront(&s1, 5);
	SeqListPushFront(&s1, 4);
	SeqListPrint(&s1);

	SeqListDestory(&s1);
}


int main()
{
	TestSeqList();
	return 0;
}