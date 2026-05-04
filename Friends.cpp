#include <bits/stdc++.h>
using namespace std;

int parent_node[30005];
int sz[30005];

int find_set(int v) {
    if (v == parent_node[v])
        return v;
    return parent_node[v] = find_set(parent_node[v]);
}

void union_sets(int a, int b, int &max_sz) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent_node[b] = a;
        sz[a] += sz[b];
        max_sz = max(max_sz, sz[a]);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parent_node[i] = i;
        sz[i] = 1;
    }
    int max_sz = 1;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        union_sets(u, v, max_sz);
    }
    cout << max_sz << "\n";
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