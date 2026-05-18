#include <bits/stdc++.h>
using namespace std;

int parent_node[1005];
int sz[1005];

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

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    vector<int> c(k);
    for (int i = 0; i < k; i++) {
        cin >> c[i];
    }

    for (int i = 1; i <= n; i++) {
        parent_node[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        union_sets(u, v);
    }

    long long max_sz = 0;
    long long sum_special = 0;
    vector<long long> special_sizes;

    for (int i = 0; i < k; i++) {
        int root = find_set(c[i]);
        long long current_sz = sz[root];
        special_sizes.push_back(current_sz);
        max_sz = max(max_sz, current_sz);
        sum_special += current_sz;
    }

    long long remaining = n - sum_special;
    long long ans = 0;
    bool added = false;

    for (int i = 0; i < k; i++) {
        long long s = special_sizes[i];
        if (s == max_sz && !added) {
            s += remaining;
            added = true;
        }
        ans += s * (s - 1) / 2;
    }

    cout << ans - m << "\n";

    return 0;
}