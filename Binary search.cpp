#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    if (!(cin >> N >> Q)) return 0;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    while (Q--) {
        int x;
        cin >> x;
        auto it = lower_bound(a.begin(), a.end(), x);
        
        if (it != a.end() && *it == x) {
            cout << (it - a.begin()) << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}