#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    string address;
    cin >> n >> m;
    unordered_map<string,string> mp;
    for (int i = 0; i < n; ++i) {
        string a ,b;
        cin >> a >> b;
        mp[a] =  b;
    }
    for (int i = 0; i < m; ++i) {
        cin >> address;
        cout << mp[address] << '\n';
    }
}