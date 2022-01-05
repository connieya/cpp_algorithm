#include "bits/stdc++.h"
#define INF 1e9
using namespace std;

int main(void) {
    int n, m, x, k;
    int arr[101][101];
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                arr[i][j] = 0;
                continue;
            }
            arr[i][j] = INF;
        }
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    cin >> x >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int l = 1; l <= n; ++l) {
                if (j==l) continue;
                arr[j][l] = min(arr[j][l] , arr[j][i]+arr[i][l]);
            }
        }
    }
    int ans =  arr[1][k]+arr[k][x];
    if (ans >= INF){
        printf("-1");
    }else {
        printf("%d",ans);
    }
}