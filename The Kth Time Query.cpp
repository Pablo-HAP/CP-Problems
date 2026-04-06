    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int N, Q;
        cin >> N >> Q;

        map<int, vector<int>> pos_map;
        for (int i = 1; i <= N; ++i) {
            int a;
            cin >> a;
            pos_map[a].push_back(i);
        }

        while (Q--) {
            int x, k;
            cin >> x >> k;
            if (pos_map.count(x) && pos_map[x].size() >= k) {
                cout << pos_map[x][k - 1] << "\n";
            } else {
                cout << -1 << "\n";
            }
        }

        return 0;
    }