#include <bits/stdc++.h>
using namespace std;

// Print LC Subsequence
// Top-down

// My solution
int main()
{
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";
    int n = s1.length();
    int m = s2.length();
    vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
            }
            else
            {
                dp[i][j] = dp[i - 1][j].length() > dp[i][j - 1].length() ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }
    cout << dp[n][m];
    return 0;
}

// Better Approach
int main()
{
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";
    int n = s1.length();
    int m = s2.length();
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
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    string res = "";
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            res = s1[i - 1] + res;
            --i;
            --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            --i;
        }
        else
        {
            --j;
        }
    }
    cout << res;
    return 0;
}