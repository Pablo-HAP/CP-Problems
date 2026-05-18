#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    long long w;
    int x;
    
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct DSU {
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }
    
    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }
    
    bool union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
            return true;
        }
        return false;
    }
};

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].x = __builtin_ctzll(edges[i].w);
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    long long S = 0;
    int edges_counted = 0;

    for (const auto& edge : edges) {
        if (dsu.union_sets(edge.u, edge.v)) {
            S += edge.x;
            edges_counted++;
            if (edges_counted == n - 1) break;
        }
    }

    cout << S + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}