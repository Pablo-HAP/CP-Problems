#include <bits/stdc++.h>
using namespace std;

int board[10][10];
bool visited[10][10];
int max_visited;
int total_squares;

int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

void solve(int r, int c, int count) {
    max_visited = max(max_visited, count);

    for (int i = 0; i < 8; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < 10 && nc >= 0 && nc < 10 && board[nr][nc] && !visited[nr][nc]) {
            visited[nr][nc] = true;
            solve(nr, nc, count + 1);
            visited[nr][nc] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, case_num = 1;
    while (cin >> n && n != 0) {
        memset(board, 0, sizeof(board));
        memset(visited, false, sizeof(visited));
        total_squares = 0;
        max_visited = 0;

        for (int i = 0; i < n; i++) {
            int skip, len;
            cin >> skip >> len;
            for (int j = skip; j < skip + len; j++) {
                board[i][j] = 1;
                total_squares++;
            }
        }

        visited[0][0] = true;
        solve(0, 0, 1);

        int unreachable = total_squares - max_visited;
        cout << "Case " << case_num++ << ", " << unreachable << " ";
        if (unreachable == 1) cout << "square can not be reached.\n";
        else cout << "squares can not be reached.\n";
    }
    return 0;
}