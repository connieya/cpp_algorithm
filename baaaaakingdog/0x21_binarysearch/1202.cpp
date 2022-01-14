#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int >> jewelry;
    multiset<int> ms;
    while (n--) {
        int weight, value;
        cin >> weight >> value;
        jewelry.push_back({value, weight});
    }
    sort(jewelry.begin(), jewelry.end());
    while (k--) {
        int bag_weight;
        cin >> bag_weight;
        ms.insert(bag_weight);
    }
    int len = jewelry.size();
    long long ans = 0;
    for (int i = len - 1; i >= 0; --i) {
        int weight = jewelry[i].second;
        int value = jewelry[i].first;
        auto it = ms.lower_bound(weight);
        if (it == ms.end()) continue;
        ans += value;
        ms.erase(it);
    }
    cout << ans;
}