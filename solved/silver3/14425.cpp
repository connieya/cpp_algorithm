#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    unordered_map<string,int> mp;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        mp[str]++;
    }
    int ans =0;
    for (int i = 0; i < m; ++i) {
        string str;
        cin >> str;
        ans += mp[str] > 0;
    }
    cout << ans;
}
