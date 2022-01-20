#include "bits/stdc++.h"

using namespace std;

vector<int> graph[10001];
vector<int> ans;
bool visited[10001];
int arr[10001];
int n, m, cnt = 0, MX = -100;

void dfs(int v) {
    visited[v] = true;
    for (int next: graph[v]) {
        if (!visited[next]) {
            cnt++;
            dfs(next);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        fill(visited, visited + 10001, false);
        cnt = 0;
        dfs(i);
        arr[i] = cnt;
        if (cnt > MX) {
            MX = cnt;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (arr[i] == MX) {
            cout << i << ' ';
        }
    }
}