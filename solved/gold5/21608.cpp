#include "bits/stdc++.h"

using namespace std;

int n;
int board[21][21];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
unordered_map<int, vector<int>> mp;


vector<pair<int, int>> solve(int num) {
    vector<pair<int, int>> v;
    vector<int> list = mp[num];
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j]) continue;
            int like = 0;
            for (int k = 0; k < 4; ++k) {
                int nx = dx[k] + i;
                int ny = dy[k] + j;
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (find(list.begin(), list.end(), board[nx][ny]) != list.end()) {
                    like++;
                }
            }
            if(like > cnt){
                v.clear();
                cnt = like;
                v.push_back({i,j});
            }else if(like == cnt){
                v.push_back({i,j});
            }
        }
    }
    if(v.size() == 1) return v;
    cnt = 0;
    vector<pair<int,int>> res;
    for (int i = 0; i < v.size(); ++i) {
        int x = v[i].first;
        int y = v[i].second;
        int empty = 0;
        for (int j = 0; j < 4; ++j) {
            int nx = x +dx[j];
            int ny = y +dy[j];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(!board[nx][ny]) empty++;
        }
        if(empty > cnt){
            res.clear();
            res.push_back({x,y});
            cnt = empty;
        }else if(empty == cnt){
            res.push_back({x,y});
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int num;
    vector<int> students;
    int score[] = {0,1,10,100,1000};
    for (int i = 0; i < n * n; ++i) {
        cin >> num;
        students.push_back(num);
        vector<int> list(4);
        for (int j = 0; j < 4; ++j) {
            cin >> list[j];
        }
        mp[num] = list;
    }
    for (int i = 0; i < students.size(); ++i) {
        int student = students[i];
        auto res = solve(student);
        board[res[0].first][res[0].second] = student;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            vector<int> list = mp[board[i][j]];
            int cnt = 0;
            for (int k = 0; k < 4; ++k) {
                int nx = dx[k]+i;
                int ny = dy[k]+j;
                if(nx < 0 || nx >=n || ny < 0 || ny >=n) continue;
                if(find(list.begin(),list.end(),board[nx][ny]) != list.end()){
                    cnt++;
                }
            }
            ans += score[cnt];

        }
    }
    cout << ans;
}