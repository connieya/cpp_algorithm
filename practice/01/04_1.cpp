#include "bits/stdc++.h"

using namespace std;

int ch[17];
int can[17][2];
int n;
int ans = INT_MAX;
void dfs(int L , int start) {
    if (L == n/2){
        int whiteTeam = 0;
        int blackTeam = 0;
        for (int i = 0; i < n; ++i) {
            if (ch[i] == 0){
                whiteTeam += can[i][0];
            }else {
                blackTeam += can[i][1];
            }
        }
        int sub = abs(whiteTeam-blackTeam);
        ans = min(ans, sub);
        return;
    }
    for (int i = start; i < n; ++i) {
        ch[i] = 1;
        dfs(L+1, i+1);
        ch[i] = 0;
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> can[i][0] >> can[i][1];
    }
    dfs(0,0);
    cout << ans;
}