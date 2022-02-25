#include "bits/stdc++.h"
#define INF 1000000007
using namespace std;


long long dp[100001][8];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int d;
    cin >> d;
    dp[1][1] = 1;
    dp[1][2] = 1;
    for (int i = 1; i < d; ++i) {
        dp[i+1][0] = (dp[i][1]+dp[i][2]) % INF;
        dp[i+1][1] = (dp[i][3]+dp[i][2]+dp[i][0]) % INF;
        dp[i+1][2] = (dp[i][3]+dp[i][1]+dp[i][0]+dp[i][4]) % INF;
        dp[i+1][3] = (dp[i][1]+dp[i][2]+dp[i][4]+dp[i][5]) % INF;
        dp[i+1][4] = (dp[i][2]+dp[i][3]+dp[i][5]+dp[i][7]) % INF;
        dp[i+1][5] = (dp[i][3]+dp[i][4]+dp[i][6]) % INF;
        dp[i+1][6] = (dp[i][5]+dp[i][7]) % INF;
        dp[i+1][7] = (dp[i][4]+dp[i][6]) % INF;

    }
    cout << dp[d][0];
}