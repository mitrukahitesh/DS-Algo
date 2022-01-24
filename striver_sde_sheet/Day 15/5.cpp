#include <bits/stdc++.h>
using namespace std;

// Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/

string prefix(string &s1, string &s2)
{
    int i = 0;
    int n1 = s1.length(), n2 = s2.length();
    string res = "";
    while (i < n1 && i < n2 && s1[i] == s2[i])
        res.push_back(s1[i]), i++;
    return res;
}
string longestCommonPrefix(vector<string> &strs)
{
    string pre = strs[0];
    for (int i = 1; i < strs.size() && pre != ""; ++i)
    {
        pre = prefix(pre, strs[i]);
    }
    return pre;
}