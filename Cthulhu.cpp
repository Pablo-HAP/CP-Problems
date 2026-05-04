#include <bits/stdc++.h>
using namespace std;

int parent_node[105];

int find_set(int v) {
    if (v == parent_node[v])
        return v;
    return parent_node[v] = find_set(parent_node[v]);
}

void union_sets(int a, int b, int &components) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        parent_node[b] = a;
        components--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    if (n != m) {
        cout << "NO" << "\n";
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        parent_node[i] = i;
    }

    int components = n;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        union_sets(u, v, components);
    }

    if (components == 1) {
        cout << "FHTAGN!" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}