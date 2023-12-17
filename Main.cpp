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
	printf("请输入你的操作:>\n");
	printf("1、头插  2、头删\n");
	printf("3、尾插  4、尾删\n");
	printf("5、打印  -1、退出\n");
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
				printf("请输入数据你要头插的数据，以-1结束：");
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
				printf("请输入数据你要尾插的数据，以-1结束：");
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
				printf("无此选项，请重新输入\n");
				break;
		}
	}
	SeqListDestory(&s1);
}


int main()
{
	//TestSeqList();
	MenuTest();
	return 0;
}