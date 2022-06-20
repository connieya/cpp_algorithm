﻿#include "bits/stdc++.h"

using namespace std;

struct Team {
    int sum = 0;
    int problem[101] = {0,};
    int cnt = 0;
    int idx;
    int time;

    bool operator<(const Team &t) const { //
        if (t.sum == sum) {
            if (t.cnt == cnt) {
                return time < t.time;
            }
            return cnt < t.cnt;
        }
        return sum > t.sum;
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, v, m, t, id, number, score;
    cin >> t;
    while (t--) {
        cin >> n >> k >> v >> m;
        Team team[101];
        for (int i = 1; i <= n; i++) {
            team[i].idx = i;
        }
        for (int i = 0; i < m; ++i) {
            cin >> id >> number >> score;
            if (score > team[id].problem[number]) {
                team[id].sum -= team[id].problem[number];
                team[id].problem[number] = score;
                team[id].sum += score;
            };
            team[id].cnt++;
            team[id].time = i;
        }
        sort(team + 1, team + (n + 1));
        for (int i = 1; i <= n; i++) {
            if (team[i].idx == v) {
                cout << i << '\n';
                break;
            }
        }

    }
}