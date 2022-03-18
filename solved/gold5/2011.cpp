#include "bits/stdc++.h"

#define MOD 1000000

using namespace std;
int dp[5001];
int a[5001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int len = s.size();
    for (int i = 1; i <= len; ++i) {
        a[i] = s[i-1]-'0';
    }
    dp[0] =1;
    for (int i = 1; i <= len; ++i) {
        if (a[i]> 0) {
            dp[i] = (dp[i]+dp[i-1]) % MOD;
        }
        int x = a[i-1]*10 + a[i];
        if (x>=10 && x <= 26){
            dp[i] = (dp[i] + dp[i-2]) % MOD;
        }
    }
    cout << dp[len];

}