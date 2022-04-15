#include "bits/stdc++.h"

using namespace std;
int ans[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, num;
    cin >> n;
    stack<pair<int, int>> S;
    cin >> num;
    S.push({0, num});
    for (int i = 1; i < n; ++i) {
        cin >> num;
        while (!S.empty() && S.top().second < num) {
            ans[S.top().first] = num;
            S.pop();
        }
        S.push({i, num});
    }
    while (!S.empty()) {
        ans[S.top().first] = -1;
        S.pop();
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
}