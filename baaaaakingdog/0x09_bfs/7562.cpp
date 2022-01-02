#include "stdio.h"
#include "queue"

using namespace std;

queue<pair<int, int>> Queue;
int dx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[] = {-1, 1, 2, 2, 1, -1, -2, -2};

int main(void) {
    int t, n, x1, y1, x2, y2;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        int board[300][300] = {0};
        bool visited[300][300] = {false};
        scanf("%d %d",&x1,&y1);
        scanf("%d %d",&x2,&y2);
        visited[x1][y1] = true;
        Queue.push({x1, y1});
        while (!Queue.empty()) {
            auto cur = Queue.front();
            Queue.pop();
            for (int i = 0; i < 8; ++i) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    board[nx][ny] = board[cur.first][cur.second] +1;
                    Queue.push({nx,ny});
                }
            }
        }
        printf("%d\n",board[x2][y2]);
    }
}