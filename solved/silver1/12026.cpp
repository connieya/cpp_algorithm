#include "bits/stdc++.h"

#define INF 21470000000
using namespace std;

long long ans = INF;
int n;
long long dp[10001];
char boj[] = {'B', 'O', 'J'};
string str;

void dfs(int start, int idx, long long sum) {
    if (start == n - 1) {
        if (ans > sum) {
            ans = sum;
        }
        return;
    }
    int nxt_idx = (idx + 1) % 3;
    char nxt = boj[nxt_idx];
    for (int i = start + 1; i < n; ++i) {
        if (str[i] == nxt && dp[i] >=  sum + (i - start) * (i - start)) {
            dp[i] = sum + (i - start) * (i - start);
            dfs(i, nxt_idx, sum + (i - start) * (i - start));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> str;
    for (int i = 0; i < n; ++i) {
        dp[i] = 21470000000;
    }
    dfs(0, 0, 0);
    if (ans == INF) {
        cout << -1;
    } else {
        cout << ans;
    }
}
