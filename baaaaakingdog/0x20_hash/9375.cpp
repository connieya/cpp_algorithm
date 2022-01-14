#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<string , int> m;
        while (n--) {
            string name , type;
            cin >> name >> type;
            if (m.find(type) == m.end()) {
                m.insert({type,1});
            }else {
                m[type]++;
            }
        }
        int ans = 1;
        for (auto i: m) {
            ans *= i.second+1;
        }
        ans--;
        cout << ans << '\n';
    }
}