#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    double cost;
    int type; // 0 for UTP, 1 for Optical Fiber

    bool operator<(const Edge& other) const {
        if (abs(cost - other.cost) > 1e-9) {
            return cost < other.cost;
        }
        return type < other.type;
    }
};

struct DSU {
    vector<int> parent;
    int components;

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        components = n;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    bool union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            parent[b] = a;
            components--;
            return true;
        }
        return false;
    }
};

void solve(int tc) {
    int n, w;
    double r, u, v;
    if (!(cin >> n >> r >> w >> u >> v)) return;

    vector<pair<double, double>> towns(n);
    for (int i = 0; i < n; i++) {
        cin >> towns[i].first >> towns[i].second;
    }

    vector<Edge> edges;
    edges.reserve(n * (n - 1) / 2);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dx = towns[i].first - towns[j].first;
            double dy = towns[i].second - towns[j].second;
            double d = sqrt(dx * dx + dy * dy);
            
            double cost;
            int type;
            if (d <= r) {
                cost = d * u;
                type = 0; // UTP
            } else {
                cost = d * v;
                type = 1;
            }
            edges.push_back({i, j, cost, type});
        }
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    double utp_total = 0.0;
    double fiber_total = 0.0;

    for (const auto& edge : edges) {
        if (dsu.components == w) break;
        
        if (dsu.union_sets(edge.u, edge.v)) {
            if (edge.type == 0) {
                utp_total += edge.cost;
            } else {
                fiber_total += edge.cost;
            }
        }
    }

    cout << "Caso #" << tc << ": "
         << fixed << setprecision(3) << utp_total << " " << fiber_total << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (cin >> t) {
        for (int tc = 1; tc <= t; tc++) {
            solve(tc);
        }
    }
    return 0;
}