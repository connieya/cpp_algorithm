#include "bits/stdc++.h"

using namespace std;

vector<int> V[1001];

int dfs(int cur) {

    int res = 1;
    for (int next : V[cur]) {
        res = max(res , dfs(next)+1);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >>m;
    for (int i = 0; i < m; ++i) {
        int a ,b;
        cin >> a >>b;
        V[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        cout << dfs(i) << ' ';
    }
}