#include <bits/stdc++.h>
using namespace std;

// Celebrity problem
// https://www.geeksforgeeks.org/the-celebrity-problem/

// Most optimal
int celebrity(vector<vector<int>> &arr, int n)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        if (arr[l][r] == 1)
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    int celeb = l;
    for (int i = 0; i < n; ++i)
    {
        if (i != celeb)
        {
            if (arr[i][celeb] == 0 || arr[celeb][i] == 1)
                return -1;
        }
    }
    return celeb;
}