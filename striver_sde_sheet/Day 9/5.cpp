#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}

void find_part(vector<vector<string>> &res, string &s, vector<string> &part, int k)
{
    if (k == s.length())
    {
        res.push_back(part);
    }
    string p = "";
    for (int i = k; i < s.length(); ++i)
    {
        p += s[i];
        if (isPalindrome(s, k, i))
        {
            part.push_back(p);
            find_part(res, s, part, i + 1);
            part.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    vector<string> part;
    find_part(res, s, part, 0);
    return res;
}