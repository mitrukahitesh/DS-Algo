#include <bits/stdc++.h>
using namespace std;

// String to Integer (atoi)
// https://leetcode.com/problems/string-to-integer-atoi/

int myAtoi(string s)
{
    int res = 0;
    int sign = 1;
    int i = 0;
    while (i < s.length() && s[i] == ' ')
        ++i;
    if (i == s.length())
        return res;
    if (s[i] == '+' || s[i] == '-')
    {
        if (s[i] == '-')
            sign = -1;
        i++;
    }
    while (i < s.length() && (s[i] - '0' >= 0 && '9' - s[i] >= 0))
    {
        long long x = (long long)res * 10l + (long long)sign * (long long)(s[i] - '0');
        if (x >= INT_MAX)
            return INT_MAX;
        else if (x <= INT_MIN)
            return INT_MIN;
        res = x;
        i++;
    }
    return res;
}