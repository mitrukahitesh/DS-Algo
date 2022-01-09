#include <bits/stdc++.h>
using namespace std;

/*
    Brute force
    Store all elements in a array, sort it and return mid element
    O(r*clog(r*c)) time
    O(r*c) space

    Optimal
    Use Binary Search
    O(32 * rlogc) time
    O(1) space
    since the numbers will be max of 32 bit,
    so binary search of numbers from min to max will be performed in at most 32 ( log2(2^32) = 32 ) operations.
 */

// https://www.geeksforgeeks.org/find-median-row-wise-sorted-matrix/

int median(vector<vector<int>> &matrix, int r, int c)
{
    int l = matrix[0][0], h = matrix[0][0];
    for (int i = 0; i < r; ++i)
    {
        l = min(l, matrix[i][0]);
        h = max(h, matrix[i][c - 1]);
    }
    int desired = (r * c + 1) / 2;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        int count = 0;
        for (int i = 0; i < r; ++i)
        {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        if (count < desired)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return l;
}