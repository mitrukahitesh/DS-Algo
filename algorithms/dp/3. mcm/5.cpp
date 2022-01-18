#include <bits/stdc++.h>
using namespace std;

// Egg Dropping Problem

// DP(MCM) + Binary search for optimization

// https://leetcode.com/problems/super-egg-drop/solution/

// O(f(eggs)logf) time

int solve(int eggs, int f, vector<vector<int>> &dp)
{
    if (eggs == 1 || f == 1 || f == 0)
        return f;
    if (dp[eggs][f] != -1)
        return dp[eggs][f];
    int res = INT_MAX;
    int l = 1, h = f;
    while (l <= h)
    {
        int k = l + (h - l) / 2;
        int a = solve(eggs - 1, k - 1, dp);
        int b = solve(eggs, f - k, dp);
        res = min(max(a, b), res);
        if (a < b)
            l = k + 1;
        else
            h = k - 1;
    }
    return dp[eggs][f] = res + 1;
}
// k = eggs
// n = floors
int superEggDrop(int k, int n)
{
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
    return solve(k, n, dp);
}