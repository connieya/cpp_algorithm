#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n,m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int ans = 0;
        for (int b = 1; b < n; ++b) {
            for (int a = 1; a < b; ++a) {
                if ( (a*a+b*b+m )% (a*b) == 0) {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}