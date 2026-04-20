#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    const int INF = 1e9;

    vector<vector<int>> monsterDist(n, vector<int>(m, INF));
    vector<vector<int>> dist(n, vector<int>(m, INF));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1, -1}));
    vector<vector<char>> parentMove(n, vector<char>(m));

    queue<pair<int,int>> q;

    pair<int,int> start;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                q.push({i, j});
                monsterDist[i][j] = 0;
            } else if (grid[i][j] == 'A') {
                start = {i, j};
            }
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    char mv[4] = {'D', 'U', 'L', 'R'};

    // BFS from all monsters
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (grid[nx][ny] == '#') continue;
            if (monsterDist[nx][ny] != INF) continue;

            monsterDist[nx][ny] = monsterDist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    auto isBoundary = [&](int x, int y) {
        return x == 0 || x == n - 1 || y == 0 || y == m - 1;
    };

    // If A already starts on boundary, escape immediately
    if (isBoundary(start.first, start.second)) {
        cout << "YES\n0\n\n";
        return 0;
    }

    // BFS from A
    queue<pair<int,int>> pq;
    pq.push(start);
    dist[start.first][start.second] = 0;

    pair<int,int> finish = {-1, -1};

    while (!pq.empty()) {
        auto [x, y] = pq.front();
        pq.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (grid[nx][ny] == '#') continue;
            if (dist[nx][ny] != INF) continue;

            int nd = dist[x][y] + 1;

            // Must arrive strictly before any monster
            if (nd >= monsterDist[nx][ny]) continue;

            dist[nx][ny] = nd;
            parent[nx][ny] = {x, y};
            parentMove[nx][ny] = mv[k];
            pq.push({nx, ny});

            if (isBoundary(nx, ny)) {
                finish = {nx, ny};
                break;
            }
        }
        if (finish.first != -1) break;
    }

    if (finish.first == -1) {
        cout << "NO\n";
        return 0;
    }

    string path;
    pair<int,int> cur = finish;
    while (cur != start) {
        path.push_back(parentMove[cur.first][cur.second]);
        cur = parent[cur.first][cur.second];
    }
    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << '\n';
    cout << path << '\n';

    return 0;
}