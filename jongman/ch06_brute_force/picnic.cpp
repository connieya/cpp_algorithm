#include "bits/stdc++.h"

using namespace std;

bool areFriends[11][11];
bool visited[11];
int ans = 0;

void init(){
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 11; ++j) {
            areFriends[i][j] = false;
        }
    }
    for (int i = 0; i < 11; ++i) {
        visited[i] = false;
    }
}

void dfs(int n){
    int first = -1;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]){
            first = i;
            break;
        }
    }
    if (first == -1) {
        ans++;
        return;
    }
    for (int i = first+1; i < n; ++i) {
        if (!visited[i] && !visited[first] && areFriends[i][first]){
            visited[i] = visited[first] = true;
            dfs(n);
            visited[i] = visited[first] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n ,m;
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            int a ,b;
            cin >> a >> b;
            areFriends[a][b] = true;
            areFriends[b][a] = true;
        }
        ans = 0;
        dfs(n);
        cout << ans << '\n';
        init();
    }
}