#include "bits/stdc++.h"

using namespace std;
#define X first
#define Y second // pair 에서 first , second를 줄여서 쓰기 위해서 사용

int board[502][502] =
        {{1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
         {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
         {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
         {1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
         {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}; // 1이 파란 칸, 0이 빨간 칸에 대응

bool visit[502][502];
int n = 7 , m = 10; // 행의 수 , 열의 수
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>> queue;
    visit[0][0] = 1;
    queue.push({0,0});
    while (!queue.empty()) {
        pair<int , int> cur = queue.front();
        queue.pop();
        cout << '(' << cur.X << "," << cur.Y << ") -> ";
        for (int i = 0; i < 4; ++i) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >=n || ny < 0 || ny >= m ) continue;
            if (visit[nx][ny] || board[nx][ny] != 1) continue;
            visit[nx][ny] = 1;
            queue.push({nx,ny});
        }
    }
}