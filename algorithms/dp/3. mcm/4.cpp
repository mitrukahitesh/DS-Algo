#include <bits/stdc++.h>
using namespace std;

// Scrambled String

unordered_map<string, bool> dp;
bool solve(string s, string target)
{
    if (s == target)
        return true;
    if (dp.find(s + target) != dp.end())
        return dp[s + target];
    int n = s.length();
    for (int k = 0; k < n - 1; ++k)
    {
        //without swap
        if (isScramble(s.substr(0, k + 1), target.substr(0, k + 1)) &&
            isScramble(s.substr(k + 1, n), target.substr(k + 1, n)))
            return dp[s + target] = true;
        //with swap
        if (isScramble(s.substr(0, k + 1), target.substr(n - k - 1, n)) &&
            isScramble(s.substr(k + 1, n), target.substr(0, n - k - 1)))
            return dp[s + target] = true;
    }
    return dp[s + target] = false;
}
bool isScramble(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    if (s1.length() == 0 && s2.length() == 0)
        return true;
    return solve(s1, s2);
}