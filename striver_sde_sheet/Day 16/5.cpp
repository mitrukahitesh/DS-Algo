#include <bits/stdc++.h>
using namespace std;

// Count and say
// https://leetcode.com/problems/count-and-say/

string countAndSay(int n)
{
    vector<int> arr(10, 0);
    arr[1] = 1;
    string res = "1";
    for (int i = 2; i <= n; ++i)
    {
        string temp = "";
        int cnt = 1, j = 1;
        while (j < res.length())
        {
            if (res[j] != res[j - 1])
            {
                temp = temp + to_string(cnt) + res[j - 1];
                cnt = 1;
            }
            else
            {
                cnt++;
            }
            ++j;
        }
        temp = temp + to_string(cnt) + res[j - 1];
        res = temp;
    }
    return res;
}