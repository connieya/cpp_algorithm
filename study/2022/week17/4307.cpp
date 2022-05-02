#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int stick , n, mx = -1, mn = -1;
        cin >> stick >> n;
        for (int i = 0; i < n; ++i) {
            int d;
            cin >> d;
           int t_mn = min(stick-d ,d);
           int t_mx = max(stick-d,d);
            if (t_mn > mn){
                mn = t_mn;
            }
            if (t_mx >mx){
                mx = t_mx;
            }
           mx = max(mx,t_mx);
        }
        cout << mn << ' ' << mx << '\n';

    }
}