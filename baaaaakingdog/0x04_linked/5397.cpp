#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        stack<char> L;
        stack<char> R;
        string str;
        cin >> str;
        for (char ch: str) {
            if (ch == '<') {
                if (!L.empty()) {
                    R.push(L.top());
                    L.pop();
                }

            } else if (ch == '>') {
                if (!R.empty()) {
                    L.push(R.top());
                    R.pop();
                }
            } else if (ch == '-') {
                if (!L.empty()) {
                    L.pop();
                }
            } else {
                L.push(ch);
            }

        }
        while (!L.empty()) {
            R.push(L.top());
            L.pop();
        }
        while (!R.empty()) {
            cout << R.top();
            R.pop();
        }
        cout << '\n';

    }
}