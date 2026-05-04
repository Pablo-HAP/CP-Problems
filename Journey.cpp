#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];

double dfs(int u, int p) {
    double sum = 0;
    int children = 0;
    for (int v : adj[u]) {
        if (v != p) {
            sum += dfs(v, u) + 1.0;
            children++;
        }
    }
    if (children == 0) return 0.0;
    return sum / children;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << fixed << setprecision(15) << dfs(1, 0) << endl;

    return 0;
}