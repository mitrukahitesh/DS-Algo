#include <bits/stdc++.h>
using namespace std;

/*
    Brute force :
    O(n) time
    O(1) space

    Optimal :
    O(log2)
    O(1) space
*/

// Take care of range of power i.e. -2^31 to 2^31 - 1
// Taking abs(-2^31) causes int overflow, so we have converted to long long
double getPow(double ans, long long n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return getPow(ans * ans, n / 2);
    }
    return ans * getPow(ans, --n);
}
double myPow(double x, int N)
{
    double ans = getPow(x, abs((long long)N));
    return N > 0 ? ans : (double)1 / ans;
}