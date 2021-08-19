#include <bits/stdc++.h>
using namespace std;

/*
 Brute force:
 for each element check number of smaller elements
 O(n2) time and O(1) space

 Optimal:
 Using merge sort technique
 Here, if arr[i] > arr[j], then number of inversions in that particular subarray is (mid - i + 1)
 where  i is [low, mid], j is [mid + 1, high].
 O(nlogn) time and  O(n) space
*/

long long getMergeCount(long long *arr, int low, int high)
{
    if (low >= high)
        return 0;
    long long mid = low + (high - low) / 2;
    long long leftSubArrayCount = getMergeCount(arr, low, mid);
    long long rightSubArrayCount = getMergeCount(arr, mid + 1, high);
    long long *temp = new long long[high - low + 1];
    long long k = 0;
    long long i = low;
    long long j = mid + 1;
    long long mergeCount = 0;
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            ++i;
        }
        else
        {
            temp[k] = arr[j];
            ++j;
            mergeCount += (mid - i + 1);
        }
        ++k;
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        ++i;
        ++k;
    }
    while (j <= high)
    {
        temp[k] = arr[j];
        ++j;
        ++k;
    }
    for (int k = 0; k < (high - low + 1); ++k)
    {
        arr[low + k] = temp[k];
    }
    return leftSubArrayCount + rightSubArrayCount + mergeCount;
}

long long int inversionCount(long long arr[], long long N)
{
    return getMergeCount(arr, 0, N - 1);
}