#include "bits/stdc++.h"

using namespace std;

int n,m;
int board[13][13];
vector<int> chess[13][13];
vector<tuple<int,int,int>> v;
int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,1,-1,0,0};
bool isOver = false;

void turn(int x, int y ,int dir, int num) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(nx < 0 || nx >= n || ny < 0 || ny >= m){

    }
    int c = board[nx][ny];
    if(c == 0) {
        auto curr = chess[x][y];
        for(auto r  :curr){
            chess[nx][ny].push_back(r);
        }
        chess[x][y].clear();
        if(chess[nx][ny].size() >=4){
            isOver = true;
        }
        return;
    }
    if(c==1){
        reverse(chess[x][y].begin() , chess[x][y].end());
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
            cin >> board[i][j];
        }
    }
    int x,y,z;

    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> z;
        v.push_back({x-1,y-1,z});
        chess[x-1][y-1].push_back(i);
    }
    int ans = 1;
    while (ans < 1000){
        for (int i = 0; i < m; ++i) {
            int x, y ,z;
            tie(x,y,z) = v[i];
        }
        ans++
    }


}