#include "bits/stdc++.h"

using namespace std;

char board[51][51];
int dist[2502];
int d[51][51];
bool checked[2501][2501];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    memset(dist, -1, sizeof(dist));
    vector<pair<int,int>> mirrors;
    int start = -1 ,end;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
            if (board[i][j] == '#') {
                if(start == -1){
                    start = mirrors.size();
                }else {
                    end = mirrors.size();
                }
                mirrors.push_back({i,j});
                d[i][j] = mirrors.size()-1;
            }else if(board[i][j] == '!'){
                mirrors.push_back({i,j});
                d[i][j] = mirrors.size()-1;
            }
        }
    }
    int m = mirrors.size();
    for (int i = 0; i < m; ++i) {
        int x = mirrors[i].first;
        int y = mirrors[i].second;
        for (int j = 0; j < 4; ++j) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            while (nx >= 0 && nx < n && ny >=0 && ny < n && board[nx][ny] != '*'){
                if(board[nx][ny] == '!' || board[nx][ny] == '#'){
                    checked[i][d[nx][ny]] = true;
                }
                nx += dx[j];
                ny += dy[j];
            }
        }
    }
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()){
        int now = q.front();
        q.pop();
        for (int i = 0; i < m; ++i) {
            if(checked[now][i] && dist[i] == -1){
                dist[i] = dist[now]+1;
                q.push(i);
            }
        }
    }
    cout << dist[end]-1;
}