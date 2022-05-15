#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> weight(n);
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
    }
    sort(weight.begin() , weight.end());
    int ans = 0;
    for (auto w : weight) {
        if(ans +1  < w) break;
        ans += w;
    }
    cout << ans +1;
}