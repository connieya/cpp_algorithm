#include "bits/stdc++.h"

typedef long long ll;

using namespace std;

ll solve(ll v){
    if (v== 0) return 0;
    if (v == 1) return 1;
    if (v%2) return v/2+2* solve(v/2)+1;
    else return v/2 + 2* solve(v/2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll a,b;
    cin >> a >> b;
    cout << solve(b)- solve(a-1);
}