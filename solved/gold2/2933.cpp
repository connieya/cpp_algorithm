#include "bits/stdc++.h"

using namespace std;

char cave[101][101];
bool cluster[101][101];
vector<int> stick;
vector<pair<int, int>> air;
int R, C;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool comp(const pair<int, int> a, const pair<int, int> b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}

void init() {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cluster[i][j] = false;
        }
    }
}


void print_result() {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << cave[i][j];
        }
        cout << '\n';
    }
}

bool throw_stick(int height, bool flag) {
    height = R - height;
    if (flag) {
        for (int i = 0; i < C; ++i) {
            if (cave[height][i] == 'x') {
                cave[height][i] = '.';
                return true;
            }
        }
    } else {
        for (int i = C - 1; i >= 0; --i) {
            if (cave[height][i] == 'x') {
                cave[height][i] = '.';
                return true;
            }
        }
    }
    return false;
}

int remake_cave(int x, int y) {
    int i;
    int cnt = 0;
    for (i = x + 1; i < R; ++i) {
        if (cave[i][y] == 'x') {
            if (!cluster[i][y]) return 2147000;
            return cnt;

        } else if (cave[i][y] == '.') {
            cnt++;
        }
    }
    return cnt;
}

void checkAirCluster() {
    air.clear();
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (!cluster[i][j] && cave[i][j] == 'x') {
                air.push_back({i, j}); // 공중에 떠 있는 클러스터;
            }
        }
    }
    int len = air.size();
    if (len == 0) {
        return;
    }
    sort(air.begin(), air.end(), comp);
    int idx;
    int min_value = INT_MAX;
    for (int i = 0; i < len; ++i) {
        idx = remake_cave(air[i].first, air[i].second);
        min_value = min(min_value, idx);
    }
    for (int i = 0; i < len; ++i) {
        int x = air[i].first;
        int y = air[i].second;
        cave[x][y] = '.';
        cave[x + min_value][y] = 'x';
    }
}

void bfs() {
    queue<pair<int, int>> Q;
    init();
    for (int i = 0; i < C; ++i) {
        if (cave[R - 1][i] == 'x' && !cluster[R - 1][i]) {
            Q.push({R - 1, i});
            cluster[R - 1][i] = true;
        }
    }
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (cave[nx][ny] == 'x' && !cluster[nx][ny]) {
                cluster[nx][ny] = true;
                Q.push({nx, ny});
            }
        }
    }
}

void solve() {
    int len = stick.size();
    bool dir = false;
    for (int i = 0; i < len; ++i) {
        if (i % 2 == 0) {
            dir = true;
        } else {
            dir = false;
        }
        if (!throw_stick(stick[i], dir))continue;
        bfs();
        checkAirCluster();
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k, height;
    cin >> R >> C;
    for (int i = 0; i < R; ++i) {
        cin >> cave[i];
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> height;
        stick.push_back(height);
    }
    solve();
    print_result();
}