#include "bits/stdc++.h"
#define INF 101


typedef long long ll;

using namespace std;

int arr[INF];
ll dp[INF][21];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    dp[0][arr[0]] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= 20; ++j) {
            for(const int nxt : {j+arr[i], j-arr[i]}){
                if(nxt <= 20 && nxt >= 0){
                    dp[i][nxt] += dp[i-1][j];
                }
            }
        }
    }
    cout << dp[n-2][arr[n-1]];
}