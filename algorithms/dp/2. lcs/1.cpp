#include <bits/stdc++.h>
using namespace std;

// Longest Common Subsequence
// Bottom-up (with memoization)
// O(x * y) time and space
// A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.

int lcs_util(int x, int y, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (x == 0 || y == 0)
        return 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    if (s1[x - 1] == s2[y - 1])
        return dp[x][y] = 1 + lcs_util(x - 1, y - 1, s1, s2, dp);
    return dp[x][y] = max(lcs_util(x - 1, y, s1, s2, dp), lcs_util(x, y - 1, s1, s2, dp));
}

int lcs(int x, int y, string s1, string s2)
{
    vector<vector<int>> dp(x + 1, vector<int>(y + 1, -1));
    return lcs_util(x, y, s1, s2, dp);
}