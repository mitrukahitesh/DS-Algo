#include <bits/stdc++.h>
using namespace std;

/*
    O(2^n + n) time (n for putting ans in vector)
    O(2^n * k) space (average length k)
    O(n) aux space for recursion
*/

// My approach
void find_subsets(vector<vector<int>> &res, vector<int> &nums, int N, int k, vector<int> &set)
{
    if (k == N)
    {
        res.push_back(set);
        return;
    }
    // Skip duplicates if not taking the current number
    int i = k + 1;
    while (i < N && nums[k] == nums[i])
    {
        ++i;
    }
    find_subsets(res, nums, N, i, set);
    set.push_back(nums[k]);
    find_subsets(res, nums, N, k + 1, set);
    set.pop_back();
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> set;
    find_subsets(res, nums, nums.size(), 0, set);
    return res;
}

// Tutorial
void find_subsets_2(vector<vector<int>> &res, vector<int> &nums, int N, int k, vector<int> &set)
{
    res.push_back(set);
    for (int i = k; i < N; ++i)
    {
        if (i != k && nums[i] == nums[i - 1])
            continue;
        set.push_back(nums[i]);
        find_subsets_2(res, nums, N, i + 1, set);
        set.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> set;
    find_subsets(res, nums, nums.size(), 0, set);
    return res;
}