#include <bits/stdc++.h>
using namespace std;

bool solve(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[i].size(); ++j)
        {
            if (board[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; ++c)
                {
                    if (isValid(board, i, j, c))
                    {
                        board[i][j] = c;
                        if (solve(board))
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool isValid(vector<vector<char>> &board, int r, int c, char ch)
{
    for (int i = 0; i < board.size(); ++i)
    {
        if (board[r][i] == ch)
            return false;
        if (board[i][c] == ch)
            return false;
        if (board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == ch)
            return false;
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    solve(board);
}