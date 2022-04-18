#include "bits/stdc++.h"

using namespace std;
int board[21][21];
int h, w;
int coverType[4][3][2] =
        {
                {{0, 0}, {1, 0}, {0, 1}},
                {{0, 0}, {0, 1}, {1, 1}},
                {{0, 0}, {1, 0}, {1, 1}},
                {{0, 0}, {1, 0}, {1, -1}}
        };

bool setting(int x, int y, int type, int delta) {
    bool ok = true;
    for (int i = 0; i < 3; ++i) {
        int nx = x + coverType[type][i][0];
        int ny = y + coverType[type][i][1];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
            ok = false;
        } else if ( (board[nx][ny] += delta) > 1) {
            ok = false;
        }
    }
    return ok;
}

int cover() {
    int x = -1;
    int y = -1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (board[i][j] == 0) {
                x = i;
                y = j;
                break;
            }
        }
        if (y != -1) break;
    }
    if (y == -1) return 1;
    int ret = 0;
    for (int type = 0; type < 4; ++type) {
        if (setting(x, y, type, 1)) {
            ret += cover();
        }
        setting(x, y, type, -1);
    }
    return ret;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    string str;
    cin >> t;
    while (t--) {
        cin >> h >> w;
        for (int i = 0; i < h; ++i) {
            cin >> str;
            int len = str.length();
            for (int j = 0; j < len; ++j) {
                if (str[j] == '#') {
                    board[i][j] = 1;
                }
            }
        }
        cout << cover() << '\n';
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                board[i][j] = 0;
            }
        }
    }
}