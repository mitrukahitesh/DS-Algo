#include <bits/stdc++.h>
using namespace std;

// (arr[0]^arr[1]^....^arr[n-1]) ^ (1^2^.....^n) = X ^ Y (repeating ^ missing)
// XOR Property a^a = 0
// XOR is commutative, associative, identity element, self-inverse
// Divide numbers in two sets depending on right most set bit of x ^ y, this will bring x and y in different sets
// Divide 1...n in to same set and perform XOR
// O(5n) time
// O(1) space

int *findTwoElement(int *arr, int n)
{
    int *ans = new int[2];
    int xor1 = 0;
    for (int i = 1; i <= n; ++i)
    {
        xor1 ^= i;
    }
    for (int i = 0; i < n; ++i)
    {
        xor1 ^= arr[i];
    }
    int bucketSet = 0;
    int bucketUnset = 0;
    int rightmostSet = xor1 & (-xor1);
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] & rightmostSet)
        {
            bucketSet ^= arr[i];
        }
        else
        {
            bucketUnset ^= arr[i];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (i & rightmostSet)
        {
            bucketSet ^= i;
        }
        else
        {
            bucketUnset ^= i;
        }
    }
    ans[0] = bucketUnset;
    ans[1] = bucketSet;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == bucketSet)
        {
            ans[0] = bucketSet;
            ans[1] = bucketUnset;
            break;
        }
    }
    return ans;
}