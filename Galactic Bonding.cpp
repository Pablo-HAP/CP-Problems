#include <bits/stdc++.h>
using namespace std;

int parent_node[1005];

int find_set(int v) {
    if (v == parent_node[v])
        return v;
    return parent_node[v] = find_set(parent_node[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        parent_node[b] = a;
    }
}

void solve(int tc) {
    int n;
    double d;
    cin >> n >> d;
    
    vector<pair<double, double>> stars(n);
    for (int i = 0; i < n; i++) {
        cin >> stars[i].first >> stars[i].second;
        parent_node[i] = i;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dx = stars[i].first - stars[j].first;
            double dy = stars[i].second - stars[j].second;
            if (dx * dx + dy * dy <= d * d) {
                union_sets(i, j);
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (parent_node[i] == i) {
            ans++;
        }
    }
    
    cout << "Case " << tc << ": " << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (cin >> t) {
        for (int i = 1; i <= t; i++) {
            solve(i);
        }
    }
    
    return 0;
}