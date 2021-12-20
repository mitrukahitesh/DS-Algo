#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

bool compare(Job &j1, Job &j2)
{
    if (j1.profit > j2.profit)
        return true;
    else if (j1.profit == j2.profit)
        return j1.dead > j2.dead;
    return false;
}

// O(nlogn) + O(n * m) time, m for checking free slot
// O(1) space
vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, compare);
    vector<int> res(2, 0);
    int slot[101] = {0};
    for (int i = 0; i < n; ++i)
    {
        int j = arr[i].dead;
        while (j > 0 && slot[j] != 0)
        {
            --j;
        }
        if (j > 0)
        {
            slot[j] = arr[i].profit;
            ++res[0];
            res[1] += arr[i].profit;
        }
    }
    return res;
}