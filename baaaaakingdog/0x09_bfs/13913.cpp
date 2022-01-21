#include "bits/stdc++.h"

using namespace std;

const int MX = 1e5;
bool visited[MX + 1];
int ans[MX+1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    queue<pair<int, int>> Q;
    stack<int> S;
    Q.push({n, 0});
    visited[n] = true;
    int idx = 0;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        if (cur.first == k) {
            idx = cur.first;
            cout << cur.second << '\n';
            break;
        }
        for (int x: {1, -1, cur.first}) {
            int nxt = x + cur.first;
            if (nxt >= 0 && nxt <= MX && !visited[nxt]) {
                visited[nxt] = true;
                Q.push({nxt, cur.second + 1});
                ans[nxt] = cur.first;
            }
        }
    }
    S.push(idx);
    ans[n] = 0;
    while (ans[idx] != 0){
        idx = ans[idx];
        S.push(idx);
    }
    while (!S.empty()){
        cout << S.top() <<' ';
        S.pop();
    }
}