#include "bits/stdc++.h"

#define INF 21470000
using namespace std;

string S, T, tmp;
int ans = INF;

void print() {
    cout << tmp << '\n';
}

void pressSwitch(int i, int n) {
    if (i > 0) {
        tmp[i - 1] = (tmp[i - 1] == '0') ? '1' : '0';
    }
    tmp[i] = (tmp[i] == '0') ? '1' : '0';
    if (i + 1 < n) {
        tmp[i + 1] = (tmp[i + 1] == '0') ? '1' : '0';
    }
}

void solve(int n, int start) {
    tmp = S;
    int cnt = 0;
    if (start == 0) {
        tmp[0] = (tmp[0] == '0') ? '1' : '0';
        tmp[1] = (tmp[1] == '0') ? '1' : '0';
        cnt++;
    }
    for (int i = 1; i < n; ++i) {
        if (tmp[i - 1] != T[i - 1]) {
            cnt++;
            pressSwitch(i, n);
        }
    }
    if (tmp == T) {
        ans = min(ans, cnt);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cin >> S >> T;
    solve(n, 0);
    solve(n, 1);

    if (ans == INF) {
        cout << -1;
    } else {
        cout << ans;
    }
}