#pragma once
#include <string>
#include <iostream>

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