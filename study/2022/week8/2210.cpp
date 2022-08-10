#include "bits/stdc++.h"

using namespace std;


int arr[5][5];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
unordered_set<int> s;

void dfs(int l ,int x ,int y , int sum){
    if(l==5){
        s.insert(sum);
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int nx = x +dx[i];
        int ny = y+ dy[i];
        if(nx <0 || nx>=5 || ny < 0 || ny >=5) continue;
        dfs(l+1, nx, ny , sum*10+arr[nx][ny]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            dfs(0,i,j,arr[i][j]);
        }
    }

    cout << s.size();

}