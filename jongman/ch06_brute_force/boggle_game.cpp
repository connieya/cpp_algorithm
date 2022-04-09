#include "bits/stdc++.h"

using namespace std;

char board[5][5];
int dx[] = {0,-1,0,1,0,-1,-1,1,1};
int dy[] = {0,0,1,0,-1,-1,1,1,-1};

bool dfs(int L , int len , const string &word , int x ,int y) {
    if (L == len){
        return true;
    }
    for (int i = 0; i < 9; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx>=5 || ny < 0 || ny >=5) continue;
        if (word[L] == board[nx][ny]){
            if(dfs(L+1,len,word,nx,ny)) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> board[i][j];
        }
    }
    int t, x, y;
    string word;
    cin >> t;
    while (t--) {
        cin >> word >> x >> y;
        if (word[0] =! board[x][y]) {
            cout << 0 << '\n';
        }else {
            cout << dfs(1,word.length(),word,x,y) << '\n';
        }
    }
}