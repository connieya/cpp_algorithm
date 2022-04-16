#include "bits/stdc++.h"

using namespace std;

vector<int> graph[200001];
bool visited[200001];
int ans = 0;
int cnt = 0;
string s;
void dfs(int start, int prev) { // 트리 구조일때만 가능함 !!!!!
    for (int nxt: graph[start]) {
        if (nxt == prev) continue;
        if (s[nxt-1] == '1'){
            cnt++;
            continue;
        }
        visited[nxt] = true;
        dfs(nxt, start);
    }
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
            cnt = 0;
            dfs(i, i);
            ans += cnt*(cnt-1);
        }
    }
    cnt = 0;
    for (int i = 1; i <=e ; ++i) {
        if (s[i-1] == '1'){
            for (int nxt: graph[i]) {
                if (s[nxt-1] == '1'){
                    cnt++;
                }
            }
        }
    }
    ans += cnt;
    cout << ans;
}