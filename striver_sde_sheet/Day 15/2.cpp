#include <bits/stdc++.h>
using namespace std;

// Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/

// (i, j) = substr(i, j)

string longestPalindrome(string s)
{
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    dp[0][0] = true;
    int maxI = 0, maxL = 1;
    for (int i = 1; i < n; ++i)
    {
        dp[i][i] = true;
        if (s[i - 1] == s[i])
        {
            dp[i - 1][i] = true;
            maxI = i - 1;
            maxL = 2;
        }
    }
    //Lengths > 2
    for (int k = 3; k <= n; ++k)
    {
        //Starting at i
        for (int i = 0; i <= n - k; ++i)
        {
            int j = i + k - 1;
            // abba => a == b && non boundary substring is palindrome
            dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
            if (dp[i][j] && maxL < k)
            {
                maxI = i;
                maxL = k;
            }
        }
    }
    return s.substr(maxI, maxL);
}