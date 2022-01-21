#include <bits/stdc++.h>
using namespace std;

// Sliding Window Maximum
// https://leetcode.com/problems/sliding-window-maximum/

// Storing numbers in decreasing order

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    list<int> ls;
    vector<int> res;
    for (int i = 0; i < n; ++i)
    {
        while (!ls.empty() && nums[ls.back()] <= nums[i])
            ls.pop_back();
        ls.push_back(i);
        if (!ls.empty() && ls.front() < (i - k + 1))
            ls.pop_front();
        if (i >= k - 1)
            res.push_back(nums[ls.front()]);
    }
    return res;
}