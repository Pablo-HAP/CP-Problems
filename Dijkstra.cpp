#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
vector<pair<int, int>> adj[100005];
long long dist[100005];
int p[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                p[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[n] == INF) {
        cout << -1 << "\n";
    } else {
        vector<int> path;
        for (int v = n; v != 0; v = p[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}