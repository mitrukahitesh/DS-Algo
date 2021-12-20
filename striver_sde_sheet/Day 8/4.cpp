#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

bool compare(Item i1, Item i2)
{
    return (double)i1.value / (double)i1.weight > (double)i2.value / (double)i2.weight;
}

// O(nlogn) time
// O(1) sapce
double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, compare);
    double val = 0;
    int i = 0;
    while (W > 0 && i < n)
    {
        if (arr[i].weight <= W)
        {
            val += arr[i].value;
            W -= arr[i].weight;
        }
        else
        {
            double ratio = (double)arr[i].value / (double)arr[i].weight;
            val += W * ratio;
            W = 0;
        }
        ++i;
    }
    return val;
}