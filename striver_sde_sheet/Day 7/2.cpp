#include <bits/stdc++.h>
using namespace std;

/*
    Brute force:
    O(n^3 logm) time using 3 loops and a set to store res
    O(m) space for set
    m = number of triplets
*/

// O(nlogn) + O(n^2) time
// O(m) space, m = number of triplets
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    // nums.size() returns size_type, an unsigned integral type
    for (int i = 0; i < (int)nums.size() - 2; ++i)
    {
        int l = i + 1, h = nums.size() - 1;
        while (l < h)
        {
            if (nums[i] + nums[l] + nums[h] == 0)
            {
                vector<int> v;
                v.push_back(nums[i]);
                v.push_back(nums[l]);
                v.push_back(nums[h]);
                res.push_back(v);
                while (l < h && nums[l] == nums[l + 1])
                    ++l;
                ++l;
                while (h > l && nums[h] == nums[h - 1])
                    --h;
                --h;
            }
            else if (nums[i] + nums[l] + nums[h] > 0)
            {
                --h;
            }
            else
            {
                ++l;
            }
        }
        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            ++i;
    }
    return res;
}