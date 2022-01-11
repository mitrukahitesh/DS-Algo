#include <bits/stdc++.h>
using namespace std;

// Print shortest common Supersequence
// 2 methods

string shortestCommonSupersequence(string str1, string str2)
{
    int n = str1.length(), m = str2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
        dp[i][0] = i;
    for (int i = 1; i <= m; ++i)
        dp[0][i] = i;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string res = "";
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            res = str1[i - 1] + res;
            i--;
            j--;
        }
        else if (dp[i - 1][j] < dp[i][j - 1])
        {
            res = str1[i - 1] + res;
            i--;
        }
        else
        {
            res = str2[j - 1] + res;
            j--;
        }
    }
    while (i > 0)
    {
        res = str1[--i] + res;
    }
    while (j > 0)
    {
        res = str2[--j] + res;
    }
    return res;
}

// Directly from LCS
string shortestCommonSupersequence(string str1, string str2)
{
    int n = str1.length(), m = str2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string res = "";
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            res = str1[i - 1] + res;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            res = str1[i - 1] + res;
            i--;
        }
        else
        {
            res = str2[j - 1] + res;
            j--;
        }
    }
    while (i > 0)
    {
        res = str1[--i] + res;
    }
    while (j > 0)
    {
        res = str2[--j] + res;
    }
    return res;
}