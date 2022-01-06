#include "bits/stdc++.h"

using namespace std;

int d[101];
int arr[101][101];
int n,m;
void dfs(int start) {
    for (int i = 1; i <=n ; ++i) {
        if (arr[start][i] && !d[i]) {
            d[i] =1;
            dfs(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    d[1] = 1;
    dfs(1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += d[i];
    }
    cout << ans-1;

}