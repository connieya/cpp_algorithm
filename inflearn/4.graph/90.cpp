#include "bits/stdc++.h"

using namespace std;

int jungle[26][26];
bool visited[26][26];
int n, ans;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct State {
    int x, y, dis;

    State(int a, int b, int c) {
        x = a;
        y = b;
        dis = c;
    }

    bool operator<(const State &bb) const {
        if (dis == bb.dis) {
            if (x == bb.x) return y > bb.y;
            return x > bb.x;
        }
        return dis > bb.dis;
    }
};

struct Lion {
    int x, y, size, ate;

    void sizeUp() {
        size++;
        ate = 0;
    }
};

void init() {
    for (int i = 0; i < n; ++i) {
        fill(visited[i], visited[i] + n, false);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    Lion simba;
    simba.ate = 0;
    simba.size = 2;
    priority_queue<State> pq;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> jungle[i][j];
            if (jungle[i][j] == 9) {
                simba.x = i;
                simba.y = j;
                jungle[i][j] = 0;
            }
        }
    }
    pq.push(State(simba.x, simba.y, 0));
    while (!pq.empty()) {
        State cur = pq.top();
        pq.pop();
        int x = cur.x;
        int y = cur.y;
        int dis = cur.dis;
        if (jungle[x][y] != 0 && jungle[x][y] < simba.size) {
            simba.x = x;
            simba.y = y;
            simba.ate++;
            if (simba.ate >= simba.size) simba.sizeUp();
            jungle[x][y] = 0;
            init();
            while (!pq.empty()) pq.pop();
            ans += cur.dis;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (!visited[nx][ny] && simba.size >= jungle[nx][ny]) {
                visited[nx][ny] = true;
                pq.push(State(nx, ny, dis + 1));
            }
        }
    }
    cout << ans;
}