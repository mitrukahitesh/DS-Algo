#include <bits/stdc++.h>
using namespace std;

/*
    Brute force:
        For all bar i, find highest bar from [0, i] and [i, n - 1]
        Water in bar i = min(leftMax, rightMax) - i
    O(n^2) time
    O(1) space

    Better:
        Make 2 arrays,
        leftMax = store left max bar for all bars
        rightMax = store right max bar for all bars
        Iterate and find sum of storage, storage of i = min(leftMax[i], rightMax[i]) - height[i]
    O(3n) time
    O(2n) space

    Optimal:
        Two pointer
        O(n) time
        O(1) space
    
    Stack can also be used
*/

// Better
int trap(vector<int> &height)
{
    int n = height.size();
    long long sum = 0;
    int *left = new int[n];
    int *right = new int[n];
    left[0] = height[0];
    right[n - 1] = height[n - 1];
    for (int i = 1; i < n; ++i)
    {
        left[i] = max(left[i - 1], height[i]);
    }
    for (int i = n - 2; i >= 0; --i)
    {
        right[i] = max(right[i + 1], height[i]);
    }
    for (int i = 0; i < n; i++)
    {
        sum += left[i] < right[i] ? left[i] - height[i] : right[i] - height[i];
    }
    return sum;
}

// Optimal
int trap(vector<int> &height)
{
    int n = height.size();
    long long sum = 0;
    int left = 0;
    int right = n - 1;
    int lmax = 0;
    int rmax = 0;
    while (left < right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] >= lmax)
                lmax = height[left];
            else
                sum += lmax - height[left]; // reaching this point ensures that there is a bar <= lmax on the right
            ++left;
        }
        else
        {
            if (height[right] >= rmax)
                rmax = height[right];
            else
                sum += rmax - height[right]; // reaching this point ensures that there is a bar <= lmax on the left
            --right;
        }
    }
    return sum;
}