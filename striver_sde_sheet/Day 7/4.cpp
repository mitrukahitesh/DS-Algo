#include <bits/stdc++.h>
using namespace std;

// O(n) time
// O(1) space
int removeDuplicates(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    int l = 0;
    int r = 1;
    while (r < nums.size())
    {
        if (nums[r] != nums[l])
        {
            nums[l + 1] = nums[r];
            ++l;
        }
        ++r;
    }
    return l + 1;
}