#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    stack<pair<int, int>> S;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int height;
        cin >> height;
        if (S.empty()) {
            cout << 0 << ' ';
        } else {
            while (!S.empty() && height > S.top().first) {
                S.pop();
            }
            if (S.empty()) {
                cout << 0 << ' ';
            } else {
                cout << S.top().second << ' ';
            }
        }
        S.push({height, i});
    }

}