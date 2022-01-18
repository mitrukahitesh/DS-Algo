#include <bits/stdc++.h>
using namespace std;

// Palindrome Partitioning

// Optimization: https://www.youtube.com/watch?v=9h10fqkI7Nk&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=37

bool isPalindrome(string &s, int i, int j)
{
    while (i < j)
    {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}
int solve(string &s, int i, int j, vector<vector<int>> &dp)
{
    if (i >= j || isPalindrome(s, i, j))
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int res = INT_MAX;
    for (int k = i; k < j; ++k)
    {
        if (isPalindrome(s, i, k)) // Without this, won't be accepted in leetcode
            res = min(res, 1 + solve(s, i, k, dp) + solve(s, k + 1, j, dp));
    }
    return dp[i][j] = res;
}
int minCut(string s)
{
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(s, 0, n - 1, dp);
}