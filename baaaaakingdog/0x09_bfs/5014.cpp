#include "bits/stdc++.h"

using namespace std;

int dp[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int F,S,G,U,D;
    cin >> F >> S >> G >> U >>D;
    queue<int> q;
    memset(dp,-1, sizeof(dp));
    q.push(S);
    dp[S] = 0;
    while (!q.empty()){
        int now = q.front();
        q.pop();
        if(now == G){
            cout << dp[now];
            exit(0);
        }
        if(now+U <= F && dp[now+U] == -1){
            q.push(now+U);
            dp[now+U] = dp[now]+1;
        }
        if(now-D >= 1 && dp[now-D] == -1){
            q.push(now-D);
            dp[now-D] = dp[now]+1;
        }
    }
    cout << "use the stairs";
}