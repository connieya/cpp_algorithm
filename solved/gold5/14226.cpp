﻿#include "bits/stdc++.h"

using namespace std;

int visited[2000][2000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int s, l = 0;
    cin >> s;
    queue<pair<int, int>> Q;
    Q.push({1, 0});
    memset(visited, -1, sizeof(visited));
    visited[1][0] = 0;
    while (!Q.empty()) {
        int screen = Q.front().first;
        int clip_board = Q.front().second;
        Q.pop();
        if (screen == s) {
            cout << visited[screen][clip_board];
            exit(0);
        }
        if (visited[screen][screen] == -1) {
            visited[screen][screen] = visited[screen][clip_board] + 1;
            Q.push({screen, screen});
        }
        if (screen - 1 >= 0 && visited[screen - 1][clip_board] == -1) {
            visited[screen - 1][clip_board] = visited[screen][clip_board] + 1;
            Q.push({screen - 1, clip_board});
        }
        if (screen + clip_board < 2000 && visited[screen + clip_board][clip_board] == -1) {
            visited[screen + clip_board][clip_board] = visited[screen][clip_board] + 1;
            Q.push({screen + clip_board, clip_board});
        }
    }
}