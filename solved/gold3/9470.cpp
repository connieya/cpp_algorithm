#include "bits/stdc++.h"

using namespace std;

vector<int> graph[1001];
vector<int> seq_list[1001];
int indegree[1001];
int maxValue[1001];

void init(int m) {
    for (int i = 1; i <= m; ++i) {
        graph[i].clear();
        seq_list[i].clear();
        indegree[i] = 0;
        maxValue[i] = 0;
    }
}

int topology(int m) {
    queue<pair<int, int>> q;
    for (int i = 1; i <= m; ++i) {
        if (indegree[i] == 0) {
            q.push({i, 1});
        }
    }
    while (!q.empty()) {
        int node = q.front().first;
        int seq = q.front().second;
        maxValue[node] = seq;
        q.pop();
//        cout << "node :  " << node << " seq : " << seq << '\n';
        for (int nxt: graph[node]) {
            seq_list[nxt].push_back(seq);
            indegree[nxt]--;
            if (indegree[nxt] == 0) {
                int max_num = 1;
                int cnt = 0;
//                cout << " nxt :  " << nxt << "   -> ";
                for (int s: seq_list[nxt]) {
//                    cout << s << ' ';
                    if (s > max_num) {
                        max_num = s;
                        cnt = 1;
                    } else if (s == max_num) {
                        cnt++;
                    }

                }
//                cout << '\n';
                if (cnt == 1) {
                    q.push({nxt, max_num});
                } else if (cnt >= 2) {
                    q.push({nxt, max_num + 1});
                }
            }
        }
    }

    return maxValue[m];

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int k, m, p;
        cin >> k >> m >> p;
        for (int i = 0; i < p; ++i) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            indegree[b]++;
        }
        cout << k << " " << topology(m) << '\n';
        init(m);
    }
}