#include "bits/stdc++.h"
#define MOD 1234567891

typedef long long ll;
using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int L;
    string str;
    cin >> L;
    cin >> str;
    ll ans = 0;
    ll power = 1;
    for (int i = 0; i < L; ++i) {
        ll hash = (str[i]-96);
        ans += (hash*power);
        ans %= MOD;
        power *= 31;
        power %= MOD;
    }
    cout << ans % MOD;
}