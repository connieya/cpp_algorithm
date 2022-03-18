#include "bits/stdc++.h"

using namespace std;

int n, ans = -1;
int board[16][2];

void dfs(int L, int sum) {
    if (L > n + 1) {
        return;
    }
    if (L == n+1){
        if (sum > ans) {
            ans = sum;
        }
        return;
    }

    dfs(L + 1, sum);
    dfs(L + board[L][0], sum + board[L][1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> board[i][0] >> board[i][1];
    }
    dfs(1, 0);
    cout << ans;
}
