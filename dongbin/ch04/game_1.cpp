#include "bits/stdc++.h"

using namespace std;

int arr[51][51];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int dir;

void turn_left() {
    dir = (dir+3)%4;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, x, y;
    cin >> n >> m;
    cin >> x >> y >> dir;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }
    int ans = 1;
    arr[x][y] = 1;
    while (1) {
        int i;
        for (i = 0; i < 4; ++i) {
            turn_left();
            if (arr[x + dx[dir]][y + dy[dir]] == 0) {
                arr[x + dx[dir]][y + dy[dir]] = 1;
                x += dx[dir];
                y += dy[dir];
                ans++;
                break;
            }
        }
        if (i == 4) {
            x -= dx[dir];
            y -= dy[dir];
            if (arr[x][y] == 1) break;
        }
    }
    cout << ans;


}