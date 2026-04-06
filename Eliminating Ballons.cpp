#include <bits/stdc++.h>
using namespace std;
int flechas_na_altura[1000005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int total_flechas = 0;

    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;

        if (flechas_na_altura[h] > 0) {
            flechas_na_altura[h]--;
            flechas_na_altura[h - 1]++;
        } else {
            total_flechas++;
            flechas_na_altura[h - 1]++;
        }
    }

    cout << total_flechas << endl;

    return 0;
}