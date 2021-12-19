#include "bits/stdc++.h"

using namespace std;

int board[502][502] =
        {
                {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
                {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
                {1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
                {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        }; // 1이 파란칸, 0이 빨간 칸에 대응

bool visited[502][502];
int n = 7, m = 10;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<pair<int , int>> S;
    visited[0][0] =1;
    S.push({0,0});
    while (!S.empty()) {
        auto cur =S.top(); S.pop();
        cout << '(' << cur.first << ',' << cur.second << ") ->";
        for (int i = 0; i < 4; ++i) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
            if(visited[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
            visited[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
            S.push({nx,ny});
        }
     }
}