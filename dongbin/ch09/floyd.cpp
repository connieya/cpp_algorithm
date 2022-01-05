#include "bits/stdc++.h"

#define INF 1e9
using namespace std;

int main(void) {
    int n, m, a, b, c;
    int arr[10][10];
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                arr[i][j] = 0;
            } else {
                arr[i][j] = INF;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        arr[a][b] = c;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                if (j==k) continue;
                arr[j][k] = min(arr[j][k] ,arr[j][i] +arr[i][k]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (arr[i][j] == INF) {
                cout <<  "INFINITY"  << ' ';
            }else{
                cout <<  arr[i][j]  << ' ';
            }
        }
        cout << '\n';

    }


}