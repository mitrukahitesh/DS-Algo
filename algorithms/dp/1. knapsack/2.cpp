#include <bits/stdc++.h>
using namespace std;

// 0-1 Knapsack
// Top-Down
// Time Complexity: O(N*W)
// Sapce Complexity: O(N*W)

int knapSack(int w, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][w];
}