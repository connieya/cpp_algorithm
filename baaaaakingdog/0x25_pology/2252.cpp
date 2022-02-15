#include "bits/stdc++.h"

using namespace std;

int students[32001];
vector<int> d[32001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a , b;
        cin >> a >> b;
        students[b]++;
        d[a].push_back(b);
    }
    queue<int> Q;
    for (int i = 1; i <= n; ++i) {
        if (students[i] == 0){
            Q.push(i);
        }
    }
    while (!Q.empty()){
        int now = Q.front();
        Q.pop();
        cout << now << ' ';
        for (int next :d[now]) {
            students[next]--;
            if (students[next] == 0){
                Q.push(next);
            }
        }
    }

}