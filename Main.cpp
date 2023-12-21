#include"SeqList.h"
#include"SList.h"

/********************************�ò���ΪLeetCode���Դ���*******************************/
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int end1 = m - 1, end2 = n - 1;
	int end = nums1Size - 1;
	while (end1 >= 0 && end2 >= 0)
	{
		if (nums1[end1] > nums2[end2])
		{
			nums1[end--] = nums1[end1--];
		}
		else
		{
			nums1[end--] = nums2[end2--];
		}
	}
	while (end2 >= 0)
	{
		nums1[end--] = nums2[end2--];
	}

}

/********************************�ò���Ϊ˳�����Դ���*******************************/
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

	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPopFront(&s1);
	SeqListPopFront(&s1);
	SeqListPrint(&s1);

	SeqListDestory(&s1);
}

void Menu()
{
	printf("******************************\n");
	printf("��������Ĳ���:>\n");
	printf("1��ͷ��  2��ͷɾ\n");
	printf("3��β��  4��βɾ\n");
	printf("5����ӡ  -1���˳�\n");
	printf("******************************\n");
}

void MenuTest()
{
	int input = 0, x = 0;
	SL s1;
	SeqListInit(&s1);
	while (input != -1)
	{
		Menu();
		scanf_s("%d", &input);
		switch (input)
		{
			case 1:
				printf("������������Ҫͷ������ݣ���-1������");
				scanf_s("%d", &x);
				while (x != -1)
				{
					SeqListPushFront(&s1, x);
					scanf_s("%d", &x);
				}
				break;
			case 2:
				SeqListPopFront(&s1);
				break;
			case 3:
				printf("������������Ҫβ������ݣ���-1������");
				scanf_s("%d", &x);
				while (x != -1)
				{
					SeqListPushBack(&s1, x);
					scanf_s("%d", &x);
				}
				break;
			case 4:
				SeqListPopBack(&s1);
				break;
			case 5:
				SeqListPrint(&s1);
				break;
			case -1:
				break;
			default:
				printf("�޴�ѡ�����������\n");
				break;
		}
	}
	SeqListDestory(&s1);
}

/********************************�ò���Ϊ˳�����Դ���*******************************/
void TestSList()
{
	SLTNode* phead = NULL;
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	SListPushBack(&phead, 5);
	SListPushBack(&phead, 6);
	SListPrint(phead);

	SListPoPBack(&phead);
	SListPrint(phead);
}

/****************************************Main����***********************************/
int main()
{
	//˳���
	//TestSeqList();
	//MenuTest();

	//������
	TestSList();

	//LeetCodeTest
	/*int nums1[] = { 1, 2, 3, 0, 0, 0 };
	int nums2[] = { 2, 5, 6 };
	int nums1Size = 6, nums2Size = 3;
	int m = 3, n = 3;
	merge(nums1, nums1Size, m, nums2, nums2Size, n);
	for (int i = 0; i < nums1Size; i++)
	{
		printf("%d", nums1[i]);
	}*/

	return 0;
}
