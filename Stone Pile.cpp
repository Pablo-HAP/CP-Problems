#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<ll> w(n);
    ll total_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        total_sum += w[i];
    }

    ll min_diff = total_sum;

    for (int i = 0; i < (1 << n); i++) {
        ll current_pile_a = 0;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                current_pile_a += w[j];
            }
        }
        
        ll current_diff = abs(2 * current_pile_a - total_sum);
        min_diff = min(min_diff, current_diff);

        if (min_diff <= (total_sum % 2)) break;
    }

    cout << min_diff << endl;

    return 0;
}