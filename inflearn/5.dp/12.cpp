#include "bits/stdc++.h"
#define INF 214700000
using namespace std;

int arr[101][101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i==j){
                continue;
            }
            arr[i][j] = INF;
        }
    }
    for (int i = 0; i < m; ++i) {
        int a,b,c;
        cin >> a>> b >>c;
        arr[a][b] =c;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                arr[i][j] = min(arr[i][j] , arr[i][k]+arr[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j =1; j <= n; ++j) {
            if (arr[i][j] == INF){
                cout << "M" << ' ';
                continue;
            }
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}