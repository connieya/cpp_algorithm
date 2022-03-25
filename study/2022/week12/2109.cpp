#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, day, pay, max_day = -1, ans = 0;
    cin >> n;
    vector<pair<int, int>> schedule;
    priority_queue<int> pq;
    for (int i = 0; i < n; ++i) {
        cin >> pay >> day;
        if (day > max_day) {
            max_day = day;
        }
        schedule.push_back({day, pay});
    }
    sort(schedule.begin(), schedule.end());
    int len = schedule.size();
    int j = len-1;
    for (int i = max_day; i >=1 ; --i) {
        for (; j>=0; j--) {
            if (schedule[j].first < i) break;
            pq.push(schedule[j].second);
        }
        while (!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;

}