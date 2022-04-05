#include "bits/stdc++.h"
#define INF 1e8
using namespace std;

int arr[16];
bool visited[16];
int ans;
int l,r,x;

void dfs(int L, int len) {
    if (L == len) {
        int cnt = 0;
        int sum = 0;
        int min_v = INF;
        int max_v = 0;
        for (int i = 0; i < len; ++i) {
            if (visited[i]) {
                sum+= arr[i];
                cnt++;
                min_v = min(min_v,arr[i]);
                max_v = max(max_v,arr[i]);
            }
        }
        if (cnt < 2) return;
        if (sum >= l && sum <= r && max_v-min_v >= x){
            ans++;
        }
        return;
    }

    visited[L] = true;
    dfs(L + 1, len);
    visited[L] = false;
    dfs(L + 1, len);

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    dfs(0, n);
    cout << ans;
}