#include "bits/stdc++.h"

using namespace std;

int n;
vector<int> graph[100001];
int d[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int a,b;
    for (int i = 0; i < n-1; ++i) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    queue<int> q;
    q.push(1);
    while (!q.empty()){
        int now = q.front();
        q.pop();
        for(int next : graph[now]){
            q.push(next);
        }

    }

}