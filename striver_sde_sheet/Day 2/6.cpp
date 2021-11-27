#include <bits/stdc++.h>
using namespace std;

/*
    Brute force :
    Use 2nd matrix and put ith row of given matrix to (n-i)th column of second matrix
    O(n2) time
    O(n2) space
    Optimal :
    Take transpose and reverse every row
    O(n2) + O(n2) time
    O(1) space
*/

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        int j = 0, k = n - 1;
        while (j < k)
        {
            swap(matrix[i][j], matrix[i][k]);
            ++j;
            --k;
        }
    }
}
