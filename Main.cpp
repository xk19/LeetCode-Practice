#include"SeqList.h"
#include"SList.h"

/********************************�ò���ΪLeetCode���Դ���*******************************/
// Definition for singly - linked list.
struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode* cur = head, * pre = NULL;
	while (cur)
	{
		if (cur->val == val)
		{
			if (cur == head)
			{
				head = cur->next;
				free(cur);
				cur = head;
			}
			else
			{
				pre->next = cur->next;
				free(cur);
				cur = pre->next;
			}
		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}
	return head;
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
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 6);
	SListPrint(phead);

	//Find
	SLTNode* pos = SListFind(phead, 1);
	int i = 0;
	while(pos)
	{ 
		printf("��%d���ڵ��ַΪ:%p\n", ++i, pos);
		pos = SListFind(pos->next, 1);
	}

	//Replace
	pos = SListFind(phead, 4);
	if (pos) pos->data = 40;
	SListPrint(phead);

	//Insert
	pos = SListFind(phead, 5);
	if (pos)
	{
		SListInsert(&phead, pos, 50);
	}
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
	//�ֶ���������
	/*struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n1->val = 7;
	n2->val = 7;
	n3->val = 7;
	n4->val = 7;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;
	struct ListNode* head = removeElements(n1, 7);*/

	return 0;
}
