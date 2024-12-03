#include "LeetCode.h"
#include <iostream>
using namespace std;

/********求两数之和******/
Sum::Sum()
{
    _sum += _i;
    ++_i;
}
int Sum::_i = 1;
int Sum::_sum = 0;

int Solution::Sum_Solution(int n)
{
    Sum* P = new  Sum[n];
    return Sum::GetSum();
}

/***********给日期求天数***********/
int DataSum()
{
    static int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 31, 30, 31 };
    int year, month, day;
    while (cin >> year >> month >> day)
    {
        int n = 0;
        for (int i = 1; i < month; i++)
        {
            n += monthDays[i];
        }
        n += day;
        if (month > 2 && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)))
        {
            n += 1;
        }
        cout << n << endl;
    }
    return 0;
}