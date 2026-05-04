#include <bits/stdc++.h>
using namespace std;

long long solve_dp(int n, int k) {
    if (k <= 0) return 0;
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    long long MOD = 1000000007;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }
    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, d;
    if (!(cin >> n >> k >> d)) return 0;

    long long MOD = 1000000007;
    long long all_paths = solve_dp(n, k);
    long long paths_less_than_d = solve_dp(n, d - 1);

    long long ans = (all_paths - paths_less_than_d + MOD) % MOD;
    cout << ans << "\n";

    return 0;
}