#include <bits/stdc++.h>
using namespace std;

// My approach
// O(nlogn) time
// O(n) space
int findPlatform(int arr[], int dep[], int n)
{
    vector<pair<int, int>> trains;
    for (int i = 0; i < n; ++i)
    {
        trains.push_back({arr[i], dep[i]});
    }
    sort(trains.begin(), trains.end());
    priority_queue<int, vector<int>, greater<int>> pfs;
    for (int i = 0; i < n; ++i)
    {
        if (!pfs.empty() && pfs.top() < trains[i].first)
        {
            pfs.pop();
        }
        pfs.push(trains[i].second);
    }
    return pfs.size();
}

// Optimal
// O(nlogn) time
// O(1) space
// https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);
    int res = 0;
    int curr = 0;
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            ++curr;
            ++i;
        }
        else
        {
            --curr;
            ++j;
        }
        res = max(res, curr);
    }
    return res;
}