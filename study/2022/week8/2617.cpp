#include "bits/stdc++.h"

#define INF 21470000
using namespace std;

int heavy[101][101];
int light[101][101];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            heavy[i][j] = INF;
            light[i][j] = INF;
        }
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        heavy[a][b] = 1;
        light[b][a] = 1;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                heavy[i][j] =
                        min(heavy[i][j], heavy[i][k] + heavy[k][j]);
                light[i][j] = min(light[i][j], light[i][k] + light[k][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int h_cnt = 0;
        int l_cnt = 0;
        for (int j = 1; j <= n; ++j) {
            if (heavy[i][j] != INF) {
                h_cnt++;
            }
            if (light[i][j]!= INF) {
                l_cnt++;
            }
        }
        if (h_cnt >= (n + 1) / 2 || l_cnt >= (n+1)/2){
            ans++;
        }
    }
    cout << ans;

}