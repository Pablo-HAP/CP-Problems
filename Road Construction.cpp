#include <bits/stdc++.h>
using namespace std;

int parent_node[100005];
int sz[100005];
int components;
int max_sz;

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

        components--;
        max_sz = max(max_sz, sz[a]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    components = n;
    max_sz = 1;

    for (int i = 1; i <= n; i++) {
        parent_node[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        union_sets(u, v);

        cout << components << " " << max_sz << "\n";
    }

    return 0;
}