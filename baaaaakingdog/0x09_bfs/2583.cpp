#include "stdio.h"
#include "vector"
#include "queue"
#include "algorithm"
using namespace std;

int map[100][100];

int n, m;

int bfs(int x, int y);

queue<pair<int, int>> Q;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main(void) {
    int k, y1, x1, y2, x2, cnt = 0;
    vector<int> ans;
    scanf("%d %d %d", &m, &n, &k);
    while (k--) {
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
        for (int i = m - x2; i < m - x1; i++) {
            for (int j = y1; j < y2; ++j) {
                map[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[j][i] == 0) {
                cnt++;
                ans.push_back(bfs(j, i));
            }
        }
    }
    sort(ans.begin(),ans.end());
    printf("%d\n", cnt);
    for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }
}

int bfs(int x, int y) {
    int cnt = 1;
    map[x][y] = 1;
    Q.push({x, y});
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && map[nx][ny] == 0) {
                cnt++;
                map[nx][ny] = 1;
                Q.push({nx, ny});
            }
        }
    }
    return cnt;
}