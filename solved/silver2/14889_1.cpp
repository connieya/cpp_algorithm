#include "bits/stdc++.h"

using namespace std;

int team[21][21], ans =INT_MAX;
bool d[11];


void divideTeam(int L, int n, int start) {
    if (L == n / 2) {
        int start = 0;
        int link = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (d[i] && d[j]) start+= team[i][j];
                if (!d[i] && !d[j]) link += team[i][j];
            }
        }
        int sub = abs(start-link);
        if (ans > sub){
            ans = sub;
        }
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