    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int Q;
        cin >> Q;

        deque<int> dq;
        bool isReversed = false;

        while (Q--) {
            string cmd;
            cin >> cmd;

            if (cmd == "push_back") {
                int n;
                cin >> n;
                if (!isReversed) dq.push_back(n);
                else dq.push_front(n);
            }
            else if (cmd == "toFront") {
                int n;
                cin >> n;
                if (!isReversed) dq.push_front(n);
                else dq.push_back(n);
            }
            else if (cmd == "back") {
                if (dq.empty()) {
                    cout << "No job for Ada?\n";
                } else {
                    if (!isReversed) {
                        cout << dq.back() << "\n";
                        dq.pop_back();
                    } else {
                        cout << dq.front() << "\n";
                        dq.pop_front();
                    }
                }
            }
            else if (cmd == "front") {
                if (dq.empty()) {
                    cout << "No job for Ada?\n";
                } else {
                    if (!isReversed) {
                        cout << dq.front() << "\n";
                        dq.pop_front();
                    } else {
                        cout << dq.back() << "\n";
                        dq.pop_back();
                    }
                }
            }
            else if (cmd == "reverse") {
                isReversed = !isReversed;
            }
        }

        return 0;
    }