#include "bits/stdc++.h"

#define INF 1e9

using namespace std;

int laboratory[51][51];
int state[51][51];
int temp[11];
int n, m, ans = INF, spread;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<pair<int, int>> virus;

void init() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            state[i][j] = -1;
        }
    }
}


void bfs() {
    init();
    int total_time = 0;
    int infect = 0;
    queue<pair<int, int>> Q;
    for (int i = 0; i < m; ++i) {
        int x = virus[temp[i]].first;
        int y = virus[temp[i]].second;
        state[x][y] = 0;
        Q.push({x, y});
    }
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || laboratory[nx][ny] == 1) continue;
            if (state[nx][ny] == -1) {
                state[nx][ny] = state[x][y] + 1;
                if (laboratory[nx][ny] == 0) {
                    total_time = state[nx][ny];
                    infect++;
                }
                Q.push({nx,ny});
            }

        }
    }
    if (infect == spread) {
        ans = min(ans, total_time);
    }
}

void print_result() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << state[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void spreadVirus(int L, int start) {
    if (L == m) {
        bfs();
        return;
    }
    for (int i = start; i < virus.size(); ++i) {
        temp[L] = i;
        spreadVirus(L + 1, i + 1);
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> laboratory[i][j];
            if (laboratory[i][j] == 2) {
                virus.push_back({i, j});
            } else if (laboratory[i][j] == 0) {
                spread++;
            }
        }
    }
    spreadVirus(0, 0);
    if (ans == INF) {
        cout << -1;
    } else {
        cout << ans;
    }
}