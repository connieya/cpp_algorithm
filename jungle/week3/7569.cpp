#include "bits/stdc++.h"

using namespace std;

int tomato[101][101][101];

int dx[] = {-1, 0, 1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dh[] = {0, 0, 0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int row, column, height,total = 0,day;
    cin >> column >> row >> height;
    queue<pair<pair<int, int>, pair<int,int>>> Q;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < row; ++j) {
            for (int k = 0; k < column; ++k) {
                cin >> tomato[j][k][i];
                if (tomato[j][k][i] == 1) {
                    Q.push({{j, k}, {i,0}});
                }else if (tomato[j][k][i] == -1){
                    total++;
                }
            }
        }
    }
    while (!Q.empty()) {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int h = Q.front().second.first;
        int cnt = Q.front().second.second;
        Q.pop();
        total++;
        day = cnt;
        for (int i = 0; i < 6; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nh = h + dh[i];
            if (nx < 0 || nx >= row || ny < 0 || ny >= column || nh < 0 || nh >= height) {
                continue;
            }
            if (tomato[nx][ny][nh] == 0) {
                tomato[nx][ny][nh] = 1;
                Q.push({{nx, ny}, {nh,cnt+1}});
            }
        }
    }
    if (total == row*column*height){
        cout << day;
    }else {
        cout << -1;
    }

}