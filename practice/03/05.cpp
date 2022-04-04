#include "bits/stdc++.h"

using namespace std;

int board[101][101];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

typedef struct Room {
    int x;
    int y;
    int dir;
    int cnt;
    Room(int nx ,int ny , int d , int c) {
        x = nx;
        y = ny;
        dir = d;
        cnt = c;
    }
    bool operator<(const Room &r)const {
        return cnt > r.cnt;
    }

} ROOM;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n ,tomX,tomY,jerryX,jerryY;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> board[i][j];
            if (!board[i][j]){
                board[i][j] = -1;
            }
        }
    }
    cin >> tomX >> tomY >> jerryX >> jerryY;
    board[tomX][tomY] = 0;
    priority_queue<ROOM> Q;
    Q.push(ROOM(tomX,tomY,-1,0));
    int ans = -1;
    while (!Q.empty()) {
        int len = Q.size();
        for (int i = 0; i < len; ++i) {
            auto cur = Q.top();
            Q.pop();
            int x = cur.x;
            int y = cur.y;
            int cnt = cur.cnt;
            cout << x << ' ' << y << " direction = " << cur.dir << " cnt = >" << cnt << '\n';
            if (x == jerryX && y == jerryY) {
                ans = cur.cnt-1;
                break;
            }
            for (int i = 0; i < 4; ++i) {
                int nx = x +dx[i];
                int ny = y +dy[i];
                if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
                if (board[nx][ny] == -1) {
                    board[nx][ny] = board[x][y] +1;
                    if (cur.dir != i){
                        Q.push(ROOM(nx,ny,i,cnt+1));
                    }else {
                        Q.push(ROOM(nx,ny,i,cnt));
                    }

                }
            }
        }

    }
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= n; ++j) {
//            cout << board[i][j] << ' ';
//        }
//        cout << '\n';
//    }
    if (ans == -1) {
        cout << -1;
    }else {
        cout << ans;
    }
//    cout << "answer ======" << ans;
}