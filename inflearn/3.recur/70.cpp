#include "stdio.h"
#include "vector"
#include "queue"

using namespace std;

int answer[20];
vector<int> map[21];
bool visited[21];


int main(void) {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        map[a].push_back(b);
    }
    visited[1] = true;
    queue<int> Q;
    Q.push(1);
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < map[cur].size(); ++i) {
            if (!visited[map[cur][i]]) {
                visited[map[cur][i]] = true;
                Q.push(map[cur][i]);
                answer[map[cur][i]] = answer[cur] + 1;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (answer[i] == 0) {
            answer[i] = -1;
        }
        printf("%d : %d\n", i, answer[i]);

    }
}