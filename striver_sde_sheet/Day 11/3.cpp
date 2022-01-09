#include <bits/stdc++.h>
using namespace std;

/**
 * Brute force: Linear search OR Using XOR on all elements
 * O(n) time
 * O(1) space
 * 
 * Optimal:
 * Binary Search
 * O(logn) time
 * O(1) space
 */

// https://www.geeksforgeeks.org/find-the-element-that-appears-once-in-a-sorted-array/

int search(int arr[], int n)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int x = arr[mid];
        if (mid % 2 == 0)
        {
            if (arr[mid + 1] == x)
                l = mid + 1;
            else
                r = mid - 1;
        }
        else if (mid % 2 == 1)
        {
            if (arr[mid - 1] == x)
                l = mid + 1;
            else
                r = mid - 1;
        }
        else
        {
            l = mid;
            break;
        }
    }
    return arr[l];
}