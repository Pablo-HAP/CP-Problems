#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> parent, vis;
int cycle_start = -1, cycle_end = -1;

bool dfs(int u, int p) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;

        if (!vis[v]) {
            parent[v] = u;
            if (dfs(v, u)) return true;
        } else {
            cycle_start = v;
            cycle_end = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.assign(n + 1, {});
    parent.assign(n + 1, -1);
    vis.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1)) break;
        }
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> cycle;
    cycle.push_back(cycle_start);

    for (int v = cycle_end; v != cycle_start; v = parent[v]) {
        cycle.push_back(v);
    }
    cycle.push_back(cycle_start);

    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << '\n';
    for (int x : cycle) cout << x << ' ';
    cout << '\n';

    return 0;
}