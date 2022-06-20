#include "bits/stdc++.h"

using namespace std;

int dp[10001];
int arr[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, start, end;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    cin >> start >> end;
    if (arr[start] == 1) {
        cout << 1;
        exit(0);
    }
    fill(dp, dp + n + 1, -1);
    dp[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int now = q.front();
        int mp = arr[now];
        if(now == end) {
            cout << dp[now];
            exit(0);
        }
        q.pop();
        for(int i=now; i<=10000; i+=mp){
            if(dp[i] == -1){
                dp[i] = dp[now]+1;
                if(i == end){
                    cout << dp[i];
                    exit(0);
                }
                q.push(i);
            }
        }

        for(int i=now; i>=1; i-=mp){
            if(dp[i] == -1){
                dp[i] = dp[now]+1;
                if(i == end){
                    cout << dp[i];
                    exit(0);
                }
                q.push(i);
            }
        }
    }
    cout << -1;
}