#include "bits/stdc++.h"

using namespace std;

int domino[101][101];
char state[101][101];
int ans;
int n, m, r;
int dx[] = {0, 1, -1, 0}; // 동 남 북 서
int dy[] = {1, 0, 0, -1};

int getDirection(char ch) {
    if (ch == 'E') return 0;
    if (ch == 'S') return 1;
    if (ch == 'N') return 2;
    return 3;
}

void fallDomino(int x, int y, int dir) {
    int height = domino[x][y];
    int nx = x;
    int ny = y;
    while (height) {
        if (nx < 1 || nx > n || ny < 1 || ny > m) break;
        if (state[nx][ny] == 'S') {
            ans++;
            state[nx][ny] = 'F';
            height = max(height, domino[nx][ny]);
        }
        nx += dx[dir];
        ny += dy[dir];
        height--;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> r;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> domino[i][j];
            state[i][j] = 'S';
        }
    }
    int offenseX, offenseY, defenseX, defenseY;
    char ch;
    for (int i = 0; i < r; ++i) {
        cin >> offenseX >> offenseY >> ch;
        cin >> defenseX >> defenseY;
        int dir = getDirection(ch);
        if (state[offenseX][offenseY] == 'S') fallDomino(offenseX, offenseY, dir);
        state[defenseX][defenseY] = 'S';
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << state[i][j] << ' ';
        }
        cout << '\n';
    }
}