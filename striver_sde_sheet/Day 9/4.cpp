#include <bits/stdc++.h>
using namespace std;

// My approach
void find_sets(vector<vector<int>> &res, vector<int> &candidates, int N, int t, int s, int k, vector<int> &set)
{
    if (s == t)
    {
        res.push_back(set);
        return;
    }
    if (s > t || k == N)
        return;
    int i = k + 1;
    while (i < N && candidates[i] == candidates[k])
    {
        ++i;
    }
    find_sets(res, candidates, N, t, s, i, set);
    set.push_back(candidates[k]);
    find_sets(res, candidates, N, t, s + candidates[k], k + 1, set);
    set.pop_back();
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> set;
    find_sets(res, candidates, candidates.size(), target, 0, 0, set);
    return res;
}

// Tutorial
void comb(vector<vector<int>> &res, vector<int> &temp, vector<int> &c, int t, int idx)
{
    if (t < 0)
        return;
    if (t == 0)
    {
        res.push_back(temp);
        return;
    }
    for (int i = idx; i < c.size(); ++i)
    {
        if (i != idx && (c[i] == c[i - 1]))
            continue;
        if (c[i] > t)
            break;
        int num = c[i];
        temp.push_back(num);
        comb(res, temp, c, t - num, i + 1);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    if (target == 0)
        return {{}};

    sort(begin(candidates), end(candidates));

    vector<vector<int>> res;
    vector<int> temp;
    comb(res, temp, candidates, target, 0);

    return res;
}