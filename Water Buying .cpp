#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    while (q--) {
        long long n, a, b;
        cin >> n >> a >> b;

        long long pairCost = min(2 * a, b);
        long long ans = (n / 2) * pairCost + (n % 2) * a;

        cout << ans << '\n';
    }

    return 0;
}