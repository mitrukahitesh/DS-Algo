#include <bits/stdc++.h>
using namespace std;

// O(n) time
// O(1) space
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int max = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == 1)
        {
            ++sum;
        }
        else
        {
            if (sum > max)
                max = sum;
            sum = 0;
        }
    }
    return max > sum ? max : sum;
}