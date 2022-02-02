#include "bits/stdc++.h"

using namespace std;

int roma[4] = {1, 5, 10, 50};
bool visited[1001];
int ans = 0;

void dfs(int L, int start, int sum, int n) {
    if (L == n) {
        if (!visited[sum]) {
            visited[sum] = true;
            ans++;
        }
        return;
    }
    for (int i = start; i < 4; ++i) {
        dfs(L + 1, i, sum + roma[i], n);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    dfs(0, 0, 0, n);
    cout << ans;
}