#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    int max_depth = 0;
    for (int i = 1; i <= n; i++) {
        int depth = 0;
        int current = i;
        while (current != -1) {
            current = p[current];
            depth++;
        }
        max_depth = max(max_depth, depth);
    }

    cout << max_depth << "\n";

    return 0;
}