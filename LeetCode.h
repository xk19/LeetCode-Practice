#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
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