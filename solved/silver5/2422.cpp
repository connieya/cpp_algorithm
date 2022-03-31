#include "bits/stdc++.h"

using namespace std;

bool checked[201][201];
int arr[3];
int ans = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        checked[a][b] = checked[b][a] = true;

    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            if (checked[i][j]) continue;
            for (int k = j+1; k <= n; ++k) {
                if (!checked[i][k] && !checked[j][k]){
                    ans++;
                }
            }
        }
    }
    cout << ans;
}