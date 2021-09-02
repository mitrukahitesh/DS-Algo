#include <bits/stdc++.h>
using namespace std;

/*
    Brute force :
    Generate all substrings
    O(n^2) time
    O(n) space for hashset

    Better solution :
    O(n) time (O(2n) at max)
    O(n) space

    Optimal solution :
    O(n) time exactly
    O(n) space
*/

// Better than brute for but still O(n^2)
int lengthOfLongestSubstring(string s)
{
    map<char, int> index;
    int l = s.length();
    int count = 0;
    int max = 0;
    int start = 0;
    for (int i = 0; i < l; ++i)
    {
        char c = s[i];
        if (index.find(c) == index.end())
        {
            ++count;
            max = max > count ? max : count;
            index[c] = i;
        }
        else
        {
            i = index[c];
            index.clear();
            count = 0;
        }
    }
    return max;
}

// Better solution
int lengthOfLongestSubstring(string s)
{
    unordered_set<char> sett;
    int n = s.length();
    int l = 0;
    int r = 0;
    int max = 0;
    while (r < n)
    {
        char c = s[r];
        if (sett.find(c) == sett.end())
        {
            max = max > (r - l + 1) ? max : (r - l + 1);
        }
        else
        {
            while (sett.find(c) != sett.end())
            {
                sett.erase(s[l]);
                ++l;
            }
            max = max > (r - l + 1) ? max : (r - l + 1);
        }
        sett.insert(c);
        ++r;
    }
    return max;
}

// Optimal solution
int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> m;
    int n = s.length();
    int l = 0;
    int r = 0;
    int max = 0;
    while (r < n)
    {
        char c = s[r];
        if (m.find(c) != m.end())
        {
            if (m[c] >= l)
            {
                l = m[c] + 1;
            }
        }
        max = max > (r - l + 1) ? max : (r - l + 1);
        m[c] = r;
        ++r;
    }
    return max;
}