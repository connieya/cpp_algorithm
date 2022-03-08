#include "bits/stdc++.h"

using namespace std;

int arr[3001][3];
bool visited[3001];

void dfs(int n , vector<int> V[3001]) {
    visited[n] = true;
    for (int next : V[n]) {
        if (!visited[next]){
            dfs(next,V);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n ,ans = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        }
        fill(visited,visited+3001, false);
        vector<int> V[3001];
        for (int i = 1; i <= n; ++i) {
            for (int j = i+1; j <= n; ++j) {
                int R = (arr[i][2]+arr[j][2])*(arr[i][2]+arr[j][2]);
                int distance = (arr[i][1]-arr[j][1])*(arr[i][1]-arr[j][1])+ (arr[i][0]-arr[j][0])*(arr[i][0]-arr[j][0]);
                if (R>=distance){
                    V[i].push_back(j);
                    V[j].push_back(i);
                }
            }
        }
        for(int i=1; i<=n; i++) {
            if (!visited[i]) {
                ans++;
                dfs(i , V);
            }
        }
        cout << ans << '\n';
    }
}