#include "bits/stdc++.h"

#define INF 987654321
using namespace std;

int n, l, s, e;
vector<int> subway[100001];
vector<int> station[100001];
int check[100001];
bool visited[100001];

void bfs(int start){
     queue<int> q;
     q.push(start);
     check[start] = -1;
    while (!q.empty()){
        int num = q.front();
        q.pop();
        for(auto line : station[num]){
            if(visited[line]) continue;
            visited[line] = true;
            for(auto next : subway[line]){
                if(check[next] == INF){
                    check[next] = check[num]+1;
                    q.push(next);
                }
            }
        }
    }
    check[start] = 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l;
    int num;
    for (int line = 1; line <= l; line++) {
        while (1) {
            cin >> num;
            if (num == -1) break;
            subway[line].push_back(num);
            station[num].push_back(line);
        }
    }
    cin >> s >> e;
    for (int i = 1; i <=n; ++i) {
        check[i] = INF;
    }
    bfs(s);
    cout << ( check[e] == INF ? -1 : check[e]);
}