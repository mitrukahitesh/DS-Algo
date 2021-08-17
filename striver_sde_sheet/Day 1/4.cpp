#include <bits/stdc++.h>
using namespace std;

// Kadane's Algorithm
// O(n) time O(1) space
// O(n2) brute force

int maxOf(int a, int b)
{
    return a > b ? a : b;
}

int maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int max = nums[0];
    for (int i = 0; i < nums.size(); ++i)
    {
        sum = maxOf(nums[i] + sum, nums[i]);
        max = maxOf(sum, max);
    }
    return max;
}