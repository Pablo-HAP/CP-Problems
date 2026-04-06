#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<pair<int, int>> activities;

        for (int i = 0; i < N; i++) {
            int start, end;
            cin >> start >> end;
            activities.push_back({end, start});
        }

        sort(activities.begin(), activities.end());

        int count = 0;
        int lastEnd = -1;

        for (int i = 0; i < N; i++) {
            int end = activities[i].first;
            int start = activities[i].second;

            if (start >= lastEnd) {
                count++;
                lastEnd = end;
            }
        }

        cout << count << '\n';
    }

    return 0;
}