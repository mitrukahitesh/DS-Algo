#include <bits/stdc++.h>
using namespace std;

// Rod cutting
// Top-down
// O(n * n) time and space complexity
// W = n, val = price, wt = [1,2.....,n] => Knapsack

int cutRod(int price[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (j < i)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(price[i - 1] + dp[i][j - i], dp[i - 1][j]);
            }
        }
    }
    return dp[n][n];
}