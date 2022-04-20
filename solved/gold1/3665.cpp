#include "bits/stdc++.h"

using namespace std;

bool graph[501][501];
int indegree[501];
int arr[501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        // 초기화 작업을 같이 하자
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
            indegree[i] = 0;
            for (int j = 1; j <= n; ++j) {
                graph[i][j] = false;
            }
        }
        for (int i = 1; i <= n; ++i) {
            int from = arr[i];
            for (int j = i + 1; j <= n; ++j) {
                int to = arr[j];
                graph[from][to] = true;
                indegree[to]++;
            }
        }
        int m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            if (graph[a][b]) {
                graph[a][b] = false;
                graph[b][a] = true;
                indegree[a]++;
                indegree[b]--;
            } else { // graph[b][a] == true
                graph[b][a] = false;
                graph[a][b] = true;
                indegree[b]++;
                indegree[a]--;
            }

        }
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        bool flag = false;
        while (!q.empty()) {
            if (q.size() > 1) {
                flag = true;
                break;
            }
            int c = q.front();
            ans.push_back(c);
            q.pop();
            for (int i = 1; i <= n; ++i) {
                if (graph[c][i]) {
                    indegree[i]--;
                    if (indegree[i] == 0) {
                        q.push(i);
                    }
                }
            }
        }
        if (ans.size() == n) {
            for (int a: ans) {
                cout << a << ' ';
            }
            cout << '\n';
        } else if (flag) {
            cout << "?" << '\n';
        } else {
            cout << "IMPOSSIBLE" << '\n';
        }
    }

}