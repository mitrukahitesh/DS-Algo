#include <bits/stdc++.h>
using namespace std;

/*
    Brute force is O(n2)

    Optimal:
    O(n) time (one pass)
    O(1) space
*/

int maxProfit(vector<int> &prices)
{
    int max, min, tempMin;
    max = min = tempMin = prices[0];
    for (auto it : prices)
    {
        if (tempMin > it)
        {
            tempMin = it;
        }
        else if (it > tempMin && max - min < it - tempMin)
        {
            min = tempMin;
            max = it;
        }
    }
    return max - min;
}

// Edotorial - JAVA
// public int maxProfit(int prices[])
// {
//     int minprice = Integer.MAX_VALUE;
//     int maxprofit = 0;
//     for (int i = 0; i < prices.length; i++)
//     {
//         if (prices[i] < minprice)
//             minprice = prices[i];
//         else if (prices[i] - minprice > maxprofit)
//             maxprofit = prices[i] - minprice;
//     }
//     return maxprofit;
// }