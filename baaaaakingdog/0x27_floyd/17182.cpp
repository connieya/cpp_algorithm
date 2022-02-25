#include "bits/stdc++.h"

using namespace std;

int arr[10][10];
bool checked[10];
int ans = 214700;
void dfs(int index , int L , int sum, int n) {
    if (L == n-1){
        ans = min(ans,sum);
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (checked[i]) continue;
        checked[i] = true;
        dfs(i,L+1,sum+arr[index][i],n);
        checked[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , start;
    cin >> n >> start;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (arr[i][j] > arr[i][k]+arr[k][j]) {
                    arr[i][j] = arr[i][k]+arr[k][j];
                }
            }
        }
    }
    checked[start] = true;
    dfs(start,0,0,n);
    cout << ans;


}