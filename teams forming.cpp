#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int total_problems = 0;


    for (int i = 0; i < n; i += 2) {
        total_problems += (a[i+1] - a[i]);
    }

    cout << total_problems << endl;

    return 0;
}