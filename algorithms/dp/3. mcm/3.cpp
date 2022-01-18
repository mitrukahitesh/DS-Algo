#include <bits/stdc++.h>
using namespace std;

// Evaluate Expression to True Boolean Parenthesization

// Approach - https://leetcode.com/discuss/general-discussion/1279635/boolean-parenthesization-easy-c

// My approach
pair<int, int> solve(string &s, int i, int j, vector<vector<pair<int, int>>> &dp)
{
    pair<int, int> count;
    count = make_pair(0, 0);
    if (i > j)
        return count;
    if (dp[i][j].first != -1)
        return dp[i][j];
    if (i == j)
    {
        if (s[i] == 'T')
            count.first = 1;
        else
            count.second = 1;
        return dp[i][j] = count;
    }
    for (int k = i + 1; k < j; k += 2)
    {
        pair<int, int> a = solve(s, i, k - 1, dp);
        pair<int, int> b = solve(s, k + 1, j, dp);
        if (s[k] == '&')
        {
            count.first += (a.first * b.first) % 1003;
            count.second += (a.first * b.second + a.second * b.first + a.second * b.second) % 1003;
        }
        else if (s[k] == '|')
        {
            count.first += (a.first * b.first + a.first * b.second + a.second * b.first) % 1003;
            count.second += (a.second * b.second) % 1003;
        }
        else
        {
            count.first += (a.first * b.second + a.second * b.first) % 1003;
            count.second += (a.second * b.second + a.first * b.first) % 1003;
        }
        count.first %= 1003;
        count.second %= 1003;
    }
    return dp[i][j] = count;
}

int countWays(int n, string s)
{
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, -1}));
    return solve(s, 0, n - 1, dp).first;
}