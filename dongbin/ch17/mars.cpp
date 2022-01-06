#include "bits/stdc++.h"
#define INF 1e7
using namespace std;

int arr[125][125];
int dis[125][125];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> arr[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            fill(dis[i],dis[i]+n,INF);
        }
        priority_queue<pair<int , pair<int , int>>> pq;
        pq.push({-arr[0][0] , {0,0}});
        dis[0][0] = arr[0][0];
        while (!pq.empty()) {
            int now_cost = -pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if (dis[x][y] < now_cost) continue;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >=n || ny < 0 || ny>=n) continue;
                int next_cost = now_cost + arr[nx][ny];
                if (dis[nx][ny] > next_cost){
                    dis[nx][ny] = next_cost;
                    pq.push({-next_cost , {nx,ny}});
                }
            }
        }
        cout << dis[n-1][n-1] << '\n';
    }
}