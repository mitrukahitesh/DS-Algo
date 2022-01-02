#include <bits/stdc++.h>
using namespace std;

// Coin change problem: Maximum number of ways
// Top-down
// O(m * n) time and space complexity
// Subset sum count (Perfect Sum Problem Q5) + unbounded knapsack

long long int count(int s[], int m, int n)
{
    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
    for (int i = 0; i <= m; ++i)
        dp[i][0] = 1;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (s[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i][j - s[i - 1]] + dp[i - 1][j];
            }
        }
    }
    return dp[m][n];
}