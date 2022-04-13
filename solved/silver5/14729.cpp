#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    double score;
    priority_queue<double> pq;
    vector<double> v;
    for (int i = 0; i < n; ++i) {
        cin >> score;
        if (pq.size() == 7) {
            pq.push(score);
            pq.pop();
        } else {
            pq.push(score);
        }
    }
    while (!pq.empty()) {
        v.push_back(pq.top());
        pq.pop();
    }
    sort(v.begin(), v.end());
    for (double i: v) {
        printf("%.3lf\n", i);
    }

}