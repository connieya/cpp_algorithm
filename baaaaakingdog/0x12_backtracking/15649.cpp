#include "bits/stdc++.h"

using namespace std;

int n, m;
int arr[9];
bool visited[9];

void dfs(int L){
    if(L == m){
        for (int i = 0; i < m; ++i) {
            cout << arr[i] << ' ';
        }
        cout <<'\n';
        return;
    }

    for(int i=1; i<=n; i++){
        if(visited[i]) continue;
        visited[i] = true;
        arr[L] = i;
        dfs(L+1);
        visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    dfs(0);
}