#include "bits/stdc++.h"

using namespace std;

int n, m, d, res;
int board[16][16];
int temp[16][16];
bool visited[16][16];
vector<pair<int, int>> target;

typedef struct {
    int x;
    int y;
    int dist;
} Info;

void copy() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            temp[i][j] = board[i][j];
        }
    }
}

bool comp(Info a, Info b) {
    if (a.dist <= b.dist) {
        if (a.dist == b.dist) {
            if (a.y < b.y) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

void move_row() {
    for (int i = n - 1; i >= 1; --i) {
        for (int j = 0; j < m; ++j) {
            temp[i][j] = temp[i - 1][j];
        }
    }
    for (int i = 0; i < m; ++i) {
        temp[0][i] = 0;
    }
}

int attack() {
    int ans = 0;
    bool flag;
    copy();
    while (1) {
        flag = true;
        memset(visited, false, sizeof(visited));
        for (int k = 0; k < 3; ++k) {
            int x = target[k].first;
            int y = target[k].second;
            vector<Info> v;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (!temp[i][j]) continue;
                    int distance = abs(i - x) + abs(j - y);
                    if (distance <= d) {
                        Info info;
                        info.x = x;
                        info.y = y;
                        info.dist = distance;
                        v.push_back(info);
                    }
                }
            }
            sort(v.begin(), v.end(), comp);
            if (v.size()) {
                visited[v[0].x][v[0].y] = true;
                flag = false;
            }
        }
        if (flag) break;
        for (int i = 0; i <n ; ++i) {
            for (int j = 0; j < m; ++j) {
                if(visited[i][j]){
                    ans++;
                    temp[i][j] = 0;
                }
            }
        }
        move_row();
    }
    return ans;
}

void dfs(int L, int x, int y) {
    if (L == 3) {
        int a = attack();
        res = max(a, res);
        return;
    }
    if (x == n) {
        return;
    }
    if (y == m) {
        x++;
        y = 0;
    }

    for (int i = x; i < n; ++i) {
        for (int j = y; j < m; ++j) {
            target.push_back({i, j});
            dfs(L + 1, i, j + 1);
            target.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> d;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    dfs(0, 0, 0);
    cout << res;
}