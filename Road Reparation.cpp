#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    long long w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int parent_node[100005];
int sz[100005];

int find_set(int v) {
    if (v == parent_node[v])
        return v;
    return parent_node[v] = find_set(parent_node[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        parent_node[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    for (int i = 1; i <= n; i++) {
        parent_node[i] = i;
        sz[i] = 1;
    }

    sort(edges.begin(), edges.end());

    long long total_cost = 0;
    int edges_added = 0;

    for (const auto& edge : edges) {
        if (find_set(edge.u) != find_set(edge.v)) {
            total_cost += edge.w;
            union_sets(edge.u, edge.v);
            edges_added++;
            if (edges_added == n - 1) break;
        }
    }

    if (edges_added == n - 1) {
        cout << total_cost << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}