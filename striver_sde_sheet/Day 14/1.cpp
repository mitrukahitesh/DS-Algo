#include <bits/stdc++.h>
using namespace std;

// Next smaller element
// https://www.geeksforgeeks.org/next-smaller-element/

vector<int> help_classmate(vector<int> arr, int n)
{
    vector<int> res(n);
    stack<int> s;
    for (int i = 0; i < n; ++i)
    {
        while (!s.empty() && arr[s.top()] > arr[i])
        {
            res[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty())
    {
        res[s.top()] = -1;
        s.pop();
    }
    return res;
}