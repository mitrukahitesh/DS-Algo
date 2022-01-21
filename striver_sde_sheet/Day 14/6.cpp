#include <bits/stdc++.h>
using namespace std;

// Implement Min Stack
// https://leetcode.com/problems/min-stack/

class MinStack
{
public:
    // Number - Minimum number till that number
    list<pair<int, int>> nums;
    MinStack()
    {
    }

    void push(int val)
    {
        int x = val;
        if (nums.size() != 0)
            x = min(val, nums.back().second);
        nums.push_back({val, x});
    }

    void pop()
    {
        nums.pop_back();
    }

    int top()
    {
        return nums.back().first;
    }

    int getMin()
    {
        return nums.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// Another approach
/*
    val < min
    val - min < 0
    val - min + val < 0 + val
    2*val - min < val

    modified = 2*val - min
    min = 2*val - modified
    Here, val = currentMin and min = previous min
*/
class MinStack
{
public:
    list<long long> nums;
    long long mini;
    MinStack()
    {
        mini = INT_MIN;
    }

    void push(long long val)
    {
        if (nums.empty())
        {
            nums.push_back(val);
            mini = val;
            return;
        }
        if (val < mini)
        {
            nums.push_back(2 * val - mini);
            mini = val;
        }
        else
        {
            nums.push_back(val);
        }
    }

    void pop()
    {
        if (nums.back() < mini)
            mini = 2 * mini - nums.back();
        nums.pop_back();
        if (nums.empty())
            mini = INT_MAX;
    }

    int top()
    {
        return nums.back() < mini ? mini : nums.back();
    }

    int getMin()
    {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */