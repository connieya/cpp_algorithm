#include "bits/stdc++.h"
#define INF 1e9

using namespace std;

int laboratory[51][51];
int state[51][51];
int temp[11];
int n,m, ans = INF;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
vector<pair<int,int>> virus;

void init(){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (laboratory[i][j] == 1){
                state[i][j] = -2;
            }else {
                state[i][j] = -1;
            }
        }
    }
}

int countMinTime(){
    int result = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (state[i][j] == -1) return -1;
            if (state[i][j] == -2) continue;
            result = max(result,state[i][j]);
        }
    }
    return result;
}

int bfs(){
    init();
    queue<pair<int,int>> Q;
    for (int i = 0; i < m; ++i) {
        int x = virus[temp[i]].first;
        int y = virus[temp[i]].second;
        state[x][y] = 0;
        Q.push({x,y});
    }
    while (!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >=n || ny < 0 || ny >=n) continue;
            if (laboratory[nx][ny] != 1 && state[nx][ny] == -1){
                state[nx][ny] = state[x][y]+1;
                Q.push({nx,ny});
            }
        }
    }

    return countMinTime();
}

void put_virus(int L ,int start) {
    if (L == m){
        int res = bfs();
        if (res == -1) return;
        ans = min(res,ans);
        return;
    }

    for (int i = start; i < virus.size(); ++i) {
        temp[L] = i;
        put_virus(L+1,i+1);
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> laboratory[i][j];
            if (laboratory[i][j] == 2){
                virus.push_back({i,j});
            }
        }
    }
    put_virus(0,0);
    if (ans == INF){
        cout << -1;
    }else {
        cout << ans;
    }
}