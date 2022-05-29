#include "bits/stdc++.h"

using namespace std;

string str, bridge[2];
int len, sz;
int cache[20][2][102];

int dfs(int dir, int str_idx, int turn) {
    if (str_idx == len) {
        return 1;
    }
    int &ret = cache[str_idx][turn][dir+1];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = dir + 1; i < sz; i++) {
        if (bridge[!turn][i] == str[str_idx]) {
            ret += dfs(i, str_idx + 1, !turn);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> str >> bridge[0] >> bridge[1];
    len = str.length();
    sz = bridge[0].length();
    memset(cache, -1, sizeof(cache));
    cout << dfs(-1, 0, 0) + dfs(-1, 0, 1);

}