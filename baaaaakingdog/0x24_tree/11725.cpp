#include "bits/stdc++.h"

using namespace std;

vector<int> tree[100001];
int d[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    queue<int> Q;
    Q.push(1);
    while (!Q.empty()){
        int now = Q.front();
        Q.pop();
        for (int next: tree[now]) {
            if (d[now] == next){
                continue;
            }
            d[next] = now;
            Q.push(next);
        }
    }
    for (int i = 2; i <= n; ++i) {
        cout << d[i] << '\n';
    }
}