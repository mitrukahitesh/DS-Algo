#include <bits/stdc++.h>
using namespace std;

// O(n) + O(nlogn) + O(n) time
// O(n) space
// Choose the activity that has samllest ending time
int activitySelection(vector<int> start, vector<int> end, int n)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i)
    {
        v.push_back({end[i], start[i]});
    }
    sort(v.begin(), v.end());
    int res = 0;
    int last = -1;
    for (int i = 0; i < n; ++i)
    {
        if (v[i].second > last)
        {
            ++res;
            last = v[i].first;
        }
    }
    return res;
}