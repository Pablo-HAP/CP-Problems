#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;
    if (!(cin >> n >> x)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long soma_atual = 0;
    int contador = 0;
    int L = 0;

    for (int R = 0; R < n; R++) {
        soma_atual += a[R];

        while (soma_atual > x && L <= R) {
            soma_atual -= a[L];
            L++;
        }

        if (soma_atual == x) {
            contador++;
        }
    }

    cout << contador << endl;

    return 0;
}