#include <bits/stdc++.h>
using namespace std;

/**
 * Brute force -> Linear search
 * 
 * Optimal:
 * Find pivot
 * Divide array into two parts
 * Perform binary search
 */

int search(int arr[], int l, int h, int key)
{
    int n = h - l + 1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (arr[mid] > arr[n - 1])
            l = mid + 1;
        else
            h = mid - 1;
    }
    int pivot = l;
    if (key > arr[n - 1])
        l = 0, h = pivot - 1;
    else
        l = pivot, h = n - 1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return -1;
}