#include "bits/stdc++.h"

using namespace std;

int arr[1001];
int ans[1001];
vector<int> v[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        arr[b]++;
        v[a].push_back(b);
    }
    queue<int> Q;
    for (int i = 1; i <= n; ++i) {
        if (arr[i] == 0) {
            Q.push(i);
        }
    }
    int L = 1;
    while (!Q.empty()) {
        int len = Q.size();
        for (int i = 0; i < len; ++i) {
            int cur = Q.front();
            Q.pop();
            ans[cur] = L;
            for(int next : v[cur]) {
                arr[next]--;
                if (arr[next] == 0){
                    Q.push({next});
                }
            }

        }
        L++;
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }


}