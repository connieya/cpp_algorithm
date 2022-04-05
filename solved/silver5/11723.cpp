#include "bits/stdc++.h"

using namespace std;
int n;
int s = 0;

void solve(string op) {
    int m, ans;
    if (op == "add") {
        cin >> m;
        s = s | 1<< m;
        return;
    }
    if (op == "check") {
        cin >> m;
        if (s & 1 << m){
            ans = 1;
        }else {
            ans = 0;
        }
        cout << ans << '\n';
        return;
    }
    if (op == "toggle") {
        cin >> m;
        s = s  ^ 1 << m;
        return;
    }
    if (op == "all") {
        s = ~0;
        return;
    }
    if (op == "remove") {
        cin >> m;
        s = s & ~(1 << m);
        return;
    }
    if (op == "empty") {
        s  = 0;
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string op;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> op;
        solve(op);
    }

}