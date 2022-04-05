#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans=0;
    char ch;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ch;
        ans += ch == '1';
    }
    cout << ans;
}