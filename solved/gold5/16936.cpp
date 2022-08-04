﻿#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
ll arr[101];
vector<pair<int, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll m;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        m = arr[i];
        int cnt = 0;
        while (m % 3 == 0) {
            cnt++;
            m /= 3;
        }
        v.push_back({cnt, arr[i]});
    }

    sort(v.begin(), v.end(), [&](pair<int, ll> &a, pair<int, ll> &b) {
        return a.first == b.first ? a.second < b.second : a.first > b.first;
    });
    for (int i = 0; i < n; ++i) {
        cout << v[i].second << ' ';
    }
}