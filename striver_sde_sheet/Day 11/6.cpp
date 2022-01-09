#include <bits/stdc++.h>
using namespace std;

/**
 * Brute force: Merge sorted array
 * O(m + n) time
 * O(m + n) space, O(1) optimized space
 * 
 * Optimal: Binary Search
 * O(min(logn, logm)) time
 * O(1) space
 */

int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    if (n > m)
        return kthElement(arr2, arr1, m, n, k);
    int l = max(0, k - m), r = min(k, n); //Impt
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int cut = k - mid;
        int l1 = mid <= 0 ? INT_MIN : arr1[mid - 1];
        int l2 = cut <= 0 ? INT_MIN : arr2[cut - 1];
        int r1 = mid >= n ? INT_MAX : arr1[mid];
        int r2 = cut >= m ? INT_MAX : arr2[cut];
        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        if (l1 > r2)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return 0;
}