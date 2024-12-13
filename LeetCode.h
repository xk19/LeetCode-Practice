#pragma once
#include <string>
#include <iostream>

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