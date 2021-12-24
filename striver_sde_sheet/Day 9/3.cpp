#include <bits/stdc++.h>
using namespace std;

// O(2^t * k) time, k = time for insertion in ds
// O(2^n * k) space, (average length k) (at max because 2^n is max no. of subsets)

// My appraoch
void find_combinations(vector<vector<int>> &res, vector<int> &nums, vector<int> ds, int N, int t, int k, int s)
{
    if (s == t)
    {
        res.push_back(ds);
        return;
    }
    for (int i = k; i < N && s + nums[i] <= t; ++i)
    {
        ds.push_back(nums[i]);
        find_combinations(res, nums, ds, N, t, i, s + nums[i]);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> ds;
    find_combinations(res, nums, ds, nums.size(), target, 0, 0);
    return res;
}