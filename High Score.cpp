#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

struct Edge {
    int u, v;
    long long w;
};

vector<int> adj[2505], rev_adj[2505];
bool vis_from_1[2505], vis_to_n[2505];

void dfs1(int u) {
    vis_from_1[u] = true;
    for (int v : adj[u]) {
        if (!vis_from_1[v]) dfs1(v);
    }
}

void dfs2(int u) {
    vis_to_n[u] = true;
    for (int v : rev_adj[u]) {
        if (!vis_to_n[v]) dfs2(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    dfs1(1);
    dfs2(n);

    vector<long long> dist(n + 1, -INF);
    dist[1] = 0;

    for (int i = 1; i < n; i++) {
        for (auto &e : edges) {
            if (dist[e.u] != -INF) {
                dist[e.v] = max(dist[e.v], dist[e.u] + e.w);
            }
        }
    }

    bool infinite = false;
    for (auto &e : edges) {
        if (dist[e.u] != -INF && dist[e.u] + e.w > dist[e.v]) {
            if (vis_from_1[e.u] && vis_to_n[e.v]) {
                infinite = true;
                break;
            }
        }
    }

    if (infinite) {
        cout << -1 << "\n";
    } else {
        cout << dist[n] << "\n";
    }

    return 0;
}