#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , k;
    cin >> n >> k;
    int ans ;
    for (ans = 0;  ; ans++) {
        int tmp = n;
        int cnt = 0;
        while (tmp) {
            if (tmp % 2) {
                cnt++;
            }
            tmp /=2;
        }
        if (cnt <= k) {
            break;
        }
        n++;
    }
    cout << ans;

}