#include <bits/stdc++.h>
using namespace std;

// Copy elements in one big array and sort and then divide
// Insertion sort kind of method O(n * m) time O(1) space
// Optimal is GAP method -> kindof shell sort method
// gap = ceil((n + m) / 2)
// gap = gap / 2
// O((n+m) log2(n+m)) time, log2(n+m) = number of gap operations, n+m = traversal in each gap operation

//Insertion sort kindof
void merge(long long arr1[], long long arr2[], int n, int m)
{
    int j = 0;
    for (int i = 0; i < n && j < m; ++i)
    {
        if (arr2[j] < arr1[i])
        {
            int temp = arr1[i];
            arr1[i] = arr2[j];
            arr2[j] = temp;
            int k = j + 1;
            while (k < m && arr2[k] < arr2[k - 1])
            {
                int temp = arr2[k];
                arr2[k] = arr2[k - 1];
                arr2[k - 1] = temp;
                ++k;
            }
        }
    }
}

//GAP Method
void merge(long long arr1[], long long arr2[], int n, int m)
{
    int i, j, gap = n + m;
    for (gap = getGap(gap); gap > 0; gap = getGap(gap))
    {
        //comparing elements in first array
        for (i = 0; i + gap < n; ++i)
        {
            if (arr1[i] > arr1[i + gap])
            {
                swap(arr1[i], arr1[i + gap]);
            }
        }
        //comparing elements in both arrays
        for (j = gap >= n ? gap - n : 0; i < n && j < m; ++j, ++i)
        {
            if (arr1[i] > arr2[j])
            {
                swap(arr1[i], arr2[j]);
            }
        }
        //comparing elements in second array
        if (j < m)
        {
            for (j = 0; j + gap < m; ++j)
            {
                if (arr2[j] > arr2[j + gap])
                {
                    swap(arr2[j], arr2[j + gap]);
                }
            }
        }
    }
}
int getGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}