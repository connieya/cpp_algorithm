#include "bits/stdc++.h"

using namespace std;

int arr[16][2];
int n;
int res = -1;

void dfs(int start, int sum) {
    if (start == n + 1) {
        res = max(res, sum);
        return;
    }
    if (start + arr[start][0] <= n + 1) {
        dfs(start+arr[start][0] , sum + arr[start][1]);
    }
    dfs(start+1,sum);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int t, p;
        cin >> t >> p;
        arr[i][0] = t;
        arr[i][1] = p;
    }
    dfs(1,0);
    cout << res;
}