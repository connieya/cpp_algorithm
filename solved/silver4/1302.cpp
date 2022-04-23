#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, cnt = -1;
    string ans;
    vector<string> v;
    cin >> n;
    unordered_map<string, int> mp;
    set<string> s;

    for (int i = 0; i < n; ++i) {
        string input;
        cin >> input;
        mp[input]++;
        s.insert(input);
    }
    for (string i : s) {
        int m = mp[i];
        if (m > cnt){
            v.clear();
            v.push_back(i);
            cnt = m;
            ans = i;
        }else if (cnt == m) {
            v.push_back(i);
        }
    }
    sort(v.begin(),v.end());
    cout << v[0];
}