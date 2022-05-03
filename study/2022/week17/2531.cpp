#include "bits/stdc++.h"

using namespace std;

int check[3001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, d, k, c, ans = 1;
    vector<int> v;
    cin >> n >> d >> k >> c;
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        v.push_back(b);
    }
    int lt = 0;
    int end = v.size();
    int rt = k, mx;
    check[c]++;
    for (int i = 0; i < k; ++i) {
        if (check[v[i]] == 0) {
            ans++;
        }
        v.push_back(v[i]);
        check[v[i]]++;
    }
    mx = ans;
    while (lt < end) {
        check[v[lt]]--;
        if (check[v[lt]] == 0) ans--;
        if (check[v[rt]] == 0) ans++;
        check[v[rt]]++;
        mx = max(mx, ans);
        lt++;
        rt++;
    }
    cout << mx;



}