#include <iomanip>
#include <iostream>

using namespace std;

#define D 8

bool isAvailable(int board[D][D], int row, int col) {
    if (board[row][col] == 0 && (row < D && row >= 0) && (col < D && col >= 0))
        return true;
    return false;
}

bool knightMove(int board[D][D], int movedNum, int curRow, int curCol) {
    if (movedNum == 64) {
        return true;
    }
    int r[] = {2,  1, -1, -2, -2,
               -1, 1, 2};  // Take a note that the order of the x_move and
                           // y_move arrays are going to affect the running time
                           // of the algorithm drastically. Think of a case,
    // when a person chooses 6 wrong long paths and finally reaching the goal in
    // the 7th path and another case when the person took the correct path in the
    // first turn.
    // This is also similar. The order given here is a tested one
    int c[] = {1, 2, 2, 1, -1, -2, -2, -1};
    /*if we know that our destination is in the east direction,
    then checking the paths leading in the east first is a wise
     technique apart from checking all the paths.*/
    for (int i = 0; i < D; ++i) {
        int nextRow = curRow + r[i];
        int nextCol = curCol + c[i];
        if (isAvailable(board, nextRow, nextCol)) {
            board[nextRow][nextCol] = movedNum + 1;
            bool test = knightMove(board, movedNum + 1, nextRow, nextCol);
            if (test) return true;
            board[nextRow][nextCol] = 0;  // backtracking
        }
    }
    return false;
}

int main() {
    int board[D][D] = {0};
    board[0][0] = 1;
    bool ans = knightMove(board, 1, 0, 0);
    if (ans) {
        for (int i = 0; i < D; i++) {
            for (int j = 0; j < D; j++) {
                cout << setw(3) << board[i][j] << " ";
            }
            cout << "\n";
        }
    } else
        cout << "Not possible!\n";
    return 0;
}