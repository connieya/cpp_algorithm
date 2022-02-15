#include "bits/stdc++.h"

using namespace std;

int singer[1001];
vector<int> s[1001];
vector<int> result;
int arr[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, cnt;
    cin >> n >> m;
    queue<int> Q;
    for (int i = 0; i < m; ++i) {
        cin >> cnt;
        for (int j = 0; j < cnt; ++j) {
            cin >> arr[j];
            if (j == 0) continue;
            singer[arr[j]]++;
        }
        for (int j = 0; j < cnt - 1; ++j) {
            s[arr[j]].push_back(arr[j + 1]);
        }
    }
    for (int i = 1; i <= n; ++i) {
//        cout << singer[i] << ' ';
        if (singer[i] == 0) {
            Q.push(i);
        }
    }
    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        result.push_back(now);
        for (int next: s[now]) {
            singer[next]--;
            if (singer[next] == 0) {
                Q.push(next);
            }
        }
    }
    if (result.size() != n) {
        cout << 0 << '\n';
    } else {
        for (int a: result) {
            cout << a << '\n';
        }
    }
}