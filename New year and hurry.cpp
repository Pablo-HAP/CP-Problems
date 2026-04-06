#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int total_time = 240;
    int available_time = total_time - k;
    int solved = 0;
    int current_sum = 0;

    for (int i = 1; i <= n; ++i) {
        int cost = 5 * i;
        if (current_sum + cost <= available_time) {
            current_sum += cost;
            solved++;
        } else {
            break;
        }
    }

    cout << solved << endl;

    return 0;
}