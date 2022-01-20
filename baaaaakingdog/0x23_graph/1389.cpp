#include "bits/stdc++.h"

#define INF 1e6;
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int user[101][101];
    int n, m , ans = 0 , MIN = INF;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                user[i][j] = 0;
                continue;
            }
            user[i][j] = INF;
        }
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        user[a][b] = 1;
        user[b][a] = 1;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <=n; ++j) {
                user[i][j] = min(user[i][j], user[i][k] + user[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        int sum = 0;
        for (int j = 1; j <= n; ++j) {
            sum += user[i][j];
        }
        if (MIN > sum){
            MIN = sum;
            ans = i;
        }
    }
    cout << ans;
}
