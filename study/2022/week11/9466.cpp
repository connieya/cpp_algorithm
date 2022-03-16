#include "bits/stdc++.h"

using namespace std;

int arr[100001] , cnt;
bool visited[100001];
bool done[100001];

void dfs(int now) {
    visited[now] = true;
    int nxt = arr[now];
    if (!visited[nxt]) {
        dfs(nxt);
    } else if (!done[nxt]) {
        while (now != nxt){
            cnt++;
            nxt = arr[nxt];
        }
        cnt++;
    }
    done[now] = true;

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        fill(visited,visited+100001,false);
        fill(done , done+100001 , false);
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]){
                dfs(i);
            }
        }
        cout << n-cnt << '\n';
    }
}