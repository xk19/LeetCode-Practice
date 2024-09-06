#include "SeqList.h"
#include "SList.h"

/********************************LeetCode测试函数********************************/
struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* cur = head, * prev = NULL;

    while (cur)
    {
        if (cur->val == val)
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

/********************************顺序表的测试函数********************************/
void TestSeqList()
{
    SL phead;
    int pos;
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

/********************************链表的测试函数********************************/
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

    SListDestory(&phead);

}

/**************************************菜单测试代码*********************************/
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
    
    //链表
    TestSList();

    //菜单
    //MenuTest();

    //手动创建链表
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
    struct ListNode* head = removeElements(n1, 7); */

    return 0;
}