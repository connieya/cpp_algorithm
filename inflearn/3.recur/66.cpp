#include "stdio.h"
#include "vector"

using namespace std;

int n, m, cnt;
bool visited[30];
vector<int> map[30];

void dfs(int L) {
    if (L == n) {
        cnt++;
        return;
    }
    for (int i = 0; i < map[L].size(); i++) {
        if (!visited[map[L][i]]){
            visited[map[L][i]] = true;
            dfs(map[L][i]);
            visited[map[L][i]] = false;
        }
    }
}

int main() {
    int a, b;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d", &a, &b);
        map[a].push_back(b);
    }
    visited[1] = true;
    dfs(1);
    printf("%d", cnt);

}