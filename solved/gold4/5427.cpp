#include "bits/stdc++.h"

using namespace std;

int t, n, m;
char building[1001][1001];
int escape[1001][1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
queue<pair<int, int>> fire;
queue<pair<int, int>> person;
int a,b;

void moveFire() {
    while (!fire.empty()) {
        int x = fire.front().first;
        int y = fire.front().second;
        fire.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || building[nx][ny] == '#') continue;
            if (escape[nx][ny] == -1) {
                escape[nx][ny] = escape[x][y] + 1;
                fire.push({nx, ny});
            } else {
                if (escape[x][y] + 1 < escape[nx][ny]) {
                    escape[nx][ny] = escape[x][y] + 1;
                    person.push({nx, ny});
                }
            }
        }
    }
}

bool movePerson() {
    while (!person.empty()) {
        a = person.front().first;
        b= person.front().second;
        person.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                return true;
            }
            if (building[nx][ny] == '#') continue;
            if (escape[nx][ny] == -1) {
                escape[nx][ny] = escape[a][b] + 1;
                person.push({nx, ny});
            } else {
                if (escape[a][b] + 1 < escape[nx][ny]) {
                    escape[nx][ny] = escape[a][b] + 1;
                    person.push({nx, ny});
                }
            }

        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    string input;
    while (t--) {
        cin >> n >> m;
        while (!person.empty()){
            person.pop();
        }
        for (int i = 0; i < m; ++i) {
            cin >> input;
            for (int j = 0; j < n; ++j) {
                building[i][j] = input[j];
                escape[i][j] = -1;
                if (building[i][j] == '*') {
                    escape[i][j] = 0;
                    fire.push({i, j});
                } else if (building[i][j] == '@') {
                    escape[i][j] = 0;
                    person.push({i, j});
                }
            }
        }
        moveFire();
        if (movePerson()) {
            cout << escape[a][b] + 1 << '\n';
        }else {
            cout << "IMPOSSIBLE" << '\n';
        }
    }
}