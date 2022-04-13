#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

vector<pair<int, int>> line;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, y;
    ll ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        line.push_back({x, y});
    }
    sort(line.begin(), line.end());
    int len = line.size();
    int start = line[0].first , end = line[0].second;
    for (int i = 1; i < len; ++i) {
        if (line[i].first > end) {
            ans += (end-start);
            start = line[i].first;
            end  = line[i].second;
        }else {
            if (line[i].second > end){
                end = line[i].second;
            }
        }
    }
    ans += end-start;
    cout << ans;
}