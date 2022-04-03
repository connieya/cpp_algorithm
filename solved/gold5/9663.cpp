#include "bits/stdc++.h"

using namespace std;

bool column[16];
bool diagonal_r[31];
bool diagonal_l[31];

int ans;

void dfs(int L, int n) {
    if (L == n + 1) {
        ans++;
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!column[i] && !diagonal_r[i + L] && !diagonal_l[i - L + n]) {
            column[i] = diagonal_r[i + L] = diagonal_l[i - L + n] = true;
            dfs(L + 1, n);
            column[i] = diagonal_r[i + L] = diagonal_l[i - L + n] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    dfs(1, n);
    cout << ans;

}