#include <bits/stdc++.h>
using namespace std;

// Longest Common Substring
// Top-down
// The idea is to find the length of the longest common suffix for all
// substrings of both strings and store these lengths in a table.
// Recursion + memoization won't work

int longestCommonSubstr(string s1, string s2, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    int max = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (dp[i][j] > max)
                max = dp[i][j];
        }
    }
    return max;
}
