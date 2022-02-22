#include "bits/stdc++.h"

#define INF 2147000

using namespace std;
int arr[101][101];
int nxt[101][101];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            arr[i][j] = INF;
            nxt[i][j] = INF;
        }
    }
}

void createBusRoad(int m) {
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = min(arr[a][b], c);
    }
}

void floydWarshall(int n) {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == j) continue;
                if (arr[i][j] > arr[i][k]+arr[k][j]){
                    arr[i][j] = arr[i][k]+arr[k][j];
                    nxt[i][j] = k;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    init(n);
    createBusRoad(m);
    floydWarshall(n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (arr[i][j] == INF) {
                cout << 0 << ' ';
                continue;
            }
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }


}