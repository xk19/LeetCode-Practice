#include "LeetCode.h"
#include <iostream>
#include <utility>
using namespace std;

/********������֮��******/
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