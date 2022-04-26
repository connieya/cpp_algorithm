#include "bits/stdc++.h"

using namespace std;

bool visited[10001];
int dp[10001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int s;
        cin >> s;
        visited[s] = true;
    }
    dp[2] = 1;
    for (int i = 2; i <= n/2+1; ++i) {
        for (int j = 1; j <=i; ++j) {

        }
    }

}
