﻿#include "bits/stdc++.h"

using namespace std;

pair<int, int> arr[31];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int d, k;
    cin >> d >> k;
    arr[1] = {1, 0};
    arr[2] = {0, 1};
    arr[3] = {1, 1};
    for (int i = 4; i <= d; ++i) {
        arr[i] = {arr[i - 1].first + arr[i - 2].first, arr[i - 1].second + arr[i - 2].second};
    }
    
    int idx = 1;
    while (1){
        int v = k- idx*arr[d].first;
        if (v % arr[d].second == 0) {
            cout << idx << '\n' << v / arr[d].second;
            exit(0);
        }
        idx++;
    }
}