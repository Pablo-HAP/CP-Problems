#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    pair<int,int> start, finish;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') finish = {i, j};
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1, -1}));
    vector<vector<char>> move_taken(n, vector<char>(m));

    queue<pair<int,int>> q;
    q.push(start);
    vis[start.first][start.second] = true;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    char moves[4] = {'U', 'D', 'L', 'R'};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                !vis[nx][ny] && grid[nx][ny] != '#') {

                vis[nx][ny] = true;
                parent[nx][ny] = {x, y};
                move_taken[nx][ny] = moves[k];
                q.push({nx, ny});
                }
        }
    }

    if (!vis[finish.first][finish.second]) {
        cout << "NO\n";
        return 0;
    }

    string path;
    pair<int,int> cur = finish;

    while (cur != start) {
        path.push_back(move_taken[cur.first][cur.second]);
        cur = parent[cur.first][cur.second];
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path << "\n";

    return 0;
}