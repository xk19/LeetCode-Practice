#include "LeetCode.h"

/**********通过构造函数求1+2+3+...+n之和*********/
Sum::Sum()
{
    _sum += _i;
    ++_i;
}
int Sum::_i = 1;
int Sum::_sum = 0;

int Sum1ToN::Sum_1toN(int n)
{
    Sum* P = new  Sum[n];
    return Sum::GetSum();
}

/*******************给日期求天数***************/
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

/***************仅仅反转字母****************/

bool ReverseChar::IsChar(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

string ReverseChar::ReverseOnlyLetters(string s)
{
    int begin = 0;
    int end = s.size() - 1;

    while (begin < end)
    {
        while (!IsChar(s[begin]) && begin < end)
        {
            begin++;
        }
        while (!IsChar(s[end]) && begin < end)
        {
            end--;
        }
        swap(s[begin++], s[end--]);
    }
    return s;
}


/**********字符串中的第一个唯一字符**************/
int FirstUniqChar::firstUniqChar(string s)
{
    int count[26] = { 0 };
    for (auto ch : s)
    {
        count[ch - 'a']++;
    }
    for (size_t i = 0; i < s.size(); i++)
    {
        if (count[s[i] - 'a'] == 1)
        {
            return i;
        }
    }
    return -1;
}

/********************验证回文串******************/

bool Palindrome::isCharOrNumber(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        return true;
    else
        return false;
}
bool Palindrome::isPalindrome(string s) {
    for (auto& ch : s)
    {
        if (ch >= 'A' && ch <= 'Z')
            ch += 32;
    }
    int begin = 0;
    int end = s.size() - 1;
    while (begin < end)
    {
        while (!(isCharOrNumber(s[begin])) && begin < end)
        {
            ++begin;
        }
        while (!(isCharOrNumber(s[end])) && begin < end)
        {
            --end;
        }

        if (s[begin] != s[end])
        {
            return false;
        }
        else
        {
            ++begin;
            --end;
        }
    }
    return true;
}


/********************字符串相加/相乘*******************/
string AddString::addStrings(string num1, string num2) {
    int end1 = num1.size() - 1;
    int end2 = num2.size() - 1;
    int next = 0;

    string str;
    while (end1 >= 0 || end2 >= 0)
    {
        int val1 = 0, val2 = 0;
        int strnum = 0;
        if (end1 >= 0)
            val1 = num1[end1] - '0';
        else
            val1 = 0;
        if (end2 >= 0)
            val2 = num2[end2] - '0';
        else
            val2 = 0;

        strnum = val1 + val2 + next;
        if (strnum > 9)
        {
            strnum -= 10;
            next = 1;
        }
        else
        {
            next = 0;
        }

        str += (strnum + '0');
        end1--;
        end2--;
    }
    if (next == 1) str += (next + '0');

    reverse(str.begin(), str.end());
    return str;
}

string AddString::multiply(string num1, string num2) {

    int end = num2.size() - 1;
    int count = 0;
    string result("0");

    while (end >= 0)
    {
        string i("0");
        string part("0");
        if (num1 == "0") return "0";

        while (i[0] != num2[end])
        {
            part = addStrings(part, num1);
            i = addStrings(i, "1");
        }

        for (int j = 0; j < count; j++)
        {
            part += '0';
        }
        --end;
        ++count;
        result = addStrings(result, part);
    }


    return result;
}


/*****************只出现一次的数字***************/
int SingleNumber::singleNumber(vector<int>& nums) {
    int  result = 0;
    for (auto e : nums)
    {
        result ^= e;
    }
    return result;
}

int SingleNumber::singleNumber3(vector<int>& nums) {
    int  result = 0;
    int count[32] = { 0 };
    for (auto e : nums)
    {
        for (int i = 0; i < 32; i++)
        {
            if (e & (1 << i))
                ++count[i];
        }
    }
    cout << count[1] << count[0] << endl;
    for (int i = 0; i < 32; i++)
    {
        if (count[i] % 3 == 1) result += (1 << i);
    }

    return result;
}

vector<int> SingleNumber::singleNumber2Dif(vector<int>& nums) {
    int val = 0, flag;
    for (auto e : nums)
    {
        val ^= e;
    }
    for (flag = 0; flag < 32; flag++)
    {
        if (val & (1 << flag))
            break;
    }
    vector<int> result(2, 0);
    for (auto e : nums)
    {
        if (e & (1 << flag))
            result[0] ^= e;
        else
            result[1] ^= e;
    }
    return result;
}


/**********************杨辉三角*********************/
vector<vector<int>> TriangleGenerate::generate(int numRows) {
    vector<vector<int>> vv;
    vv.resize(numRows);
    vv[0].resize(1);
    vv[0][0] = 1;
    if (numRows == 1) return vv;
    for (int i = 1; i < numRows; ++i)
    {
        vv[i].resize(i + 1);
        vv[i][i] = 1;
        vv[i][0] = 1;
        for (int j = 1; j < i; ++j)
        {
            vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
        }
    }
    return vv;
}


/*********************最小栈**********************/
void MinStack::push(int val) {
    _st.push(val);
    if (_minist.empty() || val <= _minist.top())
    {
        _minist.push(val);
    }
}

void MinStack::pop() {
    if (_st.top() == _minist.top())
    {
        _minist.pop();
    }
    _st.pop();
}

int MinStack::top() {
    return _st.top();
}

int MinStack::getMin() {
    return _minist.top();
}



/***************栈的压入、弹出序列******************/
bool StackIsPopOrder::IsPopOrder(vector<int>& pushV, vector<int>& popV) {
    // write code here
    stack<int> st;
    int pushi = 0, popi = 0;
    while (pushi < pushV.size())
    {
        st.push(pushV[pushi]);
        ++pushi;
        while (!st.empty() && st.top() == popV[popi])
        {
            st.pop();
            ++popi;
        }
    }
    return st.empty();
}



/****************逆波兰表达式求值******************/
int EvalRPN::evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (auto& str : tokens)
    {
        if (str == "+" || str == "-" || str == "*" || str == "/")
        {
            int right = st.top();
            st.pop();
            int left = st.top();
            st.pop();

            switch (str[0])
            {
            case '+':
                st.push(left + right);
                break;
            case '-':
                st.push(left - right);
                break;
            case '*':
                st.push(left * right);
                break;
            case '/':
                st.push(left / right);
                break;
            }
        }
        else
        {
            st.push(stoi(str));
        }
    }
    return st.top();
}



