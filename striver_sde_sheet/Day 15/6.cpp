#include <bits/stdc++.h>
using namespace std;

// Rabin Karp Algorithm
// https://leetcode.com/problems/repeated-string-match/

int mod = 101;
int base = 256;
int h = 1;
bool rabinKarp(string s, string p)
{
    int pHash = 0;
    int sHash = 0;
    for (auto it : p)
        pHash = (pHash * base + it) % mod;
    for (int i = 0; i < p.length(); ++i)
        sHash = (sHash * base + s[i]) % mod;
    for (int i = p.length(); i <= s.length(); ++i)
    {
        if (pHash == sHash)
        {
            if (p == s.substr(i - p.length(), p.length()))
                return true;
        }
        if (i < s.length())
        {
            sHash = ((((sHash - h * s[i - p.length()]) * base) % mod) + s[i]) % mod;
        }
    }
    return false;
}
int repeatedStringMatch(string a, string b)
{
    string x = "";
    int cnt = 0;
    for (int i = 1; i < b.length(); ++i)
        h = (h * base) % mod;
    while (x.length() < b.length())
        x = x + a, cnt++;
    if (rabinKarp(x, b))
        return cnt;
    x = x + a;
    cnt++;
    if (rabinKarp(x, b))
        return cnt;
    return -1;
}