#include "bits/stdc++.h"

using namespace std;

int dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a ,b;
    cin >> a >> b;
    a = ' '+a;
    b = ' '+b;
    int len_a = a.length();
    int len_b = b.length();
    for (int i = 1; i < len_a; ++i) {
        for (int j = 1; j < len_b; ++j) {
            if (a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }

    cout << dp[len_a-1][len_b-1];
}