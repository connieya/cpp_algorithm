#include "bits/stdc++.h"

#define INF 100001

using namespace std;

vector<int> graph[INF];
int a, b, c;
int indegree[INF];
int building[INF];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> c;
    int x, y;
    for (int i = 0; i < b; ++i) {
        cin >> x >> y;
        graph[x].push_back(y);
        indegree[y]++;
    }
    for (int i = 0; i < c; ++i) {
        cin >> x >> y;
        if (x == 1) {
            if (indegree[y] > 0) {
                cout << "Lier!";
                exit(0);
            }
            if(indegree[y] == 0){
                building[y]++;
                if(building[y] == 1){
                    for (int next: graph[y]) {
                        indegree[next]--;
                    }
                }
            }

        } else {
            if (building[y] <= 0) {
                cout << "Lier!";
                exit(0);
            }
            building[y]--;
            if (building[y] == 0) {
                for (int next: graph[y]) {
                    indegree[next]++;
                }
            }
        }
    }
    cout << "King-God-Emperor";
}