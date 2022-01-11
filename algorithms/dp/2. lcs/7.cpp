#include <bits/stdc++.h>
using namespace std;

// Longest Palindromic Subsequence
// https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/ (For other solution)

int longestPalinSubseq(string A)
{
    string s1 = A;
    string s2 = A;
    reverse(s2.begin(), s2.end());
    int x = s1.length(), y = s2.length();
    vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));
    for (int i = 1; i <= x; ++i)
    {
        for (int j = 1; j <= y; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[x][y];
}