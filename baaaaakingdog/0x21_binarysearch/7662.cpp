#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        multiset<int> s;
        while (n--) {
            char op;
            int num;
            cin >> op >> num;
            if (op == 'I') {
                s.insert(num);
                continue;
            }
            if (op == 'D' && !s.empty()) {
                if (num == -1) {
                    s.erase(s.begin());
                } else {
                    s.erase(prev(s.end()));
                }
            }
        }

        if (s.empty()) {
            cout << "EMPTY" << '\n';
        } else {
            cout << *prev(s.end()) << ' ' << *(s.begin()) << '\n';
        }
    }
}