/****************用栈实现队列******************/
void MyQueue::push(int x) {
    st1.push(x);
}

int MyQueue::pop() {
    if (st2.empty())
    {
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
    }
    int temp = st2.top();
    st2.pop();
    return temp;
}

int MyQueue::peek() {
    if (st2.empty())
    {
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
    }
    return st2.top();
}

bool MyQueue::empty() {
    return st1.empty() && st2.empty();
}



/******************用队列实现栈********************/
void MyStack::push(int x) {
    if (qu1.empty())
    {
        qu1.push(x);
        while (!qu2.empty())
        {
            qu1.push(qu2.front());
            qu2.pop();
        }
    }
    else
    {
        qu2.push(x);
        while (!qu1.empty())
        {
            qu2.push(qu1.front());
            qu1.pop();
        }
    }
}

int MyStack::pop() {
    int tmp = 0;
    if (!qu1.empty())
    {
        tmp = qu1.front();
        qu1.pop();
    }
    else
    {
        tmp = qu2.front();
        qu2.pop();
    }
    return tmp;
}

int MyStack::top() {
    if (!qu1.empty())
        return qu1.front();
    else
        return qu2.front();
}

bool MyStack::empty() {
    return qu1.empty() && qu2.empty();
}



/****************数组中的第K个最大元素****************/
int FindKthLargest::findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> kth;
    for (auto e : nums)
        kth.push(e);
    while (--k)
    {
        kth.pop();
    }
    return kth.top();
}



/*****************将整数按权重排序*****************/
int ReWeight::getKth(int lo, int hi, int k) {
    for (int i = lo; i <= hi; i++)
    {
        nums.push_back(i);
    }
    sort(nums.begin(), nums.end(), cmp);
    return nums[k - 1];
}


/*****************合并两个有序数组*****************/
void MergeOrderNums::merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int a = m - 1, b = n - 1, i = m + n - 1;
    while (a >= 0 && b >= 0)
    {
        if (nums1[a] >= nums2[b]) nums1[i--] = nums1[a--];
        else nums1[i--] = nums2[b--];
    }
    if (a < 0)
    {
        while (b >= 0)
        {
            nums1[i--] = nums2[b--];
        }
    }
}



/*****************删除有序数组中的重复项 II*****************/
int RemoveDuplicates2::removeDuplicates(vector<int>& nums) {
    int posprv = 0, pos = 1, flag = 0;
    if (nums.size() <= 2) return nums.size();
    int i = 2;
    while (i < nums.size())
    {
        if (nums[posprv] == nums[pos] && nums[pos] == nums[i])
        {
            i++;
        }
        else
        {
            nums[++pos] = nums[i++];
            posprv++;
        }
    }
    return pos + 1;
}