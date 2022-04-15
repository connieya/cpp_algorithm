#include "bits/stdc++.h"

#define MAX 100001

using namespace std;

vector<int> graph[MAX];
vector<pair<int, int>> connect;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        connect.push_back({a, b});
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < q; ++i) {
        int d;
        cin >> d;
        int x = connect[d - 1].first;
        int y = connect[d - 1].second;
    }

}