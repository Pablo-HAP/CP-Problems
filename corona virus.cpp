#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }

        int min_val = 15, max_val = 0;
        int current_group_size = 1;

        for (int i = 0; i < n - 1; i++) {
            if (x[i+1] - x[i] <= 2) {
                current_group_size++;
            } else {
                min_val = min(min_val, current_group_size);
                max_val = max(max_val, current_group_size);
                current_group_size = 1;
            }
        }

        min_val = min(min_val, current_group_size);
        max_val = max(max_val, current_group_size);

        cout << min_val << " " << max_val << "\n";
    }
    return 0;