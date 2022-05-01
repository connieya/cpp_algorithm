#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , mx =0;
    string ans;
    cin >> n;
    unordered_map<string,int> mp;
    for (int i = 0; i < n; ++i) {
        string book;
        cin >> book;
        mp[book]++;
    }
    for (auto m : mp) {
        if (m.second > mx){
            mx = m.second;
            ans = m.first;
        }else if (m.second == mx){
            if (m.first < ans){
                ans = m.first;
            }
        }
    }
    cout << ans;

}