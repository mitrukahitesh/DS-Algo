#include <bits/stdc++.h>
using namespace std;

/**
 * Appraoch 1
 * O(n! * n) time
 * O(n + n) space for taken and per (ignoring res)
 * 
 * Approach 2
 * O(n! * n) time
 * O(1) space
 * 
 * Approach 2
 * O(n! * n) time
 * O(n) space for recursive stack
 */

// Approach 1
void find_permutation(vector<vector<int>> &res, vector<int> &per, vector<int> &taken, vector<int> &nums)
{
    if (per.size() == nums.size())
    {
        res.push_back(per);
        return;
    }
    for (int i = 0; i < nums.size(); ++i)
    {
        if (!taken[i])
        {
            per.push_back(nums[i]);
            taken[i] = 1;
            find_permutation(res, per, taken, nums);
            taken[i] = 0;
            per.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> per;
    vector<int> taken(nums.size(), 0);
    find_permutation(res, per, taken, nums);
    return res;
}

// Approach 2
void reverse(vector<int> &nums, int l, int r)
{
    while (l < r)
        swap(nums[l++], nums[r--]);
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    res.push_back(nums);
    long long int fac = 1;
    for (int i = 1; i <= nums.size(); ++i)
        fac *= i;
    while (fac--)
    {
        int k = nums.size() - 2;
        while (k >= 0 && nums[k] > nums[k + 1])
            --k;
        if (k < 0)
            break;
        int l = nums.size() - 1;
        while (nums[k] > nums[l])
            --l;
        swap(nums[k], nums[l]);
        reverse(nums, k + 1, nums.size() - 1);
        res.push_back(nums);
    }
    return res;
}

// Approach 3
void recurPermute(vector<vector<int>> &res, vector<int> &nums, int k)
{
    if (k == nums.size())
    {
        res.push_back(nums);
        return;
    }
    for (int i = k; i < nums.size(); ++i)
    {
        swap(nums[i], nums[k]);
        recurPermute(res, nums, k + 1);
        swap(nums[i], nums[k]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;
    recurPermute(res, nums, 0);
    return res;
}