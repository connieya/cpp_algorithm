#include "bits/stdc++.h"
#define MAX 100001

using namespace std;

vector<int> city[MAX];
bool visited[MAX];
int MX;
void dfs(int start , int L){
    if (L > MX) MX = L;
    visited[start] = true;
    for (int nxt : city[start]) {
        if (!visited[nxt]){
            dfs(nxt , L+1);
        }
    }
    visited[start] = false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        city[a].push_back(b);
        city[b].push_back(a);
    }
    int ans = MAX;
    for (int i = 1; i <= n; ++i) {
        MX = -1;
        dfs(i,0);
        ans = min(ans,MX);
    }
    cout << ans;
}