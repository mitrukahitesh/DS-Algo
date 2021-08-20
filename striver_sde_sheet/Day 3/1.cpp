#include <bits/stdc++.h>
using namespace std;

/*
    Brute force :
    O(n2) time
    O(1) time

    Another approach : 
    Binary search on each row
    O(nlogn) time
    O(1) space

    Better :
    Find the row first
    Then use binary search for that row
    O(n + logm) time
    O(1) space

    Optimal :
    Binary search on 2D matrix
    row number of Nth element = N / (num of columns)
    col  ''    '' ''     ''   = N % (num of columns)
    O(log(n * m)) time
    O(1) space
*/

// Leetcode variant
// Better Approach
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int i;
    for (i = 0; i < row; ++i)
    {
        if (matrix[i][col - 1] >= target)
        {
            return binarySearch(matrix[i], target, 0, col - 1);
        }
    }
    return false;
}
bool binarySearch(vector<int> &arr, int target, int low, int high)
{
    if (low > high)
        return false;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
    {
        return true;
    }
    else if (arr[mid] > target)
    {
        return binarySearch(arr, target, low, mid - 1);
    }
    else
    {
        return binarySearch(arr, target, mid + 1, high);
    }
    return false;
}

// Binary search on 2D matrix
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();
    return binarySearch(matrix, target, 0, row * col - 1);
}
bool binarySearch(vector<vector<int>> &arr, int target, int low, int high)
{
    if (low > high)
        return false;
    int mid = low + (high - low) / 2;
    int row = mid / arr[0].size();
    int col = mid % arr[0].size();
    if (arr[row][col] == target)
    {
        return true;
    }
    else if (arr[row][col] > target)
    {
        return binarySearch(arr, target, low, mid - 1);
    }
    else
    {
        return binarySearch(arr, target, mid + 1, high);
    }
    return false;
}

// Gfg variant
// O(n + m) time
// O(1) space
int matSearch(vector<vector<int>> &mat, int N, int M, int X)
{
    int i = 0, j = M - 1;
    while (i < N && j >= 0)
    {
        if (mat[i][j] == X)
        {
            return 1;
        }
        else if (mat[i][j] > X)
        {
            --j;
        }
        else
        {
            ++i;
        }
    }
    return 0;
}