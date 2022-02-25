#include "bits/stdc++.h"

using namespace std;

int forest[1001][1001];
int dis[1001][1001][2];
int w, h, ans = 2147000;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


void init(int h, int w) {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            for (int k = 0; k < 2; ++k) {
                dis[i][j][k] = -1;
            }
        }
    }
}

bool OOP(int nx, int ny) {
    return nx < 0 || nx >= h || ny < 0 || ny >= w;
}

void bfs(int x, int y , int index) {
    queue<pair<int,int>> Q;
    dis[x][y][index] = 0;
    Q.push({x, y});
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        int x = cur.first;
        int y = cur.second;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (OOP(nx, ny)) continue;
            if (forest[nx][ny] != 1 && dis[nx][ny][index] == -1) {
                dis[nx][ny][index] = dis[x][y][index] + 1;
                Q.push({nx, ny});
            }
        }
    }
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> w >> h;
    pair<int, int> yh;
    pair<int, int> gs;
    vector<pair<int,int>> k_dis;
    init(h, w);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> forest[i][j];
            if (forest[i][j] == 2) {
                yh.first = i;
                yh.second = j;
            }
            if (forest[i][j] == 3) {
                gs.first = i;
                gs.second = j;
            }
            if (forest[i][j] == 4) {
                k_dis.push_back({i,j});
            }
        }
    }
    bfs(yh.first,yh.second,1);
    bfs(gs.first, gs.second,0);
    int len = k_dis.size();
    for (int i = 0; i < len; ++i) {
        int x = k_dis[i].first;
        int y = k_dis[i].second;
        if (dis[x][y][0] == -1 || dis[x][y][1] == -1) continue;
        ans = min(ans , dis[x][y][0]+dis[x][y][1]);
    }
    cout << ans;
}