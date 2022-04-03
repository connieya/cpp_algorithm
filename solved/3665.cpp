#include "bits/stdc++.h"

using namespace std;

int temp[501];
int indegree[501];
vector<int> R[501];

void topology(int n) {
    queue<int> Q;
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0){
            Q.push(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (Q.empty()){
            cout << "IMPOSSIBLE" << '\n';
            return;
        } else if (Q.size() > 1) {
            cout << "?";
        }
        int x = Q.front();
        Q.pop();
        ans.push_back(x);
        for (int nxt: R[x]) {
            if (--indegree[nxt] == 0) {
                Q.push(nxt);
            }
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
void init(int n) {
    for (int i = 1; i <= n; ++i) {
        R[i].clear();
        indegree[i] = 0;
        temp[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> temp[i];
        }
        for (int i = 0; i < n; ++i) {
            indegree[temp[i]] = i;
            for (int j = i+1; j <n ; ++j) {
                R[temp[i]].push_back(temp[j]);
            }
        }
        int m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            int a,b;
            cin >> a >> b;
            bool ok = false;
            int t;
            for (int j = 0; j < R[a].size(); ++j) {
                if (R[a][j] == b){
                    ok = true;
                    t = j;
                    break;
                }
            }
            if (ok) {
                R[a].erase(R[a].begin()+t);
                R[b].push_back(a);
                indegree[a]--;
                indegree[b]++;
            }else {
                for (int j = 0; j < R[b].size(); ++j) {
                    if (R[b][j] == a){
                        R[b].erase(R[b].begin() + j);
                        break;
                    }
                }
                R[b].push_back(a);
                indegree[a]++;
                indegree[b]--;
            }
        }
        topology(n);
        init(n);
    }
}