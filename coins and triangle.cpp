#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long N;
    if (!(cin >> N)) return;

    long long ans = (-1 + sqrt(1 + 8.0 * N)) / 2;

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}