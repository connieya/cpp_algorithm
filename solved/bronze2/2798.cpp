#include "bits/stdc++.h"

using namespace std;

int arr[101];
int temp[3];
int ans = 0;
int m;
void dfs(int n,int L , int start){
    if (L == 3) {
        int sum = arr[temp[0]]+arr[temp[1]]+arr[temp[2]];
        if (sum <= m && sum > ans){
            ans = sum;
        }
        return;
    }

    for (int i = start; i < n; ++i) {
        temp[L] = i;
        dfs(n,L+1,i+1);
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    dfs(n,0,0);
    cout << ans;

}