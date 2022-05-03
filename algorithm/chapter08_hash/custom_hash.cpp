#include "bits/stdc++.h"

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    unordered_map<int, int> mp;
    mp[10] =12;
    mp[11] =15;
    mp[12] =17;
    mp[13] =142;

    if (mp.find(13) != mp.end()){
        cout << mp[13] << '\n';
    }

    if (mp.find(11) == mp.end()){
        cout << mp[11] << '\n';
    }

    if (mp.find(15) == mp.end()){
        cout << mp[15] << '\n';
    }

}