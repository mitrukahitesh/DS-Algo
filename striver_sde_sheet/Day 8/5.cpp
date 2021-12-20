#include <bits/stdc++.h>
using namespace std;

// Coins [1,2,5,10,20,50,100,500,1000]
// O(n) time
// O(1) space
int minCoins(int coins[], int M, int V)
{
    sort(coins, coins + M);
    int res = 0;
    for (int i = M - 1; i >= 0 && V; --i)
    {
        if (coins[i] <= V)
        {
            res += V / coins[i];
            V %= coins[i];
        }
    }
    return V != 0 ? -1 : res;
}