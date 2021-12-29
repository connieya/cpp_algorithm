#include "stdio.h"
#include "queue"
#include "vector"
#include "algorithm"
using namespace std;

int map[100][100];
bool visited[100][100];
int n;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<pair<int, int >> v;

void bfs(int x, int y, int num);

int main(void) {
    int num = 1;
    int ans = 214700;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (map[i][j] && !visited[i][j]) {
                map[i][j] = num;
                visited[i][j] = true;
                bfs(i, j, num);
                num++;
            }
        }
    }
    int tmp = 0;
    for (int i = 0; i < v.size() - 1; ++i) {
        int x1 = v[i].first;
        int y1 = v[i].second;
        for (int j = i + 1; j < v.size(); ++j) {
            int x2 = v[j].first;
            int y2 = v[j].second;
            if (map[x1][y1] != map[x2][y2]) {
                tmp = abs(x1 - x2) + abs(y1 - y2) - 1;
                ans = min(ans, tmp);
            }
        }
    }
    printf("%d",ans);
}

void bfs(int x, int y, int num) {
    queue<pair<int, int >> Q;
    Q.push({x, y});
    while (!Q.empty()) {
        bool isEdge = false;
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (map[nx][ny] && !visited[nx][ny]) {
                visited[nx][ny] = true;
                map[nx][ny] = num;
                Q.push({nx, ny});
            }
            if (!map[nx][ny]) {
                isEdge = true;
            }
        }
        if (isEdge){
            v.push_back({cur.first, cur.second});
        }
    }
}