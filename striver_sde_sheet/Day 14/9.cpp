#include <bits/stdc++.h>
using namespace std;

// Maximum of minimum for every window size
// https://www.geeksforgeeks.org/find-the-maximum-of-minimums-for-every-window-size-in-a-given-array/

vector<int> maxOfMin(int arr[], int n)
{
    vector<int> right(n, n);
    vector<int> left(n, -1);
    vector<int> res(n + 1, 0);
    stack<int> s;
    for (int i = 0; i < n; ++i)
    {
        while (!s.empty() && arr[s.top()] > arr[i])
        {
            right[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    for (int i = n - 1; i >= 0; --i)
    {
        while (!s.empty() && arr[s.top()] > arr[i])
        {
            left[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    for (int i = 0; i < n; ++i)
    {
        int len = right[i] - left[i] - 1;
        res[len] = max(res[len], arr[i]);
    }
    // res: MAX_ELEMENT _ _ _ _ x _ _ _ _ MIN_ELEMENT : min < x < max
    /*
    Below are few important observations to fill remaining entries 
    a) Result for length i, i.e. ans[i] would always be greater or same as result for length i+1, i.e., ans[i+1]. 
    b) If ans[i] is not filled it means there is no direct element which is minimum of length i and 
    therefore either the element of length ans[i+1], or ans[i+2], and so on is same as ans[i] 
    */
    for (int i = n - 1; i > 0; --i)
        res[i] = max(res[i], res[i + 1]);
    return vector<int>(res.begin() + 1, res.end());
}