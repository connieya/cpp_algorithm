#include "bits/stdc++.h"

using namespace std;

int main(void)
{
    int n , m;
    cin >> n >> m;
    int d[50] = {0,};
    vector<int> graph[50];
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        d[b]++;
        graph[a].push_back(b);
    }
    queue<int> Q;
    for (int i = 1; i <= n; ++i) {
        if (!d[i]){
            Q.push(i);
        }
    }
    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        cout << now << ' ';
        for (int i = 0; i < graph[now].size(); ++i) {
            int node = graph[now][i];
            d[node]--;
            if (!d[node]){
                Q.push(node);
            }
        }
    }
}