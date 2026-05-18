#include <bits/stdc++.h>
using namespace std;

struct State {
    long long d;
    int u;
    int used;
    bool operator>(const State& other) const {
        return d > other.d;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
    }

    const long long INF = 1e18;
    vector<vector<long long>> dist(n + 1, vector<long long>(2, INF));
    dist[1][0] = 0;

    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, 1, 0});

    while (!pq.empty()) {
        State curr = pq.top();
        pq.pop();

        long long d = curr.d;
        int u = curr.u;
        int used = curr.used;

        if (d > dist[u][used]) continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            long long w = edge.second;

            if (dist[u][used] + w < dist[v][used]) {
                dist[v][used] = dist[u][used] + w;
                pq.push({dist[v][used], v, used});
            }

            if (used == 0) {
                if (dist[u][0] + w / 2 < dist[v][1]) {
                    dist[v][1] = dist[u][0] + w / 2;
                    pq.push({dist[v][1], v, 1});
                }
            }
        }
    }

    cout << dist[n][1] << "\n";

    return 0;
}