#include "stdio.h"
#include "queue"

using namespace std;

int iceberg[300][300]; // 초기 빙산
int nx_iceberg[300][300]; // n년 후 빙산
bool visited[300][300]; // 방문 여부와 빙산 덩어리를 계산하기 위한 배열

int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int countIceberg();

void bfs(int, int);

void melting(int, int);

int main(void) {
    scanf("%d %d", &n, &m);
    int ans = 0;
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &iceberg[i][j]);
        }
    }
    while (true) {
        int cnt = countIceberg();
        if (cnt >= 2) {
            flag = true;
            break;
        }
        if (cnt == 0) {
            break;
        }
        ans++;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (iceberg[i][j] > 0) {
                    melting(i, j);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                iceberg[i][j] = nx_iceberg[i][j];
            }
        }
    }
    if (flag) {
        printf("%d", ans);
    } else {
        printf("0");
    }
}

int countIceberg() {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (iceberg[i][j] > 0 && !visited[i][j]) {
                cnt++;
                visited[i][j] = true;
                bfs(i, j);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            visited[i][j] = false;
        }
    }
    return cnt;
}

void bfs(int x, int y) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && iceberg[nx][ny] > 0) {
                visited[nx][ny] = true;
                Q.push({nx, ny});
            }
        }
    }
}

void melting(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (iceberg[nx][ny] <= 0) {
            cnt++;
        }
    }
    nx_iceberg[x][y] = iceberg[x][y] - cnt;
}