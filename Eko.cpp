#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool can_cut(const vector<int>& trees, int n, int m, int h) {
    ll total = 0;
    for (int i = 0; i < n; ++i) {
        if (trees[i] > h) {
            total += (trees[i] - h);
        }
        if (total >= m) return true;
    }
    return total >= m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> trees(n);
    int max_h = 0;
    for (int i = 0; i < n; ++i) {
        cin >> trees[i];
        if (trees[i] > max_h) max_h = trees[i];
    }

    int low = 0, high = max_h, ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (can_cut(trees, n, m, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}