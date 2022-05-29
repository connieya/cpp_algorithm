#include "bits/stdc++.h"

using namespace std;

char board[2][100001];
bool visited[2][100001];
int n, m;


bool bfs() {
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    int time = 0;
    visited[0][0] = true;
    while (!Q.empty()) {
        int len = Q.size();
        for (int i = 0; i < len; ++i) {
            auto now = Q.front();
            Q.pop();
            int dir = now.first;
            int index = now.second;
            if (index+1 >= n) return true;
            if (board[dir][index + 1] == '1' && !visited[dir][index + 1]) {
                visited[dir][index + 1] = true;
                Q.push({dir, index + 1});
            }
            if (index - 1 > time && board[dir][index - 1] == '1' && !visited[dir][index - 1]) {
                visited[dir][index - 1] = true;
                Q.push({dir, index - 1});
            }
            dir = (dir == 0) ? 1 : 0;
            if (index + m >= n) return true;
            if (board[dir][index + m] == '1' && !visited[dir][index + m]) {
                visited[dir][index + m] = true;
                Q.push({dir, index + m});
            }
        }
        time++;
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < 2; ++i) {
        cin >> board[i];
    }
    cout << bfs();
}