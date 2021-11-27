#include <bits/stdc++.h>
using namespace std;

/*
    Brute force :
    Generate all subarrays
    O(n^2) time
    O(1) space

    Optimal solution :
    y ^ x = xor => y = xor ^ x
    Similar approach as Day 4 4.cpp
    O(n) time
    O(n) space
*/

int maxXor(int arr[], int n, int k)
{
    int curr = 0;
    int count = 0;
    map<int, int> prev;
    for (int i = 0; i < n; ++i)
    {
        curr ^= arr[i];
        if (curr == k)
        {
            ++k;
        }
        if (prev.find(k ^ curr) != prev.end())
        {
            count += prev[k ^ curr];
        }
        prev[curr] += 1;
    }
    return count;
}