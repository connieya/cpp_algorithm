#include "bits/stdc++.h"

using namespace std;

int T[5050];
int arr[11];
bool visited[11];
int ans;

void dfs(int L, int k, int n , int sum) {
    if (L == k) {
        for (int i = 0; i < ans; ++i) {
            if (T[i] == sum) return;
        }
        T[ans++] = sum;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]){
            visited[i] = true;
            if (arr[i] > 9) dfs(L+1,k,n,sum*100+arr[i]);
            else dfs(L+1,k,n,sum*10+arr[i]);
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    dfs(0,k,n,0);
    cout << ans;
}