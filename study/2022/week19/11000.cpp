#include "bits/stdc++.h"

using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        int s, e;
        cin >> s >> e;
        v.push_back({s, e});
    }
    sort(v.begin(), v.end(), comp);
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(v[0].second);
    int len = v.size();
    for (int i = 1; i < len; i++) {
        int prev = pq.top();
        if (prev <= v[i].first) {
            pq.pop();
        }
        pq.push(v[i].second);
    }
    cout << pq.size();
}