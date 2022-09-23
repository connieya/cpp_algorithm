#include "bits/stdc++.h"

using namespace std;
int d[10001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    while (k--){
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int idx = d[i]-1;
            ans[idx] = p[i];
        }
        p = ans;
    }
    for (int i = 0; i < n; ++i) {
        cout << p[i] << ' ';
    }

}