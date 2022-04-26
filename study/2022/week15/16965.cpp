#include "bits/stdc++.h"

using namespace std;

int arr[101][101];
bool visited[101];
vector<int> graph[101];
vector<pair<int, int>> v;
int nodeCount;

bool dfs(int start, int target) {
    visited[start] = true;
    if (start == target) {
        return true;
    }
    for (int next: graph[start]) {
        if (!visited[next]) {
            if (dfs(next, target)) return true;
        }
    }
    return false;
}


bool isConnected(int from, int to) {
    return (arr[to][0] < arr[from][0] && arr[from][0] < arr[to][1]) ||
           (arr[to][0] < arr[from][1] && arr[from][1] < arr[to][1]);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    v.push_back({0, 0});
    while (n--) {
        int s, b, c;
        cin >> s >> b >> c;
        if (s == 1) {
            nodeCount++;
            arr[nodeCount][0] = b;
            arr[nodeCount][1] = c;
            for (int i = 1; i <= nodeCount - 1; ++i) {
                if (isConnected(i, nodeCount)) graph[i].push_back(nodeCount);
                if (isConnected(nodeCount, i))graph[nodeCount].push_back(i);
            }

        } else {
            fill(visited, visited + 101, false);
            if (dfs(b, c)) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }
}