#include "bits/stdc++.h"

using namespace std;

int forest[501][501];
int visited[501][501];
int ans = 0;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};


int solve(int tree, int x, int y , int n) {
    queue<pair<pair<int, int>, pair<int ,int >>> Q;
    Q.push({{x, y}, {tree,1}});
    int cnt = 0;
    int ans = 0;
    while (!Q.empty()) {
        auto cur = Q.front();
        int x = cur.first.first;
        int y = cur.first.second;
        tree = cur.second.first;
        cnt  = cur.second.second;
        ans = max(ans,cnt);
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (forest[nx][ny] <= tree) continue;
            Q.push({{nx,ny},{forest[nx][ny],cnt+1}});
        }
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , res =0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> forest[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int result = solve(forest[i][j], i, j,n);
            res = max(res,result);
        }
    }
    cout << res;
}