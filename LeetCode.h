#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

/********ͨ�����캯����1+2+3+...+n֮��**********/
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

 
/***************������������***************/
int DataSum();



/******************������ת��ĸ*************/
class ReverseChar {
public:
    bool IsChar(char ch);
    string ReverseOnlyLetters(string s);
};


/**********�ַ����еĵ�һ��Ψһ�ַ�**************/
class FirstUniqChar {
public:
    int firstUniqChar(string s);
};


/********************��֤���Ĵ�******************/
class Palindrome {
public:
    bool isCharOrNumber(char ch);
    bool isPalindrome(string s);
};


/********************�ַ������*******************/
class AddString {
public:
    string addStrings(string num1, string num2);
    string multiply(string num1, string num2);
};


/*****************ֻ����һ�ε�����***************/
class SingleNumber {
public:
    int singleNumber(vector<int>& nums);
    int singleNumber3(vector<int>& nums);
    vector<int> singleNumber2Dif(vector<int>& nums);
};


/**********************�������*********************/
class TriangleGenerate {
public:
    vector<vector<int>> generate(int numRows);
};


/*********************��Сջ**********************/
class MinStack {
public:
    void push(int val);
    void pop();
    int top();
    int getMin();

    stack<int> _st;
    stack<int> _minist;
};

