#include <bits/stdc++.h>
using namespace std;

// Element at row R and column C is R-1 C C-1 (combination formula) => O(n)
// i.e. at (5, 2) = 4C2
// Shortcut for nCr = n.n-1....n-r+1/r.r-1....1 i.e. same number of terms in numr and denmr

// O(n2) time
// O(n2) space
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> r(numRows);
    for (int i = 0; i < numRows; i++)
    {
        r[i].resize(i + 1);
        r[i][0] = r[i][i] = 1;

        for (int j = 1; j < i; j++)
            r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
    }
    return r;
}

// Get nth row (o indexed)
// O(n) time
// O(n) space
vector<int> getRow(int rowIndex)
{
    vector<int> row(rowIndex + 1);
    row[0] = row[rowIndex] = 1;
    for (int i = 1; i <= rowIndex / 2; ++i)
    {
        row[i] = row[rowIndex - i] = (unsigned long)row[i - 1] * (unsigned long)(rowIndex - i + 1) / i;
    }
    return row;
}