#include "bits/stdc++.h"

using namespace std;
int n;
int dist[11][11];
bool visited[11];

int shortestPath(int sum, int L, int start) {
    if (L == n) {
        if (dist[start][0] == 0) return -1;
        return sum + dist[start][0];
    }

    int ret = INT_MAX;
    for (int next = 1; next < n; ++next) {
        if (dist[start][next] == 0 || visited[next]) continue;
        visited[next] = true;
        int cand = shortestPath(sum + dist[start][next], L + 1, next);
        if (cand != 1) {
            ret = min(ret, cand);
        }
        visited[next] = false;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
        }
    }
    cout << shortestPath(0, 1,0);

}