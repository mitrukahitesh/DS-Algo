#include <bits/stdc++.h>
using namespace std;

// Minimum characters to insert in front for palindrome
// https://www.codingninjas.com/codestudio/problems/893000?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

// Using KMP
int minCharsforPalindrome(string str)
{
    string s = str;
    reverse(str.begin(), str.end());
    s = s + "$" + str;
    vector<int> lps(s.length(), 0);
    int i = 1, j = 0;
    while (i < s.length())
    {
        if (s[i] == s[j])
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
    return str.length() - lps[s.length() - 1];
}