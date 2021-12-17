#include "stdio.h"
#include "algorithm"
#include "queue"
using namespace std;
int miro[100][100];
bool visit[100][100];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int main(void) {
    int n, m;
    char str[100];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", str);
        for (int j = 0; j < m; ++j) {
            miro[i][j] = str[j] - '0';
        }
    }
    queue<pair<int , int>> queue;
    queue.push({0,0});
    visit[0][0] = 1;
    while (!queue.empty()){
        auto cur = queue.front();
        queue.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;
            if(nx >=0 && nx < n && ny >=0 && ny <m && !visit[nx][ny] && miro[nx][ny]){
                visit[nx][ny] =1;
                miro[nx][ny] = miro[cur.first][cur.second] +1;
                queue.push({nx,ny});
            }
        }
    }
    printf("%d",miro[n-1][m-1]);
}