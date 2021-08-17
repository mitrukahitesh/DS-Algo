#include <bits/stdc++.h>
using namespace std;

// Sorted or not?
// Sort and then traverse linearly, O(nlogn) + O(n) time and O(n) space

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> merged;
    if (intervals.size() == 0)
    {
        return intervals;
    }
    sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
         { return a[0] < b[0]; });
    vector<int> lastInt = intervals[0];
    for (int i = 1; i < intervals.size(); ++i)
    {
        if (intervals[i][0] <= lastInt[1])
        {
            lastInt[1] = lastInt[1] > intervals[i][1] ? lastInt[1] : intervals[i][1];
        }
        else
        {
            merged.push_back(lastInt);
            lastInt = intervals[i];
        }
    }
    merged.push_back(lastInt);
    return merged;
}