#include "bits/stdc++.h"

using namespace std;

int graph[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> graph[i][j];
        }
    }
    for (int k = 1; k <=n ; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                // i번 정점 -> j번 정점으로 경로가 있는지 확인
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
                // i번 정점에서 -> k번 정점으로 그리고 k번 정점에서 -> j번 정점으로  연결 되어 있으면 ,i번 정점에서 j 번 정점은 연결되어 있다.
                // ( 1<= k <=n  모든 정점을 탐색해서 확인)
            }
        }

    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
}