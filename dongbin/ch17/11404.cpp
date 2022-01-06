#include "bits/stdc++.h"

#define INF 1e7
using namespace std;

int city[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            city[i][j] = INF;
        }
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        city[a][b] = min(c, city[a][b]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                if (j == k) continue;
                if (i == k) continue;
                city[j][k] = min(city[j][k], city[j][i] + city[i][k]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (city[i][j] == INF) {
                cout << 0 << ' ';
                continue;
            }
            cout << city[i][j] << ' ';
        }
        cout << '\n';
    }
}