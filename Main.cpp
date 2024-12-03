#include "SeqList.h"
#include "SList.h"
#include "List.h"
#include "LeetCode.h"
#include <iostream>

using namespace std;

/********************************LeetCode测试函数********************************/
SLTNode* removeElements(SLTNode* head, int val)
{
    SLTNode* cur = head, *prev = NULL;

    while (cur)
    {
        if (cur->data == val)
        {
            if (cur == head)
            {
                head = head->next;
                free(cur);
                cur = head;
            }
            else
            {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}

/************************************顺序表************************************/
void TestSeqList()
{
    SL phead;
    SeqListInit(&phead);
    SeqListPushBack(&phead, 1);
    SeqListPushBack(&phead, 2);
    SeqListPushBack(&phead, 3);
    SeqListPushFront(&phead, 10);
    SeqListPushFront(&phead, 20);
    SeqListPushFront(&phead, 30);
    SeqLiatErase(&phead, 3);
    SeqListPrint(&phead);
}

/************************************单链表************************************/
void TestSList()
{
    SLTNode* phead = NULL;
    SListPushBack(&phead, 1);
    SListPushBack(&phead, 2);
    SListPushBack(&phead, 3);
    SListPushBack(&phead, 4);
    SListPushFront(&phead, 10);
    SListPushFront(&phead, 20);
    SListPushFront(&phead, 30);
    SListPushFront(&phead, 40);
    SListPushBack(&phead, 1);
    SListPrint(phead); 
    
    //Find
    SLTNode* pos = SListFind(phead,1);
    int i = 0;
    while(pos)
    {
        printf("第%d个节点地址为：%p\n", ++i, pos);
        pos = SListFind(pos->next, 1);
    }

    //Replace
    pos = SListFind(phead, 2);
    if (pos) pos->data = 200;
    SListPrint(phead);

    //Insert
    pos = SListFind(phead, 3);
    SListInsert(&phead, pos, 300);
    SListPrint(phead);

    //Erase
    pos = SListFind(phead, 40);
    SListErase(&phead, pos);
    SListPrint(phead);

    SListDestroy(&phead);

}

/************************************带头双向循环链表********************************/
void TestList()
{
    LTNode* phead = ListInit();
    ListPushBack(phead, 1);
    ListPushBack(phead, 2);
    ListPushBack(phead, 3);
    ListPushBack(phead, 4);
    ListPushFront(phead, 10);
    ListPushFront(phead, 20);
    ListPushFront(phead, 30);
    ListPushFront(phead, 40);

    ListPrint(phead);
    ListPoPBack(phead);
    ListPopFront(phead);
    ListPrint(phead);

    //Erase
    LTNode* pos = ListFind(phead, 30);
    ListErase(phead, pos);
    ListPrint(phead);

    ListDestroy(phead);
    phead = NULL;
}

/******************************************菜单*************************************/
void Menu()
{
    printf("*************************\n");
    printf("请输入你的操作：>\n");
    printf("1、头插 2、头删\n");
    printf("3、尾插 4、尾删\n");
    printf("5、打印 -1、退出\n");
    printf("*************************\n");
}

void MenuTest()
{
    int input = 0, x = 0;
    SL phead;
    SeqListInit(&phead);
    while (input != -1)
    {
        Menu();
        scanf_s("%d", &input);
        switch (input)
        {
        case 1:
            printf("请输入你要头插的数据，以-1结束：");
            scanf_s("%d", &x);
            while (x != -1)
            {
                SeqListPushFront(&phead, x);
                scanf_s("%d", &x);
            }
            break;
        case 2:
            SeqListPopFront(&phead);
            break;
        case 3:
            printf("请输入你要尾插的数据，以-1结束：");
            scanf_s("%d", &x);
            while (x != -1)
            {
                SeqListPushBack(&phead, x);
                scanf_s("%d", &x);
            }
            break;
        case 4:
            SeqListPopBack(&phead);
            break;
        case 5:
            SeqListPrint(&phead);
            printf("\n");
            break;
        case -1:
            break;
        default:
            printf("无此选项，请重新输入\n");
            break;
           
        }
    }
}

/****************************************Main函数***********************************/
int main()
{
    //顺序表
    //TestSeqList();
    
    //单链表
    //TestSList();

    //带头双向循环链表
    //TestList();

    //菜单
    //MenuTest();

    //手动创建链表
    /*SLTNode* n1 = (SLTNode*)malloc(sizeof(SLTNode));
    SLTNode* n2 = (SLTNode*)malloc(sizeof(SLTNode));
    SLTNode* n3 = (SLTNode*)malloc(sizeof(SLTNode));
    SLTNode* n4 = (SLTNode*)malloc(sizeof(SLTNode));
    n1->data = 7;
    n2->data = 7;
    n3->data = 7;
    n4->data = 7;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;
    SLTNode* head = removeElements(n1, 7);
    SListPrint(head);*/
    Solution st;
    cout << st.Sum_Solution(5) << endl;


    return 0;
}