#include "bits/stdc++.h"

#define INF 21470000
using namespace std;

long long d[501];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<pair<pair<int, int>, int>> bus;
    int n, m;
    cin >> n >> m;
    d[1] = 0;
    for (int i = 2; i <= n; ++i) {
        d[i] = INF;
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        bus.push_back({{a, b}, c});
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < bus.size(); ++j) {
            int s1 = bus[j].first.first;
            int s2 = bus[j].first.second;
            int time = bus[j].second;
            if (d[s1] != INF && d[s1] + time < d[s2]) {
                d[s2] = d[s1] + time;
            }
        }
    }
    if (d[1] < 0){
        cout << -1 <<'\n';
        exit(0);
    }
    for (int i = 2; i <= n; ++i) {
        if (d[i] == INF) {
            cout << -1 << '\n';
        } else {
            cout << d[i] << '\n';
        }
    }

}