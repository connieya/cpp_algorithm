#include "bits/stdc++.h"

using namespace std;

int w, h, t, s;
vector<pair<int, int>> trees;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> w >> h >> t >> s;
    for (int i = 0; i < t; ++i) {
        int x, y;
        cin >> x >> y;
        trees.push_back({x, y});
    }
    int ans = 0;
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < t; ++j) {
            int cnt = 0;
            int a = trees[i].first;
            int b = trees[j].second;
            for (int k = 0; k < t; ++k) {
                int x = trees[k].first;
                int y = trees[k].second;
                if (x >= a && x <= a+s && y>=b && y<=b+s ){
                    cnt++;
                }
            }
            ans = max(ans,cnt);
        }
    }
    cout << ans;

}