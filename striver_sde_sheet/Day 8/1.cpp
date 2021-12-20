#include <bits/stdc++.h>
using namespace std;

// O(n) + O(nlogn) + O(n) time
// O(n) space
// Choose the meetings that has samllest ending time
int maxMeetings(int start[], int end[], int n)
{
    vector<tuple<int, int, int>> m;
    for (int i = 0; i < n; ++i)
    {
        m.push_back(make_tuple(end[i], start[i], i));
    }
    sort(m.begin(), m.end());
    int res = 0;
    int last = -1;
    for (int i = 0; i < n; ++i)
    {
        if (get<1>(m[i]) > last)
        {
            ++res;
            last = get<0>(m[i]);
        }
    }
    return res;
}