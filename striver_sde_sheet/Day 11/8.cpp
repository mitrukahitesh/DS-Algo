#include <bits/stdc++.h>
using namespace std;

// Aggressive cows

// https://www.spoj.com/problems/AGGRCOW/

#define int long long
#define endl "\n"

bool feasible(int *arr, int n, int c, int D)
{
    int x = 1;
    int last = 0;
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] - arr[last] >= D)
        {
            ++x;
            last = i;
        }
        if (x == c)
            return true;
    }
    return false;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t = 1;
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        int *arr = new int[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        sort(arr, arr + n);
        int l = arr[1] - arr[0];
        int r = arr[n - 1];
        int res = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (feasible(arr, n, c, mid))
            {
                res = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << res << endl;
    }
    return 0;
}