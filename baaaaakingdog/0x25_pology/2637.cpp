#include "bits/stdc++.h"

using namespace std;

vector<pair<int, int>> graph[101];
int indegree[101];
int part[101];
int isBasic[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    queue<int> Q;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int big, small, cnt;
        cin >> big >> small >> cnt;
        indegree[small]++;
        isBasic[big]++;
        graph[big].push_back({small, cnt});
    }
    // 기본 부품 개수 계산
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            Q.push(i);
        }
    }
    part[n] =1;
    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        for (auto nxt: graph[now]) {
//            cout << nxt.first << ' ';
            indegree[nxt.first]--;
            if (indegree[nxt.first] == 0) {
                Q.push(nxt.first);

            }
            part[nxt.first] += part[now]*nxt.second;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (isBasic[i] == 0){
            cout  << i << ' ' <<  part[i] << '\n';
        }

    }
}