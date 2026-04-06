#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int MOD = 1000000007;

    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int sum = 1; sum <= x; sum++) {
        for (int i = 0; i < n; i++) {
            if (sum - c[i] >= 0) {
                dp[sum] += dp[sum - c[i]];
                if (dp[sum] >= MOD) dp[sum] -= MOD;
            }
        }
    }

    cout << dp[x] << '\n';
    return 0;
}