#include "bits/stdc++.h"

using namespace std;

int ans = 21470000;
int arr[11][11];
bool visited[11];
void dfs(int L ,int last, int n , int sum) {
    if (L== n) {
        if (arr[last][1] != 0) {
            sum += arr[last][1];
            if (ans > sum){
                ans = sum;
            }
        }
        return;
    }
    for (int i = 2; i <=n ; ++i) {
        if (!visited[i] && arr[last][i] != 0){
            visited[i] = true;
            dfs(L+1,i,n,sum+arr[last][i]);
            visited[i] = false;
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> arr[i][j];
        }
    }
    dfs(1,1,n,0);
    cout << ans;
}