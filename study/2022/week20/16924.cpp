#include "bits/stdc++.h"

using namespace std;

bool check[105][105];
vector<string> board(101);
int n, m;
vector<tuple<int, int, int>> ans;

void checkCross(int x, int y) {
    int cnt = 1;
    int size = 0;
    while (1){
        if(x+cnt >= n || x-cnt < 0 || y+cnt >= m || y-cnt < 0 ) break;
        if(board[x+cnt][y] == '.' || board[x-cnt][y] =='.' || board[x][y+cnt] == '.' || board[x][y-cnt] == '.') break;
        size = cnt;
        cnt++;
    }
    if (!size) return;
    check[x][y] = true;
    for (int i = 1; i <= size; ++i) {
        ans.push_back({x+1, y+1, i});
        check[x + i][y] = 1;
        check[x][y + i] = 1;
        check[x - i][y] = 1;
        check[x][y - i] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == '*') {
                checkCross(i, j);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == '*' && !check[i][j]) {
                cout << -1;
                exit(0);
            }
        }
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        int x, y, len;
        tie(x, y, len) = ans[i];
        cout << x << ' ' << y << ' ' << len << '\n';
    }


}