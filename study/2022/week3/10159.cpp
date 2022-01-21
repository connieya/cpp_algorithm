#include "bits/stdc++.h"

using namespace std;

int arr[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = -1;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (arr[i][k] == arr[k][j] && arr[i][k] != 0){
                    arr[i][j] = arr[i][k];
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            if (arr[i][j] == 0){
                cnt++;
            }
        }
        cout << cnt-1<< '\n';
    }
}