#include "stdio.h"
#include "queue"
#include "algorithm"
using namespace std;
int arr[8][8];
int temp[8][8];
int n, m  , MX = -1;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<pair<int,int>> Virus;

void virus(int x, int y) {
    queue<pair<int ,int >> Q;
    Q.push({x,y});
    while (!Q.empty()){
        auto cur = Q.front();
        Q.pop();
        for (int j = 0; j < 4; ++j) {
            int nx = dx[j] + cur.first;
            int ny = dy[j] + cur.second;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || temp[nx][ny] == 1){
                continue;
            }
            if (temp[nx][ny] == 0){
                temp[nx][ny] = 2;
                Q.push({nx,ny});
            }
        }
    }
}

void dfs(int count) {
    if (count == 3) {
        int ans =0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                temp[i][j] = arr[i][j];
            }
        }
        for (int i = 0; i < Virus.size(); ++i) {
           int x = Virus[i].first;
           int y = Virus[i].second;
            virus(x,y);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (temp[i][j] == 0){
                    ans++;
                }
            }
        }
        MX = max(MX ,ans);
        return;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] == 0) {
                arr[i][j] = 1;
                count++;
                dfs(count);
                arr[i][j] = 0;
                count--;
            }
        }
    }
}

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 2) {
                Virus.push_back({i,j});
            }
        }
    }
    dfs(0);
    printf("%d",MX);
}