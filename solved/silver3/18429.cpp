#include "bits/stdc++.h"

using namespace std;

int n,k,ans =0;
int kit[9];
bool visited[9];

void dfs(int L , int weight) {
    if (weight < 500) return;
    if (L == n) {
        ans++;
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]){
            visited[i] = true;
            dfs(L+1,weight+kit[i]-k);
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> kit[i];
    }
    dfs(0,500);
    cout << ans;
}