#include "bits/stdc++.h"

using namespace std;

int dp[101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    pair<int,int> p[101];
    for (int i = 0; i < n; ++i) {
        int a , b;
        cin >> a >> b;
        p[i].first = a , p[i].second =b;
    }
    sort(p,p+n);
    int MX = -1;
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = i-1; j >=0 ; --j) {
            if (p[i].second > p[j].second && dp[j]+1 > dp[i]){
                dp[i] = dp[j] +1;
            }
        }
        if (dp[i] > MX) MX = dp[i];
    }
    cout << n-MX;
}