#include "bits/stdc++.h"

using namespace std;
const int INF = 9999;
const int SWITCHES = 10;
const int CLOCKS = 16;
const char linked[SWITCHES][CLOCKS+1] = {
        "xxx.............",
        "...x...x.x.x....",
        "....x.....x...xx",
        "x...xxxx........",
        "......xxx.x.x...",
        "x.x...........xx",
        "...x..........xx",
        "....xx.x......xx",
        ".xxxxx..........",
        "...xxx...x...x.."
};
int c[16];

bool areAligned(){
    for (int i = 0; i < 16; ++i) {
        if (c[i] != 12) return false;
    }
    return true;
}

void push(int switchs){
    for (int clock = 0; clock < CLOCKS; ++clock) {
        if (linked[switchs][clock] == 'x'){
            c[clock] += 3;
            if (c[clock] == 15) c[clock] = 3;
        }
    }
}

int solve(int switchs)
{
    if (switchs == 10) return areAligned() ? 0 : INF;
    int ret = INF;
    for (int cnt = 0; cnt < 4; ++cnt) {
        ret = min(ret, cnt + solve(switchs+1));
        push(switchs);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 16; ++i) {
            cin >> c[i];
        }
        int ans = solve(0);
        if (ans == INF){
            cout << -1 << '\n';
        }else {
            cout << ans << '\n';
        }

    }
}