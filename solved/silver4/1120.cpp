#include "bits/stdc++.h"

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a, b;
    cin >> a >> b;
    int ans = INT_MAX;
    for (int i = 0; i <= b.length()-a.length(); ++i) {
        int cnt = 0;
        for (int j = 0; j < a.length(); ++j) {
            cnt += a[j] != b[j+i];
        }
        ans = min(ans,cnt);
    }
    cout << ans;

}