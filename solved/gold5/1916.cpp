#include "bits/stdc++.h"

#define INF 1001

using namespace std;

vector<pair<int, int>> graph[INF];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m , start , end;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }
    cin >> start >> end;



}