#include <bits/stdc++.h>
using namespace std;

char board[8][8];
bool col_occupied[8];
bool diag1[15];
bool diag2[15];
int ways = 0;

void solve(int row) {
    if (row == 8) {
        ways++;
        return;
    }

    for (int col = 0; col < 8; col++) {
        if (board[row][col] == '.' && !col_occupied[col] &&
            !diag1[row - col + 7] && !diag2[row + col]) {

            col_occupied[col] = diag1[row - col + 7] = diag2[row + col] = true;

            solve(row + 1);

            col_occupied[col] = diag1[row - col + 7] = diag2[row + col] = false;
            }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }

    solve(0);
    cout << ways << endl;

    return 0;
}