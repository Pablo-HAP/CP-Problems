/*#include <bits/stdc++.h>
using namespace std;
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false)    ;
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;


    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }


    sort(a.begin(), a.end());


    int L = 0;
    int R = n - 1;

    while (L < R) {
        long long soma = (long long)a[L].first + a[R].first;

        if (soma == x) {
            cout << a[L].second << " " << a[R].second << endl;
            return 0;
        } else if (soma < x) {
            L++;
        } else {
            R--;
        }
    }


    cout << "IMPOSSIBLE" << endl;

    return 0;
}