#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/implement-strstr/submissions/s
// Z Algorithm
int strStr(string haystack, string needle)
{
    if (needle == "")
        return 0;
    string s = needle + "$" + haystack;
    vector<int> z(s.length(), 0);
    int n = s.length();
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i > r)
        {
            r = l = i;
            while (r < n && s[r] == s[r - l])
                r++;
            z[i] = r - l;
            r--;
        }
        else
        {
            int k = i - l;
            if (z[k] <= r - i)
            {
                z[i] = z[k];
            }
            else
            {
                l = i;
                while (r < n && s[r] == s[r - l])
                    ++r;
                z[i] = r - l;
                r--;
            }
        }
    }
    for (int i = needle.length() + 1; i < s.length(); ++i)
    {
        if (z[i] == needle.length())
            return i - needle.length() - 1;
    }
    return -1;
}
