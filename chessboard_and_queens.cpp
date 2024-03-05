#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int ans = 0;

bool isSafe(int (&pos)[8], int row, int col) {
    for (int i = 0; i < 8; i++) {
        if (pos[i] == col || abs(pos[i] - col) == row - i) {
            return false;
        }
    }
    return true;
}

void solve(string (&board)[8], int (&pos)[8], int row) {
    if (row == 8) {
        ans++;
        return;
    }

    for (int i = 0; i < 8; i++) {
        if (board[row][i] == '*' || !isSafe(pos, row, i)) continue;

        pos[row] = i;
        solve(board, pos, row + 1);
        pos[row] = -1;
    }
}

int main(void) {
    string board[8];
    for (int i = 0; i < 8; i++) {
        getline(cin, board[i]);
    }

    int pos[8];
    fill(pos, pos+8, -1);
    solve(board, pos, 0);
    cout << ans << endl;
}