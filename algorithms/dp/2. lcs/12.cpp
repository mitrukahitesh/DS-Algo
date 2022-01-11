#include <bits/stdc++.h>
using namespace std;

// Minimum number of insertion in a string to make it a palindrome

int countMin(string s1)
{
    int x = s1.length();
    int y = s1.length();
    string s2 = s1;
    reverse(s2.begin(), s2.end());
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
    return y - dp[x][y];
}