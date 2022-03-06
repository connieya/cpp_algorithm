#include "bits/stdc++.h"

using namespace std;

int team[21][21], ans =INT_MAX;
bool d[11];

int compareTeam(int n) {
    vector<int> start_team;
    vector<int> link_team;
    for (int i = 1; i <= n; ++i) {
        if (d[i]){
            start_team.push_back(i);
        }else {
            link_team.push_back(i);
        }
    }
    int len =start_team.size();
    int start_sum = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i+1; j < len; ++j) {
            start_sum += team[start_team[i]][start_team[j]]+team[start_team[j]][start_team[i]];
        }
    }
    int link_sum = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i+1; j < len; ++j) {
            link_sum += team[link_team[i]][link_team[j]]+team[link_team[j]][link_team[i]];
        }
    }
    return abs(link_sum-start_sum);
}

void divideTeam(int L, int n, int start) {
    if (L == n / 2) {
        int sub = compareTeam(n);
        ans = min(ans,sub);
        return;
    }
    for (int i = start; i <= n; ++i) {
        d[i] = true;
        divideTeam(L + 1, n, i + 1);
        d[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> team[i][j];
        }
    }
    divideTeam(0, n, 1);
    cout << ans;
}