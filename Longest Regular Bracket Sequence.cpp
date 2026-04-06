#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    stack<int> st;
    st.push(-1);

    int mx = 0, cnt = 0;

    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i);
            } else {
                int len = i - st.top();
                if (len > mx) {
                    mx = len;
                    cnt = 1;
                } else if (len == mx) {
                    cnt++;
                }
            }
        }
    }

    if (mx == 0) cout << "0 1\n";
    else cout << mx << ' ' << cnt << '\n';

    return 0;
}