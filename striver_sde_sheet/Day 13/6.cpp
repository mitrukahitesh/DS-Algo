#include <bits/stdc++.h>
using namespace std;

// Next greater element II

// Approach 1
vector<int> nextGreaterElements(vector<int> &nums)
{
    stack<int> s;
    s.push(0);
    vector<int> res(nums.size(), -1);
    for (int i = 1; i < nums.size(); ++i)
    {
        if (s.empty())
        {
            s.push(i);
            continue;
        }
        while (!s.empty() && nums[i] > nums[s.top()])
        {
            int index = s.top();
            s.pop();
            res[index] = nums[i];
        }
        s.push(i);
    }
    int i = 0;
    while (!s.empty())
    {
        int index = s.top();
        s.pop();
        for (; i < nums.size(); ++i)
        {
            if (nums[i] > nums[index])
            {
                res[index] = nums[i];
                break;
            }
        }
    }
    return res;
}

// Editorial
vector<int> nextGreaterElements(vector<int> &nums)
{
    vector<int> res(nums.size(), -1);
    stack<int> stack;
    for (int i = 2 * nums.size() - 1; i >= 0; --i)
    {
        while (!stack.empty() && nums[stack.top()] <= nums[i % nums.size()])
        {
            stack.pop();
        }
        res[i % nums.size()] = stack.empty() ? -1 : nums[stack.top()];
        stack.push(i % nums.size());
    }
    return res;
}