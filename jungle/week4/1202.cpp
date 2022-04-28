#include "bits/stdc++.h"

using namespace std;


vector<pair<int, int>> j;
int bag[300001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    priority_queue<int> pq;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int weight, value;
        cin >> weight >> value;
        j.push_back({weight, value});
    }
    sort(j.begin(), j.end());

    for (int i = 0; i < m; ++i) {
        cin >> bag[i];
    }
    sort(bag, bag + m);
    int idx = 0;
    long long ans = 0;
    for (int i = 0; i < m; ++i) {
        while (idx < n && j[idx].first <= bag[i]) {
            pq.push(j[idx].second);
            idx++;
        }
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;
}