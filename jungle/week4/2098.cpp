#include "bits/stdc++.h"

using namespace std;

int n;
int cost[17][17];
int dp[17][1 << 16];

const int IMPOSSIBLE = 1e7;

void toBinary(int n){
    if (n==0) return;
    toBinary(n/2);
    cout << n%2;
}

int TSP(int current, int visited) {
    if (visited == (1 << n) - 1) { // 모든 도시 방문 완료
        return cost[current][0] ? cost[current][0] : IMPOSSIBLE;
    }
    int &ret = dp[current][visited];
    if (ret != -1) return ret;

    ret = IMPOSSIBLE;
    for (int i = 1; i < n; ++i) {
        if (visited & (1<<i)) continue;
        if (cost[current][i] == 0) continue;
        cout << i << ' ' << visited << ' ';
        toBinary(visited);
        cout << '\n';
        ret = min(ret , TSP(i,visited | (1<<i)) + cost[current][i]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << TSP(0,1);

}