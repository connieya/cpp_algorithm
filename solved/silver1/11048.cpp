#include "bits/stdc++.h"

using namespace std;

int n,m;
int arr[1001][1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
            arr[i][j] +=  max(arr[i-1][j],arr[i][j-1]);
        }
    }
    cout << arr[n][m];
}