#include "bits/stdc++.h"

using namespace std;

bool visited[10001];

int dx[] = {-1, 1, 5};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int s, e, k;
    cin >> s >> e >> k;
    for (int i = 0; i < k; ++i) {
        int w;
        cin >> w;
        visited[w] = true;
    }
    visited[s] = true;
    queue<int> Q;
    Q.push(s);
    int L = 0;
    while (!Q.empty()) {
        int len = Q.size();
        for (int i = 0; i < len; ++i) {
            int now = Q.front();
            Q.pop();
            for (int j = 0; j < 3; ++j) {
                int next = now + dx[j];
                if (next < 1 || next > 10000 || visited[next]) continue;
                if (next == e) {
                    cout << L + 1;
                    exit(0);
                }
                Q.push(next);
                visited[next] = true;
            }
        }
        L++;
    }


}