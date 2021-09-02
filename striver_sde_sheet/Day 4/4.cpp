#include <bits/stdc++.h>
using namespace std;

/*
    Brute force :
    Check of all subarrays
    O(n^2) time
    O(1) space

    Optimize solution :
    a[0], a[1], a[2], ........., a[n - 1]
    if sum all emelents is S, sum of a[0] to a[2] is S, then sum of a[3] to a[n-1] = 0
    O(n) time
    O(n) space
*/

int maxLen(int arr[], int n)
{
    int max = 0;
    int sum = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (sum == 0)
        {
            max = i + 1;
        }
        if (m.find(sum) == m.end())
        {
            m.insert(pair<int, int>(sum, i));
        }
        else
        {
            if (i - m[sum] > max)
            {
                max = i - m[sum];
            }
        }
    }
    return max;
}
