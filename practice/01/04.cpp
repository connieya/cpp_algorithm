#include "bits/stdc++.h"

using namespace std;

int d[17];
int team[17][2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , ans = INT_MAX;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> team[i][0] >> team[i][1];
    }
    for (int i = n/2; i < n; ++i) {
        d[i] =1;
    }
    do {
        int whiteTeam = 0;
        int blackTeam = 0;
        for (int i = 0; i < n; ++i) {
            if (d[i] == 0){
                whiteTeam +=team[i][0];
            }else {
                blackTeam += team[i][1];
            }
        }
        int sub = abs(whiteTeam-blackTeam);
        ans = min(sub,ans);
    } while (next_permutation(d,d+n));

    cout << ans;
}