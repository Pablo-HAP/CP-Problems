#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n[10];
int a[10];
bool used[10];
ll K;
bool found;

bool can_solve(int idx, ll current_sum) {
    vector<ll> remaining_n;
    for (int i = idx; i < 10; i++) remaining_n.push_back(n[i]);
    sort(remaining_n.rbegin(), remaining_n.rend());

    vector<int> remaining_digits;
    for (int i = 0; i <= 9; i++) {
        if (!used[i]) remaining_digits.push_back(i);
    }
    sort(remaining_digits.begin(), remaining_digits.end());

    ll min_future_sum = 0;
    for (int i = 0; i < remaining_n.size(); i++) {
        min_future_sum += (ll)remaining_n[i] * remaining_digits[i];
    }

    return (current_sum + min_future_sum <= K);
}

void backtrack(int idx, ll current_sum) {
    if (found) return;
    if (idx == 10) {
        if (current_sum <= K) {
            for (int i = 0; i < 10; i++) cout << a[i] << (i == 9 ? "" : " ");
            cout << "\n";
            found = true;
        }
        return;
    }

    for (int d = 0; d <= 9; d++) {
        if (!used[d]) {
            ll next_sum = current_sum + (ll)d * n[idx];
            used[d] = true;
            if (can_solve(idx + 1, next_sum)) {
                a[idx] = d;
                backtrack(idx + 1, next_sum);
                if (found) return;
            }
            used[d] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 10; i++) cin >> n[i];
        cin >> K;

        memset(used, false, sizeof(used));
        found = false;

        if (!can_solve(0, 0)) {
            cout << "-1\n";
        } else {
            backtrack(0, 0);
        }
    }
    return 0;
}