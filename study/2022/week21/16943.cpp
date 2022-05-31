#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a;
    int b;
    cin >> a >> b;
    sort(a.begin(),a.end());
    int ans = -1;
    do {
        if(a[0] == '0' || stoi(a) >= b) continue;
        ans = max(ans, stoi(a));

    } while (next_permutation(a.begin(),a.end()));
    cout << ans;
}