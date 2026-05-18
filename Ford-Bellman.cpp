#include <bits/stdc++.h>
using namespace std;

const int INF = 30000;

struct Edge {
    int u, v, w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    vector<int> dist(n + 1, INF);
    dist[1] = 0;

    for (int i = 1; i <= n - 1; i++) {
        bool changed = false;
        for (const auto& e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                changed = true;
            }
        }
        if (!changed) break;
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << (i == n ? "" : " ");
    }
    cout << "\n";

    return 0;
}