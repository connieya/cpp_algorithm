#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
const ll INF = ll(1e18);
int n, m;
vector<int> v;

bool check(ll k) {
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += k / v[i];
        if (cnt >= m) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];

    }
    ll lt = 0, rt = INF;
    while (lt + 1 < rt) {
        ll mid = (lt + rt) / 2;
        if (!check(mid)){
            lt = mid;
        }else {
            rt = mid;
        }
    }
    cout << rt;
}