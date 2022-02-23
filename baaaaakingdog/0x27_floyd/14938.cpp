#include "bits/stdc++.h"
#define INF 21470000

using namespace std;

int items[101];
int ground[101][101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,r;
    cin >> n >> m >> r;
    for (int i = 1; i <= n; ++i) {
        cin >> items[i];
        fill(ground[i],ground[i]+101,INF);
        ground[i][i] = 0;
    }
    for (int i = 0; i < r; ++i) {
        int a ,b ,d;
        cin >> a >> b >> d;
        ground[a][b] = d;
        ground[b][a] = d;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (ground[i][j] > ground[i][k]+ground[k][j]) {
                    ground[i][j] = ground[i][k] + ground[k][j];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int sum = 0;
        for (int j = 1; j <= n; ++j) {
            if (ground[i][j] <= m){
                sum += items[j];
            }
        }
        ans = max(ans , sum);
    }
    cout << ans;

}