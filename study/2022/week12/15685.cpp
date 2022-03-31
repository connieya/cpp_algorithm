#include "bits/stdc++.h"

using namespace std;

int board[101][101];
vector<int> dragon;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int x,y,d,g;
void dragon_curve() {
    int len = dragon.size();
    for (int i = len - 1; i >= 0; --i) {
        int dir = (dragon[i] + 1) % 4;
        x = x + dx[dir];
        y = y + dy[dir];
        board[x][y] = 1;
        dragon.push_back(dir);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> y >> x >> d >> g;
        dragon.clear();
        board[x][y] = 1;
        x = x + dx[d];
        y = y + dy[d];
        board[x][y] = 1;
        dragon.push_back(d);
        for (int j = 0; j < g; ++j) {
            dragon_curve();
        }
    }
    int ans = 0;
    for (int i = 0; i < 101; ++i) {
        for (int j = 0; j < 101; ++j) {
            if (board[i][j]  && board[i + 1][j]  && board[i][j + 1] && board[i + 1][j + 1] ) {
                ans++;
            }
        }
    }
    cout << ans;

}