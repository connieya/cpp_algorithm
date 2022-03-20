#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, v;
    cin >> a >> b >> v;
    if (a == v) {
        cout << 1;
        exit(0);
    }
    v -= a;
    int ans;
    if(v % (a-b) == 0){
        ans = v/(a-b) +1;
    }else {
        ans = v/(a-b) +2;
    }
    cout << ans;

}