#include "stdio.h"
#include "algorithm"

using namespace std;
int n, m, MIN = 2147000;
int map[21][21];
bool visited[21];

void dfs(int L, int sum) {
    if (L == n) {
        MIN = min(sum, MIN);
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (map[L][i] != 0 && !visited[L]) {
            visited[L] = true;
            dfs(i, sum + map[L][i]);
            visited[L] = false;
        }
    }

}

int main(void) {
    int a, b, c;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        map[a][b] = c;
    }
    dfs(1, 0);
    printf("%d", MIN);
}