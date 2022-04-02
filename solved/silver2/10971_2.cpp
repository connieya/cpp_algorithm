#include "bits/stdc++.h"

using namespace std;

int arr[11][11];
bool visited[11];
int n , ans = INT_MAX;

void dfs(int L ,int sum , int start){
    if (L == n){
        if (!arr[start][0]) return;
        sum += arr[start][0];
        if (sum< ans){
            ans = sum;
        }
        return;
    }
    for (int i = 1; i < n; ++i) {
        if (!visited[i] && arr[start][i] && ans > sum+arr[start][i]){
            visited[i] = true;
            dfs(L+1,sum+arr[start][i],i);
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    dfs(1,0,0);
    cout << ans;
}