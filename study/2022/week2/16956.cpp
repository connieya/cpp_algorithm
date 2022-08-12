#include "bits/stdc++.h"

using namespace std;

int r, c;
char board[501][501];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};


bool check(int x, int y){
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= r || ny <0 || ny >=c) continue;
        if(board[nx][ny] == 'S') return true;
    }
    return false;
}




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<pair<int,int>> wolf;
    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> board[i][j];
            if(board[i][j] == 'W'){
                wolf.push_back({i,j});
            }
        }
    }

    for(auto w : wolf){
        if(check(w.first,w.second)){
            cout << 0;
            exit(0);
        }
    }

    cout << 1 << '\n';
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
           cout << ( board[i][j] == '.' ? 'D' : board[i][j]);
        }
        cout << '\n';
    }
}