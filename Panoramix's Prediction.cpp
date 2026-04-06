#include <bits/stdc++.h>
using namespace std;

bool isPrime(int k) {
    if (k < 2) return false;
    for (int i = 2; i * i <= k; i++) {
        if (k % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int next_prime = -1;
    for (int i = n + 1; i <= 50; i++) {
        if (isPrime(i)) {
            next_prime = i;
            break;
        }
    }

    if (next_prime == m) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}