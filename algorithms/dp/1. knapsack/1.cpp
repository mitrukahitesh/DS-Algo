#include <bits/stdc++.h>
using namespace std;

// 0-1 Knapsack
// Memoization
// Time Complexity: O(N*W)
// Sapce Complexity: O(N*W)

int knapsack(int w, int *wt, int *val, int n, vector<vector<int>> &dp)
{
    if (n == 0 || w == 0)
        return 0;
    if (dp[n][w] != -1)
        return dp[n][w];
    if (wt[n - 1] <= w)
    {
        return dp[n][w] = max(val[n - 1] + knapsack(w - wt[n - 1], wt, val, n - 1, dp), knapsack(w, wt, val, n - 1, dp));
    }
    return dp[n][w] = knapsack(w, wt, val, n - 1, dp);
}

int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    return knapsack(W, wt, val, n, dp);
}