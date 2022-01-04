#include "stdio.h"

using namespace std;
bool visited[1001];
int arr[1001];

bool dfs(int node) {
    if (visited[node]) {
        return true;
    }
    visited[node] = true;
    if (dfs(arr[node])) return true;
    return false;
}

int main(void) {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &arr[i]);
            visited[i] = false;
        }
        for (int i = 1; i <= n; ++i) {
            if (visited[i]) {
                continue;
            }
            if (dfs(i)) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
}