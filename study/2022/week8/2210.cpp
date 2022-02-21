﻿#include "bits/stdc++.h"

using namespace std;

int digits[6][6];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
unordered_set<int> ans;


void dfs(int L,int sum,  int x, int y) {
    if (L == 6) {
        cout << sum <<'\n';
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        dfs(L + 1,sum*10+digits[nx][ny],  nx, ny);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> digits[i][j];
        }
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            dfs(0,digits[i][j],i,j);
        }
    }
    cout << ans.size();
}