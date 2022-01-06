#include "bits/stdc++.h"

using namespace std;

int result[501];
int times[501];
int degree[501];
vector<int> graph[501];
int n;
void topologySort();
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        times[i] = x;
        result[i] =x;
        while (true) {
            cin >> x;
            if (x == -1) break;
            graph[x].push_back(i);
            degree[i]++;
        }
    }
    topologySort();

    // 위상 정렬을 수행한 결과 출력
    for (int i = 1; i <= n; i++) {
        cout << result[i] << '\n';
    }
}

void topologySort() {
    queue<int> Q;
    for (int i = 1; i <= n; ++i) {
        if (!degree[i]) {
            Q.push(i);
        }
    }
    while (!Q.empty()){
        int now = Q.front();
        Q.pop();
        for (int next : graph[now]) {
            result[next] = max(result[next], times[next] + result[now]);
            degree[next]--;
            if (!degree[next]) {
                Q.push(next);
            }
        }
    }
}