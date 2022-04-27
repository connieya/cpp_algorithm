#include "bits/stdc++.h"
#define INF 21470000

using namespace std;

bool visited[10001];
int dp[10001][250];
int n,m;

int dfs(int num ,int cnt){
    if (num == n){
        return 0;
    }
    int &res = dp[num][cnt];
    if (res != -1) return res;

    res = INF;
    for (int i =-1; i <= 1; ++i) {
        int jump = cnt+i;
        int nextStone = jump+num;
        if (jump >=1 && nextStone <= n && !visited[nextStone]){
            res = min(res , dfs(nextStone,jump)+1);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int s;
        cin >> s;
        visited[s] = true;
    }
    memset(dp,-1, sizeof(dp));
    int ans = dfs(1,0);
    (ans == INF) ? cout << -1 : cout << ans;
}
