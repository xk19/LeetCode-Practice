#include "SeqList.h"
#include "SList.h"
#include "List.h"
#include "LeetCode.h"


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

    
    /****************************************LeetCode Test***********************************/
    
    /********通过构造函数求1+2+3+...+n之和**********/
    //Sum1ToN wqw;
    //cout << wqw.Sum_1toN(10) << endl;

    /***************给日期求天数***************/
    //DataSum();
    
    /******************仅仅反转字母*************/
    /*ReverseChar rech;
    string a("-sadsadg-0---sdf");
    cout << rech.ReverseOnlyLetters(a) << endl;*/

    /**********字符串中的第一个唯一字符**********/
    /*string ch("qqwwee");
    FirstUniqChar f;
    cout << f.firstUniqChar(ch) << endl;*/

    /*******************验证回文串**************/
    /*string ch("123321");
    Palindrome pa;
    cout << pa.isPalindrome(ch) << endl;*/

    /****************字符串相加****************/
    /*string num1("70");
    string num2("45");
    AddString adst;
    cout << adst.addStrings(num1, num2) << endl;
    cout << adst.multiply(num1, num2) << endl;*/

    /*****************只出现一次的数字***************/
    /*vector<int> nums1{2, 2, 3};
    vector<int> nums2{ 2, 2, 2, 3 };
    vector<int> nums3{ 2, 2, 5, 3 };
    SingleNumber sn;
    cout << sn.singleNumber(nums1) << endl;
    cout << sn.singleNumber3(nums2) << endl;
    vector<int> dif;
    dif = sn.singleNumber2Dif(nums3);
    cout << dif[0] << ' ' << dif[1] << endl;*/

    /**********************杨辉三角*********************/
    /*TriangleGenerate tri;
    vector<vector<int>> result;
    result = tri.generate(5);*/

    /***********************最小栈**************************/
    /*MinStack minst;
    minst.push(-2);
    minst.push(3);
    minst.push(0);
    minst.push(4);
    cout << minst.top() << endl;
    minst.pop();
    cout << minst.getMin() << endl;
    cout << minst.top() << endl;*/

   /***************栈的压入、弹出序列******************/
   /* vector<int> in = { 1, 2, 3, 4, 5 };
    vector<int> out = { 4, 2, 1, 5, 3};
    StackIsPopOrder st;
    cout << st.IsPopOrder(in, out) << endl;*/

    /****************逆波兰表达式求值******************/
    /*vector<string> in = {"4","13","5","/","+"};
    EvalRPN rpn;
    cout << rpn.evalRPN(in) << endl;*/

    /***************数组中的第K个最大元素***************/
    /*vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    FindKthLargest find;
    cout << find.findKthLargest(nums, k) << endl;*/

    /*****************将整数按权重排序*****************/
    /*ReWeight kth;
    int lo = 7, hi = 11, k = 4;
    int result = kth.getKth(lo, hi, k);
    cout << "The " << k << "-th smallest number in range [" << lo << ", " << hi << "] based on weight is: " << result << endl;*/

    /*****************合并两个有序数组*****************/
    /*vector<int> nums1 = { 1,2,3,0,0,0 };
    vector<int> nums2 = { 2,5,6 };
    int m = 3, n = 3;
    MergeOrderNums me;
    me.merge(nums1, m, nums2, n);
    for(auto e:nums1)
        cout << e << ' ';
    cout << endl;*/

    /*****************删除有序数组中的重复项 II*****************/
    /*vector<int> nums = { 0,0,1,1,1,1,2,3,3 };
    RemoveDuplicates2 rmd;
    int count = rmd.removeDuplicates(nums);
    for (int i = 0; i < count; i++)
        cout << nums[i] << ' ';
    cout << endl;*/

    /**********************多数元素***********************/  
    /*vector<int> nums = { 2,2,1,1,1,2,2 };
    MajorityElement maj;
    cout << maj.majorityElement(nums);*/

    /**********************轮转数组***********************/
    /*vector<int> nums = { 1,2,1,3,4,5,6 };
    Rotate rot;
    rot.rotate(nums, 4);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << ' ';
    cout << endl; */

    /*****************买卖股票的最佳时机*******************/
    /*vector<int> prices = { 7,1,5,3,6,4 };
    MaxProfit profit;
    cout << profit.maxProfit(prices) << endl;
    cout << profit.maxProfit2(prices) << endl;*/


    /**********************跳跃游戏***********************/
    /*vector<int> nums = { 2,3,1,1,4 };
    CanJump jump;
    cout << jump.jump(nums) << endl;*/

    /************************H指数************************/
    /*vector<int> nums = { 3,0,6,1,5 };
    HIndex h;
    cout << h.hIndex(nums) << endl;*/

    /**************除自身以外数组的乘积******************/
    /*vector<int> nums = { 1,2,3,4 };
    ProductExceptSelf pro;
    vector<int> answer = pro.productExceptSelf(nums);
    for(auto e:answer)
    {
        cout << e << ' ';
    }
    cout << endl;*/

    return 0;
}