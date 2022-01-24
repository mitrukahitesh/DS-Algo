#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/implement-strstr/submissions/
// KMP
int strStrKmp(string haystack, string needle)
{
    if (needle == "")
        return 0;
    vector<int> lps(needle.length(), 0);
    int i = 1, j = 0;
    while (i < needle.length())
    {
        if (needle[i] == needle[j])
        {
            lps[i] = ++j;
            i++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    j = 0;
    for (i = 0; i < haystack.length(); ++i)
    {
        while (j < needle.length() && i < haystack.length() && haystack[i] == needle[j])
        {
            ++i, ++j;
        }
        if (j == needle.length())
        {
            return i - needle.length();
        }
        if (j != 0)
            j = lps[j - 1], i--;
    }
    return -1;
}
