#pragma once

/*************������֮��**********/
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

class Solution {
public:
    int Sum_Solution(int n);
};

 
/***********������������***********/
int DataSum();