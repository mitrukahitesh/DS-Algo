#include <bits/stdc++.h>
using namespace std;

// O(nlogm) time
// O(1) space

// Actual problem
// https://www.geeksforgeeks.org/calculating-n-th-real-root-using-binary-search/

// https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1/#
int NthRoot(int n, int m)
{
    int l = 1, r = m;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        double expo = pow(mid, n);
        if (expo == m)
            return mid;
        else if (expo > m)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

// Actual problem solution
// O(m*log(n*10^d)) d->accuracy, time complexity
double multiply(double number, int n)
{
    double ans = 1.0;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * number;
    }
    return ans;
}

void getNthRoot(int n, int m)
{
    double low = 1;
    double high = m;
    double eps = 1e-6;

    while ((high - low) > eps)
    {
        double mid = (low + high) / 2.0;
        if (multiply(mid, n) < m)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    cout << low << " " << high << endl;

    // just to check
    cout << pow(m, (double)(1.0 / (double)n));
}
int main()
{
    int n, m;
    cin >> n >> m;
    getNthRoot(n, m);
    return 0;
}