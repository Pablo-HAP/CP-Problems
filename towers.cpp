#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    map<int, int> counts;
    for (int i = 0; i < N; ++i) {
        int length;
        cin >> length;
        counts[length]++;
    }

    int maxHeight = 0;
    for (auto const& [length, count] : counts) {
        if (count > maxHeight) {
            maxHeight = count;
        }
    }

    cout << maxHeight << " " << counts.size() << endl;

    return 0;
}