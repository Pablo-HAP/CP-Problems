#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> q(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
    }

    int m;
    cin >> m;

    const long long INF = 1e18;
    vector<long long> min_in(n + 1, INF);

    for (int i = 0; i < m; i++) {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        min_in[v] = min(min_in[v], c);
    }

    int no_supervisor_count = 0;
    long long total_cost = 0;

    for (int i = 1; i <= n; i++) {
        if (min_in[i] == INF) {
            no_supervisor_count++;
        } else {
            total_cost += min_in[i];
        }
    }

    if (no_supervisor_count > 1) {
        cout << -1 << "\n";
    } else {
        cout << total_cost << "\n";
    }

    return 0;
}