﻿#include "bits/stdc++.h"

using namespace std;

int n;
int visited[15][15];

bool Check(int x, int y) {
    for (int i = 0; i < 3; ++i) {
        const int dx = -1, dy = i - 1;
        for (int j = 1; ; ++j) {
            const int cx = x + j * dx;
            const int cy = y + j * dy;
            if (cx < 0 || cx >= n || cy < 0 || cy >= n) break;
            if (visited[cx][cy]) return 0;
        }
    }
    return 1;
}

int dfs(int L) {
    if (L == n) {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!Check(L,i)) continue;
        visited[L][i]= 1;
        ans += dfs(L+1);
        visited[L][i] = 0;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cout << dfs(0);
}