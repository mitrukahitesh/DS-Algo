#include <bits/stdc++.h>
using namespace std;

// Roman Number to Integer and vice versa
// https://leetcode.com/problems/roman-to-integer/

int romanToInt(string s)
{
    int sum = 0;
    map<char, int> m;
    m.insert({'I', 1});
    m.insert({'V', 5});
    m.insert({'X', 10});
    m.insert({'L', 50});
    m.insert({'C', 100});
    m.insert({'D', 500});
    m.insert({'M', 1000});
    for (int i = 1; i < s.length(); ++i)
    {
        if (m[s[i]] <= m[s[i - 1]])
            sum += m[s[i - 1]];
        else
            sum -= m[s[i - 1]];
    }
    sum += m[s[s.length() - 1]];
    return sum;
}