#include "stdio.h"
#include "algorithm"

using namespace std;
int a[20000];
int b[20000];

int main(void) {
    int t, n, m, j;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d", &b[i]);
        }
        int cnt = 0;
        sort(a, a + n);
        sort(b, b + m);
        for (int i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
                if (a[i] <= b[j]) {
                    break;
                }
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
}