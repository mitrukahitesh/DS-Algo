#include <bits/stdc++.h>
using namespace std;

// Largest Rectangle in Histogram
// https://leetcode.com/problems/largest-rectangle-in-histogram/

// 2 pass solution
int largestRectangleArea(vector<int> &arr)
{
    int n = arr.size();
    stack<int> s;
    vector<int> rightSmall(n, n);
    vector<int> leftSmall(n, -1);
    for (int i = 0; i < n; ++i)
    {
        while (!s.empty() && arr[s.top()] > arr[i])
        {
            rightSmall[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    stack<int> temp;
    s = temp;
    for (int i = n - 1; i >= 0; --i)
    {
        while (!s.empty() && arr[s.top()] > arr[i])
        {
            leftSmall[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    int res = 0;
    for (int i = 0; i < n; ++i)
        res = max((rightSmall[i] - leftSmall[i] - 1) * arr[i], res);
    return res;
}

// 1 pass
// Storing numbers in increasing sequence
int largestRectangleArea(vector<int> &arr)
{
    int n = arr.size();
    stack<int> s;
    int res = 0;
    for (int i = 0; i <= n; ++i)
    {
        while (!s.empty() && (i == n || arr[s.top()] > arr[i]))
        {
            int height = arr[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            res = max(res, height * width);
        }
        s.push(i);
    }
    return res;
}