#include <bits/stdc++.h>
using namespace std;

// Coin change problem: Minimum number of coins
// Top-down
// O(m * v) time and space complexity

int minCoins(int coins[], int m, int v)
{
    vector<vector<int>> dp(m + 1, vector<int>(v + 1, -1));
    for (int i = 0; i <= m; ++i)
        dp[i][0] = 0;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= v; ++j)
        {
            if (coins[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                if (dp[i][j - coins[i - 1]] == -1)
                    dp[i][j] = dp[i - 1][j];
                else if (dp[i - 1][j] == -1)
                    dp[i][j] = 1 + dp[i][j - coins[i - 1]];
                else
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
            }
        }
    }
    return dp[m][v];
}

// OR

/*
int minCoins(int coins[], int m, int v)
{
    vector<vector<int>> dp(m + 1, vector<int>(v + 1, INT_MAX - 1));
    for (int i = 0; i <= m; ++i)
        dp[i][0] = 0;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= v; ++j)
        {
            if (coins[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {ss
                dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
            }
        }
    }
    return dp[m][v] == INT_MAX - 1 ? -1 : dp[m][v];
}
*/
