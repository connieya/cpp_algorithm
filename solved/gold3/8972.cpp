#include "bits/stdc++.h"

using namespace std;

char board[101][101];
int cnt[101][101];
int dx[] = {0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
int dy[] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};
int cx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int cy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int r, c;
pair<int, int> JS;
vector<pair<pair<int, int>, bool>> v;


pair<int, int> calcMinDir(int x, int y) {
    int a = JS.first;
    int b = JS.second;
    int ans = 100000;
    pair<int, int> R;
    for (int i = 0; i < 8; ++i) {
        int nx = cx[i] + x;
        int ny = cy[i] + y;
        int dir = abs(a - nx) + abs(b - ny);
        if (dir < ans) {
            ans = dir;
            R.first = nx;
            R.second = ny;
        }
    }
    return R;
}

bool moveArduino() {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cnt[i][j] = 0;
        }
    }

    int len = v.size();
    pair<int, int> R;
    for (int i = 0; i < len; ++i) {
        if (v[i].second) {
            continue;
        }
        int x = v[i].first.first;
        int y = v[i].first.second;
        R = calcMinDir(x, y);
        if (board[R.first][R.second] == 'I') return true;
        board[x][y] = '.';
        board[R.first][R.second] = 'R';
        v[i].first.first = R.first;
        v[i].first.second = R.second;
        cnt[R.first][R.second]++;

    }
    for (int i = 0; i < len; ++i) {
        int x = v[i].first.first;
        int y = v[i].first.second;
        if (cnt[x][y] > 1) {
            v[i].second = true;
            board[x][y] = '.';
        }

    }

    return false;
}

void print() {
    for (int j = 0; j < r; ++j) {
        for (int k = 0; k < c; ++k) {
            cout << board[j][k];
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> c;
    string move, input;
    for (int i = 0; i < r; ++i) {
        cin >> input;
        for (int j = 0; j < c; ++j) {
            board[i][j] = input[j];
            if (board[i][j] == 'I') {
                JS.first = i, JS.second = j;
            } else if (board[i][j] == 'R') {
                v.push_back({{i, j}, false});
            }
        }
    }
    cin >> move;
    int len = move.size();
    bool flag = false;
    int i;
    for (i = 0; i < len; ++i) {
        int dir = move[i] - '0';
        board[JS.first][JS.second] = '.';
        JS.first = JS.first + dx[dir];
        JS.second = JS.second + dy[dir];
        if (board[JS.first][JS.second] == 'R') {
            flag = true;
            break;
        } else {
            board[JS.first][JS.second] = 'I';
            if (moveArduino()) {
                flag = true;
                break;
            }
        }
        cout << dir << '\n'; print();
    }
    if (flag) {
        cout << "kraj " << ++i;
    } else {
//        print();
    }
}