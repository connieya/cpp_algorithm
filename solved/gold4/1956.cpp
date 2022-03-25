#include "bits/stdc++.h"
#define INF 21470000

using namespace std;

int arr[401][401];

void init(int n){
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            arr[i][j] = INF;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m , a,b,c;
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        arr[a][b] =c;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                if (arr[i][k]+arr[k][j] < arr[i][j]) {
                    arr[i][j] = arr[i][k]+arr[k][j];
                }
            }
        }
    }
    int min_road = INF;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            min_road =  min(arr[i][j]+arr[j][i],min_road);
        }
    }
    if (min_road == INF){
        cout << -1;
    }else {
        cout << min_road;
    }

}