#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        priority_queue<long long> leftHeap;
        priority_queue<long long, vector<long long>, greater<long long>> rightHeap;

        while (true) {
            long long x;
            cin >> x;

            if (x == 0) {
                break;
            }

            if (x == -1) {
                cout << leftHeap.top() << '\n';
                leftHeap.pop();

                if (leftHeap.size() < rightHeap.size()) {
                    leftHeap.push(rightHeap.top());
                    rightHeap.pop();
                }
            } else {
                if (leftHeap.empty() || x <= leftHeap.top()) {
                    leftHeap.push(x);
                } else {
                    rightHeap.push(x);
                }

                if (leftHeap.size() < rightHeap.size()) {
                    leftHeap.push(rightHeap.top());
                    rightHeap.pop();
                } else if (leftHeap.size() > rightHeap.size() + 1) {
                    rightHeap.push(leftHeap.top());
                    leftHeap.pop();
                }
            }
        }
    }

    return 0;
}