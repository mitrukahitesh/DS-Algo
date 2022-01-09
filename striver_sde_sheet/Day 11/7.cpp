#include <bits/stdc++.h>
using namespace std;

// Allocate minimum number of pages

/**
 * O(nlogn) time
 * O(1) space
 */

bool feasible(int *arr, int n, int k, int m)
{
    int sum = 0;
    int x = 1;
    for (int i = 0; i < n; ++i)
    {
        // Important
        if (arr[i] > m)
            return false;
        if (sum + arr[i] <= m)
        {
            sum += arr[i];
        }
        else
        {
            sum = arr[i];
            x++;
            if (x > k)
                return false;
        }
    }
    return true;
}
int findPages(int arr[], int n, int k)
{
    if (n < k)
        return -1;
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += arr[i];
    int l = arr[n - 1], r = sum;
    int res = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (feasible(arr, n, k, mid))
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return res;
}