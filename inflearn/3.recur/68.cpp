#include "stdio.h"
#include "vector"

using namespace std;

int n, m, ans = 2147000;
vector<pair<int, int> > map[21];
bool visited[21];

void dfs(int L, int sum) {
    if (L == n) {
        if (ans > sum) {
            ans = sum;
        }
        return;
    }
    for (int i = 0; i < map[L].size(); ++i) {
        if (!visited[map[L][i].first]) {
            visited[map[L][i].first] = true;
            dfs(map[L][i].first, sum + map[L][i].second);
            visited[map[L][i].first] = false;
        }
    }
}

int main(void) {
    int a, b, c;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        map[a].push_back(make_pair(b, c));
    }
    visited[1] = true;
    dfs(1, 0);
    printf("%d", ans);
}