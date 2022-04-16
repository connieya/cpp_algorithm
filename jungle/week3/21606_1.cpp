#include "bits/stdc++.h"

using namespace std;

vector<int> graph[200001];
int ans = 0;
string s;

int dfs(int start , int prev){
    int total = 0;
    for (int nxt: graph[start]) {
        if (nxt == prev) continue;

    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int e;
    cin >> e;
    cin >> s;
    for (int i = 0; i < e - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}