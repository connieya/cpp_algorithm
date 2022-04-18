#include "bits/stdc++.h"

using namespace std;

vector<int> graph[200001];
bool visited[200001];
int ans = 0;
string s;

int dfs(int start, int prev) { // 트리 구조일때만 가능
    int count = 0;
    for (int nxt: graph[start]) {
        if (nxt == prev) continue;
        if (s[nxt - 1] == '1') {
            count++;
            continue;
        }
        visited[nxt] = true;
        count += dfs(nxt, start);
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int e;
    cin >> e;
    cin >> s;
    for (int i = 0; i < e - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= e; ++i) {
        if (s[i - 1] == '0' && !visited[i]) {
            visited[i] = true;
            int c = dfs(i, i);
            ans += c * (c - 1);
        } else if(s[i-1] == '1'){
            for (int nxt: graph[i]) {
                if (s[nxt - 1] == '1') {
                    ans++;
                }
            }
        }
    }
    cout << ans;
}