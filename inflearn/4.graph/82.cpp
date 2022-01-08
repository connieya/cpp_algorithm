#include "bits/stdc++.h"

using namespace std;

int arr[15];
int ans[15];
bool visited[15];
int n,r ,cnt;

void dfs(int L) {
    if(L == r) {
        for (int i = 0; i < L; ++i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        cnt++;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;
        ans[L] = arr[i];
        visited[i] = true;
        dfs(L+1);
        visited[i] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> r;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    dfs(0);
    cout << cnt;
}