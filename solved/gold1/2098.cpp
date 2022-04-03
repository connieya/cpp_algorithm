#include "bits/stdc++.h"
#define INF 214700000
using namespace std;

int arr[17][17];
bool visited[17];
int n , ans = INF;

void dfs(int L ,int start,int sum) {
    if (L == n) {
        sum += arr[start][0];
        if (arr[start][0] != 0 && ans > sum){
            ans = sum;
        }
        return;
    }
    for (int i = 1; i < n; ++i) {
        if (!visited[i] && arr[start][i] != 0){
            visited[i] = true;
            dfs(L+1,i,sum+arr[start][i]);
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