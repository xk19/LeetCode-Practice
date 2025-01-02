#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

/********通过构造函数求1+2+3+...+n之和**********/
class Sum {
public:
    Sum();
    static int GetSum()
    {
        return _sum;
    }
private:
    static int _i;
    static int _sum;
};

class Sum1ToN {
public:
    int Sum_1toN(int n);
};

 
/***************给日期求天数***************/
int DataSum();



/******************仅仅反转字母*************/
class ReverseChar {
public:
    bool IsChar(char ch);
    string ReverseOnlyLetters(string s);
};


/**********字符串中的第一个唯一字符**************/
class FirstUniqChar {
public:
    int firstUniqChar(string s);
};


/********************验证回文串******************/
class Palindrome {
public:
    bool isCharOrNumber(char ch);
    bool isPalindrome(string s);
};


/********************字符串相加*******************/
class AddString {
public:
    string addStrings(string num1, string num2);
    string multiply(string num1, string num2);
};


/*****************只出现一次的数字***************/
class SingleNumber {
public:
    int singleNumber(vector<int>& nums);
    int singleNumber3(vector<int>& nums);
    vector<int> singleNumber2Dif(vector<int>& nums);
};


/**********************杨辉三角*********************/
class TriangleGenerate {
public:
    vector<vector<int>> generate(int numRows);
};


/*********************最小栈**********************/
class MinStack {
public:
    void push(int val);
    void pop();
    int top();
    int getMin();

    stack<int> _st;
    stack<int> _minist;
};



/***************栈的压入、弹出序列******************/
class StackIsPopOrder {
public:
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV);
};



/****************逆波兰表达式求值******************/
class EvalRPN {
public:
    int evalRPN(vector<string>& tokens);
};



/******************用栈实现队列********************/
class MyQueue {
public:
    MyQueue() {}
    void push(int x);
    int pop();
    int peek();
    bool empty();
    stack<int> st1;
    stack<int> st2;
};



/******************用队列实现栈********************/
class MyStack {
public:
    MyStack() {}
    void push(int x);
    int pop();
    int top();
    bool empty();
    queue<int> qu1;
    queue<int> qu2;
};



/****************数组中的第K个最大元素****************/
class FindKthLargest {
public:
    int findKthLargest(vector<int>& nums, int k);
};



/*****************将整数按权重排序*****************/
class ReWeight {
public:
    int getKth(int lo, int hi, int k);
    static int weight(int num)
    {
        if (num == 1) return 0;
        if (num & 1) return weight(num * 3 + 1) + 1;
        else return weight(num / 2) + 1;
    }
    static bool cmp(int a, int b)
    {
        if (weight(a) == weight(b))
            return a < b;
        else
            return weight(a) < weight(b);
    }
    vector<int> nums;
};

/*****************合并两个有序数组*****************/
class MergeOrderNums {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
};



/*****************删除有序数组中的重复项 II*****************/
class RemoveDuplicates2 {
public:
    int removeDuplicates(vector<int>& nums);
};


/**********************多数元素***********************/
class MajorityElement {
public:
    int majorityElement(vector<int>& nums);
};



/**********************轮转数组***********************/
class Rotate {
public:
    void rotate(vector<int>& nums, int k);
};



/*****************买卖股票的最佳时机*******************/
class MaxProfit {
public:
    int maxProfit(vector<int>& prices);
    int maxProfit2(vector<int>& prices);
};



/**********************跳跃游戏***********************/
class CanJump {
public:
    bool canJump(vector<int>& nums);
    int jump(vector<int>& nums);
};


/************************H指数************************/
class HIndex {
public:
    int hIndex(vector<int>& citations);
};


/**************除自身以外数组的乘积******************/
class ProductExceptSelf {
public:
    vector<int> productExceptSelf(vector<int>& nums);
};