#include "bits/stdc++.h"

using namespace std;

int arr[11];
vector<int> graph[11];
int n, ans = INT_MAX;

bool check(vector<int> &v) {
    bool visited[11] = {false,};
    int len = v.size();
    queue<int> Q;
    Q.push(v[0]);
    visited[v[0]] = true;
    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        for (int next: graph[now]) {
            if (!visited[next] && binary_search(v.begin(), v.end(), next)) {
                visited[next] = true;
                Q.push(next);
            }
        }
    }
    for (int i = 0; i < len; ++i) {
        if (!visited[v[i]]) return false;
    }
    return true;
}

int calc(vector<int> &v1, vector<int> &v2) {
    int ret = 0;
    for (auto v: v1) {
        ret += arr[v];
    }
    for (auto v: v2) {
        ret -= arr[v];
    }
    return ret < 0 ? -ret : ret;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        while (t--) {
            int v;
            cin >> v;
            graph[i].push_back(v - 1);
        }
    }
    for (int bit = 1; bit < (1 << n) - 1; ++bit) {
        vector<int> v1, v2;
        for (int i = 0; i < n; ++i) {
            if (bit & 1 << i) {
                v1.push_back(i);
            } else {
                v2.push_back(i);
            }
        }
        if (check(v1) && check(v2)) {
            ans = min(ans, calc(v1, v2));
        }
    }
    cout << (ans == INT_MAX ? -1 : ans) << '\n';
